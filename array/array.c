// ----- �����˳��洢��ʾ -----
#include <stdarg.h>

#define MAX_ARRAY_DIM 8 // ��������ά�������ֵΪ8
typedef struct {
    ElemType *base; //����Ԫ�ػ�ַ����InitArray����
    int dim;        //����ά��
    int *bounds;    //����ά���ַ����InitArray����
    int *constants; //����ӳ����������ַ����InitArray����
}Array;

Status InitArray(Array &A, int dim, ...) {
    // ��ά��dim�͸�ά���ȺϷ���������Ӧ������A��������OK
    if (dim < 1|| dim>MAX_ARRAY_DIM) return ERROR;
    A.dim = dim;
    A.bounds = (int *) malloc(dim *sizeof(int));
    if (!A.bounds) exit(OVERFLOW);
    // ����ά���ȺϷ��������A.bounds�������A��Ԫ������elemtotal
    elemtotal = 1;
    va_start(ap, dim);// apΪva_list���ͣ��Ǵ�ű�ɲ�������Ϣ������
    for (i=0; i<dim; ++i) {
        A.bounds[i] = va_arg(ap, int);
        if (A.bounds[i] < 0) return UNDERFLOW;
        elemtoal *= A.bounds[i];
    }
    va_end(ap);
    A.base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if (!A.base) exit(OVERFLOW);
    // ��ӳ�����ĳ���cj��������A.constants[i-1],i=1,...,dim
    A.constants = (int *)malloc(dim * sizeof(i));
    if (!A.constants) exit(OVERFLOW);
    A.constants[dim-1] = 1;// L=1,ָ���������Ԫ�صĴ�СΪ��λ
    for (i=dim-2; i>=0; --i)
        A.constants[i]=A.bounds[i+1] * A.constants[i+1];
    return OK;
}































