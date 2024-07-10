#define _CRT_SECURE_NO_WARNINGS 1
//设置雷的函数需要优化
#include"game.h"
void menu()
{
	printf("********************************************\n");
	printf("*****************  1.继续  *****************\n");
	printf("*****************  0.退出  *****************\n");
	printf("********************************************\n");
	printf("请选择是否继续：");
}
void initboard(char show[ROWS][COLS])
{
	int x = 1, y = 1;
	for (x=1; x < ROWS - 1; x++)
		for (y=1; y < COLS - 1; y++)
			show[x][y] = '*';
}
void setboard(int mine[ROWS][COLS])
{
	int x=0,y=0,count = 0;
	srand((unsigned int)time(NULL));//利用时间戳产生随机值
	//此处也可以设置雷的个数然后count--也很方便，那样就只有一个while循环了
	for (count; count < EASY; count++)//放EASY个雷
	{
		while (1)
		{
			x = rand() % (ROWS - 2) + 1;
			y = rand() % (COLS-2) + 1;
			if (mine[x][y] == 0) 
			{
				mine[x][y] = 1; break;
			}
		}
	}
}
void dpyboard(char show[ROWS][COLS])
{
	int x, y;
	printf("\n");
	for ( y = 0; y < COLS-1; y++)//打印列标
		printf("%d ", y);
		printf("\n");
	for(x=1;x<ROWS-1;x++)
		{
			printf("%d ", x);//打印行标
			for (y=1; y < COLS-1; y++)//打印扫雷布局
			printf("%c ",show[x][y]);
			printf("\n");
		}
}
int findboard(int mine[ROWS][COLS], char show[ROWS][COLS])
{
	int a,b=0,x,y;
	printf("请输入你的坐标：");
	//死循环判断是否输入正确，正确跳出循环
	while(1)
	{
		scanf("%d", &a);
		x = a / 10;
		y = a % 10;
		if (x<1 || x>ROWS - 2 || y<1 || y>COLS - 2)
			printf("输入有误，请重新输入坐标：");
		else if (show[x][y] != '*')printf("重复输入！请重新输入坐标：");
		else break;
	} 
	if (mine[x][y] == 0)//没踩到雷就计算坐标周围雷的个数
	{
		b = mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1];
		show[x][y] = 48 + b; return 0;//48是ASCII表里的字符“1”，方便打印
	}
	else return 1;
}