/**
 * @file guiao1.c
 * @brief Operacoes do guiao 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include <math.h>

//! Vai buscar um numero a stack. Inverte os bits e devolve o resultado
int notBit (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "~")==0)
    {
        DATA x = pop (s);

        if (x.tipo == LONG)
        {
            long y = ~(x.elem.l);
            DATA z = cria_Long (y);
            push (s, z);
            r = 1;
        }

        if (x.tipo == ARRAY)
        {
            int i;
            int n = x.elem.arr -> sp;

            DATA arr[n];

            for (i = 0; i <= n; i++)
            {
                DATA p = pop (x.elem.arr);
                arr[i] = p;
            }

            for (i = n; i >= 0; i--)
            {
                push (s, arr[i]);
            }

            r = 1;
        }
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

        if (x.tipo ==STRING && y.tipo == STRING)
        {
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

        if (x.tipo == LONG && y.tipo == ARRAY)
        {

            for (int i = x.elem.l; i>0; i--)
            {
                push (s, y);
            }

            r = 1;
        }

        if (x.tipo == LONG && y.tipo == STRING)
        {
            int len = strlen (y.elem.str);

            y.elem.str = realloc (y.elem.str, (strlen (y.elem.str) + 1) * sizeof(char));

            for (int i = 0; i < (x.elem.l-1)*len; i++)
            {
                y.elem.str[len+i] = y.elem.str[i];
            }

            push (s, y);
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

        if (x.tipo == ARRAY)
        {
            STACK *aux = x.elem.arr;
            DATA y = aux -> stack[0];

            for (int i=0; i < aux -> sp; i++)
            {
                aux -> stack[i] = aux -> stack[i+1];
            }

            aux -> sp--;
            push (s, cria_array (aux));
            push (s, y);
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
//! Concatena elementos com arrays e arrays com arrays
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

        if (x.tipo == CHAR && y.tipo == CHAR)
        {
            char *str = malloc (3*sizeof(char));
            str[0] = y.elem.c;
            str[1] = x.elem.c;
            str[2] = '\0';
            push (s, cria_string (str));
            r = 1;
        }

        if (x.tipo == STRING && y.tipo == STRING)  // TODO FIX !!!
        {
            unsigned int i;
            unsigned int len1 = strlen (y.elem.str);
            unsigned int len2 = strlen (x.elem.str);
            char *str = calloc (len1 + len2 + 1, sizeof (char));

            for (i = 0; i < len1; i++)
            {
                str[i] = y.elem.str[i];
            }

            for (i = len1; i < len2 + len1; i++)
            {
                str[i] = x.elem.str[i-len1];
            }
            str[i] = '\0';

            DATA p = cria_string (str);

            push (s, p);

            r = 1;
        }

        if (x.tipo == CHAR && y.tipo == STRING)
        {
            char *str = malloc (2*sizeof(char));
            str[0] = x.elem.c;
            str[1] = '\0';
            y.elem.str = realloc (y.elem.str, 5*sizeof(char));
            strcat (y.elem.str, str);
            push (s, y);
            free(str);
            r=1;
        }

        if (y.tipo == CHAR && x.tipo == STRING)
        {
            int len = strlen (x.elem.str);
            char *str = malloc (2*sizeof(char) + len);
            str[0] = y.elem.c;
            str[1] = '\0';
            strcat(str, x.elem.str);
            push (s, cria_string (str));
            free (x.elem.str);
            r=1;
        }

        if (x.tipo == ARRAY && y.tipo == ARRAY)
        {
            cpyArr (x.elem.arr, x.elem.arr);
            cpyArr (y.elem.arr, x.elem.arr);
            push (s, y);
            r = 1;
        }
    }
    return r;
}

