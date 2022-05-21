/**
 * @file guiao4.c
 * @brief Operacoes do guiao 4
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//! Da push a um espaco (STRING)
int pushEspaco (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "S")==0)
    {
        push (s, cria_string (" "));
        r = 1; 
    }
    return r;
}

//! Da push a uma string
int criaString (STACK *s, char *token)
{
    int r = 0;

    for (unsigned int i = 0; i < strlen(token) - 1; i++)       // Altera o CHAR de cada indice da STRING (Basicamente remove a abertura de aspas)
    {
        token[i] = token[i+1];
    }

    for (int i = 0; i < 2; i++)                                // Vai trocar "fechar aspas" por '\0' marcando um novo fim da STRING
    {
        token[strlen(token)-1] = '\0';
    }

    DATA p = cria_string (token);                              // Transformar a STRING (token sem aspas) em DATA
    push (s, p);

    r = 1;

    return r;
}

//! Da push a um array na stack
/*!
 * @param flagArrays: ponto de paragem para o loop for
 *
 * input: [ 1 2 3 ] \n
 * output: 123
 */
int fechaArray (STACK *s, char *token, int flagArrays)
{
    int r = 0;

    if (strcmp (token, "]") == 0)
    {
        STACK *new = new_stack();

        for (int i = s -> sp; i >= flagArrays; i--)
        {
            DATA x = pop (s);
            push (new, x);
        }

        DATA p = cria_array (new);
        push (s, p);
        flagArrays = 0;
        r = 1;
    }
    return r;
}

//! Marca a abertura do parenteses reto
int abreArray (STACK *s, char *token, int flagArrays)
{
    int r = 0;

    if (strcmp (token, "[") == 0)
    {
        flagArrays += s -> sp;
        r = 1;
    }
    return r;
}

//! Da push aos numeros menores que n / tamanho de STRING ou ARRAY
/*!
 * input: 5 , \n
 * output: 01234 (ARRAY)
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

            STACK *new = new_stack();

            for (int i = range - 1; i >= 0; i--)
            {
                push (new, cria_Long(i));
            }

            DATA p = cria_array (new);
            push (s, p);

            r = 1; 
        }

        if (x.tipo == ARRAY)
        {
            long range = x.elem.arr -> sp + 1;
            push (s, cria_Long (range));

            r = 1;
        }

        if (x.tipo == STRING)
        {
            long range = strlen (x.elem.str);

            push (s, cria_Long (range));

            r = 1;
        }
    }
    return r;
}