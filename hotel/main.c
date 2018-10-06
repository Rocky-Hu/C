#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"

extern char hotelNames[4][50];

int main()
{
    int choice = 0;
    int nights;//用户入住的天数
    double totalCost;// 用户支付的总费用
    double currCost;// 用户当前入住的酒店的房费单价
    // 用户输入入住的酒店和天数，程序计算出对应的金额
    // 1.显示菜单 - 封装成函数
    // 2.计算过程
    while ((choice = Menu()) != 5)
    {
        switch(choice)
        {
            case 1: 
                currCost = HOTEL1;
                break;
            case 2: 
                currCost = HOTEL2;
                break;
            case 3: 
                currCost = HOTEL3;
                break;
            case 4: 
                currCost = HOTEL4;
                break;
            default:
                currCost = 0;
        }
        // 得到用户入住的天数
        nights = GetNights();
        // 计算总费用
        ShowPrice(nights, currCost);
    }
    printf("感谢使用本系统，再会！\n");
    return 0;
}
