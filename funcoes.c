#include <stdio.h>

void print_int_array (int a[], int len)
{
    int i;

    for (i=0; i<len; i++)
    {
        printf ("%d", a[i]);
    }

    putchar ('\n');
}

int char_to_int (char x)
{
    int a;

    a = x - '0';

    return a;
}