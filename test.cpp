#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 100
using namespace std;

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
}tree_node_t;

typedef struct StackNode {
    tree_node_t* data;
    struct StackNode* next;
}stack_node_t;

tree_node_t* createNewTreeNode(char data) {
    tree_node_t* temp = (tree_node_t *)malloc(sizeof(tree_node_t));
    temp->left=NULL;
    temp->right=NULL;
    temp->data =data;
    return temp;
}

void reverseArray(int arr[], int start, int end) 
{ 
    while (start < end){
        int temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
}      

int isSymbol(char element){
    return 1 ? (element=='+' || element=='-' || element=='*' || element=='/' || element=='^' || element =='%') : 0;
}

void changeToExpressionTree(char* expression){
    stack_node_t* temp_stack;
    tree_node_t* tree, temp_tree_1, temp_tree_2;
    for(int i=0; i<strlen(expression); i++){
        if(isSymbol(expression[i])){
            tree = 
        }
    }
}

int main(){
    tree_node_t *root;
    tree_node_t *cur;
    char expression[MAX];
    return 0;
}