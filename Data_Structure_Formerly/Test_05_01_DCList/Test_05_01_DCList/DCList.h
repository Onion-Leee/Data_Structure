#pragma once
#include"common.h"

/////////////////////////////////////////////////
//带头的双循环链表
typedef struct DCListNode
{
	ElemType data;
	struct  DCListNode* next;
	struct DCListNode* prev;
}DCListNode;

typedef struct DCList
{
	DCListNode* head;
}DCList;

static DCListNode* _Buydnode(ElemType x);
void DCListInit(DCList* plist);
void DCListDestroy(DCList* plist);
void DCListPushBack(DCList* plist, ElemType x);//1
void DCListPushFront(DCList* plist, ElemType x);//2
void DCListShow(DCList* plist);//3
void DCListPopBack(DCList* plist);//4
void DCListPopFront(DCList* plist);//5
void DCListInsertByVal(DCList* plist, ElemType val);//7
void DCListDeleteByVal(DCList* plist, ElemType val);//9
size_t DCListLength(DCList* plist);//11
void DCListSort(DCList* plist);//13
void DCListReverse(DCList* plist);//14
void DCListClear(DCList* plist);//15



DCListNode* DCListFind(DCList* plist, ElemType key);//10

static DCListNode* _Buydnode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}

void DCListInit(DCList* plist)
{
	plist->head = _Buydnode(0);
}

//1
void DCListPushBack(DCList* plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode* s = _Buydnode(x);
	s->prev = plist->head->prev;
	s->prev->next = s;
	s->next = plist->head;
	plist->head->prev = s;
}

//2
void DCListPushFront(DCList* plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode* s = _Buydnode(x);

	s->next = plist->head->next;
	s->next->prev = s;
	plist->head->next = s;
	s->prev = plist->head;

}


//3
void DCListShow(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

//4
void DCListPopBack(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->prev;
	if (plist->head->next == plist->head)
		//if(p == plist->head)
	{
		printf("循环双链表只有头结点,操作失败.\n");
		return;
	}

	plist->head->prev = p->prev;
	p->prev->next = plist->head;
	free(p);
}

//5
void DCListPopFront(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	if (p == plist->head)
	{
		printf("循环双链表只有头结点,操作失败.\n");
		return;
	}

	plist->head->next = p->next;
	p->next->prev = plist->head;
	free(p);
}

//7
void DCListInsertByVal(DCList* plist, ElemType val)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	while (p != plist->head && p->data < val)
	{
		p = p->next;
	}
	DCListNode* s = _Buydnode(val);
	s->next = p;
	s->prev = p->prev;
	p->prev->next = s;
	p->prev = s;
}

//9
void DCListDeleteByVal(DCList* plist, ElemType val)
{
	assert(plist != NULL);
	DCListNode* p = DCListFind(plist, val);
	if (p == NULL)
		return;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}


//10
DCListNode* DCListFind(DCList* plist, ElemType key)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	if (p == plist->head)
	{
		printf("双循环链表只有头结点，查找失败.\n");
		return 0;
	}
	while (p != plist->head && p->data != key)
	{
		p = p->next;
	}
	if (p != plist->head)
		return p;
	return NULL;
}


//11
size_t DCListLength(DCList* plist)
{
	assert(plist != NULL);
	size_t len = 0;
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}
	return len;
}

//13
void DCListSort(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	DCListNode* q = p->next;

	//断开链表
	p->next = plist->head;
	plist->head->prev = p;

	while (q != plist->head)
	{
		p = q;
		q = q->next;

		//寻找p插入的位置
		DCListNode* t = plist->head->next;
		while (t != plist->head && t->data < p->data)
			t = t->next;

		p->next = t;
		p->prev = t->prev;
		p->next->prev = p;
		p->prev->next = p;

		p = q;
	}
}

//14  
void DCListReverse(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	DCListNode* q = p->next;
	//断开链表
	p->next = plist->head;
	plist->head->prev = p;
	while (q != plist->head)
	{
		p = q;
		q = q->next;

		p->next = plist->head->next;
		p->prev = plist->head;
		p->next->prev = p;
		p->prev->next = p;  //plist->head->next = p;
	}
}

//15
void DCListClear(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
		p = plist->head->next;
	}
}

void DCListDestroy(DCList* plist)
{
	DCListClear(plist);
	free(plist->head);
	plist->head = NULL;
}