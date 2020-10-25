#ifndef HEADER_H
#define HEADER_H

typedef struct node {
	int item;
	struct node *next;
} Node;

typedef struct node2 {
	int item;
	struct node *previous, *next;
} Node2;

/*Creates a singly linked list of random numbers of given size*/
Node* list_create_list(int size);

/*Prints a linked list*/
void list_print_list(Node *head);

/*3.34
Moves the largest item in a singly linked list to the end of the list*/
Node* list_move_largest_item_to_end(Node *head);

/*3.35
Moves the smallest item to the front*/
Node *list_move_smallest_item_to_front(Node *head);

/*3.36
Moves all nodes in even position to odd position and vice versa*/
Node* list_flip_even_and_odds(Node *head);

/*3.37
Exchanges two nodes in a linked list when given two links t and u*/
Node* list_exchange_nodes(Node *head, Node *t, Node *u);
//helper function: returns address of nth node of singly linked list
Node *list_get_node_address(Node *head, int n);

/*3.38
Returns point to a copy of a new list*/
Node *list_copy(Node *head);

/*3.39
Removes all itemson a given list for which the function
passed as a parameter returns a non-zero value (I made it so
a random number is generated and if it's odd it returns
non-zero else if returns zero). List is modified via
pass by reference*/
void list_delete_list(Node **pHead, int(*f)(Node*));
int f(Node *list);

/*3.40
Does the same as 3.39 function except don't modify the orignial
list rather make a new list and return a pointer to it*/
Node *list_copy_deleted_list(Node *head, int(*f)(Node*));

/*3.41
Reverses a linked list with a head node (the head of the list is a node
but is not actually the "first" node. It's just used to refer to the list.
It points to the first node. Returns pointer to reversed list*/
Node* list_reverse_list(Node *list);
//creats a linked list using a head node
Node *list_create_list2(int size);
//prints a linked list using a head node
void list_print_list2(Node *list);

/*3.42
Create a list of random numbers then sorts it. Does it
with a linked list without head nodes (original problem in 
textbook did it with head nodes*/
Node* list_create_list_random(int size);
Node *list_sort_list_no_head_node(Node *head);

/*3.43
Creates a circular linked list with a head node*/
Node* list_create_circular_list_with_head_node(int size);
void list_print_circular_list_with_head_node(Node *head);
Node* list_josephus(Node *head, int M);

/*3.44
Exchanges two given nodes on a doubly linked list no head*/
Node2* doubly_list_create(int size);
Node2* doubly_list_exchange_nodes(Node2 *head, Node2 *n1, Node2 *n2);
Node2* doubly_list_get_node_address(Node2 *head, int n);
void doubly_list_print_list(Node2 *head);
void doubly_list_print_reverse_list(Node2 *head);

#endif
