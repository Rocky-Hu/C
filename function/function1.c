#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 函数原型
void calcCircle();

void calcCircle()
{
    double radius, s;
    printf("请输入圆的半径：");
    scanf("%lf", &radius);
    s = 3.14 * pow(radius, 2);
    printf("半径为%.2lf的圆的面积为：%.2lf\n", radius, s);
}

int main()
{
    calcCircle();
}