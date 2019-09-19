#include <cstdlib>
#include <iostream>
#include <cstring>
#define MAX 100
#define TRUE 1
#define FALSE 0

int isEmpty(char* stack, int* top){
    if (*top==-1) return TRUE;
    return FALSE;
}

int isFull(char* stack, int*top){
    if (*top==99) return TRUE;
    return FALSE;
}

void push(char value, char* stack, int* top){
    if(isFull(stack,top)){
        std::cout<<"Stack Overflow - Cannot push onto the stack. \n";
        return;
    }
    *top=*top+1;
    stack[*top]=value;
}

char pop(char* stack, int *top){
    if(isEmpty(stack, top)){
        std::cout<<"Cannot pop off the stack. The stack is empty. \n";
        return '-';
    }
    else{
        char top_val=stack[*top];
        *top=(*top)-1;
        return top_val;
    }
}

char peek(char* stack, int* top){
    return stack[*top];
}

int isBalance(char* stack, int top){
    char temp_stack[MAX];
    int temp_top=-1;
    int balanced =0;
    if (isEmpty(stack,&top)==0){
        for(int i=0; i<=top;i++){
            if(stack[i]=='{' || stack[i]=='[' || stack[i]=='('){
                push(stack[i],temp_stack,&temp_top);
            }
            else if(stack[i]=='}' || stack[i]==']' || stack[i]==')'){
                if ((stack[i]=='}' && peek(temp_stack,&temp_top)=='{')||(stack[i]==']' && peek(temp_stack,&temp_top)=='[') || (stack[i]==')' && peek(temp_stack,&temp_top)=='(')){
                    pop(temp_stack,&temp_top);
                }
                else{
                    return FALSE;
                }
            }
        }
        if (temp_top!=-1) return FALSE;
        return TRUE;
    }
    return balanced;
}