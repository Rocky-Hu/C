#include <stdio.h>

typedef struct _TEST_T {
        int i;
        char c[10];
}TEST_T;

int main()
{
    TEST_T gst1  = {1, "12345"};//���Գ�ʼ��������iΪ1��sΪһ���ַ���.
    TEST_T gst2  = {1};//��ʼ����������ʵ�ʸ���ʱ��ֻ��ʼ��ǰ��ĳ�Ա��
    TEST_T gst3  = {.c="12345"};//��ѡ��ĳ�ʼ����Ա��

    return 0;
}
