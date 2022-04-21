/**
 * @file main.c
 * @brief Ficheiro main
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG1 (STACK *s, char *token)
{
    if (notBit (s, token) || xorBit (s, token) || orBit (s, token) || andBit (s, token) || modulo (s, token) || divisao (s, token) || multiplicacao (s, token) || exponencializacao (s, token) || incrementar (s, token) || decrementar (s, token) || add (s, token) || sub (s, token)) return 1;
    else return 0;
}

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG2 (STACK *s, char *token)
{
    if (intParaChar (s, token) || troca2Topo (s, token) || copiaNesimo (s, token) || popG2 (s, token) || duplicar (s, token) || rodar3 (s, token)) return 1;
    else return 0;
}

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG3 (STACK *s, char *token)
{
    if (menorDosDois (s, token) || maiorDosDois (s, token) || menor (s, token) || maior (s, token) || nao (s, token) || ouShortcut (s, token) || eShortcut (s, token) || buscaPorIndice (s, token) || IfThenElse (s, token)) return 1;
    else return 0;
}

//! Funcao handle principal
int mainHandle (STACK *s, char *token)
{
    if (handleG3 (s, token) || handleG2 (s, token) || handleG1 (s, token) || val (s, token)) return 1;
    else return 0;
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
            mainHandle (s, token);
        }
        mainHandle (s, token);

        for (int i = 1; i <= s -> sp; i++)
        {
            printf ("%d", s -> stack[i]);
        }

        putchar ('\n');
    }

    return 0;
}

