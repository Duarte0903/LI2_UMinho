#include <stdio.h>


int char_to_int (char x)
{
    int a;

    a = x - '0';

    return a;
}

int subtracao (char a[], int len, int j, int resultado)
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
        sub = resultado;

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

// decrementar = '('

int decrementar (char a[], int j, int resultado)
{
    int decr; 

    if (j==0)
    {
        decr = char_to_int (a[0]) - 1;
    }

    else
    {
        decr = resultado - 1;
    }

    return decr;
}

// incrementar = ')'

int incrementar (char a[], int j, int resultado)
{
    int incr;

    if (j==0)
    {
        incr = char_to_int (a[0]) + 1;
    }

    else
    {
        incr = resultado + 1;
    }

    return incr;
}