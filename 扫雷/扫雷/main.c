#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	//�ױ�ʶ1���ձ�ʾ0
	int count=1,mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };//չʾΪ*�����ֱ�ʾ��Χ���׵���Ŀ
	setboard(mine);//�������10����
	initboard(show);//��ʼ�����
	for (count = 0;count < ROW * COL - EASY;count++)//ѭ��������-��������
	{
		dpyboard(show);//չʾ���
		if (findboard(mine,show) == 1)break;//���׾ͷ�������ѭ�������жϣ��������չʾ
	}
	//�ж��Ƿ����
	if (count == ROW * COL - EASY)
	{
		printf("��ϲ��ɹ��ų�%d���ף�\n ",EASY);
		dpyboard(show);
	}
	else
	{
		printf("\n���ź����㱻ը���ˣ�\n");//������Խ�һ���𰸺���
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
		case 0:printf("�˳���Ϸ��"); break;
		default:printf("�����������������룺");
		}
	} while (input);
	return 0;
}