#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include "status.h"
#include "generic.h"

typedef void* GENERIC_VECTOR;

/*Precondition: none
Postcondition: initializes a generic vector, in this program
for triangle objects*/
GENERIC_VECTOR generic_vector_init_default(
	Status(*item_assignment)(ITEM* pLeft, ITEM right),
	void(*item_destroy)(ITEM* phItem));
	//void (*item_print_info)(ITEM item),
	//double(*item_get_area)(ITEM item));

/*Precondition: phVector a pointer to a handle to a generic vector
Postcondition: destroys the generic vector*/
void generic_vector_destroy(GENERIC_VECTOR* phVector);

/*Precondition: hVector is a valid handle to a generic vector and value
is a valid item.
Postcondition: value is pushed back into the generic vector's data array
of objects*/
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

/*Precondition: hVector is a valid to a generic vector (in this case
each item is a triangle object
Postcondition: calls the triangle print function in triangle.c
for every single triangle object to print the points and area of
every single triangle to stdout*/
//void generic_vector_print_information(GENERIC_VECTOR hVector);

/*Precondition: hVector is a handle to a valid vector
Postcondition: returns the average area of all the triangles*/
//double generic_vector_calculate_average_area(GENERIC_VECTOR hVector);

#endif
