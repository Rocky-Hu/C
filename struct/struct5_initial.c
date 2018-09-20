#include <stdio.h>

typedef struct _TEST_T {
        int i;
        char c[10];
}TEST_T;

int main()
{
    TEST_T gst1  = {1, "12345"};//可以初始化，设置i为1，s为一个字符串.
    TEST_T gst2  = {1};//初始化个数少于实际个数时，只初始化前面的成员。
    TEST_T gst3  = {.c="12345"};//有选择的初始化成员。

    return 0;
}
