#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

//����һ���յ����Ա�L
Status InitList_Sq(SqList *L);

//��ʼ����:���Ա��Ѵ��ڣ��������:�������Ա�L
Status DestroyList_Sq(SqList *L);

//��ʼ����:���Ա��Ѵ��ڣ��������:�����Ա�L��Ϊ�ձ�
Status ClearList_Sq(SqList *L);

//��ʼ����:���Ա��Ѵ��ڣ��������:��LΪ�ձ��򷵻�TRUE���򷵻�ERROR
Status ListEmpty_Sq(SqList L);

//��ʼ����:���Ա��Ѵ��ڣ��������:����L��Ԫ�صĸ���
Status ListLength_Sq(SqList L);

//��ʼ����:���Ա��Ѵ���,1<=i<=ListLength_Sq(L)���������:��e����L�е�i��Ԫ�ص�ֵ
Status GetElem_Sq(SqList L, int i, ElemType *e);

//��ʼ����:���Ա��Ѵ���,compare()������Ԫ���ж�������
//�������:����L�е�1����e����compare()��ϵ������Ԫ�ص�λ�������������������򷵻�ֵΪ0��
Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));

//��ʼ���������Ա�L�Ѵ���
//�������:��cur_e��L��Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType * pre_e);

//��ʼ���������Ա�L�Ѵ���
//�������:��cur_e��L�����ݣ��Ҳ������һ��������next_e�������ĺ�̡��������ʧ�ܣ�next_e�޶���
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e);

//��ʼ����:���Ա����Ѵ��ڣ�1<=i<=ListLength_Sq(L)+1
//�������:��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
Status ListInsert_Sq(SqList *L, ElemType i, ElemType e);

//��ʼ����:���Ա����Ѵ��ڣ�1<=i<=ListLength_Sq(L)+1
//�������:ɾ��L�е�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
Status ListDelete_Sq(SqList *L, ElemType i, ElemType *e);

//��ʼ����:���Ա� L�Ѵ���
//�������:���ζ�L��ÿ������Ԫ�ص���visit()������һ��visit()ʧ�ܣ������ʧ��
Status ListTraverse_Sq(SqList L, void (*visit) (void const *));

//�����ַe��ָ���ڴ��ֵ
void visit_print(void const *e);

//��������Lb�ж�����La�е����ݲ��뵽La��ȥ
void Union_Sq(SqList *La, SqList Lb);

//�Ƚ�a��b�Ĵ�С��������򷵻�1�����򷵻�0
Status compare_Elem(ElemType a, ElemType b);

//��ʼ��������֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
//�������:�鲢La��Lb�õ��µ����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
void MergeList_Sq(SqList *La, SqList Lb,SqList *Lc);

#endif // SQLIST_H_INCLUDED
