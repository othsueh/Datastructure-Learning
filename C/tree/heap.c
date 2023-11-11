#include "../lib/base.h"
#include "../lib/algobase.h"
#define MAXSIZE 100

i32 heap[MAXSIZE] = {10,3,5,12,21,6,8,54,13,7,20,0};
Status heap_empty(i32 n)
{
    if(n==0)
        return TRUE;
    else 
        return FALSE;
}
Status heap_full(i32 n)
{
    if(n==MAXSIZE)
        return TRUE;
    else return FALSE;
}
void downheap(u8 i, i32 n)
{
    u8 largest = i;
    u8 l = 2*i;
    u8 r = 2*i+1;
    if(l<=n && heap[l]>heap[largest])
        largest = l;
    if(r<=n && heap[r]>heap[largest])
        largest = r;
    if(largest != i){
        i32 temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        downheap(largest, n);
    }
}
void init()
{
    for(i8 i= heap[0]/2; i>0;i--)     
        downheap(i, heap[0]);
}
Status push(i32 new, i32 *n)
{
    i32 i;
    i = ++(*n);
    if(heap_full(i))
        return ERROR;
    while(i != 1 && new > heap[i/2]){
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = new;
    return TRUE;
}
i32 pop()
{
    if(heap_empty(heap[0]))
        return ERROR;
    i32 item = heap[1];
    i32 temp = heap[heap[0]--];
    i32 parent = 1, child = 2;
    while(child <= heap[0]){
        if(child < heap[0] && heap[child] < heap[child+1])
            child++;
        if(temp >= heap[child])
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}
void heap_traverse(i32 n)
{
    if(heap_empty(n))
        printf("The heap is now empty!");
    else
        for(i8 i=1; i<=heap[0]; i++)
            printf("%d ", heap[i]);
    printf("\n");
    return;
}

int main()
{
    init();
    push(15, &heap[0]);
    push(152, &heap[0]);
    heap_traverse(heap[0]);
    printf("%d\n", pop());
    printf("%d\n", pop());
    heap_traverse(heap[0]);
    return 0;
}