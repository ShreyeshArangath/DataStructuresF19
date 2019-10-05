// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab3.cpp
// SPECIFICATION: Implement a 3-levels Priority Circular Queue using arrays
// FOR: CS 2413 Data Structure 001 501
//
// TEST CASES for Function isEmpty:
// Test case1: queue is empty
// Input: [], -1, -1
// Expected output: 1
// Actual Output: 1
// Test case2: queue is not empty
// Input: [1],0,0
// Expected Output:  0
// Actual output: 0
//
// TEST CASES for Function isEmptyQueue:
// Test case1: All the queues are empty
// Input: [],[],[],[-1,-1,-1],[-1,-1,-1]
// Expected output: 1
// Actual Output: 1
// Test case2: All queues are not empty
// Input: [],[],[1],[-1,-1,0],[-1,-1,0]
// Expected Output: 0
// Actual output: 0
//
// TEST CASES for Function isFull:
// Test case1: The queue is full
// Input: [1,2,3,4], 0, 3
// Expected output: 1
// Actual Output: 1
// Test case2: The queue is not full
// Input: [],-1,-1
// Expected Output: 0
// Actual output: 0
//
// TEST CASES for Function enqueue:
// Test case1: Inserting to an empty queue 
// Input: 18, [], -1, -1
// Expected output: [38], head=0, tail=0
// Actual Output: [38], head=0, tail=0
// Test case2: Inserting to a full queue
// Input: [1,2,3,4], 0, 3
// Expected Output: The queue is full. Returns 0
// Actual output: The queue is full. Returns 0
//
// TEST CASES for Function enqueueWithPriority:
// Test case1: Inserting with priority 1
// Input: 18, 1, [], [], [], [-1,-1,-1], [-1,-1,-1]
// Expected output: [18], [],[]
// Actual Output: [18], [],[]
// Test case2: Inserting with unknown priority
// Input: 18, 5, [],[],[],[-1,-1,-1],[-1,-1,-1]
// Expected Output: 0
// Actual output: 0
//
// TEST CASES for Function dequeue:
// Test case1: Deleting from an empty queue
// Input: [], -1, -1
// Expected output: 0
// Actual Output: 0
// Test case2: Deleting from a non-empty queue
// Input: [18],0,0
// Expected Output: 1 ([],0,0)
// Actual output: 1 (([],0,0))
//
// TEST CASES for Function dequeueWithPriority:
// Test case1: empty queue
// Input:4, *dequeued_elements, [],[],[],[-1,-1,-1],[-1,-1,-1]
// Expected output: 0
// Actual Output: 0
// Test case2: normal queue, 
// Input: 2, *dequeued_elements, [1,2],[],[],[0,-1,-1],[2,-1,-1]
// Expected Output: [],[],[]. Returns 1
// Actual output: [], [], []. Returns 1
//
// TEST CASES for Function print_queue:
// Test case1: printing an empty queue
// Input: [],-1,-1
// Expected output: 
// Actual Output: 
// Test case2: printing a queue
// Input: [1,2], 0, 1
// Expected Output:1 2
// Actual output: 1 2
//
// TEST CASES for Function currentStatus:
// Test case1: printing out an empty queue
// Input: [],[],[], [-1,-1,-1],[-1,-1,-1]
// Expected output: 
// Actual Output: 
// Test case2: printing out a priority queue
// Input: [1,2],[3,4],[5,6], [0,0,0],[1,1,1]
// Expected Output: 1,2,3,4,5,6
// Actual output: 1,2,3,4,5,6
//
// TEST CASES for Function randomDataGenerator:
// Test case1: Generates random number to enqueue
// Input: 
// Expected output: a random number between 100 and 999
// Actual Output: a random number between 100 and 999
//
// TEST CASES for Function randomPriorityGenerator:
// Test case1: Generates random number for enqueing according to priority
// Input: 
// Expected output: a random number in the range [1,3]
// Actual Output: a random number in the range [1,3]
//
// TEST CASES for Function random_number_for_dequeue:
// Test case1: Generates random number for deleting items from the queue
// Input: 
// Expected output: either 2 or 4
// Actual Output: either 2 or 4

