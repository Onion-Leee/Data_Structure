//#pragma once
#ifndef _SEQLIST_H_
#define _SEQLIST_H_


#include"common.h"
#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表结构
typedef struct SeqList
{
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;

//////////////////////////////////
//声明函数接口
void SeqListInit(SeqList* pst);
bool IsFull(SeqList* pst);
bool IsEmpty(SeqList* pst);
static bool _Inc(SeqList* pst);
void SeqListPushBack(SeqList* pst, ElemType x);//1
void SeqListPushFront(SeqList* pst, ElemType x);//2
void SeqListShow(SeqList* pst);//3
void SeqListDestroy(SeqList* pst);
void SeqListPopBack(SeqList* pst);//4
void SeqListPopFront(SeqList* pst);//5
void SeqListInsertPos(SeqList* pst, size_t pos, ElemType x);//6
void SeqListInsertVal(SeqList* pst, ElemType val);//7
void SeqListDeleteByPos(SeqList* pst, ElemType pos);//8
void SeqListDeleteByVal(SeqList* pst, ElemType val);//9
int SeqListFind(SeqList* pst, ElemType key);//10
int SeqListLength(SeqList* pst);//11
int SeqListCapacity(SeqList* pst);//12
void SeqListSort(SeqList* pst);//13
void SeqListReverse(SeqList* pst);//14
void SeqListClear(SeqList* pst);//15

//////////////////////////////////
//函数接口实现
void SeqListInit(SeqList* pst)
{
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

bool IsFull(SeqList* pst)
{
	assert(pst != NULL);
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	assert(pst != NULL);
	return pst->size == 0;
}
static bool _Inc(SeqList* pst)
{
	ElemType* new_base = (ElemType*)realloc(pst->base, sizeof(ElemType) * pst->capacity * 2);
	if (new_base == NULL)
	{
		return false;
	}
	pst->base = new_base;
	pst->capacity *= 2;
	return true;
}

//1
void SeqListPushBack(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst)&&!_Inc(pst))
	{
		printf("顺序表空间已满，不能插入数据%d\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}
//2
void SeqListPushFront(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst)&&!_Inc(pst))
	{
		printf("顺序表空间已满，不能插入数据%d\n", x);
		return;
	}
	for (size_t pos = pst->size; pos > 0; --pos)
	{
		pst->base[pos] = pst->base[pos - 1];
	}
	pst->base[0] = x;
	pst->size++;
}
//3
void SeqListShow(SeqList* pst)
{
	assert(pst != NULL);
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListDestroy(SeqList* pst)
{
	assert(pst != NULL);
	if (pst->base)
		free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}
//4
void SeqListPopBack(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能尾部删除!\n");
		return;
	}
	pst->size--;
}
//5
void SeqListPopFront(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能尾部删除!\n");
		return;
	}
	for (size_t i = 0; i < pst->size; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
//6
void SeqListInsertPos(SeqList* pst, size_t pos, ElemType x)
{
	assert(pst != NULL);
	if (pos<0 || pos>pst->size)
	{
		printf("要插入数据的位置非法,无法插入!\n");
		return;
	}
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，不可插入数据源!\n");
	}
	for (size_t i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}
//7
void SeqListInsertVal(SeqList* pst, ElemType val)
{
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，不可插入数据!\n");
		return;
	}
	int end = pst->size;
	while (end > 0 && val < pst->base[end - 1])
	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = val;
	pst->size++;
}
//8
void SeqListDeleteByPos(SeqList* pst, ElemType pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不可按坐标删除!\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("要删除数据的位置非法，不能按位置删除数据!\n");
		return;
	}
	for (size_t i = pos; i < pst->size; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

//9
void SeqListDeleteByVal(SeqList* pst, ElemType val)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，无法进行按值删除!\n");
		return;
	}
	int pos = SeqListFind(pst, val);
	if (pos == -1)
	{
		printf("要删除的数据不存在，不能进行删除操作!\n");
		return;
	}
	SeqListDeleteByPos(pst, pos);
	printf("删除成功!\n");
}
//10
int SeqListFind(SeqList* pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，查找失败!\n");
		return;
	}
	for (size_t i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
		{
			return i;
		}
	}
	return -1;
}
//11
int SeqListLength(SeqList* pst)
{
	assert(pst != NULL);
	int i = 0;
	i = pst->size;
	return i;
}
//12
int SeqListCapacity(SeqList* pst)
{
	assert(pst != NULL);
	return pst->capacity;
}
//13 
void SeqListSort(SeqList* pst)
{
	assert(pst != NULL);
	if (pst->size <= 1)
	{
		return;
	}
	for (int i = 0; i < pst->size - 1; ++i)
	{
		for (int j = 0; j < pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}
//14
void SeqListReverse(SeqList* pst)
{
	assert(pst != NULL);
	/*if (pst->size < 2);
	{
		return;
	}*/
	int left = 0;
	int right = pst->size - 1;
	while(left<right)
	{
		Swap(&pst->base[left], &pst->base[right]);
		left++;
		right--;
	}
}
//15
void SeqListClear(SeqList* pst)
{
	assert(pst != NULL);
	pst->size = 0;
}
#endif // !_SEQLIST_H_