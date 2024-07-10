#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	//雷标识1，空表示0
	int count=1,mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };//展示为*和数字表示周围的雷的数目
	setboard(mine);//随机设置10个雷
	initboard(show);//初始化面板
	for (count = 0;count < ROW * COL - EASY;count++)//循环（总数-雷数）次
	{
		dpyboard(show);//展示面板
		if (findboard(mine,show) == 1)break;//踩雷就返回跳出循环进行判断，否则继续展示
	}
	//判断是否踩雷
	if (count == ROW * COL - EASY)
	{
		printf("恭喜你成功排除%d颗雷！\n ",EASY);
		dpyboard(show);
	}
	else
	{
		printf("\n很遗憾，你被炸死了！\n");//这里可以接一个答案函数
	}
}
int main()
{
	int input=0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); break;
		case 0:printf("退出游戏！"); break;
		default:printf("输入有误！请重新输入：");
		}
	} while (input);
	return 0;
}