#include <iostream>
#include <cstdlib>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}node_t;

node_t* createNode(int data){
    node_t * new_node = (node_t *)malloc(sizeof(node_t *));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}

void insertAtTheBeginning(int data, node_t **head, node_t **tail){
    node_t * temp = createNode(data);
    if(*head==NULL){
        *head=temp;
        *tail=temp;
    }
    else {
        (*head)->prev=temp;
        temp->right=*head;
        *head=temp;
    }
}

int deleteFromTheEnd(node_t **head, node_t **tail){
    if (*tail==NULL){
        return -1;
    }
    else if(*head==*tail){
        int temp = (*tail)->data;
        *head=NULL;
        *tail=NULL;
        return temp;
    }
    else {
        node_t *temp = *tail;
        temp->prev=*tail;
        (*tail)->next=NULL;
        return temp->data;
    }
}

int main(){
    return 0;
}