#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
//1.�����2.guess
void menu()
{
	printf("*******************************************\n");
	printf("**************  1.���� *******************\n");
	printf("**************  0.�˳�  *******************\n");
	printf("*******************************************\n");
	
}
void game()
{
	int guess;
	int ret = rand()%101;
	while (1) {
		printf("��Ҫ�µ���Ϊ��\t");
		scanf("%d", &guess);
		if (guess > ret)
			printf("̫���ˣ���\n");
		else if (guess == ret)
		{
			printf("���죬�����Ǹ������ĵ�ë��û�����%d!!\n", ret); break;
		}
		else printf("̫С�ˣ���\n");
	}
	
}
int main()
{
	int a;
	srand((unsigned int)time(NULL)); 
	do {
		printf("��ѡ���Ƿ������\n");
		menu();
		scanf("%d", &a);
		switch (a) {
		case 1:game(); break;
		case 0:printf("��Ϸ������"); break;
		default:printf("��������������ѡ�񣡣�");
		}
	} while(a);
	return 0;
}
