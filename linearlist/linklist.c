// -----���Ա�ĵ�����洢�ṹ-----
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void CreateList_L(LinkList &L, int n)
{
    // ��λ������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ������Ա�L��
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;// �Ƚ���һ����ͷ�ڵ�ĵ�����
    for (int i=n; i>0; --i) {
        p = (LinkList) malloc(sizeof(LNode));// �����½ڵ�
        scanf(&p -> data);// ����Ԫ��ֵ
        p->next = L->next;L->next=p;// ���뵽��ͷ
    }
}// CreateList_L

Status GetElem_L(LinkList L, int i, ElemType &e)
{
    // LΪ��ͷ�ڵ�ĵ������ͷָ��
    // ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
    p = L->next; j = 1;// ��ʼ����pָ���һ���ڵ㣬jΪ������
    while (p && j<i)   // ˳ʱ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
    {
        p = p->next;
        ++j;
    }
    if (!p || j>i)
        return ERROR;// ��i��Ԫ�ز�����
    e = p->data; // ȡ��i��Ԫ��
    return OK;
}// GetElem_L

Status ListInsert_L(LinkList &L, int i, ElemType E)
{
    // �ڴ�ͷ�ڵ�ĵ������Ա�L�еĵ�i��λ��֮ǰ����Ԫ��e
    p = L; j=0;
    while (p && j< i-1)// Ѱ�ҵ�i-1���ڵ�
    {
        p = p->next;
        ++j;
    }
    if (!p || j>i) return ERROR; // iС��1���ߴ��ڱ���1
    s = ��LinkList) malloc(sizeof(LNode));// �����½ڵ�
    s->data=e;s->next=p->next;// ����L��
    p->next=s;
    return OK;
}// ListInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
    p = L; j=0;
    while (p->next && j<i-1){// Ѱ�ҵ�i���ڵ㣬����pָ����ǰ��
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i-1) return ERROR;// ɾ��λ�ò�����
    q = p->next; p->next=q->next;// ɾ�����ͷŽڵ�
    e=q->data;
    free(q);
    return OK;
}// ListDelete_L









































