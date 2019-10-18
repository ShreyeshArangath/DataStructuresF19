// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab5.cpp
// SPECIFICATION: Write the essential functions for a Doubly Linked List and reverse the list using recursion. 
// FOR: CS 2413 Data Structure 001 501

// TEST CASES for Function :
// Test case1: Input is an integer
// Input: 12
// Expected output: 18. pointer to the node
// Actual Output: 18. pointer to the node
// Test case2: Input is not an integer
// Input: 'a'
// Expected Output: 97
// Actual output: 97

// TEST CASES for Function insertAtTheBeginning:
// Test case1: Input is an integer
// Input: 18, pointer to the head, pointer to the tail
// Expected output: head->18<-tail
// Actual Output: head->18<-tail
// Test case2: Input is not an integer
// Input: 'a', pointer to the head, pointer to the tail
// Expected Output: head->97<-tail
// Actual output: head->97<-tail

// TEST CASES for Function deleteFromTheEnd:
// Test case1: Empty doubly linked list
// Input:  pointer to the head, pointer to the tail (head->NULL<-tail)
// Expected output: -1
// Actual Output: -1
// Test case2: One element in the list
// Input:  pointer to the head, pointer to the tail (head->97<-tail)
// Expected Output:97, head->NULL<-tail
// Actual output: 97, head->NULL<-tail

// TEST CASES for Function print_list:
// Test case1: Empty List
// Input:  pointer to the head, pointer to the tail (head->NULL<-tail)
// Expected output: 
// Actual Output: 
// Test case2: One element in the list
// Input:  pointer to the head, pointer to the tail (head->97<-tail)
// Expected Output:97<=>NULL
// Actual output:97<=>NULL

// TEST CASES for Function reverse_doubly_linked_list:
// Test case1: One element in the list
// Input:  pointer to the head, pointer to the tail (head->97<-tail)
// Expected output: tail->97<-head
// Actual Output: tail->97<-head
// Test case2: Two elements in the list
// Input:  pointer to the head, pointer to the tail (head->97->18<-tail)
// Expected Output:tail->97->18<-head
// Actual output: tail->97->18<-head
// --------------------------------------------------------------------------------


#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

ofstream outputFile("output.txt"); 

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}node_t; 

// NAME: createNode
// INPUT PARAMETERS: data, an integer
// OUTPUT: Pointer to the new node
// PURPOSE: To create a new node for the doubly linked list. 

node_t* createNode(int data){
    node_t * new_node = (node_t *)malloc(sizeof(node_t)); //Allocates memory for the new node
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}

// NAME: insertAtTheBeginning
// INPUT PARAMETERS: data (an integer), pointer to the head, pointer to the tail
// OUTPUT: Inserts a new node at the beginning of the list. 
// PURPOSE: To insert a new node in the list. 
void insertAtTheBeginning(int data, node_t **head, node_t **tail){
    node_t * temp = createNode(data); //Create a temp node to insert into the doubly linked list. 
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

// NAME: deleteFromTheEnd
// INPUT PARAMETERS:  pointer to the head, pointer to the tail
// OUTPUT: Deletes a new node from the end of the list. 
// PURPOSE: To delete a new node in the list. 
int deleteFromTheEnd(node_t **head, node_t **tail){
    int data; //To store the data in the tail 
    if (*tail==NULL){
        return -1;
    }
    else if(*head==*tail){
        data=(*tail)->data;
        *head=NULL;
        *tail=NULL;
    }
    else {
        node_t *temp = *tail; //To store the address of the tail, to delete from the list. 
        data=temp->data;
        *tail=temp->prev;
        (*tail)->next=NULL;
        free(temp);
    }
    return data;
}


// NAME: print_list
// INPUT PARAMETERS:  pointer to the head, pointer to the tail
// OUTPUT: Prints out the list
// PURPOSE: To print out the doubly linked list
void print_list(node_t **head, node_t **tail){
   node_t *temp =*head; //Stores the address of the tail 
   while(temp!=NULL){
       cout<<temp->data<<" <=> ";
       outputFile<<temp->data<<" <=> ";
       temp=temp->next;
   }
   cout<<"NULL"<<endl;
    outputFile<<"NULL"<<endl;
}

// NAME: reverse_doubly_linked_list
// INPUT PARAMETERS:  pointer to the head
// OUTPUT: Pointer to the new head of the list
// PURPOSE: To reverse the doubly linked list. 
node_t* reverse_doubly_linked_list(node_t **head){
    if((*head)==NULL || (*head)->next==NULL){
        return *head;
    }
    else{
        node_t *new_head = reverse_doubly_linked_list(&((*head)->next)); //stores the value of the new head
        (*head)->next->next=(*head);
        (*head)->prev = (*head)->next;
        (*head)->next=NULL;
        return new_head;

    }
}

int main(){
    node_t *head = NULL; //Head pointer
    node_t *tail = NULL; //Tail pointer
    int option,value; //Variables to store the option and values in the menu.
    do{
        cout<<"1. Insert an element into the doubly linked list "<< endl;
        cout<<"2. Delete an element from the doubly linked list "<< endl;
        cout<<"3. Print the doubly linked list "<< endl;
        cout<<"4. Reverse the doubly linked list "<<endl;
        cout<<"-1. Exit "<<endl;
        cin>>option;
        
        outputFile<<"1. Insert an element into the doubly linked list "<< endl;
        outputFile<<"2. Delete an element from the doubly linked list "<< endl;
        outputFile<<"3. Print the doubly linked list "<< endl;
        outputFile<<"4. Reverse the doubly linked list "<<endl;
        outputFile<<"-1. Exit "<<endl;
        outputFile<<option<<endl;

        switch (option){
            case 1:
            {
                cout<<"Please enter a number that you would like to insert: ";
                outputFile<<"Please enter a number that you would like to insert: ";
                cin>>value;
                outputFile<<value;
                insertAtTheBeginning(value, &head, &tail);
                break;
            }
            case 2:
            {   
                value=deleteFromTheEnd(&head,&tail);
                cout<<value<<" has been deleted from the list."<<endl;
                outputFile<<value<<endl;
                break;
            }
            case 3 : {
                print_list(&head,&tail);
                break;
            }
            case 4: {
                head=reverse_doubly_linked_list(&head);
                node_t *temp =head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                tail=temp;
                break;
            }
        }
        cout<<"\n";
        outputFile<<endl;
    }while(option!=-1);
    return 0;
}