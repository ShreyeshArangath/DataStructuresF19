// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab8.cpp
// SPECIFICATION: Implement a heap with its associate functions
// FOR: CS 2413 Data Structure 001 501
//
//TEST CASES in the output file. 
// --------------------------------------------------------------------------------

#include <iostream>
#define SIZE 100

using namespace std;

// NAME: Max_heapify
// INPUT PARAMETERS: heap(an array), root (integer), size (integer)
// OUTPUT: Converts the subtree rooted at the given root into a max-heap
// PURPOSE: To max_heapify the array
void Max_heapify(int heap[], int root, int size){
    int temp; //Used as swap variable
    int left_child_index = 2*root+1; //Index of the left child
    int right_child_index = 2*root+2; //Index of the right child
    int largest=root; //Index of the largest element
    if(left_child_index< size && heap[left_child_index]>heap[largest]){
        largest=left_child_index;
    }
    if(right_child_index<size && heap[right_child_index]>heap[largest]){
       largest=right_child_index;
    }
    if(largest!=root){
        temp=heap[largest];
        heap[largest]=heap[root];
        heap[root]=temp;

        Max_heapify(heap, largest, size);
    }
}

// NAME: Build_heap
// INPUT PARAMETERS: heap(an array), size (integer)
// OUTPUT: Max-heap
// PURPOSE: To build the heap using the max_heapify function on all the subtrees that are not leaves
void Build_heap(int heap[], int size){
    int i = size/2 -1; //Index of the parent node that is not a leaf
    while(i>=0){
        Max_heapify(heap, i, size);
        i--;
    }
}

// NAME: print_heap
// INPUT PARAMETERS: heap(an array), index (integer), heap_size (integer)
// OUTPUT: Prints the heap level-by-level
// PURPOSE: To print the heap
void print_heap(int heap[], int index, int heap_size){
    int step=0; //Step-wise traversal
    int i; //Loop variable
    for(i=index; i<heap_size; i++){
        if (heap[i]!=0)cout<<heap[i];
        if(i==step){
            step=step*2+2;
            cout<<endl;
        }
        else cout<<" ";
    }
    cout<<"\n \n";
}

// NAME: Max_heapify
// INPUT PARAMETERS: heap(an array), root (integer), size (integer)
// OUTPUT: Returns the new heap after deleting the root
// PURPOSE: To delete the root of the heap   
int Delete_root(int heap[], int* heap_size){
    int deleted_element=heap[0]; //Stores the value at the root
    heap[0]=heap[*heap_size-1];
    *heap_size-=1;
    Max_heapify(heap, 0, *heap_size);
    return deleted_element;
}

// NAME: get_array
// INPUT PARAMETERS: heap(an array)
// OUTPUT: Returns the input array from the user
// PURPOSE: To get the input array from the user
int get_array(int heap[]){
    int val; //Value input by the user
    int i=0; //Loop Counter
    cout<<"Please enter a number (-1 to quit): ";
    cin>>val;
    while(val!=-1 && i<SIZE){
        heap[i]=val;
        i++;
        cout<<"Please enter a number (-1 to quit): ";
        cin>>val;
    }
    return i+1;
}

int main(){
    int heap[SIZE]; 
    int heap_size; //Stores the heap size
    int root; //Stores the value of the root
    int deleted_element; //Stores the deleted element
    int option; //User option
    do{
        cout<<"1. Input numbers into an array"<<endl;
        cout<<"2. Max Heapify"<<endl;
        cout<<"3. Build the heap"<<endl;
        cout<<"4. Delete the root"<<endl;
        cout<<"5. Print the heap"<<endl;
        cout<<"-1. Quit"<<endl;
        cin>>option;
        switch(option){
            case 1: {
                heap_size=get_array(heap);
                break;
            }
            case 2:{
                cout<<"Which subtree would you like to max_heapify? (b/w 0 and n-1)";
                cin>>root;
                Max_heapify(heap, root, heap_size);
                break;
            }
            case 3: {
                Build_heap(heap, heap_size);
                break;
            }
            case 4: {
                deleted_element=Delete_root(heap, &heap_size);
                cout<<deleted_element<<" has been deleted."<<endl;
                break;
            }
            case 5: {
                print_heap(heap,0, heap_size);
                break;
            }
        }
    
    }while(option!=-1);

    return 0;
}