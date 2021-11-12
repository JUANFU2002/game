#pragma once
//头文件的包含：
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//符号的声明：
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int row, int col,char set);
//打印棋盘
void DisplayBoard(char board[ROW][COL],int row,int col);
//布置雷
void SetMine(char mine[ROW][COL], int row, int col);

void FindMine(char mine[ROWS][COLS],char show [ROWS][COLS],int row,int col);

