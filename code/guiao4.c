/**
 * @file guiao4.c
 * @brief Operacoes do guiao 4
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

//! Da push a uma string FIX !!!
int criaString (STACK *s, char *token)
{
    int r = 0;
    int flag = 0;
    char str[100];

    if (strcmp (token, "\"")==0)
    {
        flag = s -> sp;

        if (strcmp (token, "\"")==0)
        {
            for (int i = flag; i>=0; i--)
            {
                DATA x = pop (s);
                char c = x.elem.c;
                str[i] = c;
            }

            DATA p = cria_string (str);

            push (s, p);
        } 
        r = 1;       
    }
    return r;
}

//! Da push a um array na stack FIX !!!
int criaArray (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "]")==0)
    {
        STACK *arr = new_stack ();

        while (strcmp (token, "[") == 1)
        {
            DATA x = pop (s);
            push (arr, x);
        }

        DATA y = cria_array (arr);

        push (s, y);

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
                push (s, cria_Long(i));
            }

            r = 1; 
        }

        if (x.tipo == ARRAY)
        {
            long range = 0;

            for (int i = x.elem.arr -> sp; i >= 0; i--) range ++;

            push (s, cria_Long (range));

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