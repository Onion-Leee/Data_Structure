#pragma once
#include "common.h"

#define CIRCLE_QUEUE_DEFAULT_SIZE 8
#define CIRCLE_QUEUE_INC_SIZE 4

typedef struct CircleQueue
{
	ElemType* base;
	int capacity;
	int front;
	int rear;
}CircleQueue;
///////////////////////////////////////////////
//�����ӿڵ�ַ
void CircleQueueInit(CircleQueue* psq);
bool CircleQueueIsFull(CircleQueue* psq);
bool CircleQueueIsEmpty(CircleQueue* psq);
void CircleQueueEnque(CircleQueue* psq, ElemType x);
void CiecleQueueDeque(CircleQueue* psq);
ElemType CircleQueueFront(CircleQueue* psq);
void CircleQueuePrint(CircleQueue* psq);

///////////////////////////////////////////////
//������ʵ��
void CircleQueueInit(CircleQueue* psq)
{
	assert(psq != NULL);
	psq->base = (ElemType*)malloc(sizeof(ElemType) * CIRCLE_QUEUE_DEFAULT_SIZE+1);
	assert(psq != NULL);
	psq->capacity = CIRCLE_QUEUE_DEFAULT_SIZE + 1;
	psq->front = psq->rear = 0;
}

bool CircleQueueIsFull(CircleQueue* psq)
{
	assert(psq != NULL);
	return ((psq->rear + 1) % psq->capacity) == psq->front;
}

bool CircleQueueIsEmpty(CircleQueue* psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}
void CircleQueueEnque(CircleQueue* psq, ElemType x)
{
	assert(psq != NULL);
	if (CircleQueueIsFull(psq))
	{
		printf("ѭ����������, %d �������.\n", x);
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear = (psq->rear + 1) % psq->capacity;
}
void CircleQueueDeque(CircleQueue* psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿգ����ܳ���.\n");
		return;
	}
	psq->front = (psq->front + 1) % psq->capacity;
}
ElemType CircleQueueFront(CircleQueue* psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿգ�����ȡ��ͷԪ��.\n");
		return;
	}

	return psq->base[psq->front];
}
void CircleQueuePrint(CircleQueue* psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i != psq->rear;)
	{
		printf("%d ", psq->base[i]);
		i = (i + 1) % psq->capacity;
	}
}