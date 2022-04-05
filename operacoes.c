#include "stack.h"

void add (STACK *s)
{
    int x = pop (s);
    int y = pop (s);

    push (s, x + y);
}