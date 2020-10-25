#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* list_create_list(int size)
{
	Node *head, *temp;
	int i;

	head = (Node*)malloc(sizeof(Node));
	head->item = 1;
	temp = head;
	for (i = 1; i < size; i++) {
		temp = (temp->next = (Node*)malloc(sizeof(Node)));
		temp->item = i + 1;
	}
	temp->next = NULL;
	return head;
}

void list_print_list(Node *head)
{
	while (head != NULL) {
		printf("%d\n", head->item);
		head = head->next;
	}
}

/*3.34*/
Node* list_move_largest_item_to_end(Node *head)
{
	Node *temp, //walk through list
		*largest, //stores largest node
		*previous; //stores node before largest

	if (head == NULL)
		return NULL;
	//size is 1
	if (head->next == NULL)
		return head;
	//size is 2 or greater
	previous = NULL;
	temp = largest = head;
	while (temp->next != NULL) {
		if (temp->next->item > largest->item) {
			largest = temp->next;
			previous = temp;
		}
		temp = temp->next;
	}
	//largest node was first node
	if (previous == NULL) {
		previous = head->next;	//store new head node in previous
		head->next = temp->next;	//point to NULL since it's last node
		temp->next = head;		//make head the last node
		return previous;	//previous is the new head
	}

	if (largest != temp) {
		previous->next = largest->next;	//point previous node to node following largest
		temp->next = largest;
		largest->next = NULL;
	}
	return head;
}

/*3.35*/
Node *list_move_smallest_item_to_front(Node *head)
{
	Node *temp, //walk through list
		*smallest, //stores largest node
		*previous; //stores node before largest

	if (head == NULL)
		return NULL;
	//size is 1
	if (head->next == NULL)
		return head;
	//size is 2 or greater
	previous = NULL;
	temp = smallest = head;
	while (temp->next != NULL) {
		if (temp->next->item < smallest->item) {
			smallest = temp->next;
			previous = temp;
		}
		temp = temp->next;
	}

	//smallest node was not first node
	if (previous != NULL) {
		previous->next = smallest->next;
		smallest->next = head;
		return smallest;
	}
	//smallest node was first node
	return head;
}


Node* list_flip_even_and_odds(Node *head)
{
	Node *odd, *even, *previous, *new_head;

	//empty or one node list
	if (head == NULL || head->next == NULL)
		return head;

	//2 or more nodes
	previous = NULL;
	odd = head;
	even = head->next;
	new_head = even;

	while (odd->next != NULL) {
		odd->next = even->next;
		even->next = odd;
		if (previous != NULL)
			previous->next = even;
		previous = odd;
		if (odd->next != NULL) {
			odd = odd->next;
			if (odd->next != NULL)
				even = odd->next;
		}
	}
	return new_head;
}

/*3.37*/
Node* list_exchange_nodes(Node *head, Node *t, Node *u) 
{	
	if (head == NULL || u == t)
		return head;

	Node *before_t = NULL, *after_t = head->next,
		*before_u = NULL, *after_u = head->next, *temp = head;

	//get nodes before/after t
	while (temp != t && temp != NULL) {
		before_t = temp;
		temp = temp->next;
	}
	after_t = temp->next;
	
	temp = head;
	while (temp != u && temp != NULL) {
		before_u = temp;
		temp = temp->next;
	}
	after_u = temp->next;
	
	//case 1: u is head
	if (u == head) {
		head = t;
		//t is right after u
		if (after_u == t)
			t->next = u;
		//t is not right after u
		else {
			t->next = after_u;
			before_t->next = u;
		}
		u->next = after_t;
	}
	//case 2: t is head
	else if (t == head) {
		head = u;
		//u is right after t
		if (after_t == u)
			u->next = t;
		//t is not right after u
		else {
			u->next = after_t;
			before_u->next = t;
		}
		t->next = after_u;
	}
	//case 3: neither are head, u is before t
	else if (u->next == t) {
		before_u->next = t;
		t->next = u;
		u->next = after_t;
	}
	//case 4: neither are head, t is before u
	else if (t->next == u) {
		before_t->next = u;
		u->next = t;
		t->next = after_u;
	}
	//case 5: neither are head, not adjacent
	else {
		before_u->next = t;
		t->next = after_u;
		before_t->next = u;
		u->next = after_t;
	}
	return head;
}
//helper function: returns address of nth node
Node *list_get_node_address(Node *head, int n)
{
	Node *node = head;
	int i;

	for (i = 1; i < n && node != NULL; i++)
		node = node->next;
	return node;
}


Node *list_copy(Node *head)
{
	Node *new_list = NULL, *temp;
	if (head != NULL) {
		new_list = (Node*)malloc(sizeof(Node));
		new_list->item = head->item;
		new_list->next = NULL;
		temp = new_list;
		head = head->next;
		while (head != NULL) {
			temp->next = (Node*)malloc(sizeof(Node));
			temp->next->item = head->item;
			temp = temp->next;
			head = head->next;
		}
	}
	temp->next = NULL;
	return new_list;
}

