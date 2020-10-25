#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ROWS 4
#define COLUMNS 3
int*** malloc3d(int num_2D_arrays, int rows_2D_array, int columns_2D_array);
void print3DArray(int*** _3DArray, int size, int rows, int columns);

int main(int argc, char *argv[])
{
	int ***t = malloc3d(SIZE, ROWS, COLUMNS);
	print3DArray(t, SIZE, ROWS, COLUMNS);

	return 0;
}

/*size: size of 3D array (number of 2D arrays)
  rows: number of rows in each 2D array
  columns: number of columns in each row in each 2D array*/
int*** malloc3d(int size, int rows, int columns)
{
	int i, j, k;
	int ***t = (int***)malloc(sizeof(int**) * size);		/*Allocate 3D array: array of pointers to 2D arrays*/
	for (i = 0; i < size; i++) {						
		t[i] = (int**)malloc(sizeof(int*) * rows);			/*Allocate each 2D array pointer*/
		for (j = 0; j < rows; j++) {					
			t[i][j] = (int*)malloc(sizeof(int) * columns);	/*Allocate the 1D arrays and initialize as 0*/
			for (k = 0; k < columns; k++)
				t[i][j][k] = 0;
		}
	}
	return t;
}

void print3DArray(int*** _3DArray, int size, int rows, int columns)
{
	int i, j, k;

	for (i = 0; i < size; i++) {
		printf("ARRAY %d\n", i + 1);
		for (j = 0; j < rows; j++) {
			for (k = 0; k < columns; k++)
				printf("%d ", _3DArray[i][j][k]);
			printf("\n");
		}
		printf("\n\n");
	}
}
