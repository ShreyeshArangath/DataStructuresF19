#include <cstdlib>
#include <iostream>
#include <cstring>
#define MAX 100
#define TRUE 1
#define FALSE 0


int isEMPTY(char* stack, int* top){
    if (*top==-1) return TRUE;
    return FALSE;
}

int isFULL(char* stack, int*top){
    if (*top==99) return TRUE;
    return FALSE;
}

void PUSH(char value, char* stack, int* top){
    if(isFULL(stack,top)){
        std::cout<<"Stack Overflow - Cannot PUSH onto the stack. \n";
        return;
    }
    *top=*top+1;
    stack[*top]=value;
}

char POP(char* stack, int *top){
    if(isEMPTY(stack, top)){
        std::cout<<"Cannot POP off the stack. The stack is empty. \n";
        return '-';
    }
    else{
        char top_val=stack[*top];
        *top=(*top)-1;
        return top_val;
    }
}

char PEEK(char* stack, int* top){
    return stack[*top];
}

int isBalance(char* stack, int top){
    char temp_stack[MAX];
    int temp_top=-1;
    int balanced =0;
    if (isEMPTY(stack,&top)==0){
        for(int i=0; i<=top;i++){
            if(stack[i]=='{' || stack[i]=='[' || stack[i]=='('){
                PUSH(stack[i],temp_stack,&temp_top);
            }
            else if(stack[i]=='}' || stack[i]==']' || stack[i]==')'){
                if ((stack[i]=='}' && PEEK(temp_stack,&temp_top)=='{')||(stack[i]==']' && PEEK(temp_stack,&temp_top)=='[') || (stack[i]==')' && PEEK(temp_stack,&temp_top)=='(')){
                    POP(temp_stack,&temp_top);
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


int precedence_calculator(char operand){
    if(operand=='/'|| operand=='*')
        return 3;
    else if(operand=='+' || operand=='-'){
        return 1;
    }
    else if(operand=='%'){
        return 2;
    }
    else {
        return -1;
    }  
}

int isOperation(char element){
    return (element=='+' || element=='-' || element=='*' || element=='/' || element=='%');
}

void inFixToPostFix(char* expression){
    char stack[MAX];
    int top=-1;
    PUSH('?',stack,&top);
    int length = strlen(expression);
    for(int i=0; i<length; i++){
        if(isOperation(expression[i])){
            while(PEEK(stack,&top)!='?'  && precedence_calculator(expression[i])<=precedence_calculator(stack[top])){ 
                std::cout<<POP(stack,&top);
            }
            PUSH(expression[i],stack,&top);
        }
        else if(expression[i]=='('){
            PUSH(expression[i],stack,&top);
        }
        else if(expression[i]==')'){
            while (PEEK(stack,&top)!='?' && PEEK(stack,&top)!='(')
            {
                std::cout<<POP(stack,&top);
            }
            if (PEEK(stack,&top)=='('){
                POP(stack,&top);
            }
            
        }
        
        else
        {
            std::cout<<expression[i];
        }
        
    }
    while (PEEK(stack,&top)!='?')
    {
        std::cout<<POP(stack,&top);
    }
    
}

int main(){
    char stack[MAX];
    int top=-1;
    char top_val;
    char expresssion[MAX]="A-(B/C+(D%E*F)/G)*H";
    inFixToPostFix(expresssion);
    std::cout<<top_val<<'\n';
}