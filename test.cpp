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

stack_node_t* createStackNode(tree_node_t* data){
    stack_node_t* temp = (stack_node_t*)malloc(sizeof(stack_node_t));
    temp->data=data;
    return temp;
}

stack_node_t* PUSH(tree_node_t* data, stack_node_t** top){
    stack_node_t* temp = createStackNode(data);
    temp->next=*top;
    *top=temp;
    return *top;
}

tree_node_t* POP(stack_node_t **top){
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


int isSymbol(char element){
    return 1 ? (element=='+' || element=='-' || element=='*' || element=='/' || element=='^' || element =='%') : 0;
}

void changeToExpressionTree(char* expression){
    stack_node_t* temp_stack_top;
    tree_node_t* tree, *temp_tree_1, *temp_tree_2;
    for(int i=0; i<strlen(expression); i++){
        if(isSymbol(expression[i])){
            tree = createNewTreeNode(expression[i]);
            temp_tree_1=temp_stack_top->data;
            POP(&temp_stack_top);
            temp_tree_2=temp_stack_top->data;
            POP(&temp_stack_top);

            tree->right=temp_tree_1;
            tree->left= temp_tree_2;

        
        }
    }
}

int main(){
    tree_node_t *root;
    tree_node_t *cur;
    char expression[MAX];
    return 0;
}