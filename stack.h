#include <stdio.h>
#include <cstdlib>

int isEMPTY(char* stack, int* top);
int isFULL(char* stack, int*top);
int PUSH(char value, char* stack, int* top);
char POP(char* stack, int *top);
char PEEK(char* stack, int* top);
int isBalance(char* stack, int top);
int precedence_calculator(char operation);
int isOperation(char element);
int inFixToPostFix(char* expression, char* output);
