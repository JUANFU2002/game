#pragma once
//ͷ�ļ��İ�����
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//���ŵ�������
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

//��ʼ������
void InitBoard(char board[ROWS][COLS], int row, int col,char set);
//��ӡ����
void DisplayBoard(char board[ROW][COL],int row,int col);
//������
void SetMine(char mine[ROW][COL], int row, int col);

void FindMine(char mine[ROWS][COLS],char show [ROWS][COLS],int row,int col);

