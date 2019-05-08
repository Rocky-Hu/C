#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

//构造一个空的线性表L
Status InitList_Sq(SqList *L);

//初始条件:线性表已存在；操作结果:销毁线性表L
Status DestroyList_Sq(SqList *L);

//初始条件:线性表已存在；操作结果:将线性表L置为空表
Status ClearList_Sq(SqList *L);

//初始条件:线性表已存在；操作结果:若L为空表则返回TRUE否则返回ERROR
Status ListEmpty_Sq(SqList L);

//初始条件:线性表已存在；操作结果:返回L中元素的个数
Status ListLength_Sq(SqList L);

//初始条件:线性表已存在,1<=i<=ListLength_Sq(L)；操作结果:用e返回L中第i个元素的值
Status GetElem_Sq(SqList L, int i, ElemType *e);

//初始条件:线性表已存在,compare()是数据元素判定函数；
//操作结果:返回L中第1个与e满足compare()关系的数据元素的位序。若这样的数不存在则返回值为0。
Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));

//初始条件：线性表L已存在
//操作结果:若cur_e是L的元素，且不是第一个，则用pre_e返回它的前驱。否则操作失败，pre_e无定义
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType * pre_e);

//初始条件：线性表L已存在
//操作结果:若cur_e是L的数据，且不是最后一个，则用next_e返回它的后继。否则操作失败，next_e无定义
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e);

//初始条件:线性表你已存在，1<=i<=ListLength_Sq(L)+1
//操作结果:在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert_Sq(SqList *L, ElemType i, ElemType e);

//初始条件:线性表你已存在，1<=i<=ListLength_Sq(L)+1
//操作结果:删除L中第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete_Sq(SqList *L, ElemType i, ElemType *e);

//初始条件:线性表 L已存在
//操作结果:依次对L的每个数据元素调用visit()函数。一旦visit()失败，则操作失败
Status ListTraverse_Sq(SqList L, void (*visit) (void const *));

//输出地址e所指向内存的值
void visit_print(void const *e);

//将存在于Lb中而不在La中的数据插入到La中去
void Union_Sq(SqList *La, SqList Lb);

//比较a，b的大小，若相等则返回1，否则返回0
Status compare_Elem(ElemType a, ElemType b);

//初始条件：已知顺序线性表La和Lb的元素按值非递减排列
//操作结果:归并La和Lb得到新的线性表Lc,Lc的元素也按值非递减排列
void MergeList_Sq(SqList *La, SqList Lb,SqList *Lc);

#endif // SQLIST_H_INCLUDED
