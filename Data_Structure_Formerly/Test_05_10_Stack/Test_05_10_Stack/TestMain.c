#include "LinkStack.h"

//��ջ
void main()
{
	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPrint(&st);
	ElemType val = LinkStackTop(&st);
	printf("ջ��Ϊ%d\n", val);
	LinkStackPop(&st);
	LinkStackPrint(&st);
	LinkStackDestroy(&st);
	LinkStackPrint(&st);
}






//˳��ջ
/*
void main()
{
	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPrint(&st);
	SeqStackPop(&st);
	SeqStackPush(&st, 10);
	SeqStackPrint(&st);
	SeqStackPop(&st);
	SeqStackPush(&st, 11);
	ElemType val = SeqStackTop(&st);
	printf("ջ��Ԫ����%d\n", val);
	SeqStackDestroy(&st);
}
*/