#include <cstdlib>
#include <iostream>
#define MAX 100
#define TRUE 1
#define FALSE 0

void push(char value, char* stack, int* top){
    *top=*top+1;
    stack[*top]=value;
}

int isEmpty(char* stack, int* top){
    if (*top==-1) return TRUE;
    return FALSE;
}

char pop(char* stack, int *top){
    if(isEmpty(stack, top)){
        std::cout<<"The stack is empty.";
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


int main(){
    char stack[MAX];
    int top=-1;
    char top_val;
    push('a', stack, &top);
    push('a', stack, &top);
    push('a', stack, &top);
    push('a', stack, &top);
    push('d', stack, &top);
    top_val=peek(stack, &top);
    std::cout<<top_val<<'\n';
}