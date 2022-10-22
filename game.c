#include"game.h"




void menu()
{
	printf("************************************\n");
	printf("*******        1.play       ********\n");
	printf("*******        0.exit       ********\n");
	printf("************************************\n");
}


void InitBoard(char board[ROWS][COLS], int rows, int cols, int set)
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
	printf("------------ɨ����Ϸ-------------\n");
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//��ӡ�к�
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{

			printf("%c ", board[i][j]);

		}
		printf("\n");
	}

	printf("------------ɨ����Ϸ-------------\n");
}




void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}

}




int get_mine_count(char mine[ROWS][COLS], int x, int y)

{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';

}





void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win <  ROW * COL - EASY_COUNT)
	{
		printf("������Ҫ���ҵ�����:>\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);//ͳ����
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}

		}
		else
			printf("����Ƿ�������������:>\n");
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		DisplayBoard(mine, ROW, COL);
		printf("��ϲ����ɨ�׳ɹ�������\n");
	}
}

void game()
{
	//�������̣�
	//���mine�Ƿ��׵�
	char mine[ROWS][COLS] = { 0 };
	//���show�ǷŲ��ҳ����׵����ݵ�
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);
}