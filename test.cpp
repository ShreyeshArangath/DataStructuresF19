// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab1.cpp
// SPECIFICATION: Create a linked list and its associated functions such as insertion, deletion, max, min, mode, mean, and median.
// FOR: CS 2413 Data Structure Section 001 - 501

// TEST CASES for Function insertAtTheBeginning:
// Test case1: The test input is a float data along with linked list pointers.   //List head->NULL
    // Input: 3.2,&head,&tail
    // Expected output: head->3.2->NULL
    // Actual Output: head->3.2->NULL
// Test case2: Testing invalid char input //List: head-> 3.2->NULL
    // Input: 'a',&head,&tail
    // Expected Output: head->'a'->3.2->->NULL
    // Actual output: head->97->3.2->->NULL


// TEST CASES for insertAtTheEnd:
// Test case1: The test input is a float data along with linked list pointers. //List - head->97->3.2->NULL
    // Input: 1.6,&head,&tail
    // Expected output: head->97->3.2->1.6->NULL
    // Actual Output: head->97->3.2->1.6->NULL
// Test case2: Testing invalid char input  //List: head->97->3.2->NULL
    // Input: 'b',&head,&tail
    // Expected Output:head->97->3.2->'b'->NULL
    // Actual output: head->97->3.2->98->NULL

// TEST CASES for insertAfterTheValue:
// Test case1: Basic float input. //List - 3.2->NULL
    // Input: 2.4,3.2,&head,&tail
    // Expected output: 3.2->2.4
    // Actual Output:  3.2->2.4
// Test case2: Testing invalid char input
    // Input: 3.2,'b',&head,&tail //3.2->NULL
    // Expected Output:3.2->'b'
    // Actual output: 3.2->98

// TEST CASES for Function deleteAtTheBeginning:
// Test case1: Basic deletion using floats//List: 3.2->98->16->NULL
    // Input: &head,&tail  
    // Expected output: head->98->16
    // Actual Output: head->98->16
// Test case2: Deletion from an empty list.  //List: head->NULL
    // Input: &head,&tail
    // Expected Output: No records exist in the list. Deletion at the beginning is not possible.
    // Actual output: No records exist in the list. Deletion at the beginning is not possible.

// TEST CASES for Function deleteAtTheEnd:
// Test case1:  Basic deletion using floats //List: 3.2->98->16->NULL
    // Input: &head,&tail
    // Expected output: 3.2->98->NULL
    // Actual Output:  3.2->98->NULL
// Test case2:
    // Input: Deletion from an empty list. //List: head->NULL
    // Expected Output: No records exist in the list. Deletion from the end is not possible.
    // Actual output: No records exist in the list. Deletion from the end is not possible.

// TEST CASES for Function deleteNodeWithValue: //List: 3.2->98->16->NULL
// Test case1: Deleting a value that exists in the list. 
    // Input: 98,&head,&tail
    // Expected output: 3.2->16->NULL
    // Actual Output: 3.2->16->NULL
// Test case2:  
    // Input: Deleting a value that doesn't exist in the list //List: 3.2->98->16->NULL
    // Expected Output: No records exist in the list with the specified values. Deletion not possible.
    // Actual output: No records exist in the list with the specified values. Deletion not possible.

// TEST CASES for Function insertInOrder:
// Test case1: Inserting a float value //List: 3.2->9.8->16->NULL
    // Input: 17, &head, &tail
    // Expected output: 3.2->9.8->16->17->NULL
    // Actual Output: 3.2->9.8->16->17->NULL
// Test case2: Inserting a char value //List: 3.2->9.8->16->NULL
    // Input: 'a', &head, &tail
    // Expected Output: 3.2->9.8->16->'a'->NULL
    // Actual output: 3.2->9.8->16->97->NULL

// TEST CASES for Function selectionSort:
// Test case1: Sorting a list of floats.  //List: 3.2->98->16->NULL
    // Input: &head
    // Expected output: 3.2->16->98->NULL
    // Actual Output: 3.2->16->98->NULL
