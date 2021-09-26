#pragma once
#include"common.h"

////////////////////////////////////////////
//˳��ջ

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE 3

typedef struct SeqStack
{
	ElemType* base;
	size_t capacity;
	int top;
}SeqStack;

///////////////////////////////////////////
//�����Ľӿڵ�ַ
void SeqStackInit(SeqStack* pst);
bool SeqStackIsFull(SeqStack* pst);
bool SeqStackIsEmpty(SeqStack* pst);
void SeqStackPush(SeqStack* pst, ElemType x);
void SeqStackPop(SeqStack* pst);
void SeqStackPrint(SeqStack* pst);
ElemType SeqStackTop(SeqStack* pst);
void SeqStackDestroy(SeqStack* pst);

//////////////////////////////////////////
//������ʵ��
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
		printf("ջ�ռ�������%d������ջ��\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack* pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ռ�Ϊ�գ����ܽ��г�ջ��\n");
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
		printf("ջ�ѿգ�����ȡջ��Ԫ��.\n");
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