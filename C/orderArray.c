#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 30
#define ERROR 0
#define OK 1
typedef int ElementType;
typedef struct 
{
    ElementType data[30];
    int size;
}SqList;

typedef int Status;

//Get the element of the i-th position O(1)
Status GetElem(SqList *L, int i, ElementType *e)
{
    if(L->size == 0 || i < 1 || i > L->size) return ERROR;
    else {
        *e = L->data[i-1];
        return 1;
    }
}

//Insert the element e into the i-th position O(n)
Status ListInsert(SqList *L, int i, ElementType e)
{ 
    if(L->size == MAXSIZE || i < 1 || i > L->size + 1) return ERROR;
    else{
        for(int j = L->size - 1; j >= i-1 ; j--){
            L->data[j+1] = L->data[j];
        }
    }
    L->data[i-1] = e;
    L->size++;
    return OK;
}

//Delete the element of the i-th position O(n)
Status ListDelete(SqList *L, int i, ElementType *e)
{
    if( L->size == MAXSIZE || i < 1 || i > L->size) return ERROR;
    *e = L->data[i-1];
    if(i < L->size){
        for(int j = i; j < L->size;j++){
            L->data[j-1] = L->data[j];
        }
    }
    L->size--;
    return OK;
}

//Print the list O(n)
Status PrintList(SqList *L)
{
    if(L->size==0) return ERROR;
    else{
        for(size_t i = 0; i < L->size;i++){
            printf("%d ", L->data[i]);
        }
        printf("\n");
    }
    return OK;
}

//main function
int main()
{
    srand(time(0));
    SqList *L = (SqList *)malloc(sizeof(SqList));
    L->size = 29;
    for(size_t i = 0; i < L->size; i++){
        L->data[i] = i+1;
    }
    int *e;
    ListDelete(L, 1, e);
    PrintList(L);
    free(L);
    
}
