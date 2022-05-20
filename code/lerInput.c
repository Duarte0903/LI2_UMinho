/**
 * @file lerInput.c
 * @brief Funcoes relativas a leitura do input
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include <assert.h>

//! Ler linha
int lerLinha (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "l") == 0)
    {
        char *str1 = malloc (10240 * sizeof(char));

        assert (fgets(str1, 10240, stdin) != NULL);

        int x = strlen(str1);

        char *str2 = malloc ((x+1) * sizeof(char));

        strcpy(str2,str1);

        push (s, cria_string (str2));

        free(str1);                                        /*!< Libertar o espaco de str1 */

        r = 1;
    }
    return r;
}

//! Le todo o input e tansforma-o numa STRING
/*!
 * Guarda o input de uma linha em str1
 * Depois de ler a linha passa a STRING lida para str2 e le a proxima
 * Se str1[0] == '\n' para o loop 
 * Finalmente da push a STRING guardada em str2
 */
int lerInput (STACK *s, char *token)
{
    int r = 0;

    if (strcmp (token, "t") == 0)
    {
        char *str1 = malloc (10240*sizeof(char));
        char *str2 = malloc (10240*sizeof(char));

        while (fgets(str1, 10240, stdin) && str1[0] != '\n')
        {
            strcat(str2, str1);
        }

        push (s, cria_string (str2));
        r = 1; 
    }
    return r;
}