void list_delete_list(Node **pHead, int(*f)(Node*)) {
	Node *temp, *before = NULL, *after;
	int status;
	if (*pHead != NULL) {
		//delete first and succcessive heads if they need to be deleted
		status = f(*pHead);
		while (status != 0 && *pHead != NULL) {
			temp = (*pHead)->next;
			free(*pHead);
			*pHead = temp;
			if (*pHead != NULL)
				status = f(*pHead);
		}
	}
	//if all nodes were not deleted at this point
	if (*pHead != NULL) {
		//at this point, the first node should not be deleted so we check the second node
		temp = (*pHead)->next;
		//case: new head is not only node
		if (temp != NULL) {
			before = *pHead;
			after = temp->next;
			status = f(temp);
			while (temp != NULL) {
				//delete the node
				if (status != 0) {
					before->next = after;
					free(temp);
				}
				//don't delete node
				else
					before = temp;
				//setup for next node
				temp = after;
				if (temp != NULL) {
					after = temp->next;
					status = f(temp);
				}
			}
		}
	}
}

int f(Node *list)
{
	if (list->item % 2 == 0)
		return 0;
	else
		return 1;
}


Node *list_copy_deleted_list(Node *head, int(*f)(Node*))
{
	Node *new_head = NULL, *temp;
	int status;

	while (head != NULL) {
		status = f(head);
		if (status == 0) {
			//making first node
			if (new_head == NULL) {
				new_head = (Node*)malloc(sizeof(Node));
				new_head->item = head->item;
				new_head->next = NULL;
				temp = new_head;
			}
			//making 2nd or greater node
			else
			{
				temp->next = (Node*)malloc(sizeof(Node));
				temp->next->item = head->item;
				temp = temp->next;
			}
		}
		head = head->next;
	}
	temp->next = NULL;
	return new_head;
}

Node* list_reverse_list(Node *list)
{
	Node *saved_head = list, *before = NULL, *current = list->next, *after;
	while (current != NULL) {
		after = current->next;	//save pointer to node after one about to be reversed
		current->next = before;	//reverse the current unreversed node
		before = current;		//change before to be the first node of processed list thus far
		current = after;		//move current to next unreversed node
	}
	saved_head->next = before;
	return saved_head;
}

Node *list_create_list2(int size)
{
	Node *head, *temp;
	int i;

	head = (Node*)malloc(sizeof(Node));
	head->next = (Node*)malloc(sizeof(Node));
	head->next->item = 1;
	temp = head->next;
	for (i = 1; i < size; i++) {
		temp = (temp->next = (Node*)malloc(sizeof(Node)));
		temp->item = i + 1;
	}
	temp->next = NULL;
	return head;
}

void list_print_list2(Node *list)
{
	Node *head = list->next;
	while (head != NULL) {
		printf("%d\n", head->item);
		head = head->next;
	}
}

Node* list_create_list_random(int size)
{
	Node *head, *temp;
	int i;

	head = (Node*)malloc(sizeof(Node));
	head->item = rand();
	temp = head;
	for (i = 1; i < size; i++) {
		temp = (temp->next = (Node*)malloc(sizeof(Node)));
		temp->item = rand();
	}
	temp->next = NULL;
	return head;
}

Node *list_sort_list_no_head_node(Node *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node *new_head, *before_current, *current, *after_current,
		*before_smallest, *smallest, *after_smallest, *temp, *after_temp;
	
	//get smallest node in list
	before_smallest = NULL; smallest = head; after_smallest = head->next;
	before_current = head; current = head->next; after_current = current->next;
	while (current != NULL) {
		if (current->item < smallest->item) {
			before_smallest = before_current; smallest = current; after_smallest = after_current;
		}
		before_current = current; current = after_current;
		if (current != NULL)
			after_current = current->next;
	}

	new_head = smallest;	//make smallest node the head of the new list
	if (new_head == head) {	//if smallest node was first node, make head of unsorted list the second node
		head = head->next;
	}
	else {	/*smallest node was not first node. Head of unsorted list is still first node
			remove the smallest node from the list*/
		before_smallest->next = after_smallest;
	}
	new_head->next = NULL;	//new list has one item so point next to NULL.
	
	/*At this point, the node we grab from unsorted list will always be larger
	than first node in sorted list so just insert it manually*/
	temp = head;	//address of next unsorted node
	after_temp = head->next;	//address of unsorted node following this one
	new_head->next = temp;
	temp->next = NULL;

	//sort the rest of the nodes
	temp = after_temp;
	if (temp != NULL)	//temp will be NULL if linked list size was 2
		after_temp = temp->next;
	while (temp != NULL) {
		//find where in sorted list to insert the unsorted node
		for (before_current = new_head, current = new_head->next;
			current != NULL;
			before_current = current, current = current->next)
		{
			if (current == NULL || temp->item < current->item)
				break;
		}
		before_current->next = temp;
		temp->next = current;

		temp = after_temp;
		if (temp != NULL)
			after_temp = temp->next;
	}
	
	return new_head;
}


