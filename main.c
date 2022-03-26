#include "operacoes.c"
#include <stdio.h>
#include <string.h>


// j guarda o indice do ultimo operador

int main ()
{
    char a[100];
    int i, j = 0, len, resultado = 0;

    fgets (a, 100, stdin);

    len = strlen (a);

    for (i=0; i<len; i++)
    {
        if (a[i]=='+')
        {
            int x;

            x = soma (a,i,j);

            resultado = resultado + x;

            j = i;

            i ++;
        }

        if (a[i]=='-')
        {
            int x;

            x = subtracao (a,i,j,resultado);

            resultado = x;

            j = i;

            i++;
        }

        if (a[i]=='(')
        {
            int x;

            x = decrementar (a,j,resultado);

            resultado = x;

            j = i;

            i++;
        }

        if (a[i]==')')
        {
            int x;

            x = incrementar (a,j,resultado);

            resultado = x;

            j = i;

            i++;
        }
    }

    printf ("%d\n", resultado);

    return 0;
}