/**
 * @file operacoes.c
 * @brief Operacoes 
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include <stdlib.h>

//! Função auxiliar para a operacoesparser dos casos com aritmeticas
int aritmeticas(char *token, STACK *s)
{
    int n=0;

    if(strcmp(token,"+") == 0) n = add(s);
    if(strcmp(token,"-") == 0) n = sub(s);
    if(strcmp(token,"*") == 0) n = multiplicacao(s);
    if(strcmp(token,"/") == 0) n = divisao(s);
    if(strcmp(token,")") == 0) n = incrementar(s);
    if(strcmp(token,"(") == 0) n = decrementar(s);
    if(strcmp(token,"%") == 0) n = modulo(s);
    if(strcmp(token,"#") == 0) n = exponenciacao(s);

    return n;
}

//! Função auxiliar para a operacoesparser dos casos com logicas
int logicas(char *token, STACK *s)
{
    int n = 0;

    if(strcmp(token,"&") == 0) n = andBit(s);
    if(strcmp(token,"|") == 0) n = orBit(s);
    if(strcmp(token,"^") == 0) n = xorBit(s);
    if(strcmp(token,"~") == 0) n = notBit(s);
    if(strcmp(token,"e&")== 0) n = eShortcut(s);
    if(strcmp(token,"e|")== 0) n = ouShortcut(s);

    return n;
}

//! Função auxiliar para a operacoesparser dos casos com convercoes
int convercoes(char *token, STACK *s)
{
    int n = 0;
    if(strcmp(token,"c") == 0) n = intParaChar(s);


    return n;
}

//! Função auxiliar para a operacoesparser dos casos com comparacao
int comparacao(char *token, STACK *s)
{
    int n = 0;

    if(strcmp(token,"<") == 0) n = menor(s);
    if(strcmp(token,">") == 0) n = maior(s);
    if(strcmp(token,"=") == 0) n = buscaPorIndice(s);
    if(strcmp(token,"!") == 0) n = nao(s);
    if(strcmp(token,"e>")== 0) n = maiorDosDois(s);
    if(strcmp(token,"e<")== 0) n = menorDosDois(s);
    if(strcmp(token,"?") == 0) n = IfThenElse(s);

 
    return n;
}

//! Função auxiliar para a operacoesparser dos casos com operacaoS
int operacaoS(char *token, STACK *stack)
{
    int n = 0;

    if(strcmp(token,"_")  == 0) n = duplicar(stack);
    if(strcmp(token,";")  == 0) n = popG2(stack);
    if(strcmp(token,"\\") == 0) n = troca2Topo(stack);
    if(strcmp(token,"@")  == 0) n = rodar3(stack);
    if(strcmp(token,"$")  == 0) n = copiaNesimo(stack);
    

    return n;
}

//! vai buscar dois numeros a stack e coloca no topo a sua soma
int add (STACK *s)
{
    int n = verifica (s);

     DATA x, y;

        if (n == 1)
        {

            if ((tipos(s)) == 2) 
            {
                x.data.l = popl(s);
                y.data.l = popl(s);
                pushl(s, y.data.l + x.data.l);
            } 
            else 
            {
                x.data.d = popd(s);
                y.data.d = popd(s);
                pushd(s, y.data.d + x.data.d);
            }

        }
    return n;
}


//! vai buscar dois numeros a stack e coloca no topo a sua diferenca
int sub (STACK *s)
{
    int n = verifica (s);

     DATA x, y;

        if (n == 1)
        {

            if ((tipos(s)) == 2) 
            {
                x.data.l = popl(s);
                y.data.l = popl(s);
                pushl(s, y.data.l - x.data.l);
            } 
            
            else 
            {
                x.data.d = popd(s);
                y.data.d = popd(s);
                pushd(s, y.data.d - x.data.d);
            }

        }
    return n;
}

//! vai buscar dois numeros a stack e coloca no topo o seu produto
int multiplicacao (STACK *s)
{
    int n = verifica (s);

     DATA x, y;

        if (n == 1)
        {

            if ((tipos(s)) == 2) 
            {
                x.data.l = popl(s);
                y.data.l = popl(s);
                pushl(s, y.data.l * x.data.l);
            } 

            else 
            {
                x.data.d = popd(s);
                y.data.d = popd(s);
                pushd(s, y.data.d * x.data.d);
            }

        }
    return n;
}

//! vai buscar dois numeros a stack e coloca no topo a sua divisao
int divisao (STACK *s)
{
    int n = verifica (s);

     DATA x, y;

        if (n == 1)
        {

            if ((tipos(s)) == 2) 
        {
            x.data.l = popl(s);
            y.data.l = popl(s);
            pushl(s, y.data.l / x.data.l);
        } 
        else 
        {
            x.data.d = popd(s);
            y.data.d = popd(s);
            pushd(s, y.data.d / x.data.d);
        }

        }
    return n;
}

//! vai buscar um numero a stack e coloca no topo a soma do mesmo por um 
int incrementar (STACK *s)
{
    int n = 0;

    DATA P = top(s);

    if(P.t == CHAR) {P = pop(s); pushc(s, (P.data.c+1)); n = 1;}
    if(P.t == LONG) {P = pop(s);pushl(s, (P.data.l+1)); n = 1;}
    if(P.t == DOUBLE) {P = pop(s);pushd(s, (P.data.d+1)); n = 1;}

    return n;
}

//! vai buscar um numero a stack e coloca no topo a subtracao do mesmo por um 
int decrementar (STACK *s)
{
    int n = 0;

    DATA P = top(s);
    if(P.t == CHAR) {P = pop(s); pushc(s, (P.data.c-1)); n = 1;}
    if(P.t == LONG) {P = pop(s); pushl(s, (P.data.l-1)); n = 1;}
    if(P.t == DOUBLE) {P = pop(s); pushd(s, (P.data.d-1)); n= 1;}


    return n;
}

//! vai buscar dois numeros a stack e coloca no topo o resto da divisao inteira
int modulo (STACK *s)
{
    int n = 0;
    
    DATA x, y;

    if ((tipos(s)) == 2)
    {
        n = 1;
        x.data.l = popl(s);
        y.data.l = popl(s);
        pushl(s, (y.data.l) % (x.data.l));
    }

    return n;
}

//! vai buscar dois numeros (x e y) a stack e coloca do topo y^x
int exponenciacao(STACK *s)
{
    int n = verifica(s);
    int m = tipos(s);

    DATA x, y;

    if (n == 1)
    {
        if (m == 2)
        {
            x.data.l = popl(s);
            y.data.l = popl(s);
            pushl(s, pow(y.data.l, x.data.l));
        }
        else
        {
            x.data.d = popd(s);
            y.data.d = popd(s);
            pushd(s, pow(y.data.d, x.data.d));
        }
    }
  
    return n;
}

//! Vai buscar dois numeros a stack. Realiza a operacao AND em todos os bits. Devolve 1 se os dois bits forem 1 
int andBit(STACK *s)
{
    int n = 0;
    
    DATA x, y;

    if ((tipos(s)) == 2)
    {

        n = 1;
        x.data.l = popl(s);
        y.data.l = popl(s);
        pushl(s, (y.data.l) & (x.data.l));
    }

    return n;
}

//! Vai buscar dois numeros a stack. Realiza a operacao OR em todos os bits. Devolve 1 se um dos bits for 1 
int orBit(STACK *s)
{
    int n = 0;
    
    DATA x, y;

    if ((tipos(s)) == 2)
    {

        n = 1;
        x.data.l = popl(s);
        y.data.l = popl(s);
        pushl(s, (y.data.l) | (x.data.l));
    }

    return n;
}

//! Vai buscar dois numeros a stack. Realiza a operacao XOR em todos os bits. Devolve 1 se os dois bits forem diferentes 
int xorBit(STACK *s)
{
    int n = 0;
    
    DATA x, y;

    if ((tipos(s)) == 2)
    {

        n = 1;
        x.data.l = popl(s);
        y.data.l = popl(s);
        pushl(s, (y.data.l) ^ (x.data.l));
    }

    return n;
}

//! Vai buscar um numero a stack. Inverte os bits e devolve o resultado
int notBit(STACK *s)
{
    int n = 0;
    
    DATA P = top(s);

    if (P.t == LONG)
    {
        n = 1;
        P.data.l = popl(s);
        pushl(s, ~(P.data.l));
    }

    return n;
}

//! Transforma o numero no topo da stack num char 
/*!
 * input: 79 c 108 c 97 c \n
 * output: Ola
 */
