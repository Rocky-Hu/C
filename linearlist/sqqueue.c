#include "declaration.h"

#define MAXQSIZE 100  //最大队列长度
typedef struct {
    QElemType *base; //初始化的动态分配存储空间
    int front;       //头指针,若队列不空，指向队列头元素
    int rear;        //尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

Status InitQueue(SqQueue &Q) {
    // 构造一个空队列Q
    Q.base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) exit(OVERFLOW);// 存储分配失败
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLength(SqQueue Q) {
    //返回Q的元素个数，即队列的长度
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, QElementType e) {
    // 插入元素e为Q的新的队尾元素
    if ((Q.rear+1) % MAXQSIZE == Q.front) return ERROR; // 队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e) {
    // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK
    // 否则返回ERROR
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}