// Test case2:  Sorting a list of characters. //List : 'a'->'z'->'c'->NULL
    // Input: &head
    // Expected Output: 'a'->'c'->'z'->NULL
    // Actual output: 97->99->122->NULL


// TEST CASES for Function readFromFile:
// Test case1: Providing a valid file name
    // Input: FloatingLinkedListInput.txt, &head, &tail
    // Expected output: Reads in all the data from the file and stores it in the list. 
    // Actual Output: Reads in all the data from the file and stores it in the list. 
// Test case2:  Providing an invalid file name. 
    // Input: FlotingLL.txt, &head, &tail
    // Expected Output: Your file does not exist.
    // Actual output: Your file does not exist.

// TEST CASES for Function findMax:
// Test case1: 3.2->98->16->NULL
    // Input: &head
    // Expected output: 98
    // Actual Output: 98
// Test case2: NULL  
    // Input: &head
    // Expected Output: No records exist in the list. Maximum cannot be found.
    // Actual output: No records exist in the list. Maximum cannot be found.

// TEST CASES for Function findMin:
// Test case1:  3.2->98->16->NULL
    // Input: &head
    // Expected output: 3.2
    // Actual Output: 3.2
// Test case2:  NULL
    // Input: &head
    // Expected Output: No records exist in the list. Maximum cannot be found.
    // Actual output: No records exist in the list. Maximum cannot be found.

// TEST CASES for Function sizeOfList:
// Test case1:  3.2->98->16->NULL
    // Input: &head
    // Expected output: 3
    // Actual Output: 3
// Test case2:  NULL
    // Input: &head
    // Expected Output: 0
    // Actual output: 0

// TEST CASES for Function mean:
// Test case1:  3.2->98->16->NULL
    // Input: &head
    // Expected output: 39.0667
    // Actual Output: 39.0667
// Test case2:  
    // Input: NULL
    // Expected Output: There are no elements in the list.
    // Actual output: There are no elements in the list.

// TEST CASES for Function median_helper_function:
// Test case1:  3.2->98->16->NULL
    // Input: &length, &even-odd
    // Expected output: 1
    // Actual Output: 1
// Test case2:  
    // Input: NULL
    // Expected Output: 0
    // Actual output: 0

// TEST CASES for Function median:
// Test case1:  3.2->98->16->NULL
    // Input: &head
    // Expected output: 98  
    // Actual Output: 98
// Test case2:  3.2->98->16->17->NULL
    // Input: &head
    // Expected Output:57
    // Actual output: 57

// TEST CASES for Function mode:
// Test case1:  3.2->98->16->16->NULL
    // Input: &head
    // Expected output: 16
    // Actual Output: 16
// Test case2:  3.2->98->16->NULL
    // Input: &head
    // Expected Output: -1 (DNE)
    // Actual output: -1 

// TEST CASES for Function range:
// Test case1:  3.2->98->16->NULL
    // Input: &head
    // Expected output: 94.8
    // Actual Output: 94.8
// Test case2:  NULL
    // Input: &head
    // Expected Output: 0
    // Actual output: 0

// TEST CASES for Function removeDuplicates:
// Test case1:  3.2->98->16->16->NULL
    // Input: &head
    // Expected output: 3.2->98->16->NULL
    // Actual Output: 3.2->98->16->NULL
// Test case2:  3.2->98->16->NULL
    // Input: &head
    // Expected Output: 3.2->98->16->NULL
    // Actual output: 3.2->98->16->NULL

// TEST CASES for Function printFunction:
// Test case1: 3.2->98->16->NULL
    // Input: &head
    // Expected output: 
        // 3.2
        // 98
        // 16
    // Actual Output:
        // 3.2
        // 98
        // 16
// Test case2:  NULL
    // Input: &head
    // Expected Output: ''
    // Actual output:  ''


