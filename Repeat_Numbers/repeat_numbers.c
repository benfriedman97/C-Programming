#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

int main(void)
{
	int i, n, //number
		repeated_not_found = 1,	//flag indicating repeated integer not found yet
		count = 0;		//number of integers generated
	//array to store integers with a size and capacity
	int *a = (int*)malloc(sizeof(int) * 10);
	if (a == NULL) {
		printf("Failed to allocate memory during array intialization\n");
		exit(1);
	}
	int size = 0, capacity = 10;

	srand(time(0));
	while (repeated_not_found) {
		//get the number, check if repeate
		n = rand();
		while (n > 1000)
			n /= 10;
		for (i = 0; i < size; i++)
			if (n == a[i])
				repeated_not_found = 0;
		//add to array if not found, resize if necessary
		if (repeated_not_found) {
			if (size >= capacity) {
				int *temp = (int*)malloc(sizeof(int) * capacity * 2);
				if (temp == NULL) {
					printf("Failed to allocate memory during resizing of array\n");
					exit(1);
				}
				for (i = 0; i < size; i++)
					temp[i] = a[i];
				free(a);
				a = temp;
				capacity *= 2;
			}
			a[size++] = n;
		}
	}
	printf("During random number generation, it took\n%d numbers before getting a repeat\n", size);
	for (i = 0; i < size; i++)
		printf("%d\n", a[i]);
	printf("\n\nRepeat: %d\n", n);
	free(a);

	return 0;
}





int main(void)
{
	int a[MAX], i, n, count = 0;
	for (i = 1; i < MAX; i++)
		a[i] = i;
	srand(time(0));
	int not_all_numbers_generated = 1;
	while (not_all_numbers_generated) {
		n = rand();
		count++;
		while (n >= MAX)
			n /= MAX;
		if (a[n] == n)
			a[n] = -1;

		not_all_numbers_generated = 0;
		for (i = 1; i < MAX && !not_all_numbers_generated; i++) {
			if (a[i] != -1)
				not_all_numbers_generated = 1;
		}
	}
	printf("%d", count);

	return 0;
}
