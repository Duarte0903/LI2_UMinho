/**
 * @file parser.c
 * @brief Atribui tipos aos tokens e decide a operação
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <stdio.h>

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG1 (STACK *s, char *token)
{
    int r = 0;
    if (notBit (s, token) || xorBit (s, token) || orBit (s, token) || andBit (s, token) || modulo (s, token) || divisao (s, token) || multiplicacao (s, token) || exponencializacao (s, token) || incrementar (s, token) || decrementar (s, token) || add (s, token) || sub (s, token)) r = 1;
    return r;
}

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG2 (STACK *s, char *token)
{
    int r = 0;
    if (convertParaString (s, token) || convertParaInt (s, token) || lerLinha (s, token) || intParaChar (s, token) || troca2Topo (s, token) || copiaNesimo (s, token) || popG2 (s, token) || duplicar (s, token) || rodar3 (s, token)) r = 1;
    return r;
}

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG3 (STACK *s, char *token)
{
    int r = 0;
    if (menorDosDois (s, token) || maiorDosDois (s, token) || menor (s, token) || maior (s, token) || nao (s, token) || ouShortcut (s, token) || eShortcut (s, token) || buscaPorIndice (s, token) || IfThenElse (s, token)) r = 1;
    return r;
}

//! Se uma operacao der return ao 1, o output sera o resultado dessa operacao
int handleG4 (STACK *s, char *token, int flagArrays)
{
    int r = 0;
    if (fechaArray (s, token, flagArrays) || abreArray (s, token, flagArrays) || lerInput (s, token) || pushEspaco (s, token) || criaString (s, token) || range (s, token)) r = 1;
    return r;
}

//! Funcao handle principal
int mainHandle (STACK *s, char *token, int flagArrays)
{
    int r = 0;
    if (handleG1 (s, token) || handleG2 (s, token) || handleG3 (s, token) || handleG4 (s, token, flagArrays)) r = 1;
    return r;
}

//! Vai atribuir um tipo do enum ao input
void parser (STACK *s, char *token)
{
    char *resto;                                           // CHARs de um token que se encontram imediatamente depois de um valor numerico
    int flagArrays = 0;

    DATA val[26]; 
    valOmissao (val);                                      // Atribui valores as letras maiusculas

    long l = strtol (token, &resto, 10);       
    if (strlen (resto) == 0)                                // Testa se o TOKEN é LONG
    { 
        DATA p = cria_Long (l);                             // Transforma o LONG em DATA
        push (s, p);
    }

    else
    {
        double d = strtod (token, &resto);
        if (strlen (resto) == 0)                           // Testa se o TOKEN é DOUBLE
        {
            DATA p = cria_Double (d);                      // Transforma o DOUBLE em DATA
            push (s, p);
        }

        else 
        {
            if ((strstr ("+-*/()%#&|^~e&e|_;\\@$clifts<>=!?e<e>,[]S{}", token) != NULL)) mainHandle (s, token, flagArrays);       // O TOKEN é igual a um dos operadores
            if (strchr (token, 34) != NULL) criaString (s, token);                                                                // Se o CHAR " ocorre no TOKEN cria uma STRING
            if (capLtr (token) == 0) pushVal (s, token, val);                                                                     // Se o TOKEN for letra maiuscula da push ao valor associado
            if (dots (token) == 0) omissao (s, token, val);                                                                       // Se ocorrem os dois pontos seguidos por letra maiuscula, altera o valor associado a letra
        }
    }
} 

