#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int * nums;
    nums = (int *)malloc(sizeof(int) * 5);//为前面的指针动态分配了20个字节的空间
    // 等价于: int nums[5]
    // 为指针动态分配空间后，指针就变成了数组

    for (i=0;i<5;i++)
    {
        printf("请输入第%d个元素：", i+1);
        scanf("%d", nums + 1);
    }
    printf("数组元素为：\n");
    for (i=0; i<5; i++) 
    {
        printf("%d\t", *(nums + i));
    }

    free(nums);// 释放动态分配的内存
    nums = NULL;
}