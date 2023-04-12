#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 30


typedef int ElementType;
typedef struct 
{
    ElementType data[30];
    int size;
}SqList;

typedef int Status;
Status GetElem(SqList *L, int i, ElementType *e)
{
    if(L->size == MAXSIZE) return 0;
    if(i < 0 || i >= L->size) return 0;
    else {
        *e = L->data[i];
        return 1;
    }
}

int main()
{
    srand(time(0));
    SqList *L;
    L = (SqList *)malloc(sizeof(SqList));
    L->size = 29;
    for(size_t i = 0; i < 29; i++){
        L->data[i] = rand()%10;
    }
    int *e;
    *e = 3;
    // GetElem(L, 3,e);
    printf("%d \n",*e);
    
}
