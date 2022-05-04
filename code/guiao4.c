/**
 * @file guiao4.c
 * @brief Operacoes do guiao 4
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

int criaArray (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "[")==0)
    {
        
        r = 1;
    }
    return r;
}


//! D push ao numeros menores que n
/*!
 * input: 5 , \n
 * output: 01234
 */
int range (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, ",")==0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            long range  = x.elem.l;

            for (int i = 0; i < range; i++)
            {
                push (s, cria_Long(i));
            }

            r = 1; 
        }

        if (x.tipo == ARRAY_INT)
        {
            
            r = 1;
        }
    }
    return r;
}