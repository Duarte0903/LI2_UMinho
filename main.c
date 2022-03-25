#include "funcoes.c"
#include <stdio.h>
#include <string.h>


int subtracao (char a[], int len, int j)
{
    int i, sub, s[100];

    if (j==0)
    {
        sub = char_to_int (a[0]);

        for (i = 1; i < len; i++)
        {
            if (a[i] != ' ') 
            {
                sub = sub - char_to_int (a[i]);
            }
        }
    }

    else 
    {
        for (i = j + 1; i < len; i++)
        {
            if (a[i] != ' ')
            {
                sub = sub - char_to_int (a[i]);
            }
        }
    }

    return sub;
}

int soma (char a[], int len, int j)
{
    int i, sum = 0;

    if (j==0)
    {
        for (i = 0; i < len; i++)
        {
            if (a[i] != ' ') sum += char_to_int (a[i]);
        }
    }

    else
    {
        for (i = j + 1; i < len; i++)
        {
            if (a[i] != ' ') sum += char_to_int (a[i]);
        }
    }

    return sum;
}

// j guarda o indice do ultimo operador

int main ()
{
    char a[100];
    int b[100], i, j = 0, len, resultado = 0;

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

            x = subtracao (a, i,j);

            if (j==0) resultado = x;
            else resultado = resultado - x;

            j = i;

            i++;
        }
    }

    printf ("%d", resultado);

    return 0;
}