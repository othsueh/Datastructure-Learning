#include <stdio.h>
#define MAX_QUEUE_SIZE 6
typedef struct{
    int key;
}element;
element cirqueue[6];
int rear =0, front =0;
short isEmpty()
{
    return rear == front;
} 
short isFull()
{
    return (rear+1)%MAX_QUEUE_SIZE == front;
}
element deleteq(int *front, int rear)
{
    if(isEmpty())
        return cirqueue[0];
    *front = (*front+1)%MAX_QUEUE_SIZE;
    return cirqueue[*front];
}
void addq(int *rear,element item)
{
    if(isFull())
        return;
    *rear = (*rear+1)%MAX_QUEUE_SIZE;
    cirqueue[*rear] = item;
}
int main()
{
    element a,b,c,d;
    a.key = 'a';
    b.key = 'b';
    c.key = 'c';
    d.key = 'd';
    addq(&rear, a);
    addq(&rear, d);
    printf("%c\n", deleteq(&front, rear).key);
    addq(&rear, b);
    printf("%c\n", deleteq(&front, rear).key);
    addq(&rear, a);
    addq(&rear, d);
    printf("%c\n", deleteq(&front, rear).key);
    printf("%c\n", deleteq(&front, rear).key);
    addq(&rear, c);
    printf("front : %d, rear : %d\n", front, rear);

}