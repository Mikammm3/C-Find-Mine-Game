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
	printf("------------扫雷游戏-------------\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//打印行号
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{

			printf("%c ", board[i][j]);

		}
		printf("\n");
	}

	printf("------------扫雷游戏-------------\n");
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
		printf("请输入要查找的坐标:>\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);//统计雷
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}

		}
		else
			printf("坐标非法，请重新输入:>\n");
	}
	if (win == ROW * COL - EASY_COUNT)
	{
		DisplayBoard(mine, ROW, COL);
		printf("恭喜您！扫雷成功！！！\n");
	}
}

void game()
{
	//创建棋盘，
	//这个mine是放雷的
	char mine[ROWS][COLS] = { 0 };
	//这个show是放查找出的雷的数据的
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}