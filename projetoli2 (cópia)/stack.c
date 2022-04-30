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

//! Vai buscar um numero ao topo da stack
DATA pop (STACK *s)
{
    DATA x = s -> stack[s -> sp];
    s -> sp--;
    return x; 
}

void pushLong (STACK *s, long elem)
{
    s -> sp++;
    s -> stack[s -> sp].elem.l = elem;
    s -> stack[s -> sp].tipo = LONG;
}

char popLong (STACK *s)
{
    long x = s -> stack[s -> sp -1].elem.l;
    s -> sp--;
    return x;
}

void pushChar (STACK *s, char elem)
{
    s -> sp++;
    s -> stack[s -> sp].elem.c = elem;
    s -> stack[s -> sp].tipo = CHAR;
}

char popChar (STACK *s)
{
    char x = s -> stack[s -> sp -1].elem.c;
    s -> sp--;
    return x;
}