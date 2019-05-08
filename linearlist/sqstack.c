#include "declaration.h"

// ----- ջ��˳��洢��ʾ -----
#define STACK_INIT_SIZE 100; //�洢�ռ��ʼ������
#define STACKINCREMENT 10;   //�洢�ռ��������

typedef struct
{
    SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top;  // ջ��ָ��
    int stacksize;   // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

Status InitStack(SqStack &S)
{
    // ����һ����ջS
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);// �洢����ʧ��
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}// InitStack


Status GetTop(SqStack S, SElemType &e)
{
    // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if (S.top == S.base) return ERROR;
    e = *(S.top -1);
    return OK;
}// GetTop

Status Push(SqStack &S, SElemType e)
{
    // ����Ԫ��eΪ�µ�ջ��Ԫ��
    if (S.top - S.base >= S.stacksize){// ջ����׷�Ӵ洢�ռ�
        S.base = (SElemType *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) exit(OVERFLOW);// �洢����ʧ��
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}// Push

Status Pop(SqStack &S, SElemType &e)
{
    // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
    if (S.top == S.base) return ERROR;
    e = * --S.top;
    return OK;
}// Pop

































