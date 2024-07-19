#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
//1.随机数2.guess
void menu()
{
	printf("*******************************************\n");
	printf("**************  1.继续 *******************\n");
	printf("**************  0.退出  *******************\n");
	printf("*******************************************\n");
	
}
void game()
{
	int guess;
	int ret = rand()%101;
	while (1) {
		printf("您要猜的数为：\t");
		scanf("%d", &guess);
		if (guess > ret)
			printf("太大了！！\n");
		else if (guess == ret)
		{
			printf("汤庆，你真是个棒棒的叼毛！没错就是%d!!\n", ret); break;
		}
		else printf("太小了！！\n");
	}
	
}
int main()
{
	int a;
	srand((unsigned int)time(NULL)); 
	do {
		printf("请选择是否继续：\n");
		menu();
		scanf("%d", &a);
		switch (a) {
		case 1:game(); break;
		case 0:printf("游戏结束！"); break;
		default:printf("输入有误！请重新选择！！");
		}
	} while(a);
	return 0;
}
