#pragma once
#include "common.h"
typedef struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode* link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;

void LinkQueueInit(LinkQueue* pq);
void LinkQueueEnQue(LinkQueue* pq, ElemType x);
void LinkQueueDeQue(LinkQueue* pq);
void LinkQueuePrint(LinkQueue* pq);

void LinkQueueInit(LinkQueue* pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}

void LinkQueueEnQue(LinkQueue* pq, ElemType x)
{
	assert(pq != NULL);
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;

	if (pq->front == NULL)
		pq->front = pq->rear = node;
	else
	{
		pq->rear->link = node;
		pq->rear = node;
	}
}
void LinkQueueDeQue(LinkQueue* pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode* p = pq->front;
		pq->front = p->link;
		free(p);
	}
}
void LinkQueuePrint(LinkQueue* pq)
{
	assert(pq != NULL);
	LinkQueueNode* p = pq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}