// ---------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <fstream>

typedef struct Node {
    float data;
    struct Node* next;
}linked_list_node_t;

// --------------------------------------------------------------------------------
// NAME: createNewNode
// INPUT PARAMETERS: data (float number)
// OUTPUT: A node for the linked list. 
// PURPOSE: The function creates a new node for a linked list.
// --------------------------------------------------------------------------------

linked_list_node_t* createNewNode(float data){
    linked_list_node_t *temp = (linked_list_node_t *)malloc(sizeof(linked_list_node_t)); // Allocates memory for a linked list node. 
    temp->data=data;
    temp->next=NULL;
    return temp;
}

// --------------------------------------------------------------------------------
// NAME: insertAtTheBeginning
// INPUT PARAMETERS: data (float number), pointer to the head, pointer to the tail. 
// OUTPUT: New node generated at the head. Returns a pointer to the head node. 
// PURPOSE: To create a new node that is inserted at the head of the list. 
// --------------------------------------------------------------------------------

linked_list_node_t* insertAtBeginning(float data, linked_list_node_t **head,linked_list_node_t **tail){
    //Stores the newly created node for insertion at the beginning
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

// --------------------------------------------------------------------------------
// NAME: insertAtTheEnd
// INPUT PARAMETERS: data (float number), pointer to the head, pointer to the tail. 
// OUTPUT:  New node generated at the tail. Returns a pointer to the head node. 
// PURPOSE: To create a new node that is inserted at the end of the list. 
// --------------------------------------------------------------------------------

linked_list_node_t* insertAtTheEnd(float data, linked_list_node_t**head, linked_list_node_t **tail){
    //Stores the newly created node for insertion at the beginning
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

// --------------------------------------------------------------------------------
// NAME: insertAfterTheValue
// INPUT PARAMETERS: dataToInsert (float number),dataToSearch (float number), pointer to the head, pointer to the tail. 
// OUTPUT:  New node generated after a value occurs in a list. Returns a pointer to the head node. 
// PURPOSE: To create a new node that is inserted after the value is found in the list. 
// -------------------------------------------------------------------------------
linked_list_node_t* insertAfterTheValue(float dataToInsert, float dataToSearch, linked_list_node_t** head, linked_list_node_t **tail){
    
    linked_list_node_t *cur = *head; // To store the current node while searching a value
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
            linked_list_node_t *new_node = createNewNode(dataToInsert); //Holds the new node. 
            linked_list_node_t *temp=cur->next; //Holds the address of node after the current node. 
            cur->next=new_node;
            new_node->next=temp;
        }

    }
    return *head;
}

// --------------------------------------------------------------------------------
// NAME: deleteAtTheBeginning
// INPUT PARAMETERS:  pointer to the head, pointer to the tail. 
// OUTPUT:  Deletes the first node in the list. Returns a pointer to the head node. 
// PURPOSE: To delete the first node in the list. 
// -------------------------------------------------------------------------------
linked_list_node_t * deleteAtTheBeginning(linked_list_node_t **head, linked_list_node_t **tail) {
    if (*head==NULL){
        std::cout<<"No records exist in the list. Deletion at the beginning is not possible.\n";
    }
    else{
        if ((*head)->next == NULL){
            *head=*tail=NULL;
            return *head;
        }
        linked_list_node_t *temp = *head; // Temporarily holds the address of the head for deletion. 
        *head=(*head)->next;
        free(temp);

    }
    return *head;
}

