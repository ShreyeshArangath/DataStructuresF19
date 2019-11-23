#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}linked_list_t;

linked_list_t* createNode(int key){
    linked_list_t* new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
    new_node->data=key;
    new_node->next=NULL;
    return new_node;
}

int hash_function(int key, int size){
    return key%size;
}

void init_hash_map(linked_list_t** hash_map, int size){
    for(int i=0; i<size; i++){
        hash_map[i]=(linked_list_t *)malloc(sizeof(linked_list_t));
        hash_map[i]->next=NULL;
    }
}

linked_list_node_t* insertInOrder(int data, linked_list_node_t *head){
    linked_list_node_t *cur = head; //Pointer to the current node in the list
    linked_list_node_t *prev = head;//Pointer to the previous node in the list
    linked_list_node_t *new_node = createNode(data); //Creates a new node to be inserted into the list. 

    if (head == NULL){
        head=new_node;
        return *head;
    }
    else if (head->data >= data){
        new_node->next=head;
        head=new_node;
        return head;
    }
    while(cur!=NULL && cur->data < data){
        prev=cur;
        cur=cur->next;
    }
    prev->next=new_node;
    new_node->next=cur;

    return head;
}


int INSERT(linked_list_t** hash_map, int key, int size){
    int index = hash_function(key, size);
    linked_list_t* new_node = createNode(key);
    if(hash_map[index]->next==NULL){
       hash_map[index]->next=new_node;
   }
   else{
      
       
    //    linked_list_t* temp = hash_map[index]->next;
    //    hash_map[index]->next = new_node;
    //    hash_map[index]->next->next=temp;
   }
   return index;
}

void print_sub_list(linked_list_t* head){
    linked_list_t *cur = head; //Stores the pointer to the current node in the list. 
    while(cur!=NULL){
        std::cout<<cur->data<<"-> ";
        cur=cur->next;
    }
}

void PRINT(linked_list_t **hash_map, int size){
    for(int i=0; i<size; i++){
        cout<<i<<": ";
        if(hash_map[i]->next!=NULL){
            print_sub_list(hash_map[i]->next);
        }
        cout<<endl;
    }
}

int main(){
    int size;
    int index;
    int key;
    int option;

    cout<<"Enter the container size of the hash map: ";
    cin>>size;
    linked_list_t* hash_map[size];
    init_hash_map(hash_map, size);
    do{
        cout<<"1. Insert an element into the hash map"<<endl;
        cout<<"2. Display the hash map"<<endl;
        cout<<"-1. Quit"<<endl;
        cin>>option;
        switch(option){
            case 1: {
                cout<<"What value would you like to insert? ";
                cin>>key;
                index=INSERT(hash_map, key, size);
                cout<<"The key "<<key<<" was inserted at index "<<index<<endl;
                break;
            }
            case 2: {
                PRINT(hash_map, size);
                break;
            }
        }
    }while(option!=-1);

    return 0;
}


