/**
 * @file conversoe.c
 * @brief Funcoes relativas a conversoes de tipos
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

//! Transforma o numero no topo da stack num char 
/*!
 * input: 79 c 108 c 97 c \n
 * output: Ola
 */
int intParaChar (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "c")==0)
    {
        DATA x = pop (s);
        if (x.tipo == LONG)
        {
            DATA w = cria_Char (x.elem.l);
            push (s, w);
            r = 1;
        }
    }
    return r;
}

//! COnverte o topo da stack para INTEIRO
int convertParaInt (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "i") == 0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            push (s, x);
            r = 1;
        }

        if (x.tipo == DOUBLE)
        {
            push (s, cria_Long (x.elem.d));
            r = 1;
        }

        if (x.tipo == CHAR)
        {
            push (s, cria_Long (x.elem.c));
            r = 1;
        }

        if (x.tipo == STRING)
        {
            push (s, cria_Long (atof (x.elem.str)));
            r = 1;
        }
    }
    return r;
} 

//! Converte o topo da stack para STRING
int convertParaString (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "s") == 0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            char string [20];
            sprintf (string, "%ld", x.elem.l);
            push (s, cria_string (string));
            r = 1;
        }

        if (x.tipo == DOUBLE)
        {
            char string [20];
            sprintf (string, "%g", x.elem.d);
            push (s, cria_string (string));
            r = 1;
        }

        if (x.tipo == CHAR)
        {
            char string [20];
            sprintf (string, "%c", x.elem.c);
            push (s, cria_string (string));
            r = 1;
        }
    }
    return r;
}