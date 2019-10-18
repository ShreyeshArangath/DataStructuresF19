#include <iostream>
#include <cstdlib>

using namespace std;
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}tree_node_t;

tree_node_t* createTreeNode(int data){
    tree_node_t *new_node = (tree_node_t *)malloc(sizeof(tree_node_t));
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

tree_node_t* insert(int data, tree_node_t **root){
    tree_node_t *new_node = createTreeNode(data);
    if(*root==NULL){
        *root=new_node;
    }
    else{
        if(data <= (*root)->data){
            (*root)->left=insert(data,&((*root)->left));
        }
        else{
            (*root)->right = insert(data, &((*root)->right));
        }
    }
    return *root;
}

void breadth_first_print(tree_node_t** root){
    if(*root==NULL){
        return ;
    }
    else{
        cout<<(*root)->data;
        if((*root)->left!=NULL){
            cout<<(*root)->left->data;
        }
        else if((*root)->right!=NULL){
            cout<<(*root)->right->data;
        }
        else{
            return;
        }
        breadth_first_print(&((*root)->left));
        breadth_first_print(&((*root)->right));

    }
}

int main(){
    tree_node_t* root=NULL;
    insert(10,&root);
    breadth_first_print(&root);
    return 0;
}