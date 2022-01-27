//Copyright (c) Penyo. All rights reserved. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define POINT_SINGLE 1 //指定单题分数
#define POINT_LEVELUP 4 //指定晋级分数
#define MOUNT_UPPER 5 //指定每级题数

struct state {
	char mode[128 - 4 * 4]; //模式
	int level, score, mount, chance; //等级、本级分数、本题错次和已答题数
}player;

void Menu(), NumSpawner(), Interactor(int a, int b);
int Calc(int a, int b);

int main()
{
	player.level = 1, player.score = 0;
	Menu();
}

void Menu() //主界面
{
	system("cls");
	printf("\n\
                      你好！欢迎游玩 算术游戏\n\
  ----------------------------------------------------------------\n\
          你可以选择加、减、乘和除四则运算中的任一种运算进行挑\n\
      战。游戏开始，屏幕上随机出现两个数（一位数），你需要给出\n\
      正确的答案，若答错了可重新输入，但每道题只有最多 5 次的尝\n\
      试机会，机会用完后直接进入下一题。\n\
          每题 %d 分，总共 %d 题，达到 %d 分后可晋级，即进行两位\n\
      数计算的挑战。再次达到 %d 分即挑战成功。\n\
  ----------------------------------------------------------------\n\
                        输入 1 进入加法模式\n\
                        输入 2 进入减法模式\n\
                        输入 3 进入乘法模式\n\
                        输入 4 进入除法模式\n\n\
                            ___________\b\b\b\b\b", POINT_SINGLE, MOUNT_UPPER, POINT_LEVELUP, POINT_LEVELUP);
	scanf("%s", player.mode);
	while ((player.mode[1] = getchar()) != '\n'); //清空缓存区
	NumSpawner();
}

void NumSpawner() //生成模块
{
	int a, b; //操作数
	system("cls");
	srand(time(NULL));
	if (player.level == 1) //等级验证
		a = rand() % 10, b = rand() % 10;
	else if (player.level == 2)
		a = rand() % 90 + 10, b = rand() % 90 + 10;
	else
	{
		printf("挑战成功了！\n");
		system("pause");
		exit(0);
	}
	if ((player.mode[0] == '2' && a - b < 0) || (player.mode[0] == '4' && a % b != 0)) //有效性验证
		NumSpawner();
	Interactor(a, b);
}

void Interactor(int a, int b) //交互模块
{
	char chOrigin[128]; //未处理的用户输入结果
	int ch = EOF; //已处理的用户输入结果
	system("cls");
	if (player.score >= POINT_LEVELUP) //晋级验证
	{
		player.level++, player.score = 0, player.mount = 0;
		NumSpawner();
	}
	if (player.score < POINT_LEVELUP && player.mount >= MOUNT_UPPER) //失败验证
	{
		printf("好好学习吧！\n");
		system("pause");
		exit(0);
	}
	if (player.chance >= 5) //错次验证
	{
		player.mount++, player.chance = 0;
		NumSpawner();
	}
	printf("\n\
                       你现在正处于：模式 %c\n\
  ----------------------------------------------------------------\n\n\
                       当前成绩：%d 级 %d 分\n\
                   本级已答 %d 题，本题已错 %d 次\n\n\
  ----------------------------------------------------------------\n\
                            ", player.mode[0], player.level, player.score, player.mount, player.chance);
	switch (player.mode[0])
	{
	case '1':printf("%d + %d = ", a, b); break;
	case '2':printf("%d - %d = ", a, b); break;
	case '3':printf("%d x %d = ", a, b); break;
	case '4':printf("%d ÷ %d = ", a, b); break;
	case 'i':system("cls"); printf("Copyright (c) Penyo. All rights reserved.\n"); system("pause"); main(); break;
	default:Menu();
	}
	gets(chOrigin);
	if (atof(chOrigin) >= 0 && atof(chOrigin) <= 99 * 99)
		ch = atof(chOrigin);
	if (Calc(a, b) == ch) //加分或重试验证
	{
		player.score += POINT_SINGLE, player.mount++, player.chance = 0;
		NumSpawner();
	}
	else
	{
		player.chance++;
		Interactor(a, b);
	}
}

int Calc(int a, int b) //计算模块
{
	switch (player.mode[0])
	{
	case '1':return a + b; break;
	case '2':return a - b; break;
	case '3':return a * b; break;
	case '4':return a / b;
	}
}