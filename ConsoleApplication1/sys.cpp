
#include"stdafx.h"
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<windows.h>
#include<time.h>
#include"function.h"
#include"初始化.h"
#include"游戏控制.h"
#include<conio.h>
void printfss();
void select();
void Pos(int x, int y)//设置光标位置
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void creatMap()
{
	system("cls");
	int i;
	for (i = 0; i < 40; i += 2)
	{
		Pos(i, 0);
		printf("*");
		Pos(i, 26);
		printf("*");
	}
	for (i = 1; i < 27; i++)
	{
		Pos(0, i);
		printf("*");
		Pos(38, i);
		printf("*");
	}
	}
void printfs()
{
	system("mode con cols=110 lines=40");
	int i;
	Pos(10, 0);
	for (i = 0; i < 69; i++)
		printf("─");
	for (i = 1; i < 30; i++)
	{
		Pos(79, i);
		printf("│");
	}
	for (i = 1; i < 30; i++)
	{
		Pos(10, i);
		printf("│");
	}
	for (i = 0; i < 67; i++)
		printf("─");
	Pos(10, 0);
	printf("╭");
	Pos(79, 0);
	printf("╮");
	Pos(79, 29);
	printf("╯");
	Pos(10, 29);
	printf("╰");
	
		Pos(20, 10); printf("   ._________________.");
		Pos(20, 11); printf("   | _______________ |");
		Pos(20, 12); printf("   | I             I |");
		Pos(20, 13); printf("   | I    。。。   I |");
		Pos(20, 14); printf("   | I        。   I |");
		Pos(20, 15); printf("   | I        .    I |");
		Pos(20, 16); printf("   | I_____________I |");
		Pos(20, 17); printf("   !_________________!");
		Pos(20, 18); printf("       ._[_______]_.  ");
		Pos(20, 19); printf(" .___ | ___________ | ___.");
		Pos(20, 20); printf(" | ::: ____              |");
		Pos(20, 21); printf(" |    ~~~~[CD - ROM]     |");
		Pos(20, 22); printf(" !_______________________!");
	printf("欢迎来到贪吃蛇游戏");
	Pos(45, 15);
	printf("制作者：全嘉兴，庄江铭");
	Pos(40, 26);
	printf("按下任意键继续");
	getchar();
}
void printfss()
{

	system("cls");
	system("mode con cols=110 lines=40"); 
	int i;
	Pos(10, 0);
	for (i = 0; i < 69; i++)
		printf("─");
	for (i = 1; i < 30; i++)
	{
		Pos(79, i);
		printf("│");
	}
	for (i = 1; i < 30; i++)
	{
		Pos(10, i);
		printf("│");
	}
	for (i = 0; i < 67; i++)
		printf("─");
	Pos(10, 0);
	printf("╭");
	Pos(79, 0);
	printf("╮");
	Pos(79, 29);
	printf("╯");
	Pos(10, 29);
	printf("╰");
	Pos(15, 5);
	printf("1,开始游戏");
	Pos(15, 9);
	printf("2,排行榜");
	Pos(15, 13);
	printf("3,设置");
	Pos(15, 17);
	printf("4,关于游戏");
	Pos(15, 21);
	printf("5,规则说明");
	Pos(15, 25);
	printf("6,注销");

}		
void select()
{
	
	printfss();
	while (1)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
		CursorInfo.bVisible = false; //隐藏控制台光标  
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态  
		//fflush(stdin);
		score = 0;
		empty();
		if (GetAsyncKeyState(49))
		{
			gamestart();
		}
		else if (GetAsyncKeyState(50))
		{
			list();
			
		}
		else if (GetAsyncKeyState(51))
		{
			set();
			
		}
		else if (GetAsyncKeyState(52))
		{
			gameabout();
			
		}
		else if (GetAsyncKeyState(53))
		{
			rule();
			
		}
		else if (GetAsyncKeyState(54))
		{
			exit(0);
			
		}
	}
}
