#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#define MAX 100
using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE 0

// -------------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab7.cpp
// SPECIFICATION: Implement a program that takes in an expression and creates an expression tree. 
// FOR: CS 2413 Data Structure 001 501
//
// 
//ASSUMPTIONS: 
// 1. Since the problem statement doesn't explicitly state the use of multi-digit/
// multivariable elements within the expression. I have decided to ignore it. 
//
// NOTE: The solution handles parenthesis. 
//
//REFERENCES: 
//I have re-used my code from Lab 2 to handle some of the questions.
//
// TEST CASES: In the output file
// --------------------------------------------------------------------------------

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
}tree_node_t;

typedef struct StackNode {
    tree_node_t* data;
    struct StackNode* next;
}stack_node_t;



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
    char error[MAX]="Stack Overflow - Cannot PUSH onto the stack. \n";
    if(isFULL(stack,top)){
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
    char error[MAX]= "Cannot POP off the stack. The stack is empty. \n";
    if(isEMPTY(stack, top)){
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
    if (*top!=-1) return stack[*top];
    cout<<"Nothing in the stack. \n";
}

// NAME: isBalance
// INPUT PARAMETERS: stack, top - index of the top
// OUTPUT: Returns TRUE if the expression is balanced. 
int isBalance(char* stack, int top){
    char temp_stack[MAX]; //Used to check if the expression is balanced
    int temp_top=-1; //Value of the top of the stack
    int balanced =0; //Flag value for balanced
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
    return (element=='+' || element=='-' || element=='*' || element=='/' || element=='%');
}

// NAME: inFixToPostFix
// INPUT PARAMETERS: expression (array of char), output (array of char)
// OUTPUT: Returns the postfix form of an expression
// PURPOSE: To convert an infix expression to a postfix expression. 
int inFixToPostFix(char* expression, char* output){
    char stack[MAX]; //Stack that converts the expression from infix to postfix
    int index =0; //Index of the output array
    int top=-1; //Value of the index of the top of the stack
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

// NAME: createNewTreeNode
// INPUT PARAMETERS: data (a character)
// OUTPUT: Returns a new tree node
// PURPOSE: To create a new node
tree_node_t* createNewTreeNode(char data) {
    tree_node_t* temp = (tree_node_t *)malloc(sizeof(tree_node_t));
    temp->left=NULL;
    temp->right=NULL;
    temp->data =data;
    return temp;
}

// NAME: createStackNode
// INPUT PARAMETERS: data (a tree node) 
// OUTPUT: Returns a new tree node
// PURPOSE: To create a new node
stack_node_t* createStackNode(tree_node_t* data){
    stack_node_t* temp = (stack_node_t*)malloc(sizeof(stack_node_t));
    temp->data=data;
    return temp;
}

// NAME: push_linked_stack
// INPUT PARAMETERS: data (a tree node), pointer to the top of the stack 
// OUTPUT: Pushes an element to the stack
// PURPOSE: To push an element on the stack
stack_node_t* push_linked_stack(tree_node_t* data, stack_node_t** top){
    stack_node_t* temp = createStackNode(data); //The new node to push
    temp->next=*top;
    *top=temp;
    return *top;
}

// NAME: pop_linked_stack
// INPUT PARAMETERS: pointer to the top of the stack 
// OUTPUT: Pops an element off the stack
// PURPOSE: To pop an element off the stack
tree_node_t* pop_linked_stack(stack_node_t **top){
    if(*top==NULL){
        cout<<"Cannot pop from an empty stack";
        return NULL;
    }
    stack_node_t* temp = *top;
    tree_node_t* data = temp->data;
    (*top)=(*top)->next;
    free(temp);
    return data;
}

// NAME: isSymbol
// INPUT PARAMETERS: element (a char)
// OUTPUT: Returns true if a character is a symbol
// PURPOSE: To check if a character is a symbol
int isSymbol(char element){
    return 1 ? (element=='+' || element=='-' || element=='*' || element=='/' || element=='^' || element =='%') : 0;
}

// NAME: prefixNotation
// INPUT PARAMETERS: root (a tree node)
// OUTPUT: Converts the expression in the prefix notation
// PURPOSE: To convert the expression in the prefix notation
int prefixNotation(tree_node_t* root){
    if (root==NULL){
        return -1;
    }
    else{
        cout<<root->data;
        prefixNotation(root->left);
        prefixNotation(root->right);
    }
}


// NAME: infixNotation
// INPUT PARAMETERS: root (a tree node)
// OUTPUT: Converts the expression in the infix notation
// PURPOSE: To convert the expression in the infix notation
int infixNotation(tree_node_t* root){
    if (root==NULL){
        return -1;
    }
    else{
        infixNotation(root->left);
        cout<<root->data;
        infixNotation(root->right);
    }
}


// NAME: removeSpaces
// INPUT PARAMETERS: input array, output array
// OUTPUT: Changes the expression to not contain spaces
// PURPOSE: To remove the spaces
void removeSpaces(char* input, char* output){
    int j=0; // Index of the output array
    for(int i=0; i<strlen(input); i++){
        if(input[i]!=' '){
            output[j]=input[i];
            j++;
        }
    }
}

// NAME: countNodes
// INPUT PARAMETERS: root (a tree node)
// OUTPUT: Returns the number of nodes in the tree
// PURPOSE: To count the number of nodes in the tree
int countNodes(tree_node_t* root) { 
    if (root == NULL) return 0; 
    return (1 +countNodes(root->left) + countNodes(root->right)); 
} 

// NAME: isComplete
// INPUT PARAMETERS: root (a tree node), start (an integer), nodes (an integer)
// OUTPUT: Returns if the tree is complete or not
// PURPOSE: To check if the tree is compelte or not
int isComplete(tree_node_t* root, int start, int nodes){
    if(root==NULL) return 1;
    if(start>=nodes) return 0;
    return(isComplete(root->left, 2*start + 1, nodes) && isComplete(root->right, 2*(start+1) , nodes));
}

// NAME: convertPostFixToExpressionTree
// INPUT PARAMETERS: expression (a char array)
// OUTPUT: Returns a pointer to the root of the expression tree
// PURPOSE: To create an expression tree
tree_node_t* convertPostFixToExpressionTree(char* expression){
    stack_node_t* top; //Pointer to the top of the stack
    tree_node_t* expression_tree, *right_tree_node, *left_tree_node; //Pointers to the tree nodes
    for(int i=0; i<strlen(expression); i++){
        if(isSymbol(expression[i])){
            expression_tree = createNewTreeNode(expression[i]);
            right_tree_node=top->data;
            pop_linked_stack(&top);
            left_tree_node=top->data;
            pop_linked_stack(&top);

            expression_tree->right=right_tree_node;
            expression_tree->left= left_tree_node;
            
            push_linked_stack(expression_tree, &top);
        }
        else if(expression[i]!=' '){
            expression_tree = createNewTreeNode(expression[i]);
            push_linked_stack(expression_tree, &top);
        }
    }
    expression_tree = top->data;
    pop_linked_stack(&top);
    return expression_tree;
}

// NAME: toInteger
// INPUT PARAMETERS: element (a character)
// OUTPUT: Returns the integer value of the character
// PURPOSE: To convert char to int
int toInteger(char element){
    return int(element)-48;
}

// NAME: evaluateTheTree
// INPUT PARAMETERS: root (a tree node)
// OUTPUT: Returns the final value of the expression
// PURPOSE: To evaluate the expression
int evaluateTheTree(tree_node_t* root){
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL)return toInteger(root->data);

    int val_left = evaluateTheTree(root->left); //Value of the left subtree
    int val_right = evaluateTheTree(root->right); //Value of the right subtree

    if(root->data=='+') return val_left+val_right;
    else if(root->data=='-') return val_left-val_right;
    else if(root->data=='*')return val_left*val_right;
    else if(root->data=='/') return val_left/val_right;

}

int main(){
    char expression[MAX];
    tree_node_t* expression_tree;
    char postfix[MAX];
    char output[MAX];
    int option;
    cout<<"Enter an infix expression: ";
    cin>>expression;
    inFixToPostFix(expression, postfix);
    removeSpaces(postfix, output);
    expression_tree = convertPostFixToExpressionTree(postfix);
    do{
        cout<<"1. Display the postfix expression"<<endl;
        cout<<"2. Display the prefix expression"<<endl;
        cout<<"3. Check if it is complete"<<endl;
        cout<<"4. Evaluate the tree"<<endl;
        cout<<"-1. Quit"<< endl;
        cin>>option;

        switch(option){
            case 1: {
                cout<<output;
                cout<<endl;
                break;
            }
            case 2: {
                prefixNotation(expression_tree);
                cout<<endl;
                break;
            }
            case 3: {
                int nodes = countNodes(expression_tree);
                if(isComplete(expression_tree, 0, nodes))cout<<"It is complete."<<endl;
                else cout<<"Not complete. "<<endl;
                break;
            }
            case 4: {
                cout<<evaluateTheTree(expression_tree)<<endl;
                break;
            }
        }
    } while(option!=-1);

    return 0;
}