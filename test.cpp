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
    if (*head == NULL && *tail==NULL){
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
    if (*tail==NULL && *head==NULL){
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

linked_list_node_t* insertAfterTheValue(float dataToInsert, float dataToSearch, linked_list_node_t** head, linked_list_node_t **tail){
    
    linked_list_node_t *cur = *head;
    while(cur!=NULL && cur->data!=dataToSearch){
        cur=cur->next;
    }

    if(cur==NULL){
        std::cout<<"No specified records exist. Insertion is not possible. \n";
    }
    else{
        if (cur==*head){
            insertAtBeginning(dataToInsert,head,tail);
        }
        else if(cur==*tail){
            insertAtTheEnd(dataToInsert,head,tail);
        }
        else {
            linked_list_node_t *new_node = createNewNode(dataToInsert);
            linked_list_node_t *temp=cur->next;
            cur->next=new_node;
            new_node->next=temp;
        }

    }
    return *head;
}


linked_list_node_t * deleteAtTheBeginning(linked_list_node_t **head, linked_list_node_t **tail) {
    if (*head==NULL){
        std::cout<<"No records exist in the list. Deletion not possible.\n";
    }
    else{
        if ((*head)->next == NULL){
            *head=*tail=NULL;
            return *head;
        }
        linked_list_node_t *temp = *head;
        *head=(*head)->next;
        free(temp);

    }
    return *head;
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
    head=insertAtBeginning(1.2,&head,&tail);
    head=insertAtBeginning(2.4,&head,&tail);
    head=insertAtTheEnd(3.2,&head,&tail);
    head=insertAtBeginning(3.3,&head,&tail);
    printFunction(&head);
    std::cout<<"\n";
    head=insertAfterTheValue(1.6,2.4,&head,&tail);
    printFunction(&head);
    deleteAtTheBeginning(&head,&tail);
    deleteAtTheBeginning(&head,&tail);
    deleteAtTheBeginning(&head,&tail);
    deleteAtTheBeginning(&head,&tail);
    std::cout<<"\n";
    printFunction(&head);
    return 0;
}