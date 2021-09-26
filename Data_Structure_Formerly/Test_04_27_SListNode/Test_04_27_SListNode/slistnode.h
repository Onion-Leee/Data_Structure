#pragma once
#include"common.h"


typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode* head;
}SList;

///////////////////////////////////////////
///////////////////////////////////////////
//单链表的函数接口声明
void SListInit(SList* plist);
static SListNode* _Buynode(ElemType x);
void SListPushBack(SList* plist, ElemType item);//1
void SListPushFront(SList* plist, ElemType item);//2
void SListShow(SList* plist);//3
void SListPopBack(SList* plist);//4
void SListPopFront(SList* plist);//5
void SListInsertVal(SList* plist, ElemType val);//7
void SqListDeleteByVal(SList* plist, ElemType val);//9
SListNode* SListFind(SList* plist, ElemType key);//10
size_t SListLength(SList* plist);//11

void SListSort(SList* plist);//13
void SListReverse(SList* plist);//14
void SListClear(SList* plist);//15
void SListDestroy(SList* plist);

///////////////////////////////////////////
///////////////////////////////////////////
//单链表的函数接口实现
void SListInit(SList* plist)
{
	plist->head = NULL;
}
static SListNode* _Buynode(ElemType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
//1
void SListPushBack(SList* plist, ElemType item)
{
	assert(plist != NULL);
	SListNode* s = _Buynode(item);
	//插入的节点为第一个节点
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}
	//O(n)
	SListNode* p = plist->head;
	//查找链表的尾部节点
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
}
//2
void SListPushFront(SList* plist, ElemType item)
{
	assert(plist != NULL);
	SListNode* s = _Buynode(item);
	s->next = plist->head;
	plist->head = s;
}
//3
void SListShow(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
//4
void SListPopBack(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	if (plist->head == NULL)
	{
		printf("单链表为空，输出失败!\n");
		return;
	}
	if (p->next == NULL)
	{
		plist->head = NULL;
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
//5
void SListPopFront(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	if (plist->head == NULL)
	{
		printf("单链表为空，输出失败!\n");
		return;
	}
	plist->head = p->next;
	free(p);
}
//6

//7
void SListInsertVal(SList* plist, ElemType val)
{
	assert(plist != NULL);
	SListNode* prev = NULL;
	SListNode* p = plist->head;
	SListNode* s = _Buynode(val);
	while (p != NULL && val > p->data)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)
	{
		s->next = p;
		plist->head = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}
//10
SListNode* SListFind(SList* plist, ElemType key)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}
//9
void SqListDeleteByVal(SList* plist, ElemType val)
{
	assert(plist != NULL);
	SListNode* prev = NULL;
	SListNode* p = SListFind(plist, val);
	if (p == NULL)
	{
		printf("要删除的节点不存在.\n");
		return;
	}

	if (p == plist->head)
		plist->head = p->next;
	else
	{
		prev = plist->head;
		while (prev->next != p)
			prev = prev->next;

		//删除
		prev->next = p->next;
	}
	free(p);
}

//11
size_t SListLength(SList* plist)
{
	assert(plist != NULL);
	size_t len = 0;
	SListNode* p = plist->head;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}




//13
void SListSort(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head->next;
	SListNode* q, * t, * prev = NULL;

	plist->head->next = NULL;  //断开链表

	t = plist->head;
	while (p != NULL)
	{
		q = p->next;
		while (t != NULL && p->data > t->data)
		{
			prev = t;
			t = t->next;
		}
		if (prev == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		else //if(prev->next!=NULL)
		{
			p->next = prev->next;
			prev->next = p;
		}
		//else if (prev->next == NULL)
		//{
		//	prev->next = p;
		//	p->next = NULL;
		//}

		p = q;
		t = plist->head;
	}
}

//14
void SListReverse(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head->next;
	SListNode* q;
	if (p->next == NULL)
		return;

	//断开第一个节点
	plist->head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}


//15
void SListClear(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}
void SListDestroy(SList* plist)
{
	SListClear(plist);
	plist->head = NULL;
}



/*
////////////////////////////////////////////////////////////////
//
//定义链表节点
typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;

typedef ListNode* List;
//单链表带头结点
void ListInit(List* plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;
}

//尾插法创建单链表
void ListCreate_Tail(List* plist)
{
	assert(plist != NULL);

	ListNode* p = *plist;

	for (int i = 0; i <= 10; ++i)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

//头插法创建单链表
void LisCreate_Head(List* plist)
{
	assert(plist != NULL);
	for (int i = 0; i < 10; i++)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = (*plist)->next;
		(*plist)->next = s;
	}
}
void ListShow(List plist)
{
	ListNode* p = plist->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
*/

/*
//单链表不带头结点
typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;

typedef ListNode* List;
void ListInit(List* plist)
{
	*plist = NULL;
}

//尾插法创建单链表
void ListCreate_Tail(List* plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->data = NULL;

	ListNode* p = *plist;
	for (int i = 2; i <= 10; ++i)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//连接节点
		p->next = s;
		p = s;
	}
}
//头插法创建单链表
void ListCreate_Head(List* plist)
{
	(*plist) = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	for (int i = 1; i <= 10; ++i)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		//连接节点
		s->next = (*plist);
		(*plist) = s;
	}
}

void ListShow(List plist)
{
	ListNode* p = plist;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
*/








