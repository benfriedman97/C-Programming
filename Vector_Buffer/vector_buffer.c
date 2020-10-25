#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nmax 1000		//maximum a thousand words stored in buffer
#define STR_MAX_SIZE 10	//a word of size 10 max can be entered

typedef struct vector_buffer {
	int size, capacity;
	char *buf;
} Vector_buffer;

/*Initializes buffer to hold STR_MAX_SIZE characters*/
Vector_buffer* vector_buffer_init_default(void);
/*Inserts a new string into a buffer. If not enough capacity, will 
destroy the old buffer and create a new one and put the new addresses of
the strings into the array "a"*/
int vector_buffer_insert_new_string(Vector_buffer *vector, char *a[]);
int compare(void *i, void *j);

int main(int argc, char *argv[])
{
	Vector_buffer *vector;
	int i, N;
	int M = 0;
	char *a[Nmax];

	vector = vector_buffer_init_default();

	for (N = 0; N < Nmax; N++) {
		a[N] = &(vector->buf[vector->size]);
		if (vector_buffer_insert_new_string(vector, a) == EOF)
			break;
	}
		

	qsort(a, N, sizeof(char*), compare);
	for (i = 0; i < N; i++)
		printf("%s\n", a[i]);

	return 0;
}

int compare(void *i, void *j)
{
	return strcmp(*(char**)i, *(char**)j);
}

Vector_buffer* vector_buffer_init_default(void)
{
	Vector_buffer *vector = (Vector_buffer*)malloc(sizeof(Vector_buffer));
	if (vector != NULL) {
		vector->buf = (char*)malloc(sizeof(char) * (STR_MAX_SIZE + 1));
		if (vector->buf == NULL) {
			free(vector);
			return NULL;
		}
		vector->size = 0;
		vector->capacity = STR_MAX_SIZE + 1;
	}
	return vector;
}

int vector_buffer_insert_new_string(Vector_buffer *vector, char *a[])
{
	char str[STR_MAX_SIZE + 1];
	char *temp;
	int i, j;

	if (scanf("%9s", str) == EOF)
		return EOF;
	while (getchar() != '\n');
	if (strlen(str) + 1 + vector->size >= vector->capacity) {
		temp = (char*)malloc(sizeof(char) * vector->size);
		for (i = 0; i < vector->size; i++)
			temp[i] = vector->buf[i];
		free(vector->buf);
		vector->buf = (char*)malloc(sizeof(char) * vector->capacity * 2);
		for (i = 0; i < vector->size; i++)
			vector->buf[i] = temp[i];
		vector->capacity *= 2;
	}
	sprintf(&(vector->buf[vector->size]), str);
	vector->size += strlen(str) + 1;
	for (i = 0, j = 0; j < vector->size; i++, j++) {
		a[i] = &vector->buf[j];
		while (vector->buf[j] != '\0')
			j++;
	}
	a[i] = &vector->buf[j];
	return 1;
}
