#include"stdafx.h"
#include<stdlib.h>
#include"sys.h"
#include<windows.h>
#include<time.h>
void creatmap()
{
	int i = 0;
	for (i; i < 74; i += 2)
	{
	Pos(i, 0);
	printf("��");
	Pos(i, 30);
	printf("��");
	}
	for (i = 1; i < 30; i++)
	{
	Pos(0, i);
	printf("��");
	Pos(72, i);
	printf("��");
	}
}
void initstatus(Snake *head)
{
	int dx=0, dy=0;
	dx = head->x - (head->next->x);
	dy = head->y - (head->next->y);
	if (dx == 2 && dy == 0)
		status = R;
	else if (dx == -2 && dy == 0)
		status = L;
	else if (dx == 0 && dy == 1)
		status = D;
	else if (dx == 0 && dy == -1)
		status = U;
}
void initsnake()//��ʼ������
{
	Snake *tail;
	int i;
	tail = (Snake*)malloc(sizeof(Snake));//����β��ʼ��ʼ��������βΪ��׼�趨��ʼλ��// 
	tail->x = 24;
	tail->y = 5;
	tail->next = NULL;
	for (i = 1; i <= 4; i++)
	{
		head = (Snake*)malloc(sizeof(Snake));
		head->next = tail;
		head->x = 24+2*i;
		head->y = 5;
		tail = head;
	}
	while (tail != NULL)
	{
		Pos(tail->x, tail->y);
		printf("��");
		tail = tail->next;
	}
}
void createfood(Snake *head_1)//�������ʳ��
{
	int x = 11, y = 0,flag=0;
	Snake *food_1;
	srand((unsigned)time(NULL));
	food_1 = (Snake*)malloc(sizeof(Snake));
	time_t t1;
	time(&t1);
	srand(t1);
	while (1)
	{
	
		q = head_1;
		while ((x % 2) != 0)    //��֤��Ϊż����ʹ��ʳ��������ͷ����
		{
			x = rand() % 69 + 2;
		}
		y = 1 + rand() % 29;
		while (q != NULL)
		{
			if (x != q->x || y != q->y)
			{
				flag = 0;
			}
			else if (x == q->x && y == q->y)
			{
				flag = 1;
				break;
			}
			q = q->next;
		}
		if (flag == 1|| (food_1->x % 2) == 0)
			continue;
		else
		{
			Pos(x,y);
			printf("��");
			food_1->x = x;
			food_1->y = y;
			food = food_1;
			break;
		}
		
	}
	
}
void empty()
{
	GetAsyncKeyState(49);
	GetAsyncKeyState(50);
	GetAsyncKeyState(51);
	GetAsyncKeyState(52);
	GetAsyncKeyState(53);
	GetAsyncKeyState(54);
	GetAsyncKeyState(VK_RETURN);
	GetAsyncKeyState(VK_RETURN);
	GetAsyncKeyState(VK_SPACE);
	GetAsyncKeyState(0x59);
	GetAsyncKeyState(0x4E);
}