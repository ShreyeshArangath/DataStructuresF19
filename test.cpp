#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct Node {
    float data;
    struct Node* next;
}linked_list_node_t;


linked_list_node_t* createNewNode(float data){
    linked_list_node_t *temp = (linked_list_node_t *)malloc(sizeof(linked_list_node_t));
    temp->data=data;
    return temp;
}

linked_list_node_t* insertAtBeginning(float data, linked_list_node_t **head,linked_list_node_t **tail){
    linked_list_node_t *temp = createNewNode(data);
    if (*head == NULL and *tail==NULL){
        *head=temp;
        *tail=temp;
        (*head)->next=NULL;
    }
    else{
        temp->next=*head;
        *head=temp;
    }
    return *head;
}

linked_list_node_t* insertAtTheEnd(float data, linked_list_node_t**head, linked_list_node_t **tail){
    linked_list_node_t *temp = createNewNode(data);
    if (*tail==NULL and *head==NULL){
        *head=temp;
        *tail=temp;
        (*tail)->next=NULL;
    }
    else{
        (*tail)->next=temp;
        *tail=temp;
        (*tail)->next=NULL;
    }
    return *head;
}

linked_list_node_t* insertAfterTheValue(float dataToInsert, float dataToSearch, linked_list_node_t** head, linked_list_node_t **ta){

}

void printFunction(linked_list_node_t **head){
    linked_list_node_t *cur=*head;
    while(cur!=NULL){
        std::cout<<cur->data<<"\n";
        cur=cur->next;
    }
}

int main(){
    linked_list_node_t *head = NULL;
    linked_list_node_t *tail = NULL;
    insertAtBeginning(1.2,&head,&tail);
    insertAtBeginning(2.4,&head,&tail);
    insertAtTheEnd(3.2,&head,&tail);
    insertAtBeginning(3.3,&head,&tail);
    printFunction(&head);
    return 0;
}