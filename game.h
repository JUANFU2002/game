#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void Player_move(char board[ROW][COL], int row, int col);

void Computer_move(char board[ROW][COL], int row, int col);

//判断游戏输赢：返回一个值
//玩家赢--*
//电脑赢--#
//平局--Q
//继续--C
char is_win(char board[ROW][COL], int row, int col);


