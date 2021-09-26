#pragma once
#include "common.h"


typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode* link;  //相当于next
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode* top;
}LinkStack;

////////////////////////////////////////
//函数接口
void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack* pst,ElemType x);
void LinkStackPop(LinkStack* pst);
void LinkStackPrint(LinkStack* pst);
void LinkStackDestroy(LinkStack* pst);
ElemType LinkStackTop(LinkStack* pst);

//函数实现
void LinkStackInit(LinkStack* pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}

void LinkStackPush(LinkStack* pst,ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = pst->top;
	pst->top = node;
}

void LinkStackPop(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* p = pst->top;
	pst->top = p->link;

	free(p);
}

void LinkStackPrint(LinkStack* pst)
{
	assert(pst != NULL);
	LinkStackNode* p = pst->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}

void LinkStackDestroy(LinkStack* pst)
{
	assert(pst != NULL);
	while (pst->top != NULL)
	{
		LinkStackNode* p = pst->top;
		pst->top = p->link;
		free(p);
	}
	printf("清空完毕.\n");
}
ElemType LinkStackTop(LinkStack* pst)
{
	assert(pst != NULL);
	if (pst->top == NULL)
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	return pst->top->data;
}