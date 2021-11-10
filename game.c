#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//�汾1��
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{//������
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//	//�ָ���
//		if (i < row - 1)
//		printf("---|---|---\n");
//	}
//}
//�汾2��
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{//������
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//�ָ���
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");

			}
		}
		printf("\n");
	}
}

void Player_move(char board[ROW][COL], int row, int col)
{
	printf("�������:\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã���������\n");
			}

		}
		else
		{
			printf("����Ƿ������������룺\n");
		}
	}
}

void Computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������:\n");

	
	while (1)
	{
		x = rand() % ROW;//0~2;
		y = rand() % COL;//0~2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

int is_full(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//һ�����߳ɹ����ж�
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//һ�����߳ɹ����ж�
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1]!= ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж�ƽ��
	if (1 == is_full(board, row, col))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}