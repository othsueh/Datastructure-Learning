//!Equivalance Relation

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

Node seq[MAX_SIZE];
Status Empty(int i)
{
    if(!seq[i].next) return TRUE;
    else return FALSE;
}
Status Compare(ElemType *a, ElemType *b)
{
    if(*a == *b) return TRUE;
    else if(*a > *b){
        ElemType temp = *a;
        *a = *b;
        *b = temp;
    }
    return FALSE;
}
Status addEqu(ElemType i, ElemType j)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if(Compare(&i, &j)) return ERROR;
    Node *q = &seq[i];
    p->data = j;
    while(q->next) q = q->next;
    q->next = p;
    return OK;
}
Status visit(ElemType i)
{
    printf("%d ", i);
    return OK;
}
Status visitEq(int i)
{
    Node *p = seq[i].next;
    if(!p) return ERROR;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    int i, j;
    while(scanf("%d %d", &i, &j) != EOF)
    {
        if(i < 0 || j <0){
            printf("Invalid input!\n");
            continue;
        }
        addEqu(i, j); 
    }
    for(i = 0; i < MAX_SIZE; i++)
    {
        if(!Empty(i)){
            printf("%d: ", i);
            visitEq(i);
        } 
    }
}