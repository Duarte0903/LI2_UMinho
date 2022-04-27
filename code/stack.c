/**
 * @file stack.c
 * @brief Operacoes da stack
 * 
 */

#include <stdlib.h>
#include <string.h>
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

DATA cria_Long (long l)
{
    DATA x;
    x.tipo = LONG;
    x.elem.l = l;
    return x;
}

DATA cria_Double (double d)
{
    DATA x;
    x.tipo = DOUBLE;
    x.elem.d = d;
    return x;
}

DATA cria_char (char c)
{
    DATA x;
    x.tipo = CHAR;
    x.elem.c = c;
    return x;
}

DATA cria_string (char *s)
{
    DATA x;
    x.tipo = STRING;
    x.elem.str = (char *)malloc(sizeof(s));
    strcpy(x.elem.str,s);
    return x;
}

