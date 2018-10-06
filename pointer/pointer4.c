#include <stdio.h>

// 数组逆序
int main() 
{
    int array[] = {15, 20, 25, 30, 35};
    int * ptr_array_start = array;
    int * ptr_array_end = array + 4;

    int temp;
    while (ptr_array_start != ptr_array_end) 
    {
        temp = *ptr_array_start;
        *ptr_array_start = *ptr_array_end;
        *ptr_array_end = temp;
        ptr_array_start++;
        ptr_array_end--;
    }

    int i;
    for (i =0; i<5; i++)
    {
       printf("第%d个元素的值是%d\n", i+i, array[i]);
    }

}