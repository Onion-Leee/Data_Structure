#pragma once
#include"common.h"
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;
#define SEQLIST_DEFAULT_SIZE 8
// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);
void SeqListInit(SeqList* ps)
{
		assert(ps != NULL);
		ps->a= (int*)malloc(sizeof(int) * SEQLIST_DEFAULT_SIZE);
		assert(ps->a != NULL);
		memset(ps->a, 0, sizeof(int) * SEQLIST_DEFAULT_SIZE);
		ps->capacity = SEQLIST_DEFAULT_SIZE;
		ps->size = 0;
}
void SeqListDestory(SeqList* ps);
void SeqListDestory(SeqList* ps)
{
	assert(ps != NULL);
	if (ps->a)
		free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPrint(SeqList* ps);
void SeqListPrint(SeqList* ps)
{
	assert(ps != NULL);
	for (size_t i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
bool IsFull(SeqList* ps)
{
	assert(ps != NULL);
	return ps->size >= ps->capacity;
}
bool IsEmpty(SeqList* ps)
{
	assert(ps != NULL);
	return ps->size == 0;
}
static bool _Inc(SeqList* ps)
{
	int* new_base = (int*)realloc(ps->a, sizeof(int) * ps->capacity * 2);
	if (new_base == NULL)
	{
		return false;
	}
	ps->a = new_base;
	ps->capacity *= 2;
	return true;
}
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("˳���ռ����������ܲ�������%d\n", x);
		return;
	}
	ps->a[ps->size++] = x;
}
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("˳���ռ����������ܲ�������%d\n", x);
		return;
	}
	for (size_t pos = ps->size; pos > 0; --pos)
	{
		ps->a[pos] = ps->a[pos - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps);
void SeqListPopFront(SeqList* ps)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("˳���Ϊ�գ�����β��ɾ��!\n");
		return;
	}
	for (size_t i = 0; i < ps->size; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps);
void SeqListPopBack(SeqList* ps)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("˳���Ϊ�գ�����β��ɾ��!\n");
		return;
	}
	ps->size--;
}

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("˳���Ϊ�գ�����ʧ��!\n");
		return;
	}
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
	return -1;
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps != NULL);
	if (pos<0 || pos>ps->size)
	{
		printf("Ҫ�������ݵ�λ�÷Ƿ�,�޷�����!\n");
		return;
	}
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("˳������������ɲ�������Դ!\n");
	}
	for (size_t i = ps->size; i > pos; --i)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("˳����ѿգ����ɰ�����ɾ��!\n");
		return;
	}
	if (pos < 0 || pos >= ps->size)
	{
		printf("Ҫɾ�����ݵ�λ�÷Ƿ������ܰ�λ��ɾ������!\n");
		return;
	}
	for (size_t i = pos; i < ps->size; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}