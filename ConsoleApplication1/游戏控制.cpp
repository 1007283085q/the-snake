#include"stdafx.h"
#include"��ʼ��.h"
#include"sys.h"
#include"function.h"
#include"array.h"
#include"fs.h"
void snakemove(Snake *food);
void �������();
int status=0,sleeptime = 150;
int score = 0, add = 10;
Snake *head;//��ͷָ��
Snake *food;//ʳ��ָ��
Snake *q;
int  pause()
{
	int i = 0;
	system("cls");
	Pos(10, 10);
	printf("���ڴ�����ͣ״̬���������ѡ�����¹���");
	Pos(10, 11);
	printf("1,���ո�ص���Ϸ���ٰ��������ʼ��Ϸ");
	Pos(10, 12);
	printf("2,�浵");
	Pos(10, 13);
	printf("3,�������˵�");
	while (status >= 10)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			creatmap();			
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			initstatus(head);
			Pos(food->x, food->y);
			printf("��");
			return 1;
		}

		if (GetAsyncKeyState(50))
		{
			save();
			printf("����ɹ�");
			Sleep(1000);
		}
		if (GetAsyncKeyState(51))
		{
			system("cls");
			printfss();
			return 0;
		}
	}

}
void gamecircle()
{
	struct tm t;   //tm�ṹָ��
	time_t now;  //����time_t���ͱ���
	  //��ȡ�������ں�ʱ��
	//��ȡ�ߵĳ�ʼ����
	initstatus(head);
	while (1)
	{	
		time(&now);      //��ȡϵͳ���ں�ʱ��
		localtime_s(&t, &now); 
		Pos(81, 5);
		printf("%d/", t.tm_year + 1900);
		Pos(86, 5);
		printf("%d/", t.tm_mon + 1);
		Pos(89, 5); 
		printf("%d", t.tm_mday);
		Pos(82, 6);
		printf("%d:", t.tm_hour);
		Pos(85, 6);
		printf("%d:", t.tm_min);
		Pos(88, 6);
		printf("%d\n", t.tm_sec);
		Pos(80, 11);
		printf("�÷֣�%d  ", score);
		Pos(80, 12);
		printf("ÿ��ʳ��÷֣�%d��", add);
		if (GetAsyncKeyState(VK_UP) && status != D)
		{
			status = U;
		}
		else if (GetAsyncKeyState(VK_DOWN) && status != U)
		{
			status = D;
		}
		else if (GetAsyncKeyState(VK_LEFT) && status != R)
		{
			status = L;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && status != L)
		{
			status = R;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			status = 11;
			if (pause() == 0)
				return;
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			status = 23;
			break;
		}

		Sleep(sleeptime);
		snakemove(food);
	}
	return;
}

int biteself()//�ж��Ƿ�ҧ�����Լ�
{
	Snake *self;
	self = head->next;
	while (self != NULL)
	{
		if (self->x == head->x && self->y == head->y)
		{
			return 1;
		}
		self = self->next;
	}
	return 0;
}
void cantcrosswall()//���ܴ�ǽ
{
	if (head->x == 0 || head->x == 72 || head->y == 0 || head->y == 29)
	{
		status = 21;
		�������();
	}
}
void snakemove(Snake *food)//��ǰ��,��U,��D,��L,��R
{
	Snake * nexthead;
	cantcrosswall();
	nexthead = (Snake*)malloc(sizeof(Snake));
	if (status == U)
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1;
		if (nexthead->x == food->x && nexthead->y == food->y)//�����һ����ʳ��//
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                                               //���û��ʳ��//
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
			printf("��");
		}
	}
	if (status == D)
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
		if (nexthead->x == food->x && nexthead->y == food->y)  //��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                               //û��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
			printf("��");
		}
	}
	if (status == L)
	{
		nexthead->x = head->x - 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)//��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                                //û��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
			printf("��");
		}
	}
	if (status == R)
	{
		nexthead->x = head->x + 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)//��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                                         //û��ʳ��
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("��");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
		}
	}
	if (biteself() == 1)       //�ж��Ƿ��ҧ���Լ�
	{
		status = 22;
		�������();
	}
}

void �������()
{	
	system("cls");
	Pos(24, 12);
	if (status == 21)
	{
		printf("�Բ�����ײ��ǽ�ˡ���Ϸ����.");
	}
	else if (status == 22)
	{
		printf("�Բ�����ҧ���Լ��ˡ���Ϸ����.");
	}
	else if (status == 23)
	{
		printf("�����Ѿ���������Ϸ��");
	}
	Pos(24, 13);
	printf("���ĵ÷���%d\n", score);
	fflush(stdin);
	rewind(stdin);
	judge(score);
	while (1)
	{
		Pos(24, 19);
		printf("����ִ����һ������\n");
		Pos(24, 20);
		printf("1,�������˵�\n");
		Pos(24, 21);
		printf("2,������Ϸ\n");

		if (GetAsyncKeyState(49))
		{
			system("cls");
			printfss();
			select();
		}
		
		if (GetAsyncKeyState(50))
		{
			exit(0);
		}
		Sleep(sleeptime);
	}
}