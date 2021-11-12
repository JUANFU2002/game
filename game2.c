
#define _CRT_SECURE_NO_WARNINGS 1
#include"game2.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//�кŵĴ�ӡ
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	//��ӡ�к�
	for (i = 1; i <= row; i++ )
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("�������Ų������:");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź��㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;

			}
			else
			{
				//����x��y������Χ�м�����
				int n = get_mine_count(mine, x, y);
				show[x][y] = n + '0';
				//����ascall�����0����Ӧ48������ + �ַ� = ��ֵ��Ӧ�ַ�
				DisplayBoard(show, row, col);
				win++;
			}

		}
		else
		{
			printf("���벻�Ϸ����������룡");	
			
		}
	
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�\n");
		DisplayBoard(mine, row, col);
	}
}