// --------------------------------------------------------------------------------
// NAME: deleteAtTheEnd
// INPUT PARAMETERS:  pointer to the head, pointer to the tail. 
// OUTPUT:  Deletes the last node in the list. Returns a pointer to the head node. 
// PURPOSE: To delete the last node in the list. 
// -------------------------------------------------------------------------------
linked_list_node_t * deleteAtTheEnd(linked_list_node_t **head, linked_list_node_t **tail){
    if (*tail == NULL && *head==NULL){
        std::cout<<"No records exist in the list. Deletion from the end is not possible.\n";
    }
    else{
        linked_list_node_t *cur = *head; //Stores the pointer to the cur node in the list. 
        if (cur==*tail){
            *head=*tail=NULL;
            free(cur);
            return *head;
        }
        while(cur->next != *tail){
            cur=cur->next;
        }
        linked_list_node_t *temp = *tail; //Stores the pointer to the tail for deletion. 
        cur->next=NULL;
        *tail=cur;
        free(temp);
    }
    return *head;
}

// --------------------------------------------------------------------------------
// NAME: deleteNodeWithValue
// INPUT PARAMETERS:  data, pointer to the head, pointer to the tail. 
// OUTPUT:  Deletes the node with the value specified by the user. Returns a pointer to the head node. 
// PURPOSE: To delete the last node in the list. 
// -------------------------------------------------------------------------------

linked_list_node_t* deleteNodeWithValue(int data, linked_list_node_t **head, linked_list_node_t **tail){
    linked_list_node_t *cur=*head; //Pointer to the current node in the list.
    linked_list_node_t *prev=NULL; // Pointer to the previous node in the list. 
    while(cur!=NULL && cur->data!=data){
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL){
        std::cout<<"No records exist in the list with the specified values. Deletion not possible. \n";
        return NULL;
    }
    else{
        if(cur==*head){
            deleteAtTheBeginning(head,tail);
        }
        else if(cur==*tail){
            deleteAtTheEnd(head,tail);
        }
        else{
            linked_list_node_t *temp=cur; //Holds the pointer to the current node for deletion. 
            prev->next=temp->next;
            free(temp);
        }
    }
    return *head;
    

}

// --------------------------------------------------------------------------------
// NAME: insertInOrder
// INPUT PARAMETERS:  data, pointer to the head, pointer to the tail. 
// OUTPUT:  Inserts the node in order(ascending). Returns a pointer to the head node. 
// PURPOSE: To delete the last node in the list. 
// -------------------------------------------------------------------------------

