#include <stdio.h>
#include <stdlib.h>
#include "declaration.h"
#include "sqlist.h"
int main()
{
    SqList La,Lb,Lc;
    Status i,e;
    int j;
    i=InitList_Sq(&La);
    if(i==1) /* 创建空表La成功 */
    {
        printf("La create success\n");
        for(j=1; j<=5; j++) /* 在表La中插入5个元素 */
            ListInsert_Sq(&La,j,j);
    }
    printf("La= "); /* 输出表La的内容 */
    ListTraverse_Sq(La, visit_print);
    InitList_Sq(&Lb); /* 也可不判断是否创建成功 */
    for(j=1; j<=5; j++) /* 在表Lb中插入5个元素 */
        ListInsert_Sq(&Lb,j,2*j);
    printf("Lb= "); /* 输出表Lb的内容 */
    ListTraverse_Sq(Lb,visit_print);
    printf("Lb.length is %d\n",ListLength_Sq(Lb));
    i= LocateElem_Sq(Lb, 2, compare_Elem);
    printf("Lb中与2相等的数在第%d个位置\n",i);
    printf("La表中第%d个位置的数是%d\n", 3, GetElem_Sq(La, 3, &e));
    printf("La表中2前驱是%d\n", PriorElem_Sq(La, 2, &e));
    printf("La表中2的后继是%d\n", NextElem_Sq(La, 2, &e));
    printf("\n\n");

    printf("MergeList function:");
    MergeList_Sq(&La,Lb, &Lc);
    printf("Lc= "); /* 输出新表La的内容 */
    ListTraverse_Sq(Lc,visit_print);
    printf("Union function:");
    Union_Sq(&La,Lb);
    printf("new La= "); /* 输出新表La的内容 */
    ListTraverse_Sq(La,visit_print);
    if(ListDelete_Sq(&La,3, &e) == OK)
    {
        printf("after delete La = ");
        ListTraverse_Sq(La, visit_print);
    }
    return 0;
}
