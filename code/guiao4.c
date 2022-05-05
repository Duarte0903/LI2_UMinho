/**
 * @file guiao4.c
 * @brief Operacoes do guiao 4
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//! Da push a uma string FIX !!!
int criaString (STACK *s, char *token)
{
    int r = 0;

    if (strchr (token, 34) != NULL && strlen (token) > 1)
    {
        DATA x = cria_string (token);
        push (s, x);
        r = 1;
    }
    return r;
}

//! Da push a um array na stack FIX !!!
int criaArray (STACK *s, char *token, int flag)
{
    int r = 0;

    if (strcmp (token, "]")==0)
    {
        STACK *new = new_stack();

        for (int i = s -> sp; i>=flag; i--)
        {
            DATA x = pop (s);
            push (new, x);
        }

        DATA p = cria_array (new);
        push (s, p);

        flag = 0;
        r = 1; 
    }
    return r;
}

int abreParReto (STACK *s, char *token, int flag)
{
    int r = 0;

    if (strcmp (token, "[")==0)
    {
        flag += s -> sp;

        r = 1;
    }
    return r;
}

//! Da push aos numeros menores que n
/*!
 * input: 5 , \n
 * output: 01234
 * 
 * input: [ 1 2 3 ] \n
 * output: 3
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
                push (s, cria_Long(i));     // PUSH a LONG ou ARRAY ??
            }

            r = 1; 
        }

        if (x.tipo == ARRAY)
        {
            

            r = 1;
        }

        if (x.tipo == STRING)
        {
            long range = strlen (x.elem.str);

            DATA p = cria_Long (range);

            push (s, p);

            r = 1;
        }
    }
    return r;
}