#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vld.h>


int main(void) {
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

	srand(time(NULL));
	while (repeated_not_found) {
		//get the number, check if repeate
		n = rand() % 1000;
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


