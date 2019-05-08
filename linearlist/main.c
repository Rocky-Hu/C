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
    if(i==1) /* �����ձ�La�ɹ� */
    {
        printf("La create success\n");
        for(j=1; j<=5; j++) /* �ڱ�La�в���5��Ԫ�� */
            ListInsert_Sq(&La,j,j);
    }
    printf("La= "); /* �����La������ */
    ListTraverse_Sq(La, visit_print);
    InitList_Sq(&Lb); /* Ҳ�ɲ��ж��Ƿ񴴽��ɹ� */
    for(j=1; j<=5; j++) /* �ڱ�Lb�в���5��Ԫ�� */
        ListInsert_Sq(&Lb,j,2*j);
    printf("Lb= "); /* �����Lb������ */
    ListTraverse_Sq(Lb,visit_print);
    printf("Lb.length is %d\n",ListLength_Sq(Lb));
    i= LocateElem_Sq(Lb, 2, compare_Elem);
    printf("Lb����2��ȵ����ڵ�%d��λ��\n",i);
    printf("La���е�%d��λ�õ�����%d\n", 3, GetElem_Sq(La, 3, &e));
    printf("La����2ǰ����%d\n", PriorElem_Sq(La, 2, &e));
    printf("La����2�ĺ����%d\n", NextElem_Sq(La, 2, &e));
    printf("\n\n");

    printf("MergeList function:");
    MergeList_Sq(&La,Lb, &Lc);
    printf("Lc= "); /* ����±�La������ */
    ListTraverse_Sq(Lc,visit_print);
    printf("Union function:");
    Union_Sq(&La,Lb);
    printf("new La= "); /* ����±�La������ */
    ListTraverse_Sq(La,visit_print);
    if(ListDelete_Sq(&La,3, &e) == OK)
    {
        printf("after delete La = ");
        ListTraverse_Sq(La, visit_print);
    }
    return 0;
}