int intParaChar(STACK *s)
{
    int n = 0;

    DATA x = pop(s);

    if(x.t == STRING) {pushc(s, atof(x.data.str)); n = 1;}    
    if(x.t == LONG) {pushc(s, x.data.l); n = 1;}


    return n;
}

//! Trocar os dois elementos do topo da stack
/*!
 * input: 1 2 3 \ \n
 * output: 132
 */
int troca2Topo(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    push(s, x);
    push(s, y);

    return 1;
}

//! Copia n-ésimo elemento para o topo da stack (0 e o topo da stack)
/*!
 * input: 7 2 3 2 $ (n = 2) \n
 * output: 7237
 */
int copiaNesimo(STACK *s)
{
    int n = 0;
    DATA x = top(s);

    if(x.t == LONG)
    {
        n = 1;
        long n = popl(s);
        push(s, s->pilha[s->sp - n - 1]);
    }

    return n;
}

//! Realiza a operacao pop
/*!
 * input: 1 2 3 ; \n
 * output: 12
 */
int popG2(STACK *s)
{
    pop(s);

    return 1;
}

//! Duplica um numero e coloca-o no topo da stack
/*!
 * input: 2 _ \n
 * output: 22
 * 
 * input: 1 2 _ \n
 * output: 122 
 */
