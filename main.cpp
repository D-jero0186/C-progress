#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//�˵�menu
// ��ʼ������init  

int main()
{
	int a;
	menu();
	printf("��ѡ���Ƿ������");
	again:
	scanf("%d", &a);
	switch (a)
	{
	case 1:game(); goto again; break;
	case 0:printf("�ٴε���˳���Ϸ��"); break;
	default:printf("�������!����������:"); goto again;
	}
}