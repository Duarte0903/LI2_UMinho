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
    STRING,
    ARRAY,
    BLOCO
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
        struct stack *arr;
        struct stack *bloc;
    }elem;  
} DATA;

//! Definicao da stack. Array de elementos e stack pointer
typedef struct stack
{
    DATA stack[Max_Stack];
    int sp;
} STACK;

int handleG1 (STACK *s, char *token);
int handleG2 (STACK *s, char *token);
int handleG3 (STACK *s, char *token);
int handleG4 (STACK *s, char *token, int flagArrays);
int mainHandle (STACK *s, char *token, int flagArrays);
void parser (STACK *s, char *token);

STACK *new_stack ();
void cpyArr (STACK *a1, STACK *a2);
void printDATA (DATA x);
void printStack (STACK *s);
DATA pop (STACK *s);
void push (STACK *s, DATA elem);
DATA cria_Long (long d);
DATA cria_Double (double d);
DATA cria_Char (char c);
DATA cria_string (char *s);
DATA cria_array (STACK *arr);
DATA cria_bloco (STACK *bloco);
void valOmissao (DATA *variaveis);

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

int convertParaDouble (STACK *s, char *token);
int convertParaInt (STACK *s, char *token);
int lerLinha (STACK *s, char *token);
int intParaChar (STACK *s, char *token);
int troca2Topo (STACK *s, char *token);
int copiaNesimo (STACK *s, char *token);
int popG2 (STACK *s, char *token);
int duplicar (STACK *s, char *token);
int rodar3 (STACK *s, char *token);

int  dots (char *token);
void omissao (STACK *s, char *token, DATA valOmissao[26]);
int capLtr (char *token);
void pushVal (STACK *s, char *token, DATA valOmissao[26]);
int menorDosDois (STACK *s, char *token);
int maiorDosDois (STACK *s, char *token);
int menor (STACK *s, char *token);
int maior (STACK *s, char *token);
int nao (STACK *s, char *token);
int ouShortcut (STACK *s, char *token);
int eShortcut (STACK *s, char *token);
int buscaPorIndice (STACK *s, char *token);
int IfThenElse (STACK *s, char *token);

int lerInput (STACK *s, char *token);
int pushEspaco (STACK *s, char *token);
int criaString (STACK *s, char *token);
int abreParReto (STACK *s, char *token, int flag);
int fechaParReto (STACK *s, char *token, int flag);
int range (STACK *s, char *token);
