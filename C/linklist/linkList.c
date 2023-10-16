#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElementType;

//topic : declare structure of link list
typedef struct Node{
    ElementType data;
    struct Node * next;
}Node;
typedef Node * LinkList;

//topic : create link list
Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    return OK;
}

//topic : check the linkList
//subtopic : check the empty of link
Status ListEmpty(LinkList L)
{
    if(L->next) return FALSE;
    else return TRUE;
}
//subtopic: check the length of link
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//topic : visit the linklist
//subtopic : check the node
Status visit(ElementType e)
{
    printf("%d ",e);
    return OK;
}
//subtopic : traverse the list
Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
//topic insert a new node
Status ListInsert(LinkList *L, int i, ElementType e)
{
    int j = 1;
    LinkList p,s;
    p = *L;
    j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p||j>i){
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
//topic : Find
//subtopic : find ith element
Status GelElem(LinkList L, int i, ElementType *e)
{
    int j = 1;
    LinkList p = L->next;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if(!p||j>i){
        return ERROR;
    }
    *e = p->data;
    return OK;
}
//subtopic : find the element location by value
int LocateElem(LinkList L, ElementType e)
{
    int i = 0;  
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data == e) return i;
        p = p->next;
    }
    return ERROR;
}
//topic: Delete
//subtopic : delete the node
Status ListDelete(LinkList *L, int i, ElementType *e)
{
    int j =1;
    LinkList p,q;
    p = *L;
    while(p->next && j < i){
        p = p->next;
        ++j;
    }
    if(!(p->next)||j>i){
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}
//subtopic : clear the list
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p = (*L)->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    for(int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
void CreateListTail(LinkList *L, int n)
{
    LinkList p,t;
    srand(time(0));
    t = *L;
    for(int i = 0; i < n;i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        t->next = p;
        t = p;
    }
}
int main()
{
    ElementType e;
    LinkList L;
    //*Init the Linklist
    InitList(&L);
    printf("%d\n",ListLength(L));
    //*Insert the element
    for(int i = 1; i <= 5; i++) ListInsert(&L, i, i);
    ListTraverse(L);
    printf("%d\n",ListLength(L));
    //*Check the empty
    printf("%d\n",ListEmpty(L));
    //*Delete the element
    for(int i =3; i<=4; i++){
        if(ListDelete(&L, i, &e)) printf("The element %d is deleted\n",e);
        else printf("The element is not exist\n");
    }
    printf("%d\n",ListLength(L));
    //*Find ith element
    GelElem(L, 2, &e);
    printf("The element on 2 is %d\n",e);
    e = LocateElem(L, 4);
    if(e) printf("The element 4 is on %d\n",e);
    else printf("The element is not exist\n");
    //*Clear the list
    ClearList(&L); 
    printf("%d\n",ListEmpty(L));
    //*Create the list(by head)
    CreateListHead(&L, 10);
    ListTraverse(L);

    //*Create the list(by tail)
    ClearList(&L);
    printf("%d\n",ListEmpty(L));
    CreateListTail(&L, 10);
    ListTraverse(L);


}