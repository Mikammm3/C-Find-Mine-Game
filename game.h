#define ROW 9
#define COL 9


#define ROWS ROW+2
#define COLS COL+2


#define EASY_COUNT 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void menu();

void InitBoard(char board[ROWS][COLS], int rows, int cols, int set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char mine[ROWS][COLS], int row, int col);

int get_mine_count(char mine[ROWS][COLS], int x, int y);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

void game();

void FindSurroundingMine(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y);
