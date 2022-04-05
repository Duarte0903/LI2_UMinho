#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int sub (STACK *s, char *token)
{
    if (strcmp (token, "-") == 0)
    {
        int x = pop (s);
        int y = pop (s);
        push (s, x - y);
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

void handle (STACK *s, char *token)
{
    add (s, token) || sub (s, token) || val (s, token);
}

int main ()
{
    STACK *s = new_stack ();

    char linha[BUFSIZ], token[BUFSIZ];

    if (fgets (linha, BUFSIZ, stdin) != NULL)
    {
        while (sscanf (linha, "%s%[^\n]", token, linha) == 2)
        {
            handle (s, token);
        }
        handle (s, token);

        for (int i = 1; i <= s -> sp; i++)
        {
            printf ("%d", s -> stack[i]);
        }

        putchar ('\n');
    }

    return 0;
}

