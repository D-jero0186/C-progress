#define _CRT_SECURE_NO_WARNINGS 1
//�����׵ĺ�����Ҫ�Ż�
#include"game.h"
void menu()
{
	printf("********************************************\n");
	printf("*****************  1.����  *****************\n");
	printf("*****************  0.�˳�  *****************\n");
	printf("********************************************\n");
	printf("��ѡ���Ƿ������");
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
	srand((unsigned int)time(NULL));//����ʱ����������ֵ
	//�˴�Ҳ���������׵ĸ���Ȼ��count--Ҳ�ܷ��㣬������ֻ��һ��whileѭ����
	for (count; count < EASY; count++)//��EASY����
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
	for ( y = 0; y < COLS-1; y++)//��ӡ�б�
		printf("%d ", y);
		printf("\n");
	for(x=1;x<ROWS-1;x++)
		{
			printf("%d ", x);//��ӡ�б�
			for (y=1; y < COLS-1; y++)//��ӡɨ�ײ���
			printf("%c ",show[x][y]);
			printf("\n");
		}
}
int findboard(int mine[ROWS][COLS], char show[ROWS][COLS])
{
	int a,b=0,x,y;
	printf("������������꣺");
	//��ѭ���ж��Ƿ�������ȷ����ȷ����ѭ��
	while(1)
	{
		scanf("%d", &a);
		x = a / 10;
		y = a % 10;
		if (x<1 || x>ROWS - 2 || y<1 || y>COLS - 2)
			printf("���������������������꣺");
		else if (show[x][y] != '*')printf("�ظ����룡�������������꣺");
		else break;
	} 
	if (mine[x][y] == 0)//û�ȵ��׾ͼ���������Χ�׵ĸ���
	{
		b = mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1];
		show[x][y] = 48 + b; return 0;//48��ASCII������ַ���1���������ӡ
	}
	else return 1;
}