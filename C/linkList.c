#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElementType;

//topic : declare structure of link list
typedef struct Node{
    ElementType data;
    struct Node * next;
}Node;
typedef Node * LinkList;


//topic : generate a link list
//subtopic : create a link list by head
Status CreateLinkList_Head(LinkList * L, int n)
{
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->data = 0;
    (*L)->next = NULL;
    while(n--){
        p = (LinkList)malloc(sizeof(Node));
        p->data = n;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
//subtopic : create a link list by tail

//topic : print a link list

int main()
{
    LinkList *L;

}