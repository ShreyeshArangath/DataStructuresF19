#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#define MAX 100
#define TRUE 1
#define FALSE 0


std::ofstream outFile("output.txt");

void print(char* print_arr){
    std::cout<<print_arr;
    outFile<<print_arr;
}


int isEMPTY(char* stack, int* top){
    if (*top==-1){
        return TRUE;
    }
    return FALSE;
}

int isFULL(char* stack, int*top){
    if (*top==99) return TRUE;
    return FALSE;
}

int PUSH(char value, char* stack, int* top){
    char error[MAX]="Stack Overflow - Cannot PUSH onto the stack. \n";
    if(isFULL(stack,top)){
        print(error);
        return FALSE;
    }
    *top=*top+1;
    stack[*top]=value;
    return TRUE;
}

char POP(char* stack, int *top){
    char error[MAX]= "Cannot POP off the stack. The stack is empty. \n";
    if(isEMPTY(stack, top)){
        print(error);
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


int precedence_calculator(char operation){
    if (operation=='^')
        return 4;
    else if(operation=='/'|| operation=='*')
        return 3;
    else if(operation=='+' || operation=='-'){
        return 1;
    }
    else if(operation=='%'){
        return 2;
    }
    else {
        return -1;
    }  
}

int isOperation(char element){
    return (element=='+' || element=='-' || element=='*' || element=='/' || element=='%');
}

int inFixToPostFix(char* expression, char* output){
    char stack[MAX];
    int index =0;
    int top=-1;
    PUSH('?',stack,&top);
    int length = strlen(expression);
    if (isBalance(expression,length-1)){
        for(int i=0; i<length; i++){
            if(isOperation(expression[i])){
                output[index]=' ';
                index++;
                while(PEEK(stack,&top)!='?'  && precedence_calculator(expression[i])<=precedence_calculator(stack[top])){ 
                    output[index]=POP(stack,&top);
                    index++;
                    // std::cout<<POP(stack,&top);
                }
                PUSH(expression[i],stack,&top);
            }
            else if(expression[i]==')'){
                while (PEEK(stack,&top)!='?' && PEEK(stack,&top)!='(')
                {   
                    output[index]=POP(stack,&top);
                    index++;
                    // std::cout<<POP(stack,&top);
                }
                if (PEEK(stack,&top)=='('){
                    POP(stack,&top);
                }   
            }
            else if(expression[i]=='('){
                PUSH(expression[i],stack,&top);
            }
            else{
                output[index]=expression[i];
                index++;
                // std::cout<<expression[i];
            }
            
        }
        while (PEEK(stack,&top)!='?'){   
            output[index]=POP(stack,&top);
            index++;
            // std::cout<<POP(stack,&top);
        }
        return 1;
    }
    else{
        return 0;
    }

}


int main(){
    // char stack[MAX];
    // int top=-1;
    // char top_val;
    // char output[MAX];
    // char expression[MAX]="122.532+1^23+53+23+1.23/32";
    // inFixToPostFix(expression,output);
    // std::cout<<output<<'\n';
    // outFile<<output;
    int option;
    do
    {
        std::cout << "\n\n Stack ADT using Arrays \n \n " ;
        outFile<<"\n\n Stack ADT using Arrays \n \n " ;
        std::cout << "1: Push an element onto the stack \n" ;
        outFile<<"1: Push an element onto the stack \n" ;
        std::cout << "2: Pop an element off the stack \n" ;
        outFile<<"2: Pop an element off the stack \n" ;
        std::cout << "3: Check if the stack is empty \n";
        outFile<< "3: Check if the stack is empty \n";
        std::cout << "4: Check if the stack is full \n";
        outFile<<"4: Check if the stack is full \n";
        std::cout << "5: Peek at the stack \n";
        outFile<<"5: Peek at the stack \n";
        std::cout << "6: Check if an arithmetic expression is balanced \n";
        outFile<< "6: Check if an arithmetic expression is balanced \n";
        std::cout<< "7. Change an expression from infix to postfix \n";
        outFile<<"7. Change an expression from infix to postfix \n";
        std::cout << "-1 to Quit \n";
        std::cin>>option;
    }while(option!=-1);
    return 0;
}