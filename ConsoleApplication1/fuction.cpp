#include"stdafx.h"
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<windows.h>
#include<time.h>
#include"sys.h"
#include"初始化.h"
#include"游戏控制.h"
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
	printf("检测到有存档，是否要读取\n");
	Pos(20, 14);
	printf("读取请按y，开始游戏请按n");
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
	printf("排行榜：");
	Pos(2,3);
	printf("排名          姓名          成绩");
	for (i = 0; i<5; i++)
	{ 
		Pos(2, i+4);
		printf("%d %16s %13d\n", i + 1, sc[i].name, sc[i].score);
	}
	Pos(11, 25);
	printf("按Enter返回主菜单");
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
	printf("在这里选择你的音乐");
	Pos(2, 4);
	printf("1,We Will Rock You");
	Pos(2, 6);
	printf("2,I Hate Myself For Loving You");
	Pos(2, 8);
	printf("3,Stand By Me");
	Pos(2, 10);
	printf("4,林俊杰+-+爱不会绝迹");
	Pos(2, 12);
	printf("5,This Is Why I Was Born");
	Pos(2, 14);
	printf("6,Th3 Awak3n1ng");
	Pos(2, 16);
	printf("7,対峙 out border");
	Pos(11,25);
	printf("按空格返回主菜单");
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
			PlaySound(TEXT("D:\\CloudMusic\\林俊杰+-+爱不会绝迹.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
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
			PlaySound(TEXT("深澤秀行 - 対峙 out border"), NULL, SND_ASYNC | SND_NODEFAULT);
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
	printf("1.低级");
	Pos(14,5);
	printf("2.中级");
	Pos(14,7);
	printf("3.高级");
	Pos(14,9);
	printf("4.大神级");
	Pos(11, 25);
	printf("按Enter返回主菜单");
	empty();
	while (1)
	{
		if (GetAsyncKeyState(49))
		{
			sleeptime = 200;
			add = 10;
			Pos(12,11);
			printf("难度已设置为低级");
		}
		else if (GetAsyncKeyState(50))
		{
			sleeptime = 100;
			add = 15;
			Pos(12, 11);
			printf("难度已设置为中级");
		}
		else if (GetAsyncKeyState(51))
		{
			sleeptime = 50;
			add = 20;
			Pos(12, 11);
			printf("难度已设置为高级");
		}
		else if (GetAsyncKeyState(52))
		{
			sleeptime = 20;
			add = 25;
			Pos(12, 11);
			printf("难度已设置为大神级");
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
	printf("F1.音乐");
	Pos(15,12);
	printf("F2.难度");
	Pos(11,25);
	printf("按Enter返回主菜单");
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
	}						//将蛇的结构体存入容器中
	save_data(p);			//将容器存到结构体里
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
	printf("游戏创作者：全嘉兴  庄江铭\n");
	Pos(11, 25);
	printf("按Enter返回主菜单");
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
	printf("游戏规则\n");
	Pos(14, 5);
	printf("控制按键");
	Pos(6, 7);
	printf("↑↓←→控制蛇的上下左右移动");
	Pos(14, 8);
	printf("空格键暂停");
	Pos(12, 10);
	printf("游戏结束条件");
	Pos(1, 12);
	printf("当蛇撞到墙身或是自己的身体时游戏失败");
	Pos(3, 16);
	printf("蛇每吃到一个食物都会获得相应得分");
	Pos(3, 17);
	printf("游戏结束判断分数是否能够上排行榜");
	Pos(8, 18);
	printf("能上排行榜则记录数据");
	Pos(11, 25);
	printf("按Enter返回主菜单");
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
	if (fopen_s(&fp,"排行榜.txt", "r+") != NULL)
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
	if (fopen_s(&fp,"排行榜.txt", "w+") != NULL)
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
			printf("恭喜你成功进入排行榜前五\n");
			Pos(24, 15); 
			printf("请按空格键保存你的信息\n");
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
					printf("已准备好保存,请在下方输入你的名字");
					break;
				}
			}
			Pos(24, 17);
			char a[100];
			gets_s(a);
			strcpy_s(sc[i].name, a);
			save1();
			Pos(30, 18);
			printf("记录存储成功！");
			empty();
			break;
		}
		
	}

}
