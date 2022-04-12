/**
 * @file stack.h
 * @brief Definicao da stack
 * 
 */

#define Max_Stack 1000

typedef struct 
{
    int stack[Max_Stack];
    int sp;
} STACK;

STACK *new_stack ();
void push (STACK *s, int elem);
int pop (STACK *s);

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