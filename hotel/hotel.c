// 对应hotel.h的实现文件

#include <stdio.h>
// 包含自定义文件时，使用双引号
#include "hotel.h"

char hotelNames[4][50] = {
    "贝罗酒店", "香榭丽舍广场酒店", "阿斯图里亚斯特拉奥佩拉酒店","斯克里布索菲特酒店"
};

int Menu(void)
{
    int choice;// 用户的选择
    int result;// 用户输入后的结果判断 0 表示非法，1表示真
    int i;
    printf("请选择入住的酒店：\n");
    for (i=0;i<4;i++)
    {
        printf("%d、%s\n", i+1, hotelNames[i]);
    }
    printf("5、退出程序\n");
    printf("请输入你的选择：");
    // 当用户输入的值不合法时，重新输入
    while ((result = scanf("%d", &choice)) != 1 || choice < 1 || choice > 5)
    {
        if (result != 1) // 如果用户输入的不是数字类型
        {
            scanf("%*s");// 用户输入非整数的输入。*表示输入项在读入后不赋值
            fflush(stdin);// 清空缓冲区
        }
        printf("必须输入1-5之间的整数：");
        scanf("%d", &choice);
    }
    // 1. 用户的选择不能是非数字
    // 2. 用户必须输入1-5之间
    return choice;
}

int GetNights(void)
{
    int nights;// 用户入住的天数
    printf("先生/女士，请输入要入住的天数：");
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s");//取消赋值
        printf("请输入正确的天数，必须是整数！\n");
        printf("先生/女士，请输入要入住的天数：");
    }
    return nights;
}

void ShowPrice(int nights, double price)
{
    // 总价格=累加前一天的95%
    double total = 0;
    int i;
    for (i=0; i<nights; i++)
    {
        total += price;
        price = price * DISCOUNT;
    }
    printf("入住%d天，共花费：￥%.2lf\n", nights, total);
}