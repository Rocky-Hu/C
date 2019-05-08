#include "declaration.h"

// ----- �������С������е���ʽ�洢�ṹ -----
typedef struct QNode {
    QElemType data;
    struct QNOde *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front; // ��ͷָ��
    QueuePtr rear;  // ��βָ��
}LinkQueue;

Status InitQueue(LinkQueue &Q) {
    // ����һ���ն���Q
    Q.front = Q.rear = (QueuePtr) malloc(sizeof(QNode));
    if (!Q.front) exit(OVERFLOW);// �洢����ʧ��
    Q.front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    // ���ٶ���Q
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
    // ����Ԫ��eΪQ���µĶ�βԪ��
    p = (QueuePtr) malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW); // �洢����ʧ��
    p->data = e; p->next = NULL;
    Q.rear->next = p;
    Q.rear=p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
    // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK;
    // ���򷵻�ERROR
    if (Q.front == Q.rear) return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}















