/**
 * @file stack.c
 * @brief Operacoes da stack
 * 
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

//! Cria uma nova stack
STACK * new_stack ()
{
    return (STACK *) malloc(sizeof(STACK));
}

// Vai buscar um numero ao topo da stack
DATA pop (STACK *s)
{
    DATA x = s -> pilha[s -> sp];
    s -> sp--;
    return x; 
}

//!Função auxiliar que retira o último elemento do tipo long da stack
long popl (STACK *s)
{
    long x = s -> pilha[s -> sp -1].data.l;
    s -> sp--;
    return x;
}

//!Função auxiliar que retira o último elemento do tipo double da stack
char popd (STACK *s)
{
    long x = s -> pilha[s -> sp -1].data.d;
    s -> sp--;
    return x;
}

//!Função auxiliar que retira o último elemento do tipo char da stack
char popc (STACK *s)
{
    char x = s -> pilha[s -> sp -1].data.c;
    s -> sp--;
    return x;
}

//!Função auxiliar que retira o último elemento do tipo string da stack
char *pops (STACK *s)
{
    char *x = s -> pilha[s -> sp-1].data.str;
    s -> sp--;
    return x;
}


void push (STACK *s, DATA data)
{
    s -> sp++;
    s -> pilha[s -> sp] = data;
}

//!Função auxiliar que coloca um elemento do tipo long na stack
void pushl (STACK *s, long data)
{
    s -> sp++;
    s -> pilha[s -> sp].data.l = data;
    s -> pilha[s -> sp].t = LONG;
}

//!Função auxiliar que coloca um elemento do tipo double na stack
void pushd (STACK *s, double data)
{
    s -> sp++;
    s -> pilha[s -> sp].data.d = data;
    s -> pilha[s -> sp].t = DOUBLE;
}

//!Função auxiliar que coloca um elemento do tipo char na stack
void pushc (STACK *s, char data)
{
    s -> sp++;
    s -> pilha[s -> sp].data.c = data;
    s -> pilha[s -> sp].t = CHAR;
}

//!Função auxiliar que coloca um elemento do tipo string na stack
void pushs (STACK *s, char *data)
{
    s -> sp++;
    s -> pilha[s -> sp].data.str = data;
    s -> pilha[s -> sp].t = STRING;
}

int tipos (STACK *s)
{
    TIPO x = s->pilha [s->sp - 1].t;
    TIPO y = s->pilha [s->sp - 2].t;
    return (x+y);
}

int verifica(STACK *s)
{
    int n = 0;

    TIPO x = s->pilha [s->sp - 1].t;
    TIPO y = s->pilha [s->sp - 2].t;

    if((x == LONG || x == DOUBLE || x == CHAR ) && (y == LONG || y == DOUBLE || y == CHAR)) n = 1;

    return n;
}

DATA top(STACK *s)
{
    DATA P = s->pilha[s->sp-1];
    return P;
}