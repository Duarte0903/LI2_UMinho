/**
 * @file main.c
 * @brief Ficheiro main
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//! Funcao main. Obtem o input e invoca a funcao handle para devolver o output
int main ()
{
    STACK *s = new_stack ();

    char linha[BUFSIZ], token[BUFSIZ];

    if (fgets (linha, BUFSIZ, stdin) != NULL)
    {
        while (sscanf (linha, "%s%[^\n]", token, linha) == 2)
        {
            parser (s, token);
        }
        parser (s, token);

        printStack (s);

        putchar ('\n');
    }

    return 0;
}

