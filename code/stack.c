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

//! Vai buscar um elemento ao topo da stack
int pop (STACK *s)
{
    int x = s -> stack[s -> sp];
    s -> sp--;
    return x; 
}

//!coloca um elemento no topo da stack
void push (STACK *s, char elem)
{
    s -> sp++;
    s -> stack[s -> sp] = elem;
}