// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab2.cpp
// SPECIFICATION: Create a Stack ADT using arrays. Write isBalanced and infixToPostfix functions for the stack. 
// FOR: CS 2413 Data Structure Section 001 - 501

// TEST CASES for Function print:
// Test case1: test input is an array of characters
// Input: ['h','e','l','l','o']
// Expected output: hello (in console and in file)
// Actual Output: hello (in console and in file)
// Test case2: a character
// Input: ['a']
// Expected Output: a (in console and in file)
// Actual output a(in console and in file)

// TEST CASES for Function isEMPTY:
// Test case1: an empty stack - []
// Input: [], &top (top=-1)
// Expected output: The stack is empty. Returns 1
// Actual Output: The stack is empty. Returns 1
// Test case2: a non-empty stack - ['a','b']
// Input: ['a','b'], &top (top=1)
// Expected Output: The stack is not empty. Returns 0
// Actual output: The stack is not empty. Returns 0

// TEST CASES for Function isFULL:
// Test case1: an empty stack - []
// Input: [], &top (top=-1)
// Expected output: The stack is not full. Returns 0
// Actual Output: The stack is not full. Returns 0
// Test case2: a non-empty filled stack - ['a','b' .......,'1']
// Input: ['a','b', ........, '1' ], &top (top=99)
// Expected Output: The stack is full. Returns 1
// Actual output: The stack is full. Returns 1

// TEST CASES for Function PUSH:
// Test case1: Inserting to a non-empty stack
// Input: 'd',['a','b','c'],&top (top=2)
// Expected output: ['a','b','c','d']. Returns 1
// Actual Output: ['a','b','c','d']. Returns 1
// Test case2: Inserting into a full-stack
// Input: 'e', ['a','b','c','d',..............], &top (top=99)
// Expected Output: Stack Overflow - Cannot PUSH onto the stack. Return 0 
// Actual output: Stack Overflow - Cannot PUSH onto the stack. Return 0

// TEST CASES for Function POP:
// Test case1: Popping from a non-empty stack
// Input: ['a','b','c'], &top (top=2)
// Expected output: Returns 'c', changes top to 1
// Actual Output: Returns 'c', changes top to 1
// Test case2: Popping from an empty stack 
// Input:[], &top (top=-1)
// Expected Output: Cannot POP off the stack. The stack is empty. Returns '-'
// Actual output: Cannot POP off the stack. The stack is empty. Returns '-'

// TEST CASES for Function PEEK :
// Test case1: Non empty stack
// Input: ['a','b','c'], &top (top=2)
// Expected output: Returns 'c'
// Actual Output: Returns 'c'
// Test case2: If the stack is empty
// Input: [], &top (top=-1)
// Expected Output: Nothing in the stack. 
// Actual output: Nothing in the stack. 

// TEST CASES for Function isBalance:
// Test case1: If the expression is balanced
// Input: ['{','[','(',')',']','}']
// Expected output: Returns 1
// Actual Output: Returns 1
// Test case2: Expression is not balanced
// Input: ['1','(','3]
// Expected Output: Returns 0
// Actual output: Returns 0


// TEST CASES for Function precedence_calculator:
// Test case1: Valid operation
// Input: '+'
// Expected output: Returns 2
// Actual Output: Returns 2
// Test case2: Invalid operation
// Input: '?'
// Expected Output: Returns -1  
// Actual output: Returns -1

// TEST CASES for Function isOperation:
// Test case1: Valid operation
// Input: '+'
// Expected output: Returns 1
// Actual Output: Returns 1
// Test case2: Invalid operation
// Input: '?'
// Expected Output: Returns 0
// Actual output: Returns 0

// TEST CASES for Function inFixToPostFix:
// Test case1: Balanced infix expression
// Input: A-(B/C+(D%E*F)/G)*H 
// Expected output: ABC/DEF*%G/+H*-
// Actual Output: ABC/DEF*%G/+H*-
// Test case2: Balanced infix with multiple character var
// Input:  A-(BML/C+(D%E*F)/G)*H
// Expected Output: A BML C /D E F*% G/+ H*-
// Actual output: A BML C /D E F*% G/+ H*-

