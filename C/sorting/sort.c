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
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]); // swap(arr[i], arr[j]
            }
            printArray(arr, 10);
        }
        swap(&arr[++i], &arr[high]); // The pivot is in the right place
        int pi = i;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void insertion_sort(Elementype list[], i32 length)
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
int main()
{
    Elementype a[10] = {0};
    randomArray(a, 10);
    printf("Before sort: ");
    printArray(a, 10); 
    quickSort(a, 0, 9);
    printArray(a, 10); 
}