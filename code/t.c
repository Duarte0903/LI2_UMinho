#include <stdio.h>
#include "stack.h"


int main()
{
	STACK *s = new_stack();

	long l = 10;
	double d = 12.5;

	DATA x = cria_Long(l);
	push(s,x);
	DATA y = cria_Double(d);
	push(s,y);
}
