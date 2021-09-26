#pragma once
#include"common.h"

////////////////////////////////////////////
//顺序栈

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE 3

typedef struct SeqStack
{
	ElemType* base;
	size_t capacity;
	int top;
}SeqStack;

///////////////////////////////////////////
//函数的接口地址
void SeqStackInit(SeqStack* pst);
bool SeqStackIsFull(SeqStack* pst);
bool SeqStackIsEmpty(SeqStack* pst);
void SeqStackPush(SeqStack* pst, ElemType x);
void SeqStackPop(SeqStack* pst);
void SeqStackPrint(SeqStack* pst);
ElemType SeqStackTop(SeqStack* pst);
void SeqStackDestroy(SeqStack* pst);

//////////////////////////////////////////
//函数的实现
void SeqStackInit(SeqStack* pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base != NULL);
	pst->capacity = SEQ_STACK_DEFAULT_SIZE;
	pst->top = 0;
}


bool SeqStackIsFull(SeqStack* pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}

bool SeqStackIsEmpty(SeqStack* pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}

void SeqStackPush(SeqStack* pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst))
	{
		printf("栈空间已满，%d不能入栈。\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack* pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈空间为空，不能进行出栈。\n");
		return;
	}
	pst->top--;
}

void SeqStackPrint(SeqStack* pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0; --i)
	{
		printf("%d\n", pst->base[i]);
	}
	printf("\n");
}

ElemType SeqStackTop(SeqStack* pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能取栈顶元素.\n");
		return;
	}
	return pst->base[pst->top - 1];
}

void SeqStackDestroy(SeqStack* pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}