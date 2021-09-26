#include"seqlist.h"

int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElemType item;
	int select = 1;
	size_t pos = 0;
	ElemType val = 0;
	ElemType x = 0;
	ElemType key = 0;
	ElemType res = 0;
	while (select)      
	{
		printf("***********SeqList*************\n");
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
			//printf("������Ҫ�����ֵ[��-1����]:>");
			//while (scanf("%d", &item), item != -1)
			//{
			//	SeqListPushBack(&mylist,item);
			//}
			printf("������Ҫ�����ֵ,��-1����:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			printf("����ɹ�!\n");
			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			/*printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListPushFront(&mylist, item);*/
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("����������pos��ֵ�Լ�Ҫ�����ֵ:>");
			scanf("%d %d", &pos, &x);
			SeqListInsertPos(&mylist, pos, x);
			printf("����ɹ�!\n");
			break;
		case 7:
			SeqListSort(&mylist);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &val);
			SeqListInsertVal(&mylist, val);
			printf("����ɹ�!\n");
			break;
		case 8:
			printf("������Ҫɾ��������:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			printf("ɾ���ɹ�!\n");
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &val);
			SeqListDeleteByVal(&mylist, val);
			break;
		case 10:
			printf("������Ҫ���ҵ���ֵ:>");
			scanf("%d", &key);
			res = SeqListFind(&mylist, key);
			if (res == -1)
			{
				printf("Ҫ���ҵ�ֵ������!\n");
			}
			else
			{
				printf("Ҫ���ҵ�λ��Ϊ��%d\n", res);
			}
			break;
		case 11:
			val = SeqListLength(&mylist);
			printf("˳���ĳ���Ϊ:%d\n", val);
			break;
		case 12:
			printf("SeqList Capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("����ɹ�!\n");
			break;
		case 14:
			SeqListShow(&mylist);
			SeqListReverse(&mylist);
			SeqListShow(&mylist);
			break;
		case 15:
			SeqListClear(&mylist);
			printf("�������ݳɹ�!\n");
			break;
			//default:
			//	break;
		}
	}
	SeqListDestroy(&mylist);
	printf("�ټ���\n");
	return 0;
}