#include "declaration.h"

// -----  ���Ķѷ���洢��ʾ -----
typedef struct {
    char *ch; // ���Ƿǿմ����򰴴�������洢��������chΪNULL
    int length;// ������
}HString;

Status StrAssign(HString &T, char *chars) {
    // ����һ����ֵ���ڴ�����chars�Ĵ�T
    if (T.ch) free(T.ch);      // �ͷ�Tԭ�пռ�
    for (i=0, c=chars; c; ++i, ++c);// ��chars�ĳ���i
    if (!i) {
        T.ch = NULL;
        T.length = 0;
    } else {
        if (! (T.ch = (char *) malloc(i* sizeof(char))))
            exit(OVERFLOW);
        T.ch[0..i-1] = chars[0..i-1];
        T.length = i
    }
    return OK;
}//StrAssign

int StrLength(HString S) {
    // ����S��Ԫ�ظ�������Ϊ���ĳ���
    return S.length;
}//StrLength

int StrCompare(HString S, HString T) {
    // ��S>T���򷵻�ֵ>0; ��S=T���򷵻�ֵ=0; ��S<T���򷵻�ֵ<0
    for (i=0; i<S.length && i<T.length; ++i)
        if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
    return S.length - T.length;
}// StrCompare

Status ClearString(HString &S) {
    // ��S��Ϊ�մ�
    if (S.ch) {
        free(S.ch);
        S.ch = NULL;
    }
    S.length = 0;
    return OK;
}// ClearString

Status Concat(HString &T, HString S1, HString S2) {
    // ��T������S1��S2���Ӷ��ɵ��´�
    if (T.ch) free(T.ch); // �ͷžɿռ�
    if( !(T.ch = (char *) malloc(S1.length + S2.length)*sizeof(char)))
        exit(OVERFLOW);
    T.ch[0..S1.length-1] = S1.ch[0..S1.length-1];
    T.length = S1.length + S2.length;
    T.ch[S1.length..T.length-1] = S2.ch[0..S2.length-1];
    return OK;
}//Concat

Status SubString(HString &Sub, HString S, int pos, int len) {
    // ��Sub���ش��ĵ�pos���ַ�������Ϊlen���Ӵ�
    // ���У�1<=pos<=StrLength(S)��0<=len<=StrLength(S)-pos+1
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
        return ERROR;
    if (Sub.ch) free(Sub.ch);// �ͷžɿռ�
    if (!len) {Sub.ch = NULL; Sub.length = 0;}// ���Ӵ�
    else {// �����Ӵ�
        Sub.ch = (char *)malloc(len * sizeof(char));
        Sub.ch[0..len-1] = S.ch[pos-1..pos+len-2];
        Sub.length = len;
    }
    return OK;
}// SubString



















