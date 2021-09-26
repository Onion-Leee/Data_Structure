#include"SeqList.h"


int main()
{
	int x = 0;
	SeqList sq;
	SeqListInit(&sq);
	SeqListPushBack(&sq, x);
	SeqListPushFront(&sq, x);
	SeqListPrint(&sq);
	SeqListDestory(&sq);
	return 0;
}