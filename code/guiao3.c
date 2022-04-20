/**
 * @file guiao3.c
 * @brief Operacoes do guiao 3
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

//! Coloca no topo da stack o menor de dois numeros
int menorDosDois (STACK *s, char *token)
{
    if (strcmp (token, "e<")==0)
    {
        int x = pop (s);
        int y = pop (s);
        if (y<x) push (s, y);
        else push (s, x);
        return 1;
    }
    return 0;
}

//! Coloca no topo da stack o maior de dois numeros
int maiorDosDois (STACK *s, char *token)
{
    if (strcmp (token, "e>")==0)
    {
        int x = pop (s);
        int y = pop (s);
        if (y>x) push (s, y);
        else push (s, x);
        return 1;
    }
    return 0;
}

//! Se um numero e menor que outro coloca 1 na strack. Caso contrario 0
int menor (STACK *s, char *token)
{
    if (strcmp (token, "<")==0)
    {
        int x = pop (s);
        int y = pop (s);
        if (y<x) push (s, 1);
        else push (s, 0);
        return 1;
    }
    return 0;
}

//! Se um numero e maior que outro coloca 1 na strack. Caso contrario 0
int maior (STACK *s, char *token)
{
    if (strcmp (token, ">")==0)
    {
        int x = pop (s);
        int y = pop (s);
        if (y>x) push (s, 1);
        else push (s, 0);
        return 1;
    }
    return 0;
}

/*!
 * input: 0 ! \n
 * output: 1
 * 
 * input: 1 ! \n
 * output 0
 */
int nao (STACK *s, char *token)
{
    if (strcmp (token, "!")==0)
    {
        int x = pop (s);
        if (x == 1) push (s, 0);
        else push (s, 1);
        return 1;
    }
    return 0;
}

//! Operador logico "ou"
/*!
 * input: 0 3 e| \n
 * output: 0
 */
int ouShortcut (STACK *s, char *token)
{
    if (strcmp (token, "e|")==0)
    {
        int x = pop (s);
        int y = pop (s);
        if (y == 0 && x == 0) push (s, 0);
        if (y==0) push (s, x);
        if (x==0) push (s, y);
        if (x==1 || y==1) push (s, 1);
        return 1;
    }
    return 0;
}

//! Operador logico "e"
/*!
 * input: 1 3 e& \n
 * output: 3
 */
int eShortcut (STACK *s, char *token)
{
    if (strcmp (token, "e&")==0)
    {
        int x = pop (s);
        int y = pop (s);
        if (y == 0 || x==0) push (s, 0);
        if (x==1) push (s, y);
        if (y==1) push (s, x);
        return 1;
    }
    return 0;
}

//! Procura o indice de um numero
/*!
 * input: 3 3 = \n
 * output: 1
 */
int buscaPorIndice (STACK *s, char *token)  // FIX !!!
{
    if (strcmp (token, "=")==0)
    {
        int i, flag = 0, index;
        int x = pop (s);

        for (i = s -> sp; i > 0; i--)
        {
            if (s -> stack[i] == x)
            {
                pop (s);
                index = i;
                flag = 1;
            }
            else pop (s);
        }

        if (flag != 0) push (s, index);
        else push (s, 0);

        return 1;
    }
    return 0;
}

//! IF x diferente de zero THEN y ELSE z
/*!
 * input: 1 2 3 ? \n
 * output: 2
 * 
 * input: 0 2 3 \n
 * output: 3
 */
int IfThenElse (STACK *s, char *token)
{
    if (strcmp (token, "?")==0)
    {
        int x = pop (s);
        int y = pop (s);
        int z = pop (s);
        if (z != 0) push (s, y);
        else push (s, x);
        return 1;
    }
    return 0;
}