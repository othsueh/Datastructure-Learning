#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct
{
    int data;
}element;
element stack[MAX_SIZE];
int top = -1;

short isEmpty()
{
    return top < 0;
}
short isFull()
{
    return top >= MAX_SIZE - 1;
}

void push(int *top, element item)
{
    if(isFull())
        return;
    stack[++(*top)] = item;
}
element pop(int *top)
{
    if(isEmpty())
        return stack[0];
    return stack[(*top)--];
}
int main()
{
    element a,b,c;
    a.data = 1;
    b.data = 2;
    c.data = 3;
    push(&top, a);
    push(&top, b);
    push(&top, c);
    int output = 0;
    while(!isEmpty())
    {
        output = pop(&top).data;
        printf("%d\n", output);
    }
}