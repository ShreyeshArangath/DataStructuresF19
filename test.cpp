#include <cstdlib>
#include <iostream>
#include <fstream>

typedef struct Node {
    float data;
    struct Node* next;
}linked_list_node_t;


linked_list_node_t* createNewNode(float data){
    linked_list_node_t *temp = (linked_list_node_t *)malloc(sizeof(linked_list_node_t));
    temp->data=data;
    temp->next=NULL;
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
        std::cout<<"No records exist in the list. Deletion at the beginning is not possible.\n";
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

linked_list_node_t * deleteAtTheEnd(linked_list_node_t **head, linked_list_node_t **tail){
    if (*tail == NULL && *head==NULL){
        std::cout<<"No records exist in the list. Deletion from the end is not possible.\n";
    }
    else{
        linked_list_node_t *cur = *head;
        if (cur==*tail){
            *head=*tail=NULL;
            free(cur);
            return *head;
        }
        while(cur->next != *tail){
            cur=cur->next;
        }
        linked_list_node_t *temp = *tail;
        cur->next=NULL;
        *tail=cur;
        free(temp);
    }
    return *head;
}

linked_list_node_t* insertInOrder(float data, linked_list_node_t **head, linked_list_node_t **tail){
    linked_list_node_t *cur = *head;
    linked_list_node_t *prev = *head;
    linked_list_node_t *new_node = createNewNode(data);


    if (*head == NULL){
        *head=*tail=new_node;
        return *head;
    }
    else if ((*head)->data >= data){
        new_node->next=*head;
        *head=new_node;
        return *head;
    }
    while(cur!=NULL && cur->data < data){
        prev=cur;
        cur=cur->next;
    }
    prev->next=new_node;
    new_node->next=cur;

    return *head;
}

linked_list_node_t* readFromFile(char* file_name,linked_list_node_t **head,linked_list_node_t **tail){
    std::ifstream file(file_name);
    float temp;
    while(file >> temp){
        insertInOrder(temp,head,tail);
    }
    return *head;
}

float findMax(linked_list_node_t **head){
    if (*head == NULL){
        std::cout<<"No records exist in the list. Maximum cannot be found.\n";
        return 0.0;
    }
    linked_list_node_t *cur = *head;
    float max = cur->data;
    while(cur!=NULL){
        if (cur->data > max){
            max=cur->data;
        }
        cur=cur->next;
    }
    return max;
}

float findMin(linked_list_node_t **head){
    if(*head==NULL){
        std::cout << "No records exist in the list. Minimum cannot be found.\n";
        return 0.0;
    }
    linked_list_node_t *cur = *head;
    float min = cur->data;
    while(cur!=NULL){
        if (cur->data < min){
            min=cur->data;
        }
        cur=cur->next;
    }
    return min;
}

int sizeOfList(linked_list_node_t **head){
    int size=0;
    linked_list_node_t *cur = *head;
    if (cur==NULL) return 0;
    do
    {
        size+=1;
        cur=cur->next;
    }while(cur!=NULL);
    return size;
}

float mean(linked_list_node_t **head){
    int length = sizeOfList(head);
    float sum=0;
    linked_list_node_t *cur = *head;
    if(cur==NULL){
        std::cout<<"There are no elements in the list.";
        return 0;
    }
    while(cur!=NULL){
        sum+=cur->data;
        cur=cur->next;
    }
    return sum/length;
}

float median(linked_list_node_t **head){
    
}

void printFunction(linked_list_node_t **head){
    linked_list_node_t *cur=*head;
    while(cur!=NULL){
        std::cout<<cur->data<<"\n";
        cur=cur->next;
    }
}

int main(){
    char file_name[100]="FloatLinkedListInput.txt";
    linked_list_node_t *head = NULL;
    linked_list_node_t *tail = NULL;
    // head=insertAtBeginning(1.2,&head,&tail);
    // head=insertAtBeginning(2.4,&head,&tail);
    // head=insertAtTheEnd(3.2,&head,&tail);
    // head=insertAtBeginning(3.3,&head,&tail);
    // printFunction(&head);
    // std::cout<<"\n";
    // head=insertAfterTheValue(1.6,2.4,&head,&tail);
    // printFunction(&head);
    // deleteAtTheBeginning(&head,&tail);
    // std::cout<<"\n";
    // printFunction(&head);
    // deleteAtTheEnd(&head,&tail);
    // printFunction(&head);
    readFromFile(file_name,&head,&tail);
    printFunction(&head);
    std::cout<<"\n";
    std::cout<< "The max is: "<<findMax(&head);
    std::cout<<"\n";
    std::cout<< "The min is: " <<findMin(&head);
    std::cout<<"\n";
    std::cout<<sizeOfList(&head) << "\n";
    std::cout<<mean(&head) << "\n";
    return 0;
}