int duplicar(STACK *s)
{
    DATA x = pop(s);
    push(s, x);
    push(s, x);

    return 1;
}

//! roda os 3 elementos no topo da stack
/*!
 *  input: 1 2 3 @ \n
 *  output: 231
 */
int rodar3(STACK *s)
{
    DATA a = pop(s);
    DATA b = pop(s);
    DATA c = pop(s);
    push(s, b);
    push(s, a);
    push(s, c);

    return 1;
}


//! Coloca no topo da stack o menor de dois numeros
int menorDosDois (STACK *s)
{
    {
        int n = 0;
        DATA x = pop (s);
        DATA y = pop (s);
        
        if (x.t == LONG && y.t == DOUBLE)
        {
            if ((x.data.l) < (y.data.d))  push (s, x); 
            else push (s, y);
        }
        
        if (x.t == LONG && y.t == LONG)
        {
            if ((x.data.l) < (y.data.l)) push (s, x);
            else push (s, y);
        }
        
        if (x.t == DOUBLE && y.t == DOUBLE)
        {
            if ((x.data.d) < (y.data.d)) push (s, x); 
            else push (s, y);
        }

        if (x.t == DOUBLE && y.t == LONG)
        {
            if ((x.data.d) < (y.data.l)) push (s, x); 
            else push (s, y);
        }
        
        n = 1;

    return n;
    }
    
}

//! Coloca no topo da stack o maior de dois numeros
int maiorDosDois (STACK *s)
{
    {
      int n = 0;
      DATA x = pop (s);
      DATA y = pop (s);

        if (x.t == LONG && y.t == LONG)
        {
            if ((x.data.l) > (y.data.l)) push (s, x);
            else push (s, y);
        }

        if (x.t == DOUBLE && y.t == DOUBLE)
        {
            if ((x.data.d) > (y.data.d)) push (s, x); 
            else push (s, y);
        }

        if (x.t == LONG && y.t == DOUBLE)
        {
            if ((x.data.l) > (y.data.d))  push (s, x); 
            else push (s, y);
        }
        
        if (x.t == DOUBLE && y.t == LONG)
        {
            if ((x.data.d) > (y.data.l)) push (s, x); 
            else push (s, y);
        }
      n = 1;

      return n;
    }

}

//! Se um numero e menor que outro coloca 1 na strack. Caso contrario 0
int menor(STACK *s)
{
    int n = verifica(s);

    DATA x, y;

    if (tipos(s)==2 || tipos(s) ==3 || tipos(s)==4)
    {
        x.data.d = popd(s);
        y.data.d = popd(s);
        ((y.data.d) < (x.data.d)) ? pushl(s, 1) : pushl(s, 0);
        n=1;
    }
    else if (tipos(s) == 16)
    {
        x = pop(s);
        y = pop(s);
        if(strcmp(y.data.str, x.data.str) < 0) pushl(s, 1);
        else pushl(s, 0);
        n=1;
    }
    else if (tipos(s)==5) n = menorChar(s);
    else n = primeirochar(s);

    return n;
}

//! Função auxiliar para buscar caracteres na string
int primeirochar (STACK *s)
{
    int n = 0;
    DATA x, y;

    if (tipos(s) == 9)
    {
        x = pop(s);
        y = pop(s);
        char *vs = calloc(x.data.l+1, sizeof(char));
        unsigned int i;

        for (i = 0; i < x.data.l; i++)
        {
            vs[i] = y.data.str[i];
        }
        vs[i] = '\0';
        pushs(s, vs);
        n=1;
    }

    return n;
}

//! Função auxiliar para comparar números com caracteres
int menorChar(STACK *s)
{
    int n=0;
    DATA x, y;

    if (s->pilha[s->sp - 1].t == CHAR)
    {
        x.data.c = popd(s);
        y.data.d = popd(s);
        (y.data.d < x.data.c) ? pushl(s, 1):pushl(s, 0);
        n=1;
    }
    if (s->pilha[s->sp - 2].t == CHAR)
    {
        x.data.d = popd(s);
        y.data.c = popd(s);
        (y.data.c < x.data.d) ? pushl(s, 1):pushl(s, 0);
        n=1;
    }

    return n;
}

