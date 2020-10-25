#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node *next;
} Node;

/*creates a circular list of N nodes*/
void create_circular_list(Node *list, int N, int start);

/*Prints a circular list*/
void print_circular_list(Node *list);

/*Returns number of nodes in a circular linked list
by counting until it reaches the one it started with again.
It can start anywhere in the list and doesn't have to start
at the list head.
Alternatively, I could just mark what item was the first one,
but this wouldn't account for if there were items of the same
number*/
int calculate_number_of_nodes(Node *list);

/*Calculates the number of nodes between two other nodes
in a circular list when given the address of two other nodes*/
int calc_nodes_between_two_others(Node *list, Node *start, Node *finish);

/*Returns address of the nth item in the circular list*/
Node* get_address(Node *list, int item);


/*Inserts list pointed to by t into list pointed to by x at the
point following x*/
void combine_lists(Node *x, Node *t);

/*Moves the node following t to the position following the node
following x on the list*/
void rearrange_nodes(Node *x, Node *t);


void create_circular_list(Node *list, int N, int start)
{
	//initialize circular list of size 1
	list->item = start; list->next = list;

	Node *temp = list;
	int i;
	for (i = start + 1; i < start + N; i++) {
		temp = (temp->next = (Node*)malloc(sizeof(Node)));
		temp->item = i; temp->next = list;
	}
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


int calculate_number_of_nodes(Node *list)
{
	Node *start = list, *temp;
	int count = 0;
	temp = start->next;
	count++;
	while (temp != start) {
		temp = temp->next;
		count++;
	}
	return count;
}



Node* get_address(Node *list, int item)
{
	Node *temp = list;
	int i;
	for (i = 1; i < item; i++)
		temp = temp->next;
	return temp;
}

int calc_nodes_between_two_others(Node *list, Node *start, Node *finish)
{
	int count = 0;
	start = start->next;
	while (start != finish) {
		count++;
		start = start->next;
	}
	return count;
}




void combine_lists(Node *x, Node *t)
{
	Node *end_of_t, //last node in t that will point to the rest of x
		*to_attach,	//node in x that last node in t will point to
		*temp;	//used to find last node in t
	
	to_attach = x->next;
	end_of_t = t;
	temp = t->next;
	while (temp != t) {
		end_of_t = temp;
		temp = temp->next;
	}

	x->next = t;
	end_of_t->next = to_attach;
}


void rearrange_nodes(Node *x, Node *t)
{
	Node *temp = x->next->next;
	x->next->next = t->next;
	t->next = t->next->next;
	x->next->next = temp;
}