Node* list_create_circular_list_with_head_node(int size)
{
	Node *head = (Node*)malloc(sizeof(Node)),
		*temp;
	int i;
	for (i = 0, temp = head; i < size; i++) {
		temp->next = (Node*)malloc(sizeof(Node));
		temp->next->item = rand();
		temp = temp->next;
	}
	temp->next = head->next;
	return head;
}

void list_print_circular_list_with_head_node(Node *head)
{
	Node *temp = head->next;
	do {
		printf("%d\n", temp->item);
		temp = temp->next;
	} while (temp != head->next);
}

Node* list_josephus(Node *head, int M)
{
	int i;
	Node *current, *temp;
	//set up position so current is at last node
	current = head->next;
	while (current->next != head->next)
		current = current->next;
	
	//start eliminating nodes
	while (current != current->next) {
		for (i = 1; i < M; i++)
			current = current->next;
		temp = current->next->next;
		free(current->next);
		current->next = temp;
	}
	return current;
}

Node2* doubly_list_create(int size)
{
	Node2 *head, *previous, *current;
	int i;

	if (size <= 0)
		return NULL;
	head = (Node2*)malloc(sizeof(Node2));
	head->previous = NULL;
	head->item = 1;
	head->next = NULL;
	if (size == 1)
		return head;
	previous = head;
	for (i = 1; i < size; i++) {
		current = (Node2*)malloc(sizeof(Node2));
		current->item = i + 1;
		current->previous = previous;
		previous->next = current;
		previous = current;
	}
	current->next = NULL;
	return head;
}

void doubly_list_print_list(Node2 *head)
{
	while (head != NULL) {
		printf("%d\n", head->item);
		head = head->next;
	}
}

Node2* doubly_list_exchange_nodes(Node2 *head, Node2 *t, Node2 *u)
{
	if (head == NULL || u == t)
		return head;

	Node2 *before_t = NULL, *after_t = head->next,
		*before_u = NULL, *after_u = head->next, *temp = head;

	//get nodes before/after t
	while (temp != t && temp != NULL) {
		before_t = temp;
		temp = temp->next;
	}
	after_t = temp->next;

	temp = head;
	while (temp != u && temp != NULL) {
		before_u = temp;
		temp = temp->next;
	}
	after_u = temp->next;

	//case 1: u is head
	if (u == head) {
		head = t;
		//t is right after u
		if (after_u == t) {
			t->next = u;
			u->previous = t;
		}
		//t is not right after u
		else {
			t->next = after_u;
			after_u->previous = t;
			before_t->next = u;
			u->previous = before_t;
		}
		t->previous = NULL;
		u->next = after_t;
		if (after_t != NULL)
			after_t->previous = u;
	}
	//case 2: t is head
	else if (t == head) {
		head = u;
		//u is right after t
		if (after_t == u) {
			u->next = t;
			t->previous = u;
		}
		//u is not right after t
		else {
			u->next = after_t;
			after_t->previous = u;
			before_u->next = t;
			t->previous = before_u;
		}
		u->previous = NULL;
		t->next = after_u;
		if (after_u != NULL)
			after_u->previous = t;
	}
	//case 3: neither are head, t is right after u
	else if (u->next == t) {
		before_u->next = t;
		t->previous = before_u;
		t->next = u;
		u->previous = t;
		u->next = after_t;
		if (after_t != NULL)
			after_t->previous = u;
	}
	//case 4: neither are head, u is right after t
	else if (t->next == u) {
		before_t->next = u;
		u->previous = before_t;
		u->next = t;
		t->previous = u;
		t->next = after_u;
		if (after_u != NULL)
			after_u->previous = u;
	}
	//case 5: neither are head, not adjacent
	else {
		before_u->next = t;
		t->previous = before_u;
		t->next = after_u;
		if (after_u != NULL)
			after_u->previous = t;
		before_t->next = u;
		u->previous = before_t;
		u->next = after_t;
		if (after_t != NULL)
			after_t->previous = u;
	}
	return head;
}

Node2* doubly_list_get_node_address(Node2 *head, int n)
{
	Node2 *temp = head;
	int i;
	for (i = 1; i < n; i++) {
		if (temp == NULL)
			break;
		temp = temp->next;
	}
	return temp;
}

void doubly_list_print_reverse_list(Node2 *head)
{
	while (head->next != NULL)
		head = head->next;
	while (head != NULL) {
		printf("%d\n", head->item);
		head = head->previous;
	}
}
