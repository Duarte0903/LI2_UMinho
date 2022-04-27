/**
 * @file stack.h
 * @brief Definicao da stack
 * 
 */

#define Max_Stack 1000

//! Enum de tipos de dados
typedef enum 
{
    LONG,
    DOUBLE,
    CHAR,
    STRING
} TIPO;

//! Definicao do tipo de dados que vai ser guardado na stack
typedef struct 
{
    TIPO tipo;
    union
    {
        long l;
        double d;
        char c;
        char *str;
    }elem;  
} DATA;

//! Definicao da stack. Array de elementos e stack pointer
typedef struct 
{
    DATA stack[Max_Stack];
    int sp;
} STACK;


STACK *new_stack ();
DATA pop (STACK *s);
void push (STACK *s, char elem);

int notBit (STACK *s, char *token);
int xorBit (STACK *s, char *token);
int orBit (STACK *s, char *token);
int andBit (STACK *s, char *token);
int modulo (STACK *s, char *token);
int divisao (STACK *s, char *token);
int multiplicacao (STACK *s, char *token);
int exponencializacao (STACK *s, char *token);
int incrementar (STACK *s, char *token);
int decrementar (STACK *s, char *token);
int sub (STACK *s, char *token);
int add (STACK *s, char *token);
int val (STACK *s, char *token);

int intParaChar (STACK *s, char *token);
int troca2Topo (STACK *s, char *token);
int copiaNesimo (STACK *s, char *token);
int popG2 (STACK *s, char *token);
int duplicar (STACK *s, char *token);
int rodar3 (STACK *s, char *token);

int capB (STACK *s, char *token);
int capA (STACK *s, char *token);
int menorDosDois (STACK *s, char *token);
int maiorDosDois (STACK *s, char *token);
int menor (STACK *s, char *token);
int maior (STACK *s, char *token);
int nao (STACK *s, char *token);
int ouShortcut (STACK *s, char *token);
int eShortcut (STACK *s, char *token);
int buscaPorIndice (STACK *s, char *token);
int IfThenElse (STACK *s, char *token);