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
    if (strcmp (token, "~")==0)
    {
        int x = pop (s);
        push (s, ~x);
        return 1;
    }
    return 0;
}

//! Vai buscar dois numeros a stack. Realiza a operacao XOR em todos os bits. Devolve 1 se os dois bits forem diferentes 
int xorBit (STACK *s, char *token)
{
    if (strcmp (token , "^")==0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, y ^ x);
        return 1;
    }
    return 0;
}

//! Vai buscar dois numeros a stack. Realiza a operacao OR em todos os bits. Devolve 1 se um dos bits for 1 
int orBit (STACK *s, char *token)
{
    if (strcmp (token, "|")==0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, y | x);
        return 1;
    }
    return 0;
}

//! Vai buscar dois numeros a stack. Realiza a operacao AND em todos os bits. Devolve 1 se os dois bits forem 1 
int andBit (STACK *s, char *token)
{
    if (strcmp (token, "&")==0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, y & x);
        return 1;
    }
    return 0;
}

//! vai buscar dois numeros a stack e coloca no topo o resto da divisao inteira
int modulo (STACK *s, char *token)
{
    if (strcmp (token , "%")==0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, y % x);
        return 1;
    }
    return 0;
}

//! vai buscar dois numeros a stack e coloca no topo a sua divisao
int divisao (STACK *s, char *token)
{
    if (strcmp (token , "/")==0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, y / x);
        return 1;
    }
    return 0;
}

//! vai buscar dois numeros a stack e coloca no topo o seu produto
int multiplicacao (STACK *s, char *token)
{
    if (strcmp (token, "*")==0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, y * x);
        return 1;
    }
    return 0;
}

//! vai buscar dois numeros (x e y) a stack e coloca do topo y^x
int exponencializacao (STACK *s, char *token)
{
    if (strcmp (token, "#") == 0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, pow (y, x));
        return 1;
    }
    return 0;
}

//! vai buscar um numero a stack e coloca no topo a soma do mesmo por um 
int incrementar (STACK *s, char *token)
{
    if (strcmp (token, ")") == 0)
    {
        int x = pop (s);
        push (s, x+1);
        return 1;
    }
    return 0;
}

//! vai buscar um numero a stack e coloca no topo a subtracao do mesmo por um 
int decrementar (STACK *s, char *token)
{
    if (strcmp (token, "(") == 0)
    {
        int x = pop (s);
        push (s, x-1);
        return 1;
    }
    return 0;
}

//! vai buscar dois numeros a stack e coloca no topo a sua diferenca
int sub (STACK *s, char *token)
{
    if (strcmp (token, "-") == 0)
    {
        int x = popLong (s);
        int y = popLong (s);
        push (s, y - x);
        return 1;
    }
    return 0;
}

//! vai buscar dois numeros a stack e coloca no topo a sua soma
int add (STACK *s, char *token)
{
    if (strcmp (token, "+") == 0)
    {
        int x = popLong (s);
        int y = popLong (s);
        push (s, x + y);
        return 1;
    }
    return 0;
}


//! Devolve o valor se nao forem realizadas operacoes
int val (STACK *s, char *token)
{
    DATA val;
    sscanf (token, "%d", &val);
    push (s, val);
    return 1;
}

