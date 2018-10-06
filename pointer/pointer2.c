#include <stdio.h>

// 数组存储在一块连续的内存空间中
// 数组名就是这块连续内存空间的首地址
int main()
{
    double score[] = {98, 87, 65, 43, 76};
    printf("数组的首地址: %p\t数组首元素的地址: %p\n", score, &score[0]);
    double * ptr_score;
    ptr_score = score;

    int i;
    for (i =0; i<5; i++) 
    {
        // printf("%.2lf\n", ptr_score[i]);
        printf("%.2lf\n", *(ptr_score+i));
    }
}
