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
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
// 单链表打印
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
// 单链表尾插
void SListPushBack(SList *pplist, SLTDateType x);
void SListPushBack(SList *pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode* s = _Buynode(x);
	//插入的节点为第一个节点
	if (pplist->head == NULL)
	{
		pplist->head = s;
		return;
	}
	//O(n)
	SListNode* p = pplist->head;
	//查找链表的尾部节点
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
}
// 单链表的头插
void SListPushFront(SList* pplist, SLTDateType x);
void SListPushFront(SList* pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode* s = _Buynode(x);
	s->next = pplist->head;
	pplist->head = s;
}
// 单链表的尾删
void SListPopBack(SList* pplist);
void SListPopBack(SList* pplist)
{
	assert(pplist != NULL);
	SListNode* p = pplist->head;
	if (pplist->head == NULL)
	{
		printf("单链表为空，输出失败!\n");
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
// 单链表头删
void SListPopFront(SList* pplist);
void SListPopFront(SList* pplist)
{
	assert(pplist != NULL);
	SListNode* p = pplist->head;
	if (pplist->head == NULL)
	{
		printf("单链表为空，输出失败!\n");
		return;
	}
	pplist->head = p->next;
	free(p);
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist != NULL);
	SListNode* p = plist->next;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SList* plist);
void SListDestory(SList* plist)
{
	SListClear(plist);
	plist->head = NULL;

}
