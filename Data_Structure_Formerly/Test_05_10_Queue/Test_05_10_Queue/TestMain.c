#include "LinkQueue.h"

////////////////////////////////////////
//链式队列
void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEnQue(&Q, 1);
	LinkQueueEnQue(&Q, 2);
	LinkQueueEnQue(&Q, 3);
	LinkQueueEnQue(&Q, 4);

	LinkQueueDeQue(&Q);
	LinkQueuePrint(&Q);

}

/*
////////////////////////////////////////
//循环队列
void main()
{
	CircleQueue Q;
	CircleQueueInit(&Q);

	CircleQueueEnque(&Q, 1);
	CircleQueueEnque(&Q, 2);
	CircleQueueEnque(&Q, 3);
	CircleQueueEnque(&Q, 4);
	CircleQueueEnque(&Q, 5);
	CircleQueueEnque(&Q, 6);
	CircleQueueEnque(&Q, 7);
	CircleQueueEnque(&Q, 8);
	CircleQueuePrint(&Q);
	printf("\n");
	CircleQueueDeque(&Q);
	CircleQueuePrint(&Q);
	printf("\n");
	CircleQueueEnque(&Q, 9);
	CircleQueuePrint(&Q);
	printf("\n");
	printf("对头 = %d\n", CircleQueueFront(&Q));
}
*/

/////////////////////////////////////////////
//队列
/*
#include "Queue.h"

void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q);

	SeqQueueEnque(&Q, 1);
	SeqQueueEnque(&Q, 2);
	SeqQueueEnque(&Q, 3);
	SeqQueueEnque(&Q, 4);
	SeqQueueEnque(&Q, 5);
	SeqQueueEnque(&Q, 6);
	SeqQueueEnque(&Q, 7);
	SeqQueueEnque(&Q, 8);
	SeqQueuePrint(&Q);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	ElemType val = SeqQueueFront(&Q);
	printf("队头元素为%d\n", val);
	SeqQueuePrint(&Q);
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	SeqQueueEnque(&Q, 9);
	SeqQueuePrint(&Q);
}
*/