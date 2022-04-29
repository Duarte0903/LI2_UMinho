/**
 * @file stack.c
 * @brief Operacoes da stack
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <stdio.h>

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

//! Transforma um long em DATA
DATA cria_Long (long l)
{
    DATA x;
    x.tipo = LONG;
    x.elem.l = l;
    return x;
}

//! Transforma um double em DATA
DATA cria_Double (double d)
{
    DATA x;
    x.tipo = DOUBLE;
    x.elem.d = d;
    return x;
}

//! Transforma um char em DATA
DATA cria_Char (char c)
{
    DATA x;
    x.tipo = CHAR;
    x.elem.c = c;
    return x;
}

//! Transforma uma string em DATA
DATA cria_string (char *s)
{
    DATA x;
    x.tipo = STRING;
    x.elem.str = (char *)malloc(sizeof(s));
    strcpy(x.elem.str,s);
    return x;
}

//! Da print aos elementos da stack
void printStack (STACK *s)
{
    for (int i = 0; i < s -> sp; i++)
    {
        if (s -> stack[i].tipo == LONG) printf("%ld", s->stack[i].elem.l);
        if (s -> stack[i].tipo == DOUBLE) printf("%f", s->stack[i].elem.d);
        if (s -> stack[i].tipo == CHAR) printf("%c", s->stack[i].elem.c);
    }
}

