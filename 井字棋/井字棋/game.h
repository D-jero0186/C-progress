#pragma once
//定义棋盘大小
#define ROW 3
#define COL 3
#include<stdio.h>
#include<time.h>//用于时间戳生成真正的随机值
#include<stdlib.h>//用于生成伪随机值
//被调用函数
void menu();
void game();
