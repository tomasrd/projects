#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "stack_array.h"


void destroy_stack(struct stack* st)
{
        free(st->elements);
        st->elements = NULL;
}


void initialize_stack(struct stack* st)
{
        st->elements = (int*) malloc(MAX_ELEMENTS * sizeof(int));

        if (st->elements == NULL) {
                fprintf(stderr, "Error creating the stack\n");
                exit(EXIT_FAILURE);
        }

        st->stack_pointer = -1;
}


bool is_empty (struct stack* st)
{
        return (st->stack_pointer == 0);
}



bool is_full (struct stack* st)
{
        return (st->stack_pointer == (MAX_ELEMENTS -1) );
}


/* the function adds the new element to the array and increments the stack pointer */
void push (struct stack* st, int element)
{
        if (!is_full(st)) {
                st->stack_pointer++;
                st->elements[st->stack_pointer] = element;
        }

        else {
                fprintf(stderr, "Can't push to a full stack\n");
                destroy_stack(st);
                exit(EXIT_FAILURE);
        }
}

  
/* the function decrements the stack pointer and returns the element popped */
int pop (struct stack* st)
{
        if (!is_empty(st)) {
                st->stack_pointer--;
                return st->elements[st->stack_pointer + 1];
        }

        else {
                fprintf(stderr, "Can't pop an empty stack\n");
                destroy_stack(st);
                exit(EXIT_FAILURE);
        }
}