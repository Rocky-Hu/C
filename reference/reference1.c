#include <stdio.h>

void change(int);

void change(int num)
{
    num++;
}

int main()
{
    int num = 9;
    change(num);
    printf("%d\n", num);
    return 0;
}