// --------------------------------------------------------------------------------

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#define MAX 100 //MAX SIZE OF THE STACK
#define TRUE 1 //TRUE VAL
#define FALSE 0 //FALSE VAL


std::ofstream outFile("output.txt"); //The file stream pointer to the output file. 

// NAME: print
// INPUT PARAMETERS: Array of characters
// OUTPUT: Prints out the array into the standard output stream and the file stream
// PURPOSE: To get multiple prints within a single function call

void print(char* print_arr){
    std::cout<<print_arr;
    outFile<<print_arr;
}

// NAME: isEMPTY
// INPUT PARAMETERS: stack, pointer to the top
// OUTPUT: Returns true if the stack is empty, and FALSE elsewise
// PURPOSE: To check if the stack is empty or not. 
int isEMPTY(char* stack, int* top){
    if (*top==-1){
        return TRUE;
    }
    return FALSE;
}

// NAME: isFULL
// INPUT PARAMETERS: stack, pointer to the top
// OUTPUT: Returns true if the stack is full, and FALSE elsewise
// PURPOSE: To check if the stack is full or not. 
int isFULL(char* stack, int*top){
    if (*top==99) return TRUE;
    return FALSE;
}

// NAME: PUSH
// INPUT PARAMETERS: value - a character, stack, pointer to the top
// OUTPUT: Pushes an element onto the stack. Returns TRUE if process is successful. 
// PURPOSE: To push elements onto the stack. 
int PUSH(char value, char* stack, int* top){
    char error[MAX]="Stack Overflow - Cannot PUSH onto the stack. \n"; //The character array to print if there is an error. 
    if(isFULL(stack,top)){
        print(error);
        return FALSE;
    }
    *top=*top+1;
    stack[*top]=value;
    return TRUE;
}

