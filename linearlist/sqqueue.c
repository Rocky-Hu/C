#include "declaration.h"

#define MAXQSIZE 100  //�����г���
typedef struct {
    QElemType *base; //��ʼ���Ķ�̬����洢�ռ�
    int front;       //ͷָ��,�����в��գ�ָ�����ͷԪ��
    int rear;        //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQueue;

Status InitQueue(SqQueue &Q) {
    // ����һ���ն���Q
    Q.base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q.base) exit(OVERFLOW);// �洢����ʧ��
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLength(SqQueue Q) {
    //����Q��Ԫ�ظ����������еĳ���
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, QElementType e) {
    // ����Ԫ��eΪQ���µĶ�βԪ��
    if ((Q.rear+1) % MAXQSIZE == Q.front) return ERROR; // ������
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e) {
    // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK
    // ���򷵻�ERROR
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}














