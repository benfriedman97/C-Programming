#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include "status.h"
#include "generic.h"

typedef void* GENERIC_VECTOR;

/***bookend functions***/

GENERIC_VECTOR generic_vector_init_default(
	Status(*item_assignment)(ITEM* pLeft, ITEM right),
	void(*item_destroy)(ITEM* phItem));

void generic_vector_destroy(GENERIC_VECTOR* phVector);

/***Doing things with the vector***/
Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM value);

/*Returns size of the vector*/
int generic_vector_get_size(GENERIC_VECTOR hVector);
/*Returns capacity of the vector*/
int generic_vector_get_capacity(GENERIC_VECTOR hVector);

/*Returns address of a specific index in an array.
Returns NULL on failure (index is out of bounds)*/
ITEM generic_vector_at(GENERIC_VECTOR hVector, int index);

/*Removes element at the end of vector (you don't actually remove
the element, you just lower the size*/
Status generic_vector_pop_back(GENERIC_VECTOR hVector);

/*Notifies if vector is empty. Returns true if tempty, else false*/
Boolean generic_vector_empty(GENERIC_VECTOR hVector);

#endif
