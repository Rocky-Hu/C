// -----线性表的单链表存储结构-----
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void CreateList_L(LinkList &L, int n)
{
    // 逆位序输入n个元素的值，建立带表头节点的单链线性表L。
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;// 先建立一个带头节点的单链表
    for (int i=n; i>0; --i) {
        p = (LinkList) malloc(sizeof(LNode));// 生成新节点
        scanf(&p -> data);// 输入元素值
        p->next = L->next;L->next=p;// 插入到表头
    }
}// CreateList_L

Status GetElem_L(LinkList L, int i, ElemType &e)
{
    // L为带头节点的单链表的头指针
    // 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    p = L->next; j = 1;// 初始化，p指向第一个节点，j为计数器
    while (p && j<i)   // 顺时针向后查找，直到p指向第i个元素或p为空
    {
        p = p->next;
        ++j;
    }
    if (!p || j>i)
        return ERROR;// 第i个元素不存在
    e = p->data; // 取第i个元素
    return OK;
}// GetElem_L

Status ListInsert_L(LinkList &L, int i, ElemType E)
{
    // 在带头节点的单链线性表L中的第i个位置之前插入元素e
    p = L; j=0;
    while (p && j< i-1)// 寻找第i-1个节点
    {
        p = p->next;
        ++j;
    }
    if (!p || j>i) return ERROR; // i小于1或者大于表长加1
    s = （LinkList) malloc(sizeof(LNode));// 生成新节点
    s->data=e;s->next=p->next;// 插入L中
    p->next=s;
    return OK;
}// ListInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
    p = L; j=0;
    while (p->next && j<i-1){// 寻找第i个节点，并令p指向其前驱
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i-1) return ERROR;// 删除位置不合理
    q = p->next; p->next=q->next;// 删除并释放节点
    e=q->data;
    free(q);
    return OK;
}// ListDelete_L









