linked_list_node_t* insertInOrder(float data, linked_list_node_t **head, linked_list_node_t **tail){
    linked_list_node_t *cur = *head; //Pointer to the current node in the list
    linked_list_node_t *prev = *head;//Pointer to the previous node in the list
    linked_list_node_t *new_node = createNewNode(data); //Creates a new node to be inserted into the list. 

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

// --------------------------------------------------------------------------------
// NAME: selectionSort
// INPUT PARAMETERS:  pointer to the head. 
// OUTPUT:  Inserts the node in ascending. Returns a pointer to the head node of a sorted list. 
// PURPOSE: To sort the list in ascending order. 
void selectionSort(linked_list_node_t** head) 
{ 
    linked_list_node_t* temp = *head; //Stores the pointer to the head node
    while (temp) {  
        linked_list_node_t* min = temp;  //Stores the pointer to the min element in the list. 
        linked_list_node_t* next_node= temp->next;  //Stores the pointer to the next element in the list. 
        while (next_node) { 
            if (min->data > next_node->data) 
                min = next_node; 
  
            next_node = next_node->next; 
        } 
        float value = temp->data;  //Stores the value of the current node in the list. 
        temp->data = min->data; 
        min->data = value; 
        temp = temp->next; 
    } 
} 

// --------------------------------------------------------------------------------
// NAME: readFromFile
// INPUT PARAMETERS:  file name, pointer to the head, pointer to the tail. 
// OUTPUT:  Inserts all the data in the file into the linked list. Returns a pointer to the head. 
// PURPOSE: Reads in all the data from the file into the linked list. 
// -------------------------------------------------------------------------------
linked_list_node_t* readFromFile(char* file_name,linked_list_node_t **head,linked_list_node_t **tail){
    std::ifstream file(file_name); //Creates a input file stream for the specified file name 
    if(file.fail()) {
        std::cout<<"Your file does not exist.";
        return *head;
    }
    float temp; // Stores distinct floating values in the file temporarily
    while(file >> temp){
        insertAtBeginning(temp,head,tail);
    }
    return *head;
}

// --------------------------------------------------------------------------------
// NAME: findMax
// INPUT PARAMETERS:  pointer to the head. 
// OUTPUT:  Returns the maximum element in the list. 
// PURPOSE: To find the maximum value in a linked list. 
// -------------------------------------------------------------------------------
float findMax(linked_list_node_t **head){
    if (*head == NULL){
        std::cout<<"No records exist in the list. Maximum cannot be found.\n";
        return 0.0;
    }
    linked_list_node_t *cur = *head; //Stores the pointer to the current element in a list. 
    float max = cur->data; //Stores the maximum value in a list. 
    while(cur!=NULL){
        if (cur->data > max){
            max=cur->data;
        }
        cur=cur->next;
    }
    return max;
}

// --------------------------------------------------------------------------------
// NAME: findMin
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Returns the minium element in the list. 
// PURPOSE: To find the minimum value in a linked list.  
// -------------------------------------------------------------------------------
float findMin(linked_list_node_t **head){
    if(*head==NULL){
        std::cout << "No records exist in the list. Minimum cannot be found.\n";
        return 0.0;
    }
    linked_list_node_t *cur = *head; //Stores the pointer to the current element in a list.
    float min = cur->data; //Stores the min value in a list. 
    while(cur!=NULL){
        if (cur->data < min){
            min=cur->data;
        }
        cur=cur->next;
    }
    return min;
}
// --------------------------------------------------------------------------------
// NAME: sizeOfList
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Returns the length of the list. 
// PURPOSE: To find the length of a linked list.  
// -------------------------------------------------------------------------------
int sizeOfList(linked_list_node_t **head){
    int size=0; //Stores the length of the linked list. 
    linked_list_node_t *cur = *head; //Stores the pointer to the current node in the list. 
    if (cur==NULL) return 0;
    do
    {
        size+=1;
        cur=cur->next;
    }while(cur!=NULL);
    return size;
}

// --------------------------------------------------------------------------------
// NAME: mean
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Returns the mean value of the list. 
// PURPOSE: To find the mean of a linked list.  
// -------------------------------------------------------------------------------
float mean(linked_list_node_t **head){
    int length = sizeOfList(head); //Stores the length of the linked list. 
    float sum=0; //Stores the sum of all the elements in the list. 
    linked_list_node_t *cur = *head; //Stores the pointer to the current node in the list. 
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

// --------------------------------------------------------------------------------------------------------------------------------------
// NAME: median_helper_function
// INPUT PARAMETERS: pointer to the length variable in the median function, pointer to the even-odd variable in the median function . 
// OUTPUT: Returns the index of the median value in the list. 
// PURPOSE: To find the index of the median value of a linked list.  
// --------------------------------------------------------------------------------------------------------------------------------------
int median_helper_function(int *length, int *even_odd){
    int index_of_median; //Stores the index of the median value. 
    if (*length%2==0){
        index_of_median=*length/2-1;
        *even_odd=0;
    }
    else{
        index_of_median=*length/2;
        *even_odd=1;
    }
    return index_of_median;
}
// --------------------------------------------------------------------------------
// NAME: median 
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Returns the median value of the list. 
// PURPOSE: To find the median of a linked list.  
// -------------------------------------------------------------------------------
float median(linked_list_node_t **head){
    int length = sizeOfList(head); //Stores the size of the list. 
    int even_odd; //Stores whether the number of elements is even/odd. 
    int index_of_median=median_helper_function(&length,&even_odd); //Stores the index of the median value. 
    float median; //Stores the median value. 
    int i=0; //Serves the purpose of a list iterator used to locate the median value. 
    linked_list_node_t *cur = *head; //Stores a pointer to the head node. 
    if (cur==NULL){
        return 0.0;
    }
    if (even_odd==1){
        while(cur!=NULL && i!=index_of_median){
            cur=cur->next;
            i++;
        }
        return cur->data;
    }
    else{
        while(cur!=NULL && i!=index_of_median){
            cur=cur->next;
            i++;
        }
        float first=cur->data;
        cur=cur->next;
        float second = cur->data;
        return (first+second)/2;
    }

}

// --------------------------------------------------------------------------------
// NAME: mode
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Returns the mode value of the list. 
// PURPOSE: To find the mode of a linked list.  
// -------------------------------------------------------------------------------
float mode(linked_list_node_t **head){
    linked_list_node_t *cur_pointer = *head; //Stores the pointer to the head node. 
    float mode=0.0; //Stores the mode value in the list. 
    int max=0; //Stores the max count of the occurence of a distinct data element. 
    while(cur_pointer!=NULL){
        int count=1;
        linked_list_node_t *search_pointer = cur_pointer->next;
        while(search_pointer!=NULL){
            if(cur_pointer->data == search_pointer->data){
                count++;
            }
            search_pointer=search_pointer->next;
        }
        if (count>max){
            max=count;
            mode=cur_pointer->data;
        }
        cur_pointer=cur_pointer->next;
    }
    if (max==1) return -1;
    return mode;
}

// --------------------------------------------------------------------------------
// NAME: range
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Returns the range value of the list. 
// PURPOSE: To find the range of a linked list.  
// -------------------------------------------------------------------------------
float range(linked_list_node_t **head){
    return findMax(head)-findMin(head);
}


// --------------------------------------------------------------------------------
// NAME: removeDuplicates
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Returns the mean value of the list. 
// PURPOSE: To find the mean of a linked list.  
// -------------------------------------------------------------------------------
void removeDuplicates( linked_list_node_t **head){
    
    linked_list_node_t *temp; //Stores the value of the node to be deleted. 
    if(*head==NULL){
        return;
    }
    if((*head)->next!=NULL){
        if((*head)->data == (*head)->next->data){
            temp=(*head)->next;
            (*head)->next=(*head)->next->next;
            free(temp);
            removeDuplicates(head);
        }
        else{
            removeDuplicates(&((*head)->next));
        }
    }
}

// --------------------------------------------------------------------------------
// NAME: printFunction
// INPUT PARAMETERS: pointer to the head . 
// OUTPUT: Prints out the list. 
// PURPOSE: To print all the elements of a linked list.  
// -------------------------------------------------------------------------------
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

    // insertAtBeginning(3.2,&head,&tail);
    // insertAtBeginning('a',&head,&tail);
    // insertAtTheEnd(1.6,&head,&tail);
    // insertAtTheEnd('b',&head,&tail);
    // insertAfterTheValue(2.4,3.2,&head,&tail);
    // insertAfterTheValue(2.4,'b',&head,&tail);

    // head=insertAtBeginning(2.4,&head,&tail);
    // head=insertAtTheEnd(3.2,&head,&tail);
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

    // readFromFile(file_name,&head,&tail);
    // printFunction(&head);
    // std::cout<<"\n";
    // std::cout<< "The max is: "<<findMax(&head);
    // std::cout<<"\n";
    // std::cout<< "The min is: " <<findMin(&head);
    // std::cout<<"\n";
    // std::cout<<"The size of the list is: "<<sizeOfList(&head) << "\n";
    // std::cout<<"The mean value of the list is: "<<mean(&head) << "\n";
    // std::cout<<"The median value of the list is: "<<median(&head) << "\n";
    // std::cout<<"The mode of the list is: " << mode(&head) << "\n";
    // std::cout<<"The range of the list is: "<< range(&head) <<"\n";
    // selectionSort(&head);
    // printFunction(&head);
    // removeDuplicates(&head); 
    // std::cout<<"The size of the list is: "<<sizeOfList(&head) << "\n";


    return 0;
}