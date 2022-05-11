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
    STACK * novo = (STACK *) malloc(sizeof(STACK));
    novo->sp = -1;
    return novo;
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
    strcpy (x.elem.str,s);
    return x;
}

//! Transfere elementos entre arrays
void cpyArr (STACK *a1, STACK *a2)
{
    for (int i = a1 -> sp; i >= 0; i--)
    {
        DATA x = pop (a1);
        push (a2, x);
    }
}

//! Transforma um array em DATA
DATA cria_array (STACK *arr)
{
    DATA x;
    x.tipo = ARRAY;
    x.elem.arr = new_stack();
    cpyArr (arr, x.elem.arr);
    return x;
}

DATA cria_bloco (STACK *bloco)
{
    DATA x;
    x.tipo = BLOCO;
    x.elem.bloc = bloco;
    return x;
}

void printBloco (STACK *s)
{
    int i;

    printf("{ ");

    for (i = 0; i < s -> sp; i++)
    {
        printDATA (s -> stack[i]);
        putchar(' ');
    }
    printf("}");
}

void valOmissao (DATA *variaveis)
{
    int i=10;
    for (char a='A'; a<='F'; a++, i++)
    {
        variaveis[a-65].tipo = LONG;
        variaveis[a-65].elem.l = i;
    }

    for (char a='X', i=0; a<='Z'; a++, i++)
    {
        variaveis[a-65].tipo = LONG;
        variaveis[a-65].elem.l = i;
    }

    variaveis['S'-65].tipo = CHAR;
    variaveis['S'-65].elem.c =' ';
    variaveis['N'-65].tipo = CHAR;
    variaveis['N'-65].elem.c = '\n';
}

void printDATA (DATA x)
{
        if (x.tipo == LONG) printf("%ld", x.elem.l);
        if (x.tipo == DOUBLE) printf("%g", x.elem.d);
        if (x.tipo == CHAR) printf("%c", x.elem.c);
        if (x.tipo == STRING) printf ("%s", x.elem.str);
        if (x.tipo == ARRAY) printStack (x.elem.arr);
}

//! Da print aos elementos da stack
void printStack (STACK *s)
{
    for (int i = 0; i <= s -> sp; i++)
    {
        if (s -> stack[i].tipo == LONG) printf("%ld", s -> stack[i].elem.l);
        if (s -> stack[i].tipo == DOUBLE) printf("%g", s -> stack[i].elem.d);
        if (s -> stack[i].tipo == CHAR) printf("%c", s -> stack[i].elem.c);
        if (s -> stack[i].tipo == STRING) printf ("%s", s -> stack[i].elem.str);
        if (s -> stack[i].tipo == ARRAY) printStack (s -> stack[i].elem.arr);
        if (s -> stack[i].tipo == BLOCO) printBloco (s -> stack[i].elem.bloc);
    }
}

