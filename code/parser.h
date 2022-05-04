/**
 * @file parser.h 
 * \brief Módulo das funções de filtragem de input.
 */ 
#include "stack.h"
#include <string.h>

void parser (char linha, STACK *s);
void decideoperacoes(char *token, STACK *s);
int operacoesparser(char *token, STACK *s);
void atribui (DATA *var);
void printS(STACK *s);
void printD (DATA x);