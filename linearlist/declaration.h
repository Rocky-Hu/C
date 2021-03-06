#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define ElemType int
typedef int Status;
#define LIST_INIT_SIZE 100      //线性表存储空间的初始分配量
#define LISTINCREMENT 10        //线性表存储空间的分配增量
typedef struct
{
    ElemType *elem;         // 存储空间基址
    int length;             //当前长度
    int listsize;           //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;
#endif // DECLARATION_H_INCLUDED


