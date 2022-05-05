/**
 * @file guiao1.c
 * @brief Operacoes do guiao 1
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"

//! Vai buscar um numero a stack. Inverte os bits e devolve o resultado
int notBit (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "~")==0)
    {
        DATA x = pop (s);
        long y = ~(x.elem.l);
        DATA z = cria_Long (y);
        push (s, z);
        r = 1;
    }
    return r;
}

//! Vai buscar dois numeros a stack. Realiza a operacao XOR em todos os bits. Devolve 1 se os dois bits forem diferentes 
int xorBit (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token , "^")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        long z = y.elem.l ^ x.elem.l;
        DATA w = cria_Long (z);
        push (s, w);
        r = 1;
    }
    return r;
}

//! Vai buscar dois numeros a stack. Realiza a operacao OR em todos os bits. Devolve 1 se um dos bits for 1 
int orBit (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "|")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        long z = y.elem.l | x.elem.l;
        DATA w = cria_Long (z); 
        push (s, w);
        r = 1;;
    }
    return r;
}

//! Vai buscar dois numeros a stack. Realiza a operacao AND em todos os bits. Devolve 1 se os dois bits forem 1 
int andBit (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "&")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        long z = y.elem.l & x.elem.l;
        DATA w = cria_Long (z); 
        push (s, w);
        r = 1;
    }
    return r;
}

//! vai buscar dois numeros a stack e coloca no topo o resto da divisao inteira
int modulo (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token , "%")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);

        if (x.tipo == LONG && y.tipo == LONG)
        {
            long z = x.elem.l;
            long w = y.elem.l;
            long r = w%z;
            DATA result = cria_Long (r);
            push (s, result);
            r = 1;
        }
    }
    return r;
}

//! vai buscar dois numeros a stack e coloca no topo a sua divisao
int divisao (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token , "/")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);

        if (x.tipo == LONG && y.tipo == LONG)
        {
            long z = x.elem.l;
            long w = y.elem.l;
            long r = w/z;
            DATA result = cria_Long (r);
            push (s, result);
            r = 1;
        }
        
        if (x.tipo == LONG && y.tipo == DOUBLE) 
        {
            long z = x.elem.l;
            double w = y.elem.d;
            double r = w/z;
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == LONG) 
        {
            double z = x.elem.d;
            long w = y.elem.l;
            double r = w/z;
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == DOUBLE) 
        {
            double z = x.elem.d;
            double w = y.elem.d;
            double r = w/z;
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }
    }
    return r;
}

//! vai buscar dois numeros a stack e coloca no topo o seu produto
int multiplicacao (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "*")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);

    if (x.tipo == LONG && y.tipo == LONG)
        {
            long z = x.elem.l;
            long w = y.elem.l;
            long r = w*z;
            DATA result = cria_Long (r);
            push (s, result);
            r = 1;
        }
        
        if (x.tipo == LONG && y.tipo == DOUBLE) 
        {
            long z = x.elem.l;
            double w = y.elem.d;
            double r = w*z;
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == LONG) 
        {
            double z = x.elem.d;
            long w = y.elem.l;
            double r = w*z;
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == DOUBLE) 
        {
            double z = x.elem.d;
            double w = y.elem.d;
            double r = w*z;
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }

        if (x.tipo == ARRAY && y.tipo == LONG)
        {
            for (int i = y.elem.l; i>0; i--)
            {
                push (s, x);
            }
            r = 1;
        }

        if (x.tipo == ARRAY && y.tipo == LONG)
        {
            for (int i = y.elem.l; i>0; i--)
            {
                push (s, x);
            }
            r = 1;
        }
    }
    return r;
}

//! vai buscar dois numeros (x e y) a stack e coloca do topo y^x
int exponencializacao (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "#") == 0)
    {
        DATA x = pop (s);
        DATA y = pop (s);

        if (x.tipo == LONG && y.tipo == LONG)
        {
            long z = x.elem.l;
            long w = y.elem.l;
            long r = pow (w,z);
            DATA result = cria_Long (r);
            push (s, result);
            r = 1;
        }
        
        if (x.tipo == LONG && y.tipo == DOUBLE) 
        {
            long z = x.elem.l;
            double w = y.elem.d;
            double r = pow (w,z);
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == LONG) 
        {
            double z = x.elem.d;
            long w = y.elem.l;
            double r = pow (w,z);
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == DOUBLE) 
        {
            double z = x.elem.d;
            double w = y.elem.d;
            double r = pow (w,z);
            DATA result = cria_Double (r);
            push (s, result);
            r = 1;
        }
    }
    return r;
}

//! vai buscar um numero a stack e coloca no topo a soma do mesmo por um 
int incrementar (STACK *s, char *token)
{
    int r = 0;;
    if (strcmp (token, ")") == 0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            int y = x.elem.l + 1;
            DATA w = cria_Long (y);
            push (s, w);
            r = 1;
        }

         if (x.tipo == DOUBLE)
        {
            double y = x.elem.d + 1;
            DATA w = cria_Double (y);
            push (s, w);
            r = 1;
        }
    }
    return r;
}

//! vai buscar um numero a stack e coloca no topo a subtracao do mesmo por um 
int decrementar (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "(") == 0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            int y = x.elem.l - 1;
            DATA w = cria_Long (y);
            push (s, w);
            r = 1;
        }

         if (x.tipo == DOUBLE)
        {
            double y = x.elem.d - 1;
            DATA w = cria_Double (y);
            push (s, w);
            r = 1;
        }
    }
    return r;
}

//! vai buscar dois numeros a stack e coloca no topo a sua diferenca
int sub (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "-") == 0)
    {
        DATA x = pop (s);
        DATA y = pop (s);

        if (x.tipo == LONG && y.tipo == LONG) 
        {
            long z;
            z = y.elem.l - x.elem.l;
            DATA w = cria_Long (z);
            push (s, w);
            r = 1;
        }

        if (x.tipo == LONG && y.tipo == DOUBLE) 
        {
            double z;
            z = y.elem.l - x.elem.d;
            DATA w = cria_Double (z);
            push (s, w);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == LONG) 
        {
            double z;
            z = y.elem.d - x.elem.l;
            DATA w = cria_Double (z);
            push (s, w);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == DOUBLE) 
        {
            double z;
            z = y.elem.d - x.elem.d;
            DATA w = cria_Double (z);
            push (s, w);
            r = 1;
        }
    }
    return r;
}

//! vai buscar dois numeros a stack e coloca no topo a sua soma
int add (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "+") == 0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        
        if (x.tipo == LONG && y.tipo == LONG) 
        {
            long z;
            z = x.elem.l + y.elem.l;
            DATA w = cria_Long (z);
            push (s, w);
            r = 1;
        }

        if (x.tipo == LONG && y.tipo == DOUBLE) 
        {
            double z;
            z = x.elem.l + y.elem.d;
            DATA w = cria_Double (z);
            push (s, w);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == LONG) 
        {
            double z;
            z = x.elem.d + y.elem.l;
            DATA w = cria_Double (z);
            push (s, w);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == DOUBLE) 
        {
            double z;
            z = x.elem.d + y.elem.d;
            DATA w = cria_Double (z);
            push (s, w);
            r = 1;
        }

        if (x.tipo == ARRAY && y.tipo == DOUBLE)
        {
            push (x.elem.arr, y);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == ARRAY)
        {
            push (y.elem.arr, x);
            r = 1;
        }

        if (x.tipo == ARRAY && y.tipo == LONG)
        {
            push (x.elem.arr, y);
            r = 1;
        }

        if (x.tipo == LONG && y.tipo == ARRAY)
        {
            push (y.elem.arr, x);
            r = 1;
        }

        if (x.tipo == ARRAY && y.tipo == ARRAY)
        {
            while (y.elem.arr != NULL)
            {
                DATA x = pop (y.elem.arr);
                push (x.elem.arr, x);
            }
            r = 1;
        }
    }
    return r;
}

