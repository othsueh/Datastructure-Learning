#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMELEN 1000
#define ABS(x) ((x)<0 ? -(x) : (x))

int start = 0;
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
term *temp = NULL;
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
    term *current = p->poly;
    while(current != NULL){
        term *temp = current;
        current = current->next;
        free(temp);
    }
    free(p->name);
    free(p);
    return;
}
char *setName(char *name)
{
    name = (char *)malloc(sizeof(char) * NAMELEN);
    getchar();
    fgets(name, NAMELEN, stdin);
    name[strlen(name) - 1] = '\0';
    return name;
}
void printPolynomial(polynomial *p)
{
    temp = p->poly;
    while(temp != NULL){
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
    p->poly = (term *)malloc(sizeof(term));
    p->poly->next = NULL;
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

term *addTerm(term *p, int cof, int exp)
{
    if(start){
        p->cof = cof;
        p->exp = exp;
        start = 0;
        current->len++;
        return p;
    }
    temp = current->poly;
    for(int i = 0; i < current->len; i++){
        if(temp->exp == exp){
            temp->cof += cof;
            return p;
        }
        temp = temp->next;
    }
    term *t = (term *)malloc(sizeof(term));
    t->cof = cof;
    t->exp = exp;
    t->next = p->next;
    p->next = t;
    current->len++;
    return t;
}
polynomial *setPolynomial(polynomial *p)
{
    p->name = setName(p->name);
    printf("Polynomial %s is now created,set value to it\n", current->name);
    start = 1;
    int cof, exp;
    term *cterm = p->poly;
    while(1){
        int result = scanf("%dx^%d", &cof, &exp);
        if(result == 1)
            break;
        else{
            if(cof == 0)
                continue;
            cterm = addTerm(cterm, cof, exp);
        }
    }
    p->poly = mergeSort(p->poly);
    pol[polycount++] = current;
    return p;
}
void *deleteTerm(term *p)
{
    term *t = p;
    p = p->next;
    free(t);
    current->len--;
    return p;
}
polynomial* matchPolynomial(char *name)
{
    for(int i = 0; i < polycount; i++){
        if(strcmp(pol[i]->name, name) == 0){
            current = pol[i];
            printf("Polynomial %s is now current polynomial.\n", current->name);
            break;
        }
    }
    return current;
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
                char *name = setName(name);
                current = matchPolynomial(name);
                if(current == NULL)
                    printf("No such polynomial.\n");
                else
                    printPolynomial(current);
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
                addTerm(current->poly, cof, exp);
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
                    current->poly = deleteTerm(ltemp);
                    break;
                }
                for(int i = 0; i < current->len-1; i++){
                    if(ltemp->next->exp == exp){
                        ltemp->next = deleteTerm(ltemp->next);
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
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
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