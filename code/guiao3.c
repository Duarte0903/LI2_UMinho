/**
 * @file guiao3.c
 * @brief Operacoes do guiao 3
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

//! Procura o indice de um numero
/*!
 * input: 3 3 = \n
 * output: 1
 */
int buscaPorIndice (STACK *s, char *token)
{
    if (strcmp (token, "=")==0)
    {
        int i = s -> sp - 1;
        int x = pop (s); 
        while (i >= 0)
        {
            if (s -> stack[i] == x) push (s, i);
            else i --;
        }
        return 1;
    }
    return 0;
}

int IfThenElse (STACK *s, char *token)
{
    if (strcmp (token, "?")==0)
    {
        int x = pop (s);
        int y = pop (s);
        int z = pop (s);
        if (z == 1) push (s, y);
        else push (s, x);
        return 1;
    }
    return 0;
}