/**
 * @file guiao2.c
 * @brief Operacoes do guiao 2
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

//! Trocar os dois elementos do topo da stack
int troca2Topo (STACK *s, char *token)
{
    if (strcmp (token, "'\'")==0)
    {

    }
    return 0;
}

//! Copia n-ésimo elemento para o topo da stack (0 e o topo da stack)
int copiaNesimo (STACK *s, char *token)
{
    if (strcmp (token, "$")==0)
    {
        
    }
    return 0;
}

int popG2 (STACK *s, char *token)
{
    if (strcmp (token, ";")==0)
    {
        int x = pop (s);
        push (s, x);
        return 1;
    }
    return 0;
}

//! Multiplica um numero por 2 (duplica)
/*!
 * input: 2 _
 * output: 4
 * 
 * input: 1 2 _
 * output: 24 
 */
int duplicar (STACK *s, char *token)
{
    if (strcmp (token, "_")==0)
    {
        int x = pop (s);
        push (s, 2*x);
        return 1;
    }
    return 0;
}

//! roda os 3 elementos no topo da stack
/*!
 *  input: 1 2 3 @
 *  output: 231
 */
int rodar3 (STACK *s, char *token)
{
    if (strcmp (token, "@")==0)
    {
        int x = pop (s);
        int y = pop (s);
        int z = pop (s);
        int w = y*100 + x*10 + z;
        push (s, w);
        return 1;
    }
    return 0;

}