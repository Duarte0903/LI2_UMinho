/**
 * @file guiao3.c
 * @brief Operacoes do guiao 3
 * 
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"

int IfThenElse (STACK *s, char *token)
{
    if (strcmp (token, "?")==0)
    {
        
        return 1;
    }
    return 0;
}