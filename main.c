#include <stdio.h>
#include <string.h>

int char_to_int (char x)
{
    int a;

    a = x - '0';

    return a;
}

int subtracao (char a[], int len)
{

}

int soma (char a[], int len)
{
    int i, sum = 0;

    for (i = 0; i < len; i++)
    {
        if (a[i]==' ') i++;

        else
        {
            sum += char_to_int (a[i]);
        }
    }

    return sum;
}

void print_int_array (int a[], int len)
{
    int i;

    for (i=0; i<len; i++)
    {
        printf ("%d", a[i]);
    }

    putchar ('\n');
}

int char_arrray_len (char a[])
{
    int i, len = 0;

    for (i=0; ;i++)
    {
        if (a[i] != '\0' || a[i] != ' ') len += 1;
    }
}

int main ()
{
    char a[100];
    int b[100], i, j = 0, len;

    fgets (a, 100, stdin);

    puts (a);

    len = strlen (a);

    for (i=0; i<len; i++)
    {
        if (a[i]=='+')
        {
            int x;

            x = soma (a,i);

            b[j] = x;

            j += 1;

            i ++;
        }
    }

    print_int_array (b, j);

    return 0;
}