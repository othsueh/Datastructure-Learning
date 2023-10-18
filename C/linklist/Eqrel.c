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
ElemType stack[MAX_SIZE];
int top = -1;
Status Empty(int i)
{
    if(!seq[i].data) return TRUE;
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
Status InSeq(ElemType i, ElemType j)
{
    Node *p = seq[i].next;
    while(p)
    {
        if(p->data == j) return TRUE;
        p = p->next;
    }
    return FALSE;
}
Status addEqu(ElemType i, ElemType j)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if(InSeq(i,j)) return ERROR;
    if(!seq[i].data) seq[i].data = 1;
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
Status InStack(ElemType i)
{
    for(int j = 0; j < top; j++)
        if(stack[j] == i) return TRUE;
    return FALSE;
}
Status FreeNode(Node *p)
{
    p->data = 0;
    Node *q = p->next;
    while(q)
    {
        Node *j = q;
        q = q->next;
        free(j);
    }
    return OK;
}
Status visitEq(int i)
{
    stack[++top] = i;
    Node *p = seq[i].next;
    if(!p) return ERROR;
    while(p)
    {
        if(!InStack(p->data)){
            if(seq[p->data].next) visitEq(p->data);
            else stack[++top] = p->data;
        } 
        p = p->next;
    }
    while(stack[top]!=i)
        visit(stack[top--]);
    if(top == 0){
        printf("\n");
        top = -1;
    }
    FreeNode(&seq[i]);
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
    printf("============================\n");
    printf("The equivalance relation is:\n");
    printf("============================\n");
    for(i = 0; i < MAX_SIZE; i++)
    {
        if(!Empty(i)){
            printf("%d: ", i);
            visitEq(i);
        } 
    }
}