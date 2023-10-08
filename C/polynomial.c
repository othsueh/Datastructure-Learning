#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMELEN 1000
#define ABS(x) ((x)<0 ? -(x) : (x))

typedef struct term{
    int cof;
    int exp;
    struct term *next;
}term;

typedef struct{
    char *name;
    int len;
    term *poly;
}polynomial;

polynomial *pol[1000];
polynomial *current = NULL;
int polycount = 0;
void UI()
{
    printf("Hello, I'm othsueh, this is my polynomial program!\n 🌹 start with Welcome To The Jungle by Guns N' Roses 🌹\n");
    printf("Please choose the function you want to use and enter the number of the function name:\n");
    printf("1) Create a polynomial and name it.(It will automatically be current polynomial)\n");
    printf("2) Set current polynomial by name and present it\n");
    printf("3) Show the coefficient of the term with the given exponent from current polynomial\n");
    printf("4) Add a nonzero term to current polynomial\n");
    printf("5) Delete the term with the given exponent from current polynomial\n");
    printf("6) Add two polynomials and show the result\n");
    printf("7) Subtract two polynomials and show the result\n");
    printf("8) Multiply two polynomials and show the result\n");
    printf("9) Divide two polynomials and show the quotient and remainder\n");
    printf("10) Exit\n");
    return;
}
void freePolynomial(polynomial *p)
{
    if(p == NULL)
        return;
    if(p->name != NULL)
        free(p->name);
    
    term *current = p->poly;
    while(current != NULL){
        term *temp = current;
        current = current->next;
        free(temp);
    }
    free(p);
    return;
}
char *setName(char *name)
{
    name = (char *)malloc(sizeof(char) * NAMELEN);
    fgets(name, NAMELEN, stdin);
    name[strlen(name) - 1] = '\0';
    return name;
}
void printPolynomial(polynomial *p)
{
    term *temp = p->poly;
    while(temp != NULL){
        if(temp == p->poly){
            if(temp->exp == 0)
                printf("%d", temp->cof);
            else
                printf("%dx^%d", temp->cof, temp->exp);
        }
        else 
            printf("%dx^%d", ABS(temp->cof), temp->exp);
        temp = temp->next;
        if(temp != NULL){
            if(temp->cof < 0)    printf(" - ");
            else    printf(" + ");
        }
    }
    printf("\n");
    return;
}
polynomial *create()
{
    polynomial *p = (polynomial *)malloc(sizeof(polynomial));
    p->poly = NULL;
    p->name = NULL;
    p->len = 0;
    return p;
}

term *merge(term* left, term* right) {
    // merge with recursive
    if(!right) return left;
    if(!left) return right;
    
    if(left->exp < right->exp) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}
term *mergeSort(term *head)
{
    if(!head || !head->next)
        return head;
    term *slow = head;
    term *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;

    term *left = mergeSort(head);
    term *right = mergeSort(fast);
    return merge(left, right);
}

void findTerm(term *p, int exp)
{
    if(p->exp == exp){
        printf("The coefficient of the term with exponent %d is %d\n", exp, p->cof);
        return;
    }
    if(p->next == NULL){
        printf("The coefficient of the term with exponent %d is 0\n", exp);
        return;
    }
    findTerm(p->next, exp);
    return;
}

