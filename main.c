#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int handle (STACK *s, char *token)
{
    if(notBit (s, token) || xorBit (s, token) || orBit (s, token) || andBit (s, token) || modulo (s, token) || divisao (s, token) || multiplicacao (s, token) || exponencializacao (s, token) || incrementar (s, token) || decrementar (s, token) || add (s, token) || sub (s, token) || val (s, token))
        return 1;
    else
        return 0;
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

