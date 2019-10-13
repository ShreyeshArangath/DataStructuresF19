#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}node_t;

node_t* createNode(int data){
    node_t * new_node = (node_t *)malloc(sizeof(node_t));
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
        temp->next=*head;
        (*head)->prev=temp;
        *head=temp;
    }
}

int deleteFromTheEnd(node_t **head, node_t **tail){
    int data;
    if (*tail==NULL){
        return -1;
    }
    else if(*head==*tail){
        data=(*tail)->data;
        *head=NULL;
        *tail=NULL;
    }
    else {
        node_t *temp = *tail;
        data=temp->data;
        temp->prev=*tail;
        (*tail)->next=NULL;
        free(temp);
    }
    return data;
}

void print_list(node_t **head, node_t **tail){
   node_t *temp =*head;
   while(temp!=NULL){
       cout<<temp->data<<" <=> ";
       temp=temp->next;
   }
   cout<<"NULL"<<endl;
}

node_t* reverse_doubly_linked_list(node_t **head){
    if((*head)==NULL || (*head)->next==NULL){
        return *head;
    }
    else{
        node_t *new_head = reverse_doubly_linked_list(&((*head)->next));
        (*head)->next->next=(*head);
        (*head)->prev = (*head)->next;
        (*head)->next=NULL;
        return new_head;

    }
}

int main(){
    node_t *head = NULL;
    node_t *tail = NULL;
    insertAtTheBeginning(18,&head,&tail);
    insertAtTheBeginning(19,&head,&tail);
    print_list(&head,&tail);
    deleteFromTheEnd(&head,&tail);
    print_list(&head,&tail);
    node_t* new_head = reverse_doubly_linked_list(&head);
    print_list(&new_head,&tail);

    return 0;
}