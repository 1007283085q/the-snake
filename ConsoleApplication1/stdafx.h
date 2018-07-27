// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include<windows.h>
#include<time.h>
#include <tchar.h>
#ifndef x1
void Pos(int x, int y);
#define U 1
#define D 2
#define L 3
#define R 4  
typedef struct SNAKE//蛇的一个节点
{
	int x;
	int y;
	struct SNAKE *next;
}Snake;
typedef struct ranking_list//排行榜成员信息
{
	char name;
	int sc;
	time_t Time;
}Ranking_list;
extern int score,add;
extern int status,sleeptime;
extern Snake *head;//蛇头指针
extern Snake *food;//食物指针
extern Snake *q;//遍历指针
#endif // !1
// TODO: 在此处引用程序需要的其他头文件
