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
DATA pop (STACK *s)
{
    DATA x = s -> stack[s -> sp];
    s -> sp--;
    return x; 
}

//!coloca um elemento no topo da stack
void push (STACK *s, DATA elem)
{
    s -> sp++;
    s -> stack[s -> sp] = elem;
}

DATA cria_char(char c)
{
    DATA x = (DATA)calloc(sizeof(DATA));
    x.tipo = CHAR;
    x.tipo.c = c;
    return x
}

DATA cria_string(char *s)
{
    DATA x = (DATA)calloc(sizeof(DATA));
    x.tipo = STRING;
    x.tipo.s = strdup(s);
    return x
}