#include "../lib/base.h"
#include "../lib/algobase.h"
#define Elementype i32
void printArray(Elementype list[], i32 length)
{
    for(i32 i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}
void randomArray(Elementype *list, i32 length)
{
    srand((u32)time(NULL));
    for(i32 i = 0; i < length; i++)
    {
        list[i] = rand() % 100;
    }
}
void swap(Elementype* a, Elementype* b) {
    Elementype t = *a;
    *a = *b;
    *b = t;
}
void quickSort(Elementype arr[], i32 low, i32 high) {
    if (low < high) {
        Elementype pivot = arr[high];
        i32 i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]); // swap(arr[i], arr[j]
            }
            printArray(arr, 10);
        }
        swap(&arr[++i], &arr[high]); // The pivot is in the right place
        i32 pi = i;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void insertionSort(Elementype list[], i32 length)
{
    Elementype next;
    for(i32 i = 1; i < length; i++)
    {
        i32 j = i;
        next = list[i];
        while(j > 0 && next < list[j-1]) // 從後往前找到比next小的元素
        {
            list[j] = list[j-1];
            j--;
        }
        list[j] = next;
    }
}
i32 getMax(Elementype arr[], i32 n)
{
    Elementype max = arr[0];
    for(i32 i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(Elementype arr[], i32 n, i32 exp)
{
    Elementype output[n];
    i32 count[10] = {0};
    for(i32 i = 0; i<n; i++)
        count[arr[i]/exp%10]++;
    for(i32 i = 1; i < 10; i++)
        count[i] += count[i-1];
    for(i32 i = n-1; i >= 0; i--)
        output[--count[arr[i]/exp%10]] = arr[i];
    for(i32 i = 0; i < n; i++) 
        arr[i] = output[i];
}
void radixSort(Elementype arr[], i32 n)
{
    Elementype m = getMax(arr, n);
    for(i32 exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
    return;
}

void downheap(Elementype heap[], i32 i, i32 n)
{
    i32 largest = i;
    i32 l = 2*i+1;
    i32 r = 2*i+2;
    if(l<n && heap[l]>heap[largest])
        largest = l;
    if(r<n && heap[r]>heap[largest])
        largest = r;
    if(largest != i){
        i32 temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        downheap(heap, largest, n);
    }
}
void heapSort(Elementype list[], i32 n)
{
    for(i32 i= n/2-1; i>=0;i--)     
        downheap(list, i, n);
    for(i32 i = n-1; i>0; i--){
        swap(&list[0], &list[i]);
        downheap(list, 0, i);
    }
}
void merge(Elementype list[], i32 l, i32 mid, i32 r)
{
    i32 i, j, k;
    i32 n1 = mid - l + 1; 
    i32 n2 = r - mid;
    Elementype L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = list[l+i];
    for(j = 0; j < n2; j++)
        R[j] = list[mid+1+j];
    i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            list[k++] = L[i++];
        else
            list[k++] = R[j++];
    }
    while(i < n1)
        list[k++] = L[i++];
    while(j < n2)
        list[k++] = R[j++];
}
void mergeSort(Elementype list[], i32 l, i32 r)
{
    if(l < r){
        i32 mid = l + (r-l)/2;
        mergeSort(list, l, mid);
        mergeSort(list, mid+1, r);
        merge(list, l, mid, r);
    }
}
int main()
{
    Elementype a[10] = {0};
    randomArray(a, 10);
    printf("Before sort: ");
    printArray(a, 10); 
    // insertionSort(a, 10);
    // quickSort(a, 0, 9);
    // radixSort(a, 10);
    // heapSort(a, 10);
    mergeSort(a, 0, 9);
    printArray(a, 10); 
}