#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int func(int n)
{
	if (n <= 2)return 1;
	else
	return func(n - 1) + func(n - 2);
}
int main()
{
	int n;
	scanf("%d", &n);
	//1.1.2.3.5.8.13.21.34.55...
	printf("%d",func(n));
	return 0;
}
