#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"

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

int sub (STACK *s, char *token)
{
    if (strcmp (token, "-") == 0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, y - x);
        return 1;
    }
    return 0;
}

int add (STACK *s, char *token)
{
    if (strcmp (token, "+") == 0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, x + y);
        return 1;
    }
    return 0;
}

int val (STACK *s, char *token)
{
    int val;
    sscanf (token, "%d", &val);
    push (s, val);
    return 1;
}

