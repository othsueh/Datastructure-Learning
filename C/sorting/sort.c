#include "../lib/base.h"
#include "../lib/algobase.h"
#define EelmenType i32
void insertion_sort(EelmenType list[], i32 length)
{
    EelmenType next;
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
    EelmenType a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2 ,1};
    insertion_sort(a, 10);
}