#pragma once
#include"common.h"
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;
#define SEQLIST_DEFAULT_SIZE 8
// 对数据的管理:增删查改 
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
		printf("顺序表空间已满，不能插入数据%d\n", x);
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
		printf("顺序表空间已满，不能插入数据%d\n", x);
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
		printf("顺序表为空，不能尾部删除!\n");
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
		printf("顺序表为空，不能尾部删除!\n");
		return;
	}
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("顺序表为空，查找失败!\n");
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
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps != NULL);
	if (pos<0 || pos>ps->size)
	{
		printf("要插入数据的位置非法,无法插入!\n");
		return;
	}
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("顺序表已满，不可插入数据源!\n");
	}
	for (size_t i = ps->size; i > pos; --i)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("顺序表已空，不可按坐标删除!\n");
		return;
	}
	if (pos < 0 || pos >= ps->size)
	{
		printf("要删除数据的位置非法，不能按位置删除数据!\n");
		return;
	}
	for (size_t i = pos; i < ps->size; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}