#include"stdafx.h"
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<windows.h>
#include<time.h>
#include"sys.h"
#include"��ʼ��.h"
#include"��Ϸ����.h"
#include<conio.h>
#include"fs.h"
#include"array.h"
#include"function.h"

struct SCORE
{
	char name[40];
	int score;
}sc[5];
int i;

void read1();
void save1();
void show();
void music();
void speed();

void gamestart()
{
	int flag = 0;
	system("cls");
	Pos(20, 10);
	printf("��⵽�д浵���Ƿ�Ҫ��ȡ\n");
	Pos(20, 14);
	printf("��ȡ�밴y����ʼ��Ϸ�밴n");
	empty();
	while (1)
	{
		if (GetAsyncKeyState(0x59))
		{
			flag = 1;
			system("mode con cols=110 lines=40");
			read();
			break;
		}
		if (GetAsyncKeyState(0x4E))
		{
			system("mode con cols=110 lines=40");
			initsnake();
			break;
		}
		Sleep(200);
	}
	creatmap();
	createfood(head);
	gamecircle();
}
void show()
{
	system("cls");
	creatMap();
	read1();
	Pos(2,2);
	printf("���а�");
	Pos(2,3);
	printf("����          ����          �ɼ�");
	for (i = 0; i<5; i++)
	{ 
		Pos(2, i+4);
		printf("%d %16s %13d\n", i + 1, sc[i].name, sc[i].score);
	}
	Pos(11, 25);
	printf("��Enter�������˵�");
	while (1)
	{
		empty();
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			printfss();
			break;
		}

	}
}
void list()
{
	show();
}
void music()
{
	system("cls");
	creatMap();
	Pos(2,2);
	printf("������ѡ���������");
	Pos(2, 4);
	printf("1,We Will Rock You");
	Pos(2, 6);
	printf("2,I Hate Myself For Loving You");
	Pos(2, 8);
	printf("3,Stand By Me");
	Pos(2, 10);
	printf("4,�ֿ���+-+���������");
	Pos(2, 12);
	printf("5,This Is Why I Was Born");
	Pos(2, 14);
	printf("6,Th3 Awak3n1ng");
	Pos(2, 16);
	printf("7,���� out border");
	Pos(11,25);
	printf("���ո񷵻����˵�");
	while (1)
	{
		if (GetAsyncKeyState(49))
		{
			PlaySound(TEXT("D:\\CloudMusic\\Queen - We Will Rock You.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
		}
		else if (GetAsyncKeyState(50))
		{
			PlaySound(TEXT("D:\\CloudMusic\\Joan Jett & the Blackhearts - I Hate Myself For Loving You.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
		}
		else if (GetAsyncKeyState(51))
		{
			PlaySound(TEXT("D:\\CloudMusic\\Florence + The Machine - Stand By Me"), NULL, SND_ASYNC | SND_NODEFAULT);
		}
		else if (GetAsyncKeyState(52))
		{
			PlaySound(TEXT("D:\\CloudMusic\\�ֿ���+-+���������.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
		}
		else if (GetAsyncKeyState(53))
		{
			PlaySound(TEXT("8 Dawn Music - This Is Why I Was Born"), NULL, SND_ASYNC | SND_NODEFAULT);
		}
		else if (GetAsyncKeyState(54))
		{
			PlaySound(TEXT("Really Slow Motion - Th3 Awak3n1ng"), NULL, SND_ASYNC | SND_NODEFAULT);
		}
		else if (GetAsyncKeyState(55))
		{
			PlaySound(TEXT("������� - ���� out border"), NULL, SND_ASYNC | SND_NODEFAULT);
		}

		else if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			printfss();
			break;
		}
		Sleep(200);

	}
}
void speed()
{
	empty();
	system("cls");
	creatMap();
	Pos(14,3);
	printf("1.�ͼ�");
	Pos(14,5);
	printf("2.�м�");
	Pos(14,7);
	printf("3.�߼�");
	Pos(14,9);
	printf("4.����");
	Pos(11, 25);
	printf("��Enter�������˵�");
	empty();
	while (1)
	{
		if (GetAsyncKeyState(49))
		{
			sleeptime = 200;
			add = 10;
			Pos(12,11);
			printf("�Ѷ�������Ϊ�ͼ�");
		}
		else if (GetAsyncKeyState(50))
		{
			sleeptime = 100;
			add = 15;
			Pos(12, 11);
			printf("�Ѷ�������Ϊ�м�");
		}
		else if (GetAsyncKeyState(51))
		{
			sleeptime = 50;
			add = 20;
			Pos(12, 11);
			printf("�Ѷ�������Ϊ�߼�");
		}
		else if (GetAsyncKeyState(52))
		{
			sleeptime = 20;
			add = 25;
			Pos(12, 11);
			printf("�Ѷ�������Ϊ����");
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			printfss();
			return;
		}
		Sleep(200);
	}

}
void set()
{
	system("cls");
	creatMap();
	Pos(15,9);
	printf("F1.����");
	Pos(15,12);
	printf("F2.�Ѷ�");
	Pos(11,25);
	printf("��Enter�������˵�");
	empty();
	while(1)
	{ 
		if (GetAsyncKeyState(VK_F1))
		{
			music();
			break;
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			speed();
			break;
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			printfss();
			break;
		}

	}
}
void save()
{
	array_t *p = arr_new();
	q = head;
	while (q != NULL)
	{
		arr_add(p, q);
		if (q->next == NULL)
			break;
		q = q->next;
	}						//���ߵĽṹ�����������
	save_data(p);			//�������浽�ṹ����
}
void read()
{
	array_t *p = arr_new();
	load_data_to_container(p);
	show_data_from_container(p);
}

void gameabout()
{
	creatMap();
	Pos(5, 5);
	printf("��Ϸ�����ߣ�ȫ����  ׯ����\n");
	Pos(11, 25);
	printf("��Enter�������˵�");
	while (1)
	{
		empty();
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			printfss(); break;
		}
	}
}

void rule()
{
	creatMap();
	Pos(15, 2);
	printf("��Ϸ����\n");
	Pos(14, 5);
	printf("���ư���");
	Pos(6, 7);
	printf("�������������ߵ����������ƶ�");
	Pos(14, 8);
	printf("�ո����ͣ");
	Pos(12, 10);
	printf("��Ϸ��������");
	Pos(1, 12);
	printf("����ײ��ǽ������Լ�������ʱ��Ϸʧ��");
	Pos(3, 16);
	printf("��ÿ�Ե�һ��ʳ�ﶼ������Ӧ�÷�");
	Pos(3, 17);
	printf("��Ϸ�����жϷ����Ƿ��ܹ������а�");
	Pos(8, 18);
	printf("�������а����¼����");
	Pos(11, 25);
	printf("��Enter�������˵�");
	while (1)
	{
		empty();
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			printfss();
			break;
		}
		
	}
}

void read1()
{
	FILE *fp;
	int i;
	if (fopen_s(&fp,"���а�.txt", "r+") != NULL)
	{
		exit(0);
	}
	for(i=0;i<5;i++)
		fread(&sc[i], sizeof(SCORE), 1, fp);
	fclose(fp);
}
void save1()
{
	FILE *fp; int i;
	if (fopen_s(&fp,"���а�.txt", "w+") != NULL)
	{
		for (i = 0; i < 5; i++)
			sc[i].score = 0;
	}
	for (i = 0; i < 5; i++)
		fwrite(&sc[i], sizeof(SCORE), 1, fp);
	
	fclose(fp);
}

void judge(int a)
{	save1();
	for (i = 0; i<5; i++)
	{
		if (sc[i].score<a)
		{
			for (int j = 3; j != i - 1; j--)
			{
				sc[j + 1] = sc[j];
			}
			sc[i].score = a;
			Pos(24, 14);
			printf("��ϲ��ɹ��������а�ǰ��\n");
			Pos(24, 15); 
			printf("�밴�ո�����������Ϣ\n");
			char a1[100];
			while (1)
			{
				if (_getch() != ' ')
				{
					continue;
				}
				else
				{
					Pos(24, 16);
					printf("��׼���ñ���,�����·������������");
					break;
				}
			}
			Pos(24, 17);
			char a[100];
			gets_s(a);
			strcpy_s(sc[i].name, a);
			save1();
			Pos(30, 18);
			printf("��¼�洢�ɹ���");
			empty();
			break;
		}
		
	}

}
