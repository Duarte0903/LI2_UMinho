#define Max_Stack 1000

typedef struct 
{
    int stack[Max_Stack];
    int sp;
} STACK;

STACK *new_stack ();

void push (STACK *s, int elem);

int pop (STACK *s);