//! Se um numero e maior que outro coloca 1 na strack. Caso contrario 0
int maior(STACK *s)
{
    int n = verifica(s);

    DATA x, y;

    if (tipos(s)==2 || tipos(s) ==3 || tipos(s)==4)
    {
        x.data.d = popd(s);
        y.data.d = popd(s);
        ((y.data.d) > (x.data.d)) ? pushl(s, 1) : pushl(s, 0);
        n=1;
    }
    else if (tipos(s) == 16)
    {
        x = pop(s);
        y = pop(s);
        if(strcmp(y.data.str, x.data.str) > 0) pushl(s, 1);
        else pushl(s, 0);
        n=1;
    }
    else if (tipos(s)==5) n = maiorChar(s);
    else n = ultimochar(s);

    return n;
}

//! Função auxiliar para comparar números com caracteres
int maiorChar(STACK *s)
{
    int n=0;
    DATA x, y;

    if (s->pilha[s->sp - 1].t == CHAR)
    {
        x.data.c = popd(s);
        y.data.d = popd(s);
        (y.data.d > x.data.c) ? pushl(s, 1):pushl(s, 0);
        n=1;
    }
    if (s->pilha[s->sp - 2].t == CHAR)
    {
        x.data.d = popd(s);
        y.data.c = popd(s);
        (y.data.c > x.data.d) ? pushl(s, 1):pushl(s, 0);
        n=1;
    }

    return n;
}

//! Função auxiliar para buscar caracteres na string
int ultimochar (STACK *s)
{
    int n = 0;
    DATA x, y;

    if (tipos(s) == 9)
    {
        x = pop(s);
        y = pop(s);
        char *j = calloc(x.data.l +1 ,sizeof(char));
        int a = 0;
        unsigned int i = 0;

        for (i = strlen(y.data.str)-x.data.l; i < strlen(y.data.str); i++)
        {
            j[a] = y.data.str[i];
            a++;
        }
        j[a] = '\0';
        pushs(s, j);
        n=1;
    }

    return n;
}



/*!
 * input: 0 ! \n
 * output: 1
 * 
 * input: 1 ! \n
 * output 0
 */
int nao(STACK *s)
{
    DATA x = pop(s);
    if ((x.t == LONG && x.data.l!=0)) { pushl(s, 0);}
    if ((x.t == DOUBLE && x.data.d!=0)) { pushl(s, 0);}
    if ((x.t == CHAR && x.data.c!=0)) pushl(s, 0); else pushl(s, 1);

    return 1;
}

//! Operador logico "ou"
/*!
 * input: 0 3 e| \n
 * output: 0
 */
int ouShortcut (STACK *s)
{
    int n = verifica(s);

    DATA x, y;

    if(n == 1)
    {
        x.data.d = popd(s);
        y.data.d = popd(s);
        if ((y.data.d) != 0)  pushd(s, (y.data.d));
        if ((x.data.d != 0 && y.data.d == 0)) { pushd(s, x.data.d);} else pushl(s, 0);
    }

    return n;

}
//! Operador logico "e"
/*!
 * input: 1 3 e& \n
 * output: 3
 */
int eShortcut (STACK *s)
{
    int n = verifica(s);

    DATA x, y;

    if(n == 1)
    {
        x.data.d = popd(s);
        y.data.d = popd(s);
        if((x.data.d != 0) && (y.data.d != 0))  pushd(s, (x.data.d)); else  pushd(s, 0);    

    
    }
    return n;
}

//! Procura o indice de um numero
/*!
 * input: 3 3 = \n
 * output: 1
 */
int buscaPorIndice(STACK *s)
{
    int n = verifica(s);

    DATA x, y;

    if (n == 1)
    {
        x.data.d = popd(s);
        y.data.d = popd(s);
        if ((y.data.d) == (x.data.d)) pushl(s, 1); else pushl(s, 0);
        n = 1;
    }
    else if (tipos(s) == 16)
    {
        x = pop(s);
        y = pop(s);
        int r = strcmp(x.data.str, y.data.str);
        if (r == 0) pushl(s, 1); else pushl(s, 0);
        n = 1;
    }
    else n = indiceStrings(s);

    return n;
}
int indiceStrings (STACK *s)
{
    int n;

    if (tipos(s) == 9)
    {
        DATA x = pop(s);
        DATA y = pop(s);
        pushc(s, y.data.str[x.data.l]);
        n = 1;
    }
    else  n = 0;

    return n;
}


//! IF x diferente de zero THEN y ELSE z
/*!
 * input: 1 2 3 ? \n
 * output: 2
 * 
 * input: 0 2 3 \n
 * output: 3
 */
int IfThenElse (STACK *s)
{  
    DATA x = pop (s);
    DATA y = pop (s);
    DATA z = pop (s);
       
    if (z.t == LONG && z.data.l != 0) {push(s, y);}
    else push (s, x);
         
    return 1;
}