// NAME: POP
// INPUT PARAMETERS: stack, pointer to the top
// OUTPUT: Pop an element off the stack. Returns TRUE if process is successful. 
// PURPOSE: To pop elements off the stack. 
char POP(char* stack, int *top){
    char error[MAX]= "Cannot POP off the stack. The stack is empty. \n"; // The character array to print if there is an error. 
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

// NAME: PEEK
// INPUT PARAMETERS: stack, pointer to the top
// OUTPUT: Returns the element at the top of the stack. 
// PURPOSE: To peek at the stack. 
char PEEK(char* stack, int* top){
    if (isEMPTY(stack,top)) return '-';
    return stack[*top];
}

// NAME: isBalance
// INPUT PARAMETERS: stack, top - index of the top
// OUTPUT: Returns TRUE if the expression is balanced. 
// PURPOSE: To check if an expression has balanced brackets, parenthesis, and curly braces. 
int isBalance(char* stack, int top){
    char temp_stack[MAX]; //Temporary stack to check if it is balanced. 
    int temp_top=-1; //The index of the top of the temporary stack. 
    int balanced =0; //The result if it is balanced or not
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

// NAME: precendence_calculator
// INPUT PARAMETERS: operation (+,-,^,/,*,%)
// OUTPUT: Returns the precedence of an operation
// PURPOSE: To rank the operation by precendence for infix to prefix conversion
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

// NAME: isOperation
// INPUT PARAMETERS: operation (+,-,^,/,*,%)
// OUTPUT: Returns if char is an operation or not
// PURPOSE: To check if char is an operation or not
int isOperation(char element){
    return (element=='+' || element=='-' || element=='*' || element=='/' || element=='%' || element=='^');
}

// NAME: inFixToPostFix
// INPUT PARAMETERS: expression (array of char), output (array of char)
// OUTPUT: Returns the postfix form of an expression
// PURPOSE: To convert an infix expression to a postfix expression. 
int inFixToPostFix(char* expression, char* output){
    char stack[MAX]; //Temporary stack to store the characters from the expression. 
    int index =0; //Index of the element in the expression
    int top=-1; // The top of the temporary stack. 
    int length = strlen(expression);//Length of the expression.
    PUSH('?',stack,&top);
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

// NAME: main
// INPUT PARAMETERS: 
// OUTPUT: The menu with all the functions
// PURPOSE: To help users access the functions. 
int main(){
    char stack[MAX]; //Stack used in the program
    int top=-1; //Index of the top element of the stag
    int flag=1; //To signify errors in the program 
    int option;  //To store the user input
    char element; //To store the element
    do
    {
        std::cout << "\n\n Stack ADT using Arrays \n \n" ;
        outFile<<"\n\n Stack ADT using Arrays \n \n" ;
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
        outFile<<option << '\n';

        switch(option){
            case 1: {
                std::cout<<"Enter the element you want to push: ";
                outFile<<"Enter the element you want to push: ";
                std::cin>> element;
                outFile<< element;
                std::cout<<'\n';
                outFile<<'\n';
                flag=PUSH(element,stack,&top);
                if (flag==1){
                    std::cout<<"The element "<<element <<" has been pushed onto the stack \n";
                    outFile<< "The element "<<element <<" has been pushed onto the stack \n";
                }
                break;
            }
            case 2: {
                element=POP(stack,&top);
                if(element!='-'){
                    std::cout<<"The element "<<element<<" has been popped off the stack. \n";
                    outFile<<"The element "<<element<<" has been popped off the stack. \n";
                }
                break;
            }
            case 3: {
                flag=isEMPTY(stack,&top);
                if(flag==1){
                    std::cout<<"The stack is empty. \n";
                    outFile<<"The stack is empty. \n";
                }
                else {
                    std::cout<<"The stack is not empty. \n";
                    outFile<<"The stack is not empty. \n";
                }
                break;
            }
            case 4: {
                flag=isFULL(stack,&top);
                if(flag==1){
                    std::cout<<"The stack is full. \n";
                    outFile<<"The stack is full. \n";
                }
                else{
                    std::cout<<"The stack is not full. \n";
                    outFile<<"The stack is not full. \n";
                }
                break;
            }
            case 5: {
                element=PEEK(stack,&top);
                if (element=='-'){
                std::cout<<"The stack is empty\n";
                outFile<<"The stack is empty\n";
                break;
                }
                std::cout<<"The element at the top of the stack is: "<<element<<"\n";
                outFile<<"The element at the top of the stack is: "<<element<<"\n";
                break;
            }
            case 6: { 
                char expression[MAX]; //To store the mathematical expression from user
                std::cout<<"Please enter an expression that you want to check: ";
                outFile<<"Please enter an expression that you want to check: ";
                std::cin>>expression;
                outFile<<expression;
                int i = strlen(expression);
                flag=isBalance(expression, i);
                if (flag==1){
                    std::cout<<"\nThe expression is balanced. \n";
                    outFile<<"\nThe expression is balanced. \n";
                }
                else{
                    std::cout<<"\nThe expression is not balanced. \n";
                    outFile<<"\nThe expression is not balanced. \n";
                }
                break;
            }
            case 7: {
                char expression[MAX]; //To store the infix expression from the user
                char output[MAX]; //To store the output of the conversion
                std::cout<< "Please enter an expression that you'd like to convert: ";
                outFile<<"Please enter an expression that you'd like to convert: ";
                std::cin>>expression;
                std::cout<<"\n";
                outFile<<expression<<"\n";
                flag=inFixToPostFix(expression,output);
                if (flag!=1){
                    std::cout<<"The expression is not valid. \n";
                    outFile<<"The expression is not valid. \n";
                }
                else{
                    print(output);
                }

            }
            case -1: {
                std::cout<< "Thank you. \n";
                outFile<<"Thank you. \n";
            }
            
        }
    }while(option!=-1);
    return 0;
}