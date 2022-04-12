/**
 * @file main.c
 * @brief Ficheiro main
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handle (STACK *s, char *token)
{
    if(notBit (s, token) || xorBit (s, token) || orBit (s, token) || andBit (s, token) || modulo (s, token) || divisao (s, token) || multiplicacao (s, token) || exponencializacao (s, token) || incrementar (s, token) || decrementar (s, token) || add (s, token) || sub (s, token) || val (s, token))
        return 1;
    else
        return 0;
}

//! Funcao main. Obtem o input e invoca a funcao handle para devolver o output
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