term *deleteTerm(term *p,int *len)
{
    term *t = p;
    p = p->next;
    free(t);
    *len--;
    return p;
}
void addTerm(polynomial *p, int cof, int exp)
{
    if(cof == 0)
        return;
    term *current = p->poly;
    if(current == NULL){
        p->poly = (term *)malloc(sizeof(term));
        p->poly->cof = cof;
        p->poly->exp = exp;
        p->poly->next = NULL;
        p->len++;
        return;
    }
    term *temp = current;
    for(;temp;temp = temp->next){
        if(temp->exp == exp){
            temp->cof += cof;
            if(temp->cof == 0){
                if(temp == p->poly)
                    p->poly = deleteTerm(temp, &p->len);
                else
                    temp = deleteTerm(temp, &p->len);
            }
            return;
        }
        if(temp->next == NULL)
            break;
    }
    term *t = (term *)malloc(sizeof(term));
    t->cof = cof;
    t->exp = exp;
    t->next = temp->next;
    temp->next = t;
    p->len++;
    return;
}
polynomial *setPolynomial(polynomial *p)
{
    getchar();
    p->name = setName(p->name);
    printf("Polynomial %s is now created,set value to it\n", p->name);
    int cof, exp;
    while(1){
        int result = scanf(" %dx^%d", &cof, &exp);
        if(result == 1)
            break;
        else{
            if(cof == 0)
                continue;
            addTerm(p,cof,exp);
        }
    }
    p->poly = mergeSort(p->poly);
    pol[polycount++] = p;
    return p;
}
polynomial* matchPolynomial(char *name)
{
    polynomial *temp = NULL;
    for(int i = 0; i < polycount; i++){
        if(strcmp(pol[i]->name, name) == 0){
            temp = pol[i];
            break;
        }
    }
    return temp;
}
int compare(int a, int b) {
    if (a == b) {
        return 0;
    } else if (a > b) {
        return 1;
    } else {
        return -1;
    }
}
void addPolynomial(polynomial *p1, polynomial *p2, polynomial *p)
{
    term *t1 = p1->poly;
    term *t2 = p2->poly;
    while(t1 && t2){
        switch(compare(t1->exp, t2->exp)){
            case 1:
                addTerm(p, t2->cof, t2->exp);
                t2 = t2->next;
                break;
            case -1:
                addTerm(p, t1->cof, t1->exp);
                t1 = t1->next;
                break;
            case 0:
                addTerm(p, t1->cof + t2->cof, t1->exp);
                t1 = t1->next;
                t2 = t2->next;
                break;
        }
    }
    while(t1){
        addTerm(p, t1->cof, t1->exp);
        t1 = t1->next;
    }
    while(t2){
        addTerm(p, t2->cof, t2->exp);
        t2 = t2->next;
    }
}
void subPolynomial(polynomial *p1, polynomial *p2, polynomial *p)
{
    term *temp = p2->poly;
    for(;temp;temp = temp->next)
        temp->cof *= -1;
    addPolynomial(p1, p2, p);
    temp = p2->poly;
    for(;temp;temp = temp->next)
        temp->cof *= -1; 
}
void inputNmatch(polynomial **p1, polynomial **p2)
{
    char *a, *b;
    printf("Please enter the name of the first polynomial:\n");
    getchar();
    a = setName(a);
    printf("Please enter the name of the second polynomial:\n");
    b = setName(b);
    *p1 = matchPolynomial(a);
    *p2 = matchPolynomial(b);
    free(a);
    free(b);
}
void mulPolynomial(polynomial *p1, polynomial *p2, polynomial *p)
{
    term *t1 = p1->poly;
    term *t2 = p2->poly;
    while(t1){
        for(t2 = p2->poly;t2;t2 = t2->next)
            addTerm(p,t1->cof * t2->cof, t1->exp + t2->exp);
        t1 = t1->next;
    }
}
term *getlastterm(term* t)
{
    while(t->next)
        t = t->next;
    return t;
}
void divPolynomial(polynomial *p1, polynomial *p2, polynomial *q, polynomial *r)
{
    term *t1 = p1->poly;
    for(;t1;t1 = t1->next)
        addTerm(r, t1->cof, t1->exp);
    t1 = r->poly;
    t1 = getlastterm(t1);
    term *t2 = p2->poly;
    t2 = getlastterm(t2);
    printf("t1->exp = %d, t2->exp = %d\n", t1->exp, t2->exp);
    while(t1->exp >= t2->exp){
        int scalar = t1->cof/t2->cof;
        int exp = t1->exp - t2->exp;
        printf("scalar = %d, exp = %d\n", scalar, exp);
        addTerm(q, scalar, exp);
        for(t2 = p2->poly;t2;t2 = t2->next)
            addTerm(r, -scalar * t2->cof, exp+t2->exp);
        t2 = p2->poly;
        t2 = getlastterm(t2);
        if(r->poly != NULL){
            t1 = r->poly;
            t1 = getlastterm(t1);
            printf("test\n");
        }
    } 
}
int main()
{
    int flag = 0;
    int choice;
    int cof, exp;
    term *ltemp = NULL;
    while(!flag){
        UI();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                current = create();
                current = setPolynomial(current);
                printf("Polynomial %s has saved to current polynomial.\n", current->name);
                break;
            case 2:
                getchar();
                char *name = setName(name);
                polynomial *temppoly = NULL;
                temppoly = matchPolynomial(name);
                if(temppoly == NULL)
                    printf("No such polynomial.\n");
                else
                    current = temppoly;
                if(current != NULL){
                    printf("Current polynomial is %s\n", current->name);
                    printPolynomial(current);
                }
                free(name);
                break;
            case 3:
                if(current == NULL){
                    printf("No current polynomial, please create one.\n");
                    break;
                }
                scanf("%d", &exp);
                findTerm(current->poly, exp);
                break;
            case 4:
                if(current == NULL){
                    printf("No current polynomial, please create one.\n");
                    break;
                }
                scanf("%dx^%d", &cof, &exp);
                if(cof == 0){
                    printf("Coefficient is 0, no need to add.\n");
                    break;
                }
                addTerm(current, cof, exp);
                current->poly = mergeSort(current->poly);
                break;
            case 5:
                if(current == NULL){
                    printf("No current polynomial, please create one.\n");
                    break;
                }
                scanf("%d", &exp);
                ltemp = current->poly;
                if(ltemp->exp == exp){
                    current->poly = deleteTerm(ltemp, &current->len);
                    break;
                }
                for(int i = 0; i < current->len-1; i++){
                    if(ltemp->next->exp == exp){
                        ltemp->next = deleteTerm(ltemp->next, &current->len);
                        break;
                    }
                    if(i == current->len - 2){
                        printf("No such term.\n");
                        break;
                    }
                    ltemp = ltemp->next;
                }
                break;
            case 6:
                polynomial *pa  = create();
                polynomial *p1, *p2;
                inputNmatch(&p1, &p2);
                if(!p1 || !p2){
                    printf("No such polynomial.\n");
                    break;
                }
                addPolynomial(p1, p2, pa);
                printPolynomial(pa);
                freePolynomial(pa);
                break;
            case 7:
                polynomial *ps  = create();
                polynomial *p11, *p22;
                inputNmatch(&p11, &p22);
                if(!p11 || !p22){
                    printf("No such polynomial.\n");
                    break;
                }
                subPolynomial(p11, p22, ps);
                printPolynomial(ps);
                freePolynomial(ps);
                break;
            case 8:
                polynomial *pm = create();
                polynomial *p111, *p222;
                inputNmatch(&p111,  &p222);
                if(!p11 || !p22){
                    printf("No such polynomial.\n");
                    break;
                }
                mulPolynomial(p111,p222,pm);
                printPolynomial(pm);
                freePolynomial(pm);
                break;
            case 9:
                polynomial *pq = create();
                polynomial *pr = create();
                polynomial *p1111, *p2222;
                inputNmatch(&p1111, &p2222);
                if(!p11 || !p22){
                    printf("No such polynomial.\n");
                    break;
                }
                divPolynomial(p1111, p2222, pq, pr);
                if(pq->poly){
                    printf("The quotient is:\n");
                    printPolynomial(pq);
                }
                if(pr->poly){
                    printf("The remainder is:\n");
                    printPolynomial(pr);
                }
                freePolynomial(pq);
                freePolynomial(pr);
                break;
            case 10:
                for(int i = 0; i < polycount; i++)
                    freePolynomial(pol[i]);
                flag = 1;
                break;
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}