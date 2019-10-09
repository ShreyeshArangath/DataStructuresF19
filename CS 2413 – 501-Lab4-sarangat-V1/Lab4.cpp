// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab4.cpp
// SPECIFICATION: Write a program to convert numbers (base 10) to any specified base. 
// FOR: CS 2413 Data Structure 001 501

// TEST CASES for Function isEmpty:
// Test case1: The stack is empty.
    // Input: top->NULL
    // Expected output: 1 
    // Actual Output: 1
// Test case2: The stack is not empty. 
    // Input: top->1->2
    // Expected Output: 0
    // Actual output: 0

// TEST CASES for Function PUSH:
// Test case1: Pushing 4 into an empty stack
    // Input: 4, top->NULL
    // Expected output: top->4->NULL
    // Actual Output: top->4->NULL
// Test case2: Pushing 5 into the stack from test case 1
    // Input: 5, top->4->NULL
    // Expected Output: top->5->4->NULL
    // Actual output: top->5->4->NULL

// TEST CASES for Function POP:
// Test case1: Popping from an empty stack
    // Input: top->NULL
    // Expected output: 0
    // Actual Output: 0
// Test case2: Popping from a non-empty stack
    // Input: top->5->NULL
    // Expected Output: top->NULL. Returns 5
    // Actual output: top->NULL. Returns 5

// TEST CASES for Function PEEK:
// Test case1: An empty stack
    // Input: top->NULL
    // Expected output: 0
    // Actual Output: 0
// Test case2: A non empty staack 
    // Input: top->5->NULL
    // Expected Output: 5
    // Actual output: 5

// TEST CASES for Function printBaseConversion:
// Test case1: Converting 3 from base 10 to base 2
    // Input: top->1->1->NULL
    // Expected output: Prints out '11'
    // Actual Output: Prints out '11'
// Test case2: Converting 17 to base 22
    // Input: top->17->NULL
    // Expected Output: Prints out 'H'
    // Actual output: Prints out 'H'

// TEST CASES for Function convertToBase:
// Test case1: Converting 3 from base 10 to base 2
    // Input: 3,2, top->NULL
    // Expected output: top->1->1->NULL (stack)
    // Actual Output: top->1->1->NULL (stack)
// Test case2: Converting 3 from base 10 to base 28
    // Input: 3,28, top->NULL
    // Expected Output: Returns 0
    // Actual output: Returns 0
// --------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

const char char_namespace[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
 //It is used to map remainders>=10 to characters.


 ofstream outFile("output.txt"); //output file pointer

typedef struct node{
    int data;
    struct node *next;
}stack_record_t; //Defining a new stack record type.

// NAME: isEmpty
// INPUT PARAMETERS: a pointer to the top of the stack
// OUTPUT: Returns 1 if the stack is empty, 0 elsewise 
// PURPOSE: To check if the stack is empty
int isEmpty(stack_record_t **top){
    return (*top==NULL);
}

// NAME: PUSH
// INPUT PARAMETERS: data (an integer),a pointer to the top of the stack
// OUTPUT: Pushes the element to the top of the stack
// PURPOSE: To push elements onto the stack
void PUSH(int data,stack_record_t **top){
    stack_record_t *new_node = (stack_record_t *)malloc(sizeof(stack_record_t*)); //New node to PUSH onto the stack.
    new_node->data=data;
    new_node->next=*top;
    *top=new_node;
}

// NAME: POP
// INPUT PARAMETERS: a pointer to the top of the stack
// OUTPUT: The element that is popped of the stack
// PURPOSE: To pop elements off the stack
int POP(stack_record_t **top){
    if(isEmpty(top)){
        cout<<"Cannot pop from an empty stack.";
        return -1;
    }
    else {
        stack_record_t *temp; //Temp node to store the top of the stack. 
        int data;
        temp=*top;
        data=temp->data;
        *top=(*top)->next;
        free(temp);
        return data;
    }
}

// NAME: PEEK
// INPUT PARAMETERS: a pointer to the top of the stack
// OUTPUT: Returns the value on top of the stack
// PURPOSE: To peek at the stack
int PEEK(stack_record_t **top){
    return (*top)->data;
}

// NAME: printBaseConversion
// INPUT PARAMETERS: a pointer to the top of the stack
// OUTPUT: Prints out the base converted form of the number 
// PURPOSE: To print the base conversion 
int printBaseConversion(stack_record_t **top){
    int temp; //TO store the elements popped off the stack. 
    while(!isEmpty(top)){
        temp=POP(top);
        if(temp>=10){
            cout<<char_namespace[temp-10];
            outFile<<char_namespace[temp-10];
        }
        else{
            cout<<temp;
            outFile<<temp;
        }
        
    }
    return 1;
}

// NAME: convertToBase
// INPUT PARAMETERS: value_to_convert (an integer), base (an integer between 2 and 27),
// a pointer to the top of the stack
// OUTPUT: Pushes the remainders of base conversion to the stack
// PURPOSE: To get the reverse order of base conversion in the form of a stack
int convertToBase(int value_to_convert, int base, stack_record_t ** top){
    if(base>=2 && base<=27){
        int temp = value_to_convert; //To store the value for conversion
        int remainder; //To store the remainder of value_to_convert and base
        while(temp!=0){
            remainder=temp%base;
            PUSH(remainder, top);
            temp=temp/base;
        }
        printBaseConversion(top);
        return 1;
    }
    else {
        cout<<"Invalid entry. Enter base between 2 and 27 (inclusive)"<<'\n';
        outFile<<"Invalid entry. Enter base between 2 and 27 (inclusive)"<<'\n';
    }
    return 0;
    
}

// NAME: main
// INPUT PARAMETERS: NONE
// OUTPUT: -
// PURPOSE: Driver function
int main(){
    int option; //To check if the user wants to exit the program. 
    int value; //To store the value user wants to convert
    int base; //To store the base user wants to convert to. 
    stack_record_t *top=NULL; //Top of the stack
    do{
        cout<< "Please enter a decimal number: ";
        outFile<<"Please enter a decimal number: ";
        cin>>value;
        outFile<<value<<'\n';

        cout<< "Please enter the base you'd like to convert to: ";
        outFile<<"Please enter the base you'd like to convert to: ";
        cin>>base;
        outFile<<base<<'\n';

        cout<< "Base " << base<< " conversion of "<<value<<" is: " ;
        outFile<< "Base " << base<< " conversion of "<<value<<" is: " ;
        convertToBase(value,base,&top);

        cout<<'\n';
        outFile<<'\n';

        cout<<"Press 1 to continue, -1 to quit: ";
        outFile<<"Press 1 to continue, -1 to quit: ";
        cin>>option;
        outFile<<option;
        cout<<'\n';
        outFile<<'\n';
    }while(option!=-1);
    
    return 0;
}