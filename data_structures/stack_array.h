#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdlib.h>


#define MAX_ELEMENTS (100)  /* maximum size of the stack */

struct stack {
        int*    elements;
        int  stack_pointer;
};

/**
 * Free the memory allocated to the stack
 * */
void destroy_stack(struct stack* st);

/**
 * Initialize the stack pointer and allocate memory for the stack
 * */
void initialize_stack(struct stack* st);

/**
 * Push the element onto the stack
 * */
void push (struct stack* st, int element);

/**
 * Pop the element on the top of the stack
 * */
int pop (struct stack* st);


#endif