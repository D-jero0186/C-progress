#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"//调用宏定义和头文件
//菜单打印
void menu() {
	printf("*******************************\n");
	printf("**********  1.继续  ***********\n");
	printf("**********  0.退出  ***********\n");
	printf("*******************************\n");
}
//初始化棋子为空格
void initBoard(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			board[i][j] = ' ';
}
//打印棋盘
void displayBoard(char board[ROW][COL])
{
	//打印行”|“
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		//打印棋子和“|”
		for (j = 0; j < COL; j++) 
		{     
				printf(" %c ",board[i][j]);
				if (j < COL-1)printf("|");
		}
	printf("\n");
	//打印横向分割线”---|“
	if(i<ROW-1)
	for (j = 0; j < COL; j++) 
	{
		printf("---");
		if (j < COL - 1)printf("|");
	}
	printf("\n");
	}
}
//玩家走棋
void ply_move(char board[ROW][COL])
{
	int a= 0,x=0,y=0;
	while (1) {
	printf("请输入你的坐标：");
	scanf("%d", &a);
	x = a / 10;
	y = a % 10;
	if (board[x - 1][y - 1] == ' ' && 1<= x &&x<= ROW && 1<= y&&y <= COL)
	{
		board[x-1][y-1] = '*';
		break;
	}
	else 
	{
		printf("输入有误！");
	}
	}
}
//电脑走棋
void cpt_move(char board[ROW][COL])
{
	srand((unsigned)time(NULL));//用时间戳生成真正的随机值
	int x=0,y=0;
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ') 
			{ board[x][y] = '#'; break; }
	}
	printf("电脑走棋 %d-%d 如下：\n",x+1,y+1);
}
//判断胜负或平局，只要某个符号连成线就返回那个符号
int  judge(char board[ROW][COL])
{
	int i , j ,count;
	//判断行
	for (i = 0; i < ROW; i++)
	{
		count = 0;
			for (j=0; j < COL - 1; j++){if (board[i][j]==board[i][j+1])count++;}
			
			if (count == COL - 1)return board[i][j];
	}

	//判断列
	for (j = 0; j < COL; j++)
	{
		count = 0;
			for (i = 0; i < ROW - 1; i++)
			if (board[i][j] == board[i + 1][j])count ++;
			if (count == ROW - 1)return board[i][j];
	}
		
	//判断正对角线
	count = 0;
	for (i = 0, j = 0; i < ROW - 1; i++, j++)
		if (board[i][j] == board[i + 1][j + 1])count += 1;
	if (count == ROW - 1)return board[i][j];

	//判断副对角线
	count = 0;
	for (i = ROW-1, j = 0; i >=0; i--, j++)
		if (board[i][j] == board[i -1][j + 1])count += 1;
	if (count == ROW - 1)return board[i][j];
	//判断是否满子
	count = 0;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			if (board[i][j] == ' ')count += 1;
	if (count == 0)return 1;
	return ' ';
}
void game()
{//创建数组存放棋子
	char board[ROW][COL];
	initBoard(board);//初始化后打印棋子
	displayBoard(board);
	//循环走棋，得出结果后跳出死循环
	while (1)
	{//玩家走棋后打印
		ply_move(board);
		displayBoard(board);
		//判断胜负玩家棋子为'*'棋子满了就是平局
		if (judge(board) == '*'){printf("恭喜你赢了！\n"); break;}
		else if (judge(board) == 1) { printf("平局！\n"); break; }
		//电脑走棋后打印
		cpt_move(board);
		displayBoard(board);
		//判断函数返回电脑棋子'#'则输了
		if (judge(board) == '#'){printf("很遗憾，你输了！"); break;}
	}
	//每次下完提供选择是否继续
	menu();
}