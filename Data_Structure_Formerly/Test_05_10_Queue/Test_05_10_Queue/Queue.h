#pragma once
#include "common.h"

/////////////////////////////////
//顺序队列

#define SEQ_QUEUE_DEFAULT_SIZE 8
typedef struct SeqQueue
{
	ElemType* base;
	int capacity;
	int front;
	int rear;
}SeqQueue;
///////////////////////////////////////////////
//函数接口地址
void SeqQueueInit(SeqQueue* psq);
bool SeqQueueIsFull(SeqQueue* psq);
bool SeqQueueIsEmpty(SeqQueue* psq);
void SeqQueueEnque(SeqQueue* psq, ElemType x);
void SeqQueueDeque(SeqQueue* psq);
ElemType SeqQueueFront(SeqQueue* psq);
void SeqQueuePrint(SeqQueue* psq);

///////////////////////////////////////////////
//函数的实现
void SeqQueueInit(SeqQueue* psq)
{
	assert(psq != NULL);
	psq->base = (ElemType*)malloc(sizeof(ElemType)*SEQ_QUEUE_DEFAULT_SIZE);
	assert(psq->base != NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE;
	psq->front = psq->rear = 0;
}

bool SeqQueueIsFull(SeqQueue* psq)
{
	assert(psq != NULL);
	return psq->rear >= psq->capacity;
}

bool SeqQueueIsEmpty(SeqQueue* psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

void SeqQueueEnque(SeqQueue* psq, ElemType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		printf("队列已满，%d不能入队.\n");
		return;
	}
	psq->base[psq->rear++] = x;
}

void SeqQueueDeque(SeqQueue* psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("队列已空，不能出队.\n");
		return;
	}
	psq->front++;
}

ElemType SeqQueueFront(SeqQueue* psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("队列为空，不能取队头元素.\n");
		return;
	}
	return psq->base[psq->front];
}

void SeqQueuePrint(SeqQueue* psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i < psq->rear; ++i)
		printf("%d ", psq->base[i]);
	printf("\n");
}