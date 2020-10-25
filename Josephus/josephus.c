#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node *next;
} Node;

/*Builds a circular list by only making it circular
at the very end*/
void create_circular_list(Node *list, int N, int start);
void print_circular_list(Node *list);


int josephus_function(Node **list, int M);

int main(int argc, char *argv[])
{
	int i, j, a[20], last;
	Node *list;

	for (i = 0; i < 20; i++)
		a[i] = 0;
	
	for (i = 2; i < 1001; i++) {
		list = (Node*)malloc(sizeof(Node));
		create_circular_list(list, i, 1);
		last = josephus_function(&list, 10);
		a[last / 50]++;
		free(list);
	}
	
	for (i = 0; i < 20; i++) {
		printf("%d-%d: ", 50 * i + 1, 50 * (i + 1));
		for (j = 0; j < a[i]; j += 10)
			printf("*");
		printf("\n");
	}
	return 0;
}

void create_circular_list(Node *list, int N, int start)
{
	Node *temp;
	int i;

	list->item = start; 
	temp = list;
	for (i = start + 1; i < start + N; i++) {
		temp = (temp->next = (Node*)malloc(sizeof(Node)));
		temp->item = i;
	}
	temp->next = list;
}

void print_circular_list(Node *list)
{
	Node *temp = list;
	printf("%d\n", temp->item);
	temp = temp->next;
	while (temp != list) {
		printf("%d\n", temp->item);
		temp = temp->next;
	}
}

int josephus_function(Node **list, int M)
{
	Node *temp = *list,
		*temp2;
	int flag = 1, i;

	/*original function starts with temp pointing to last node
	Here it starts at first node so special case for first loop*/
	
	for (i = 1; i < M - 1; i++)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = temp->next->next; 
	free(temp2);
	
	while (temp != temp->next) {
		for (i = 1; i < M; i++)
			temp = temp->next;
		temp2 = temp->next;
		temp->next = temp->next->next;
		free(temp2);
	}

	*list = temp;
	return temp->item;
}
