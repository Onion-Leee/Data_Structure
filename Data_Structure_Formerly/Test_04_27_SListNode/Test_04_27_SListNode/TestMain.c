#include"slistnode.h"


int main()
{
	SList mylist;
	SListInit(&mylist);
	SListNode* p;
	ElemType item;
	int select = 1;
	size_t pos = 0;
	ElemType val = 0;
	ElemType x = 0;
	ElemType key = 0;
	ElemType res = 0;
	while (select)
	{
		printf("***********SList*************\n");
		printf("*[1] push_back   [2] push_front*\n");
		printf("*[3] show_list   [4] pop_back  *\n");
		printf("*[5] pop_front   [6] insert_pos*\n");
		printf("*[7] insert_val  [8] delete_pos*\n");
		printf("*[9] delete_val  [10] find_val *\n");
		printf("*[11] length     [12] capacity *\n");
		printf("*[13] sort       [14] reverse  *\n");
		printf("*[15] clear      [0]quit_system*\n");
		printf("*[16] remove_all �Լ�ʵ��      *\n");
		printf("********************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�����ֵ,��-1����:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			printf("����ɹ�!\n");
			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("����������pos��ֵ�Լ�Ҫ�����ֵ:>");
			scanf("%d %d", &pos, &x);
			//SListInsertPos(&mylist, pos, x);
			printf("����ɹ�!\n");
			break;
		case 7:
			SListSort(&mylist);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &val);
			SListInsertVal(&mylist, val);
			printf("����ɹ�!\n");
			break;
		case 8:
			printf("������Ҫɾ��������:>");
			scanf("%d", &pos);
			//SListDeleteByPos(&mylist, pos);
			printf("ɾ���ɹ�!\n");
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &val);
			SqListDeleteByVal(&mylist, val);
			break;
		case 10:
			printf("������Ҫ���ҵ���ֵ:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if (p == NULL)
			{
				printf("Ҫ���ҵ�ֵ������!\n");
			}
			else
			{
				printf("Ҫ���ҵ�ֵΪ��%d\n", p->data);
			}
			break;
		case 11:
			val = SListLength(&mylist);
			printf("˳���ĳ���Ϊ:%d\n", val);
			break;
		case 12:
			//printf("SList Capacity = %d\n", SListCapacity(&mylist));
			break;
		case 13:
			SListSort(&mylist);
			printf("����ɹ�!\n");
			break;
		case 14:
			SListShow(&mylist);
			SListReverse(&mylist);
			SListShow(&mylist);
			break;
		case 15:
			SListClear(&mylist);
			printf("�������ݳɹ�!\n");
			break;
			//default:
			//	break;
		}
	}
	SListDestroy(&mylist);
	printf("�ټ���\n");
	return 0;
}


/*
void Test_List()
{
	List mylist;
	ListInit(&mylist);
	ListCreate_Tail(&mylist);
	ListCreate_Head(&mylist);
	ListShow(mylist);
}
void main()
{
	Test_List();
}
*/