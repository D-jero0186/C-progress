#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define EASY 10
#define ROWS ROW+2
#define COLS COL+2
void menu();
void initboard(char show[ROWS][COLS]);
void setboard(char mine[ROWS][COLS]);
void dpyboard(char show[ROWS][COLS]);
int findboard(char mine[ROWS][COLS],char show[ROWS][COLS]);