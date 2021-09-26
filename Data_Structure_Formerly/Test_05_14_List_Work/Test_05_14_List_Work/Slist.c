#include"common.h"
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
typedef struct SList
{
	SListNode* head;
}SList;
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
// �������ӡ
void SListPrint(SListNode* plist);
void SListPrint(SListNode* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
// ������β��
void SListPushBack(SList *pplist, SLTDateType x);
void SListPushBack(SList *pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode* s = _Buynode(x);
	//����Ľڵ�Ϊ��һ���ڵ�
	if (pplist->head == NULL)
	{
		pplist->head = s;
		return;
	}
	//O(n)
	SListNode* p = pplist->head;
	//���������β���ڵ�
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
}
// �������ͷ��
void SListPushFront(SList* pplist, SLTDateType x);
void SListPushFront(SList* pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode* s = _Buynode(x);
	s->next = pplist->head;
	pplist->head = s;
}
// �������βɾ
void SListPopBack(SList* pplist);
void SListPopBack(SList* pplist)
{
	assert(pplist != NULL);
	SListNode* p = pplist->head;
	if (pplist->head == NULL)
	{
		printf("������Ϊ�գ����ʧ��!\n");
		return;
	}
	if (p->next == NULL)
	{
		pplist->head = NULL;
		return;
	}
	SListNode* prev = NULL;
	while (p->next != NULL)
	{
		prev = p;
		p = p->next;
	}
	prev->next = NULL;
	free(p);
}
// ������ͷɾ
void SListPopFront(SList* pplist);
void SListPopFront(SList* pplist)
{
	assert(pplist != NULL);
	SListNode* p = pplist->head;
	if (pplist->head == NULL)
	{
		printf("������Ϊ�գ����ʧ��!\n");
		return;
	}
	pplist->head = p->next;
	free(p);
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist != NULL);
	SListNode* p = plist->next;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestory(SList* plist);
void SListDestory(SList* plist)
{
	SListClear(plist);
	plist->head = NULL;

}
