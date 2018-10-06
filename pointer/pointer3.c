#include <stdio.h>

int main()
{
    int array[] = {15, 20, 25, 30, 35};
    int i;
    int *ptr_array = array;
    for (i =0; i<5; i++)
    {
       printf("第%d个元素的值是%d，地址为: %p\n", i+i, *ptr_array, ptr_array);
       // 每次循环都会移动指针的指向，所以要注意重置
       ptr_array++;
    }
}
