#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLUMNS 10
int** malloc2d(int r, int c);
int fill2DArray(int **a, int r, int c);
int GCD(int i, int j);

int main(int argc, char *argv[])
{
	int **a = malloc2d(ROWS, COLUMNS), i, j;
	fill2DArray(a, ROWS, COLUMNS);
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}

int** malloc2d(int r, int c)
{
	int i;
	int **t = (int**)malloc(sizeof(int*) * r);	//allocate array of pointers
	for (i = 0; i < r; i++)
		t[i] = (int*)malloc(sizeof(int) * c);	//allocate each array
	return t;
}

int fill2DArray(int **a, int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			a[i][j] = GCD(i, j);
}

int GCD(int i, int j)
{
	int GCD;
	if (i == 0 || j == 0)
		return 0;
	GCD = (i > j) ? j : i;
	while (GCD > 1) {
		if (i % GCD == 0 && j % GCD == 0)
			return 0;
		else
			GCD--;
	}
	return 1;
}
