#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//菜单menu
// 初始化棋盘init  

int main()
{
	int a;
	menu();
	printf("请选择是否继续：");
	again:
	scanf("%d", &a);
	switch (a)
	{
	case 1:game(); goto again; break;
	case 0:printf("再次点击退出游戏！"); break;
	default:printf("输入错误!请重新输入:"); goto again;
	}
}