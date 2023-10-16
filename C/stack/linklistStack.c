#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;

Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}
Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    while(p){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
        return ERROR;
    S->top = NULL;
    S->count = 0;
    return OK;
}
int StackLength(LinkStack S)
{
    return S.count;
}
Status StackEmpty(LinkStack S)
{
    if (S.count == 0)
        return TRUE;
    else
        return FALSE;
}

Status GetTop(LinkStack S, SElemType *e)
{
    if(S.top == NULL)
        return ERROR;
    else
        *e = S.top->data;
    return OK;
}

Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if(StackEmpty(*S))
        return ERROR;
    p = S->top;
    *e = p->data;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}


Status ClearStack(LinkStack *S)
{
    LinkStackPtr p,q;
    p = S->top;
    while(p){
        q = p;
        p = p->next;
        free(q);
        S->count--;
    }
    return OK; 
}
Status DestroyStack(LinkStack *S)
{
    ClearStack(S);
    free(S);
    return OK;
}

int main()
{
    LinkStack S;
    SElemType e;
    srand(time(0));
    InitStack(&S);
    if(StackEmpty(S))
        printf("The Stack is empty!\n");
    else
        printf("The Stack is not empty!\n");
    for(int i = 0; i < 10; i++){
        e = rand()%100+1;
        Push(&S, e);
    }
    printf("The Stack's length is %d\n", StackLength(S));
    printf("The Stack's elements are: ");
    StackTraverse(S);
    GetTop(S, &e);
    printf("The Stack's top element is %d\n", e);
    Pop(&S, &e);
    printf("Pop the top element %d\n", e);
    ClearStack(&S); 
    if(StackEmpty(S))
        printf("The Stack is empty!\n");
    else
        printf("The Stack is not empty!\n");
    return 0;
}