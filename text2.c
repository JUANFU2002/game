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
	char mine[ROWS][COLS] = { 0 };//��Ų��ú��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų���׵���Ϣ
	//��ʼ�� mine ����Ϊȫ0��show ����Ϊȫ*
	InitBoard(mine, ROWS, COLS, '0');

	InitBoard(show, ROWS, COLS, '*');

	//������
	SetMine(mine, ROW, COL);
	//��ʾ����
	DisplayBoard(show, ROW, COL);
	//����
	FindMine(mine,show,ROW,COL);
}


void test()
{
	//�����
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");


















































































































































































			break;
		default:
			printf("����������������룡");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}