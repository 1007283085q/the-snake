#include"stdafx.h"
#include"初始化.h"
#include"sys.h"
#include"function.h"
#include"array.h"
#include"fs.h"
void snakemove(Snake *food);
void 结束面板();
int status=0,sleeptime = 150;
int score = 0, add = 10;
Snake *head;//蛇头指针
Snake *food;//食物指针
Snake *q;
int  pause()
{
	int i = 0;
	system("cls");
	Pos(10, 10);
	printf("现在处于暂停状态啦，你可以选择以下功能");
	Pos(10, 11);
	printf("1,按空格回到游戏，再按方向键开始游戏");
	Pos(10, 12);
	printf("2,存档");
	Pos(10, 13);
	printf("3,返回主菜单");
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
				printf("◎");
				q = q->next;
			}
			initstatus(head);
			Pos(food->x, food->y);
			printf("¤");
			return 1;
		}

		if (GetAsyncKeyState(50))
		{
			save();
			printf("保存成功");
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
	struct tm t;   //tm结构指针
	time_t now;  //声明time_t类型变量
	  //获取当地日期和时间
	//获取蛇的初始方向
	initstatus(head);
	while (1)
	{	
		time(&now);      //获取系统日期和时间
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
		printf("得分：%d  ", score);
		Pos(80, 12);
		printf("每个食物得分：%d分", add);
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

int biteself()//判断是否咬到了自己
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
void cantcrosswall()//不能穿墙
{
	if (head->x == 0 || head->x == 72 || head->y == 0 || head->y == 29)
	{
		status = 21;
		结束面板();
	}
}
void snakemove(Snake *food)//蛇前进,上U,下D,左L,右R
{
	Snake * nexthead;
	cantcrosswall();
	nexthead = (Snake*)malloc(sizeof(Snake));
	if (status == U)
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1;
		if (nexthead->x == food->x && nexthead->y == food->y)//如果下一个有食物//
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                                               //如果没有食物//
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
			printf("¤");
		}
	}
	if (status == D)
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
		if (nexthead->x == food->x && nexthead->y == food->y)  //有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                               //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
			printf("¤");
		}
	}
	if (status == L)
	{
		nexthead->x = head->x - 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)//有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                                //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
			printf("¤");
		}
	}
	if (status == R)
	{
		nexthead->x = head->x + 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)//有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			score = score + add;
			createfood(head);
		}
		else                                         //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				Pos(q->x, q->y);
				printf("◎");
				q = q->next;
			}
			Pos(q->next->x, q->next->y);
			printf("  ");
			free(q->next);
			q->next = NULL;
			Pos(food->x, food->y);
		}
	}
	if (biteself() == 1)       //判断是否会咬到自己
	{
		status = 22;
		结束面板();
	}
}

void 结束面板()
{	
	system("cls");
	Pos(24, 12);
	if (status == 21)
	{
		printf("对不起，您撞到墙了。游戏结束.");
	}
	else if (status == 22)
	{
		printf("对不起，您咬到自己了。游戏结束.");
	}
	else if (status == 23)
	{
		printf("您的已经结束了游戏。");
	}
	Pos(24, 13);
	printf("您的得分是%d\n", score);
	fflush(stdin);
	rewind(stdin);
	judge(score);
	while (1)
	{
		Pos(24, 19);
		printf("您想执行哪一步操作\n");
		Pos(24, 20);
		printf("1,返回主菜单\n");
		Pos(24, 21);
		printf("2,结束游戏\n");

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