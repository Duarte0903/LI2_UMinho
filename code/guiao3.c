/**
 * @file guiao3.c
 * @brief Operacoes do guiao 3
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

//! Da push a 11
int capB (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "B")==0)
    {
        long x = 11;
        DATA y = cria_Long (x);
        push (s, y);
        r = 1;
    }
    return r;
}

//! Da push a 10
int capA (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "A")==0)
    {
        long x = 10;
        DATA y = cria_Long (x);
        push (s, y);
        r = 1;
    }
    return r;
}

//! Coloca no topo da stack o menor de dois numeros
int menorDosDois (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "e<")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);    
        if (x.elem.d < y.elem.d) push (s,x);
        else push (s, y);
        r = 1;
    }
    return r;
}

//! Coloca no topo da stack o maior de dois numeros
int maiorDosDois (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "e>")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        if (x.elem.d > y.elem.d) push (s, x);
        else push (s, y);
        r = 1;
    }
    return r;
}

//! Se um numero e menor que outro coloca 1 na strack. Caso contrario 0
int menor (STACK *s, char *token)
{
    int r = 0;
    if (strcmp (token, "<")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);

        if (x.tipo == LONG && y.tipo == LONG)
        {
            if (y.elem.l < x.elem.l) push (s, cria_Long (1));
            else push (s, cria_Long (0));
            r = 1;
        }

        if ((x.tipo == LONG && y.tipo == DOUBLE) || (x.tipo == DOUBLE && y.tipo == LONG))
        {
            if (y.elem.l < x.elem.l) push (s, cria_Long (1));
            else push (s, cria_Long (0));\
            r = 1;
        }
        
        if (x.tipo == DOUBLE && y.tipo == DOUBLE)
        {
            if (y.elem.d < x.elem.d) push (s, cria_Long (1));
            else push (s, cria_Long (0));
            r = 1;
        }
    }
    return r;
}

//! Se um numero e maior que outro coloca 1 na strack. Caso contrario 0
int maior (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, ">")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);

        if (x.tipo == LONG && y.tipo == LONG)
        {
            if (y.elem.l > x.elem.l) push (s, cria_Long (1));
            else push (s, cria_Long (0));
            r = 1;
        }

        if ((x.tipo == LONG && y.tipo == DOUBLE) || (x.tipo == DOUBLE && y.tipo == LONG))
        {
            if (y.elem.l > x.elem.l) push (s, cria_Long (1));
            else push (s, cria_Long (0));
            r = 1;
        }
        
        if (x.tipo == DOUBLE && y.tipo == DOUBLE)
        {
            if (y.elem.d > x.elem.d) push (s, cria_Long (1));
            else push (s, cria_Long (0));
            r = 1;
        }
    }
    return r;
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
    int r = 0;

    if (strcmp (token, "!")==0)
    {
        DATA x = pop (s);
        if (x.elem.l == 0) push (s, cria_Long (1));
        else push (s, x);
        r = 1;
    }
    return r;
}

//! Operador logico "ou"
/*!
 * input: 0 3 e| \n
 * output: 0
 */
int ouShortcut (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "e|")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        if (y.elem.l == 0 && x.elem.l != 0)
        {
            push (s, x); 
            r = 1;
        }

        if (x.elem.l == 0 && y.elem.l != 0) 
        {
            push (s, y); 
            r = 1;
        }

        if (x.elem.l == 1 && y.elem.l != 0) 
        {
            push (s, cria_Long (1)); 
            r = 1;
        }

        if (y.elem.l == 1 && x.elem.l != 0) 
        {
            push (s, cria_Long (1)); 
            r = 1;
        }
    }
    return r;
}

//! Operador logico "e"
/*!
 * input: 1 3 e& \n
 * output: 3
 */
int eShortcut (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "e&")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        if (y.elem.l == 0 || x.elem.l == 0) 
        {
            push (s, cria_Long (0));
            r = 1;
        }

        if (x.elem.l == 1) 
        {
            push (s, y); 
            r = 1;
        }

        if (y.elem.l == 1) 
        {
            push (s, x); 
            r = 1;
        }
    }
    return r;
}

//! Procura o indice de um numero
/*!
 * input: 3 3 = \n
 * output: 1
 */
int buscaPorIndice (STACK *s, char *token) 
{
    int r = 0;

    if (strcmp (token, "=")==0)
    {
        int i, flag = 0, index;
        DATA x = pop (s);
        long indice = x.elem.l;

        for (i = s -> sp; i > 0; i--)
        {
            if (s -> stack[i].elem.l == indice)
            {
                pop (s);
                index = i;
                flag = 1;
            }
            else pop (s);
        }

        if (flag != 0) 
        {
            push (s, cria_Long (index)); 
            r = 1;
        }

        else 
        {
            push (s, cria_Long (0)); 
            r = 1;
        }
    }
    return r;
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
    int r = 0;

    if (strcmp (token, "?")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        DATA z = pop (s);
        if (z.elem.l != 0) push (s, y);
        else push (s, x);
        r = 1;
    }
    return r;
}