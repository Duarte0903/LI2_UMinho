/**
 * @file main.c
 * @brief Ficheiro main
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"


//! Funcao main. Obtem o input e invoca a funcao handle para devolver o output
int main ()
{
    STACK *s = new_stack ();

    char linha[10240];

    assert (fgets(linha, 10240, stdin) != NULL);
    assert (linha[strlen(linha) -1] == '\n');

    int flagMain = 0;

    for (unsigned int i=0; i < strlen(linha)-1; i++)
    {
        if (flagMain == 1)
        {
            if (linha[i] == ' ') linha[i] = '.';
            if (linha[i] == '"') flagMain = 0 ;
        }
        else
        {
            if (linha[i] == '"') flagMain = 1 ;
        }
    }

    parser (linha, s);

    return 0;
}
