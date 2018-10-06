#include <stdio.h>
// 指针是一个值为内存地址的变量(或数据对象)
int main() 
{
    int num = 9;
    int * ptr_num = &num;
    // %p指针占位符
    printf("num变量的地址是: %p\n", ptr_num);
    printf("*ptr_num对应的值为: %d\n", *ptr_num); 
    *ptr_num = 9999;
    printf("num的值为: %d\n", num);   

    int num1 = 1024;
    int num2 = 2048;
    int * ptr1;
    int * ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("num1的值是%d\tnum1的地址是：%p\n", num1, ptr1);
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);
    // 将变量1的值赋给变量2
    *ptr2 = *ptr1;
    printf("重新赋值后: \n");
    printf("num1的值是%d\tnum1的地址是：%p\n", num1, ptr1);
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);
    // 直接操作指针
    ptr2 = ptr1;
    printf("直接操作地址后: \n");
    printf("num1的值是%d\tnum1的地址是：%p\n", num1, ptr1);
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);

    return 0;
}