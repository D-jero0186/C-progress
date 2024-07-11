#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"//���ú궨���ͷ�ļ�
//�˵���ӡ
void menu() {
	printf("*******************************\n");
	printf("**********  1.����  ***********\n");
	printf("**********  0.�˳�  ***********\n");
	printf("*******************************\n");
}
//��ʼ������Ϊ�ո�
void initBoard(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			board[i][j] = ' ';
}
//��ӡ����
void displayBoard(char board[ROW][COL])
{
	//��ӡ�С�|��
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		//��ӡ���Ӻ͡�|��
		for (j = 0; j < COL; j++) 
		{     
				printf(" %c ",board[i][j]);
				if (j < COL-1)printf("|");
		}
	printf("\n");
	//��ӡ����ָ��ߡ�---|��
	if(i<ROW-1)
	for (j = 0; j < COL; j++) 
	{
		printf("---");
		if (j < COL - 1)printf("|");
	}
	printf("\n");
	}
}
//�������
void ply_move(char board[ROW][COL])
{
	int a= 0,x=0,y=0;
	while (1) {
	printf("������������꣺");
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
		printf("��������");
	}
	}
}
//��������
void cpt_move(char board[ROW][COL])
{
	srand((unsigned)time(NULL));//��ʱ����������������ֵ
	int x=0,y=0;
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ') 
			{ board[x][y] = '#'; break; }
	}
	printf("�������� %d-%d ���£�\n",x+1,y+1);
}
//�ж�ʤ����ƽ�֣�ֻҪĳ�����������߾ͷ����Ǹ�����
int  judge(char board[ROW][COL])
{
	int i , j ,count;
	//�ж���
	for (i = 0; i < ROW; i++)
	{
		count = 0;
			for (j=0; j < COL - 1; j++){if (board[i][j]==board[i][j+1])count++;}
			
			if (count == COL - 1)return board[i][j];
	}

	//�ж���
	for (j = 0; j < COL; j++)
	{
		count = 0;
			for (i = 0; i < ROW - 1; i++)
			if (board[i][j] == board[i + 1][j])count ++;
			if (count == ROW - 1)return board[i][j];
	}
		
	//�ж����Խ���
	count = 0;
	for (i = 0, j = 0; i < ROW - 1; i++, j++)
		if (board[i][j] == board[i + 1][j + 1])count += 1;
	if (count == ROW - 1)return board[i][j];

	//�жϸ��Խ���
	count = 0;
	for (i = ROW-1, j = 0; i >=0; i--, j++)
		if (board[i][j] == board[i -1][j + 1])count += 1;
	if (count == ROW - 1)return board[i][j];
	//�ж��Ƿ�����
	count = 0;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			if (board[i][j] == ' ')count += 1;
	if (count == 0)return 1;
	return ' ';
}
void game()
{//��������������
	char board[ROW][COL];
	initBoard(board);//��ʼ�����ӡ����
	displayBoard(board);
	//ѭ�����壬�ó������������ѭ��
	while (1)
	{//���������ӡ
		ply_move(board);
		displayBoard(board);
		//�ж�ʤ���������Ϊ'*'�������˾���ƽ��
		if (judge(board) == '*'){printf("��ϲ��Ӯ�ˣ�\n"); break;}
		else if (judge(board) == 1) { printf("ƽ�֣�\n"); break; }
		//����������ӡ
		cpt_move(board);
		displayBoard(board);
		//�жϺ������ص�������'#'������
		if (judge(board) == '#'){printf("���ź��������ˣ�"); break;}
	}
	//ÿ�������ṩѡ���Ƿ����
	menu();
}