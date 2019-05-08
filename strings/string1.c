#include <stdio.h>

int main()
{
   // 定义字符串的几种方式
   // 字符串和字符数组的区别：最后一位是否是空字符
   char names1[] = {'j', 'a', 'c', 'k', '\0'};
   char names2[] = "jack";

   printf("%s\n", names1);
   printf("%s\n", names2);

   printf("请输入新的名称：");
   scanf("%s", names2);
   printf("%s\n", names2);
}