#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>


int operacoesparser(char *token, STACK *s)
{
    int r = 0;

    if (strstr("+-*/()%#"   ,token)  != NULL) (r = aritmeticas(token,s));
    if (strstr("&|^~e&e|"   ,token)  != NULL) (r = logicas   (token,s));
    if (strstr("_;\\@$,S/N/",token)  != NULL) (r = operacaoS    (token,s));
    if (strstr("clifst"     ,token)  != NULL) (r = convercoes(token,s));
    if (strstr("<>=!?e<e>"  ,token)  != NULL) (r = comparacao (token,s));

    return r;
}

void decideoperacoes(char *token, STACK *s)
{
    int r = operacoesparser (token,s);
    if (r==0) operacoesparser(token, s);
}


void atribui (DATA *var)
{
    int i = 10; char a = 'A'; char b = 'X'; int j = 0;
        while (a<='F')
        {
            var [a-65].t = 1;
            var [a-65].data.l=i;
            a++; i++;
        }
        while (b<='Z')
        {
            var [b-65].t = 1;
            var [b-65].data.l = j;
            a++;i++;
        }
        var['S'-65].t=4;
        var['S'-65].data.c=' ';
        var['N'-65].t=4;
        var['N'-65].data.c='\n';
}

void printS(STACK *s)
{
    int i;
    for (i = 0; i < s->sp; i++) {
        printD (s->pilha[i]);
    }
}


void printD (DATA x)
{
    switch (x.t)
    {
        case LONG : printf("%ld", x.data.l); break;
        case DOUBLE : printf("%g", x.data.d); break;
        case CHAR : printf("%c", x.data.c); break;
        case STRING : printf("%s", x.data.str); break;
        default : break;
    }
}

void parser (char *linha, STACK *s)
{
    STACK *choose;
    DATA variaveis [26];
    atribui(variaveis);

    char *token = strtok(linha, " \t\n");

   {
       char *sobra;

       long val_i = strtol(token, &sobra, 10);
        if (strlen(sobra) == 0)
        {
            pushl(choose, val_i);
        }

        else
        {
            double val_d = strtod(token, &sobra);
            if (strlen(sobra) == 0)
            {
                pushd(choose, val_d);
            }

            else 
            {
                if ((strstr("+-*/()%#&|^~e&e|_;\\@$clifts<>=!?e<e>,", token) != NULL)) decideoperacoes(token, s);
            }
        }
   } 

   printS (s);
   putchar ('\n');
}