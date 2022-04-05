#include <stdlib.h>
#include "stack.h"

STACK * new_stack ()
{
    return (STACK *) malloc(sizeof(STACK));
}

void push (STACK *s, int elem)
{
    s -> sp++;
    s -> stack[s -> sp] = elem;
}

int pop (STACK *s)
{
    int ret = s -> stack[s -> sp];
    s -> sp--;
    return ret; 
}