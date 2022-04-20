/**
 * @file stack.c
 * @brief Operacoes da stack
 * 
 */

#include <stdlib.h>
#include "stack.h"

//! Cria uma nova stack
STACK * new_stack ()
{
    return (STACK *) malloc(sizeof(STACK));
}

//! Coloca um numero no topo da stack
void push (STACK *s, int elem)
{
    s -> sp++;
    s -> stack[s -> sp] = elem;
}

//! Vai buscar um numero ao topo da stack
int pop (STACK *s)
{
    int ret = s -> stack[s -> sp];
    s -> sp--;
    return ret; 
}