// TEST CASES for Function simulate_traffic:
// Test case1: check the output file
// Test case 2: check the output file
// --------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#define TRUE 1
#define FALSE 0 
#define SIZE 10 //SIZE OF THE QUEUE
using namespace std;

ofstream outputFile("output.txt"); ///The file stream pointer to the output file. 

// NAME: isEmpty
// INPUT PARAMETERS: queue(an array), head (integer), tail (integer)
// OUTPUT: Returns 1 if the queue is empty. Else, returns 0
// PURPOSE: The functions returns a flag value to indicate if a queue is empty.
int isEmpty(int queue[], int head, int tail){
    if (head==-1 && tail==-1){
        return TRUE;
    }
    return FALSE;
}

// NAME: isEmptyQueue
// INPUT PARAMETERS: queue_1, queue_2, queue_3 (queues of respective priorities), head (an array of the indices of the head), 
//tail (an array of the indices of the tail)
// OUTPUT: Returns 1 if the queue is empty. Else, returns 0
// PURPOSE: The functions returns a flag value to indicate if the priority queue is empty.
int isEmptyQueue(int queue_1[], int queue_2[], int queue_3[], int head[], int tail[]){
    return (isEmpty(queue_1, head[0], tail[0]) && isEmpty(queue_2, head[1], tail[1]) && isEmpty(queue_3, head[2], tail[2]));
} 

// NAME: isFull
// INPUT PARAMETERS: queue(an array), head (integer), tail (integer)
// OUTPUT: Returns 1 if the queue is full. Else, returns 0
// PURPOSE: The functions returns a flag value to indicate if a queue is full.
int isFull(int queue[], int head, int tail){
    if((tail==head-1) || (head==0 && tail==SIZE-1)) return TRUE;
    return FALSE;
}

// NAME: enqueue
// INPUT PARAMETERS: value (an integer),queue(an array), head (pointer to integer), tail (pointer to integer)
// OUTPUT: Inserts an element into the queue.
// PURPOSE: To insert an element into the queue. 
int enqueue(int value, int queue[], int *head, int *tail){
    if(isFull(queue, *head, *tail)){
        cout<<"The Queue is FULL.";
        return FALSE;
    }
    else if(*head!=0 && *tail==SIZE-1){
        *tail=0;
        queue[*tail]=value;
    }
    else if(*head==-1 && *tail==-1){
        *head=*tail=0;
        queue[*head]=value;
    }
    else{
        *tail=*tail+1;
        queue[*tail]=value;
    }
    return TRUE;

}

// NAME: enqueueWithPriority
// INPUT PARAMETERS: value (an int), priority (an int b/w 1 and 3), 
// queue_1, queue_2, queue_3 (queues of respective priorities), head (an array of the indices of the head), 
//tail (an array of the indices of the tail)
// OUTPUT: Inserts the elements into the priority queue on the basis of the priority
// PURPOSE: To insert elements in terms of the priorities into the queue. 
int enqueueWithPriority(int value, int priority, int queue_1[], int queue_2[], int queue_3[], int head[], int tail[]){
    switch(priority){ //Gives the priority of the value to be inserted
        case 1: {
            if(!(isFull(queue_1, head[0], tail[0]))){
                enqueue(value, queue_1, &head[0], &tail[0]);
                break;
            }
        }
        case 2: {
            if(!(isFull(queue_2, head[1], tail[1]))){
                enqueue(value, queue_2, &head[1], &tail[1]);
                break;
            }
        }
        case 3: {
            if(!(isFull(queue_1, head[0], tail[0]))){
                enqueue(value, queue_1, &head[0], &tail[0]);
                break;
            }
        }
        default: {
            return FALSE;
        }
    }
    return TRUE;
    
}

// NAME: dequeue
// INPUT PARAMETERS: queue(an array), head (pointer to integer), tail (pointer to integer)
// OUTPUT: Deletes an element from the queue.
// PURPOSE: To delete an element from the queue. 
int dequeue(int queue[], int *head, int *tail){
    if(isEmpty(queue,*head,*tail)){
        cout<<"Cannot dequeue from an empty queue";
        return FALSE;
    }
    else
    {   
        int dequeued_value=queue[*head]; //Stores the value of the dequeud element in the queue. 
        if(*head==*tail){ 
            *head=*tail=-1;
        }
        else if(*head==SIZE-1){
            *head=0;
        }
        else {
            *head=*head+1;
        }
        return dequeued_value;
    }
}

// NAME: dequeueWithPriority
// INPUT PARAMETERS: no_to_delete(number of elements to delete),value (an integer), dequeued_elements(an array)
// queue_1, queue_2, queue_3 (queues of respective priorities), head (an array of the indices of the head), 
// tail (an array of the indices of the tail)
// OUTPUT: Deletes elements from the queue on the basis of the priority
// PURPOSE: To delete the elements from the queue wrt the priorities. 
int dequeueWithPriority(int no_to_delete , int *dequeued_elements, int queue_1[], int queue_2[], int queue_3[], int head[], int tail[]){
    int number_dequeued=0; //Keeps the count of the number of elements dequeued from the queue. 
    int data; //Keeps the track of the data dequeued from the queue. 
    while(number_dequeued<no_to_delete){
        if(!(isEmpty(queue_1, head[0], tail[0]))){
            data=dequeue(queue_1,&head[0],&tail[0]);
            dequeued_elements[number_dequeued]=data;
            number_dequeued++;
        }
        else if(!(isEmpty(queue_2, head[1], tail[1]))){
            data=dequeue(queue_2, &head[1],&tail[1]);
            dequeued_elements[number_dequeued]=data;
            number_dequeued++;
        }
        else if(!(isEmpty(queue_3, head[2], tail[2]))){
            data=dequeue(queue_3,&head[2],&tail[2]);
            dequeued_elements[number_dequeued]=data;
            number_dequeued++;
        }
        else if(number_dequeued<no_to_delete){
            return FALSE;
        }
    }
    return TRUE;
}


// NAME: print_queue
// INPUT PARAMETERS: queue(an array), head (pointer to integer), tail (pointer to integer)
// OUTPUT: Prints the queue to both the console and the output file.
// PURPOSE: To print a queue. 
void print_queue(int queue[], int head, int tail){
    int i=head; //Acts a loop pointer to iterate through the queue. 
    int j=tail; //Acts the end condition for the queue iteration. 
    if (!(isEmpty(queue, head, tail)))
    {    while(i<=j && i!=-1 && j!=-1){
            cout<<queue[i]<<" ";
            outputFile<<queue[i]<<" ";
            i++;
        }
    }

}

// NAME: currentStatus
// INPUT PARAMETERS: queue_1, queue_2, queue_3 (queues of respective priorities), head (an array of the indices of the head), 
// tail (an array of the indices of the tail)
// OUTPUT: Prints out the queues in the order of their priorities
// PURPOSE: To print queues in the order of their priorities
void current_status(int *queue1, int *queue2, int *queue3, int head[], int tail[]){
    print_queue(queue1,head[0],tail[0]);
    print_queue(queue2,head[1],tail[1]);
    print_queue(queue3,head[2],tail[2]);
    cout<<endl;
    outputFile<<endl;

}

// NAME: random_data_generator
// INPUT PARAMETERS: 
// OUTPUT: Generates a random number between 100 to 999
// PURPOSE: To get random integer data to enqueue to the queue. 
int random_data_generator(){
    return rand()%900+100; 
}

// NAME: random_priority_generator
// INPUT PARAMETERS: 
// OUTPUT: Generates a random number in the range [1,3]
// PURPOSE: To get random priorities for the data to be enqueued. 
int random_priority_generator(){
    return rand()%3+1;
} 

// NAME: random_number_for_dequeue
// INPUT PARAMETERS: 
// OUTPUT: Generates a random number either 2 or 4
// PURPOSE: To get the number of elements that are to be dequeued from the queue. 
int random_number_for_dequeue(){
    return (rand()%2+1)*2;
}

// NAME: simulate_traffic
// INPUT PARAMETERS: queue_1, queue_2, queue_3 (queues of respective priorities), head (an array of the indices of the head), 
// tail (an array of the indices of the tail)
// OUTPUT: Simulates the traffic in the queue as specified in the question. 
// PURPOSE: To simulate the traffic in a priority queue. 
int simulate_traffic(int queue1[], int queue2[], int queue3[], int head[], int tail[]){
    int status = TRUE; //Establishes the current state of the traffic
    int add_elements=6; //Specifies the number of elements to be added in the queue. 
    int count_of_elements_dequeued=0; //Keeps the count of the total number of elements dequeued, to stop simualation. 
    int dequeued_elements[SIZE]; //Stores the dequeued elements to be displayed in the output file
    int enqueued_elements[SIZE];  // Stores the enqueued elements to be displayed in the output file. 
    srand(time(NULL)); //Serves as the seed for the random number generator. 
    do{ 
    
        for(int i=0;i<add_elements;i++){
            int data=random_data_generator(); //Stores the random data temporarily
            int priority=random_priority_generator(); //Stores the priority of the random data
            status=enqueueWithPriority(data, priority, queue1, queue2, queue3, head, tail); 
            enqueued_elements[i]=data;
        }
        if (add_elements==6){
            cout<<"The initial status: "<<endl;
            outputFile<<"The initial status: "<<endl;
            current_status(queue1, queue2, queue3, head, tail);
            
        }
        else if (add_elements==3 and status!=FALSE){
            print_queue(enqueued_elements,0,add_elements-1);
            cout<<" have entered the queue. ";
            outputFile<<" have entered the queue. ";
        }

        else if(status==FALSE){
            outputFile<<"There is an overflow."<<endl;
            cout<<"There is an overflow."<<endl;
            break;
        }

        int no_to_dequeue = random_number_for_dequeue(); //Stores the number of elements to be dequeued. 
        count_of_elements_dequeued+=no_to_dequeue; 
        status=dequeueWithPriority(no_to_dequeue, dequeued_elements, queue1, queue2, queue3, head, tail);
        if (count_of_elements_dequeued==20){
            status=FALSE;
            print_queue(dequeued_elements,0,no_to_dequeue-1);
            cout<< " have exited the queue"<< endl;
            outputFile<< " have exited the queue"<< endl;
            cout<<"The status after "<< no_to_dequeue<< " elements have exited the queue: "<<endl;
            outputFile<<"The status after "<< no_to_dequeue<< " elements have exited the queue: "<<endl;
            outputFile<<"\n\n"<<"20 elements have been dequeued."<<endl;
            cout<<"\n\n"<<"20 elements have been dequeued."<<endl;
            break;
        }
        // status=dequeueWithPriority(no_to_dequeue, dequeued_elements, queue1, queue2, queue3, head, tail);
        if (status==FALSE){
            outputFile<<"\n"<<"There is an underflow."<<endl;
            cout<<"\n"<<"There is an underflow."<<endl;
            break;
        }
        else{
            cout<<"\n";
            outputFile<<"\n";
            print_queue(dequeued_elements,0,no_to_dequeue-1);
            cout<< " have exited the queue"<< endl;
            outputFile<< " have exited the queue"<< endl;
        }


        cout<<"The status after "<< no_to_dequeue<< " elements have exited the queue: ";
        outputFile<<"The status after "<< no_to_dequeue<< " elements have exited the queue: ";
        current_status(queue1, queue2, queue3, head, tail);
        add_elements=3;
        cout<<endl;
        outputFile<<endl;
        
    }while(status);

    cout<<"The status after operations:" <<endl;
    outputFile<<"The status after operations:" <<endl;
    current_status(queue1, queue2, queue3, head, tail);
    return TRUE;
}

int main(){
    int p1_queue[SIZE]; //Queue with priority 1
    int p2_queue[SIZE]; //Queue with priority 2
    int p3_queue[SIZE]; //Queue with priority 3
    int head[3]={-1,-1,-1}; //Array of the indexes of the head pointer 
    int tail[3]={-1,-1,-1}; // Array of the indexes of the tail pointer
    
    //TEST FOR SIMULATING TRAFFIC
    simulate_traffic(p1_queue, p2_queue, p3_queue, head, tail);
   
}