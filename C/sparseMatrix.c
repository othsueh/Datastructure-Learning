#include <stdio.h>
#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))
typedef struct{
    int row, col,val;
} term;

void fastTranspose(term *unit, term *tunit)
{
    int rowTerms[100] = {0};
    int startingPos[100] = {0};
    int count = unit->val;
    for(int i = 0; i < unit->val; i++)
        rowTerms[unit[i].col]++;
    startingPos[0] = 1;
    for(int i = 1; i < unit->col; i++)
        startingPos[i] = startingPos[i-1] + rowTerms[i-1];

    tunit->row = unit->col;
    tunit->col = unit->row;
    tunit->val = unit->val;

    for(int i = 1; i <= unit->val; i++){
        int j = startingPos[unit[i].col]++;
        tunit[j].row = unit[i].col;   
        tunit[j].col = unit[i].row;
        tunit[j].val = unit[i].val;
    }
}
void ArraytoTerm(term *unit, int *arr,int len)
{
    for(int i = 0; i < len; i++){
        (unit+i)->row = *(arr+i);
        (unit+i)->col = *(arr+len+i);
        (unit+i)->val = *(arr+2*len+i);
    }
}
void mmul(term *a, term*b, term*d)
{
    if(a->col != b->row){
        printf("error\n");
        return;
    }     
    int totalA = a->val;
    int totalB = b->val;
    term bt[LEN(b)];
    fastTranspose(b,bt);
    //subtopic : set boundary condition
    a[totalA+1].row = a[totalA+1].col = b[totalB+1].row = b[totalB+1].col = 0;
    int rowBegin = 1, row = a[0].row, sum = 0; 
    for(int i = 1; i <= totalA;){
        int col = bt[1].row;
        for(int j=1; j <= totalB+1;){
            if(a[i].row != row){
            }
            else if(bt[j].row != col){

            }
            else switch(){}
        }
    }
}
int main()
{
    int arra[] = {5,0,0,0,1,1,2,3,3,3,4,4,7,0,1,5,3,4,1,2,4,6,4,6,11,1,2,1,1,2,-1,4,1,2,1,2}; 
    int arrb[] = {7,0,0,2,2,2,5,5,6,4,1,3,0,1,2,1,3,2,8,1,1,2,-1,1,1,2,1};
    term a[LEN(arra)/3+1];
    term b[LEN(arrb)/3+1];
    ArraytoTerm(a,arra,LEN(arra)/3);
    ArraytoTerm(b,arrb,LEN(arrb)/3);
}