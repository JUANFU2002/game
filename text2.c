#define _CRT_SECURE_NO_WARNINGS 1
#include"game2.h"
void menu()
{
	printf("\n");
	printf("*****************************************\n");
	printf("************    1.play      *************\n");
	printf("************    0.exit      *************\n");
	printf("*****************************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出雷的信息
	//初始化 mine 数组为全0，show 数组为全*
	InitBoard(mine, ROWS, COLS, '0');

	InitBoard(show, ROWS, COLS, '*');

	//布置雷
	SetMine(mine, ROW, COL);
	//显示棋盘
	DisplayBoard(show, ROW, COL);
	//排雷
	FindMine(mine,show,ROW,COL);
}


void test()
{
	//随机数
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");


















































































































































































			break;
		default:
			printf("输入错误请重新输入！");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}