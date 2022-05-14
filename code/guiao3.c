/**
 * @file guiao3.c
 * @brief Operacoes do guiao 3
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

//! Identifica os dois pontos
int dots (char *token)
{
    char c = token[0];
    int r;

    if (c == ':') r = 0;
    else r = 1;

    return r;
}

//! Subtitui um valor de omissao pelo valor no topo da stack
void omissao (STACK *s, char *token, DATA valOmissao[26])
{
    char x = token[1];
    DATA d = s -> stack[s -> sp];
    valOmissao[x-65] = d;
}

//! Identifica uma letra maiuscula
int capLtr (char *token)
{
    char c = token[0];
    int r;

    if (c <= 90 && c >= 65) r = 0;
    else r = 1;

    return r;
}

//! Da push ao valor de omissao
void pushVal (STACK *s, char *token, DATA valOmissao[26])
{
    char c = token[0];
    int i = c - 65;
    DATA p = valOmissao[i];
    push (s, p);
}

//! Coloca no topo da stack o menor de dois numeros
int menorDosDois (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "e<")==0)
    {
        DATA x = pop (s);
        DATA y = pop (s);
        
        if (x.tipo == LONG && y.tipo == LONG)
        {
            if (x.elem.l < y.elem.l) push (s,x);
            else push (s, y);
            r = 1;
        }

        if (x.tipo == DOUBLE && y.tipo == DOUBLE)
        {
            if (x.elem.d < y.elem.d) push (s,x);
            else push (s, y);
            r = 1;
        }

        if (x.tipo == STRING && y.tipo == STRING)
        {
            if (strlen (x.elem.str) <= strlen (y.elem.str)) push (s, x);
            else push (s, y);
            r = 1;
        }
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

        if (x.tipo == LONG && y.tipo == LONG)
        {
            if (x.elem.l > y.elem.l) push (s, x);
            else push (s, y);
            r = 1;
        }
        
        if (x.tipo == DOUBLE && y.tipo == DOUBLE)
        {
            if (x.elem.d > y.elem.d) push (s, x);
            else push (s, y);
            r = 1;
        }

        if (x.tipo == STRING && y.tipo == STRING)
        {
            if (strlen (x.elem.str) > strlen (y.elem.str)) push (s, x);
            else push (s, y);
            r = 1;
        }
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

        if (x.tipo == STRING && y.tipo == STRING)
        {
            if (strlen (y.elem.str) < strlen (x.elem.str)) push (s, cria_Long (1));
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

        if (x.tipo == LONG && y.tipo == ARRAY)
        {
            int n = x.elem.l;
            STACK *new = new_stack();

            for (int i = y.elem.arr -> sp; i >= 0; i--)
            {
                if (i>=(n-1))
                {
                    DATA x = pop (y.elem.arr);
                    push (new, x);
                }
            }

            DATA p = cria_array (new);

            push (s, p);

            r = 1;
        }

        if (x.tipo == STRING && y.tipo == STRING)
        {
            if (strlen (y.elem.str) >= strlen (x.elem.str)) push (s, cria_Long (1));
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
        if (x.tipo == LONG && x.elem.l == 0) push (s, cria_Long (1));
        if (x.tipo == LONG && x.elem.l != 0) push (s, cria_Long (0));
        if (x.tipo == DOUBLE && x.elem.d != 0) push (s, cria_Long (0));
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
        DATA y = pop (s);

        if (x.tipo == LONG)
        {
            long indice = x.elem.l;

            push (s, y);

            for (i = s -> sp; i >= 0; i--)
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
                push (s, cria_Long (index+1)); 
                r = 1;
            }

            else 
            {
                push (s, cria_Long (0)); 
                r = 1;
            }
        }

        if (x.tipo == DOUBLE)
        {
            double indice = x.elem.d;

            push (s, y);

            for (i = s -> sp; i >= 0; i--)
            {
                if (s -> stack[i].elem.d == indice)
                {
                    pop (s);
                    index = i;
                    flag = 1;
                }
                else pop (s);
            }

            if (flag != 0) 
            {
                push (s, cria_Long (index+1)); 
                r = 1;
            }

            else 
            {
                push (s, cria_Long (0)); 
                r = 1;
            }
        }

        if (y.tipo == ARRAY && x.tipo == LONG)
        {
            long indice = x.elem.l;

            DATA indexArr;

            for (i = y.elem.arr -> sp; i >= 0; i--)
            {
                if (y.elem.arr -> sp == indice + 1)
                {
                    pop (y.elem.arr);
                    indexArr = y.elem.arr -> stack[y.elem.arr -> sp];
                    flag = 1;
                }
                else pop (y.elem.arr);
            }

            if (flag != 0) 
            {
                push (s, indexArr); 
                r = 1;
            }

            else 
            {
                push (s, cria_Long (0)); 
                r = 1;
            }
        }
    
        if (x.tipo == STRING)
        {
            char *busca = x.elem.str;

            push (s, y);

            for (i = s -> sp; i >= 0; i--)
            {
                if (strcmp (s -> stack[i].elem.str, busca) == 0)
                {
                    pop (s);
                    index = i;
                    flag = 1;
                }
                else pop (s);
            }

            if (flag != 0) 
            {
                push (s, cria_Long (index+1)); 
                r = 1;
            }

            else 
            {
                push (s, cria_Long (0)); 
                r = 1;
            }
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