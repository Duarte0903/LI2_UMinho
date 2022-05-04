/**
 * @file stack.h
 * @brief Definicao da stack
 * 
 */
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define Max_Stack 1000


typedef enum
{
    LONG = 1,
    DOUBLE = 2,
    CHAR = 4,
    STRING = 8,
    ARRAY =16,
} TIPO;

typedef struct 
{
    TIPO t;
    union
    {
        long l;
        double d;
        char c;
        char *str;
        struct s *a;     
    } data;
} DATA;

typedef struct s
{   
    DATA *pilha;
    int stack[Max_Stack];
    int sp;
} STACK;


STACK *new_stack ();
void parser (char *linha, STACK *s);
void decideOperations(char *token, STACK *s);
int parserOperations(char *token, STACK *s);
void atribui (DATA *var);
void printS(STACK *s);
void printD (DATA x);
int aritmeticas(char *token, STACK *s);
int logicas(char *token, STACK *s);
int convercoes(char *token, STACK *s);
int comparacao(char *token, STACK *s);
int operacaoS(char *token, STACK *stack);
DATA pop (STACK *s);
void push (STACK *s, DATA data);
char popc(STACK *s);
long popl(STACK *s);
char popd (STACK *s);
char *pops (STACK *s);
void pushc(STACK *s, char x);
void pushl(STACK *s, long x);
void pushd (STACK *s, double data);
void pushs (STACK *s, char *data);
DATA top(STACK *s);
int verifica(STACK *s);
int tipos (STACK *s);
int notBit (STACK *s);
int xorBit (STACK *s);
int orBit (STACK *s);
int andBit (STACK *s);
int modulo (STACK *s);
int divisao (STACK *s);
int multiplicacao (STACK *s);
int exponenciacao (STACK *s);
int incrementar (STACK *s);
int decrementar (STACK *s);
int sub (STACK *s);
int add (STACK *s);
int val (STACK *s);
int intParaChar (STACK *s);
int troca2Topo (STACK *s);
int copiaNesimo (STACK *s);
int popG2 (STACK *s);
int duplicar (STACK *s);
int rodar3 (STACK *s);
int menorDosDois (STACK *s);
int maiorDosDois (STACK *s);
int menor (STACK *s);
int primeirochar (STACK *s);
int menorChar(STACK *s);
int maior (STACK *s);
int maiorChar(STACK *s);
int ultimochar (STACK *s);
int nao (STACK *s);
int ouShortcut (STACK *s);
int eShortcut (STACK *s);
int buscaPorIndice (STACK *s);
int indiceStrings (STACK *s);
int IfThenElse (STACK *s);
void printS(STACK *s);
void printD (DATA x);