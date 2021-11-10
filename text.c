#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"//自己的头文件用双引号，库函数用<>
//游戏的测试逻辑
void menu()
{
	printf("***********************************\n");
	printf("*********   1.play  ***************\n");
	printf("*********   0.exit  ***************\n");
	printf("***********************************\n");

}

void game()
{
	//玩家“*”，电脑“#”；
	char board[ROW][COL] = { 0 };//数组的内容全是空格
	InitBoard(board, ROW,COL );//初始化棋盘,先将空格填到每个元素中;
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		Player_move(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		Computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if(ret=='#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局了\n");
	}


}
void test()
{
	int input = 0;

	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default :
				printf("选择错误\n");
				break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}