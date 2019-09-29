#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#define TRUE 1
#define FALSE 0
#define SIZE 10
using namespace std;



int isEmpty(int queue[], int head, int tail){
    if (head==-1 && tail==-1){
        return TRUE;
    }
    return FALSE;
}

int isEmptyQueue(int queue_1[], int queue_2[], int queue_3[], int head[], int tail[]){
    return (isEmpty(queue_1, head[0], tail[0]) && isEmpty(queue_2, head[1], tail[1]) && isEmpty(queue_3, head[2], tail[2]));
} 

int isFull(int queue[], int head, int tail){
    if((tail==head-1) || (head==0 && tail==SIZE-1)) return TRUE;
    return FALSE;
}

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

int enqueueWithPriority(int value, int priority, int queue_1[], int queue_2[], int queue_3[], int head[], int tail[]){
    switch(priority){
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

int dequeue(int queue[], int *head, int *tail){
    if(isEmpty(queue,*head,*tail)){
        cout<<"Cannot dequeue from an empty queue";
        return FALSE;
    }
    else
    {   
        int dequeued_value=queue[*head];
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

int dequeueWithPriority(int no_to_delete , int *dequeued_elements, int queue_1[], int queue_2[], int queue_3[], int head[], int tail[]){
    int number_dequeued=0;
    int data;
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

void print_queue(int queue[], int head, int tail){
    int i=head;
    int j=tail;
    if (!(isEmpty(queue, head, tail)))
    {    while(i<=j && i!=-1 && j!=-1){
            cout<<queue[i]<<" ";
            i++;
        }
    }

}

void current_status(int *queue1, int *queue2, int *queue3, int head[], int tail[]){
    print_queue(queue1,head[0],tail[0]);
    print_queue(queue2,head[1],tail[1]);
    print_queue(queue3,head[2],tail[2]);
    cout<<endl;

}

int random_data_generator(){
    return rand()%900+100; 
}

int random_priority_generator(){
    return rand()%3+1;
} 

int random_number_for_dequeue(){
    return (rand()%2+1)*2;
}

int simulate_traffic(int queue1[], int queue2[], int queue3[], int head[], int tail[]){
    int status = TRUE;
    int add_elements=6;
    int count_of_elements_dequeued=0;
    int dequeued_elements[SIZE];
    int enqueued_elements[SIZE];
    srand(time(NULL));
    do{ 
    
        for(int i=0;i<add_elements;i++){
            int data=random_data_generator();
            int priority=random_priority_generator();
            status=enqueueWithPriority(data, priority, queue1, queue2, queue3, head, tail);
            enqueued_elements[i]=data;
        }
        if (add_elements==6){
            cout<<"The initial status: "<<endl;
            current_status(queue1, queue2, queue3, head, tail);
            
        }
        else if (add_elements==3 and status!=FALSE){
            print_queue(enqueued_elements,0,add_elements-1);
            cout<<" have entered the queue. ";
        }

        else if(status==FALSE){
            cout<<"There is an overflow."<<endl;
            break;
        }

        int no_to_dequeue = random_number_for_dequeue();
        count_of_elements_dequeued+=no_to_dequeue;

        if (count_of_elements_dequeued==20){
            status=FALSE;
            cout<<"\n"<<"20 elements have been dequeued."<<endl;
            break;
        }
        status=dequeueWithPriority(no_to_dequeue, dequeued_elements, queue1, queue2, queue3, head, tail);
        if (status==FALSE){
            cout<<"\n"<<"There is an underflow."<<endl;
            break;
        }
        else{
            cout<<"\n";
            print_queue(dequeued_elements,0,no_to_dequeue-1);
            cout<< " have exited the queue"<< endl;
        }


        cout<<"\n"<<"The status after "<< no_to_dequeue<< " elements have exited the queue: ";
        current_status(queue1, queue2, queue3, head, tail);
    
        add_elements=3;
        
    }while(status);

    cout<<"The status after operations:" <<endl;
    current_status(queue1, queue2, queue3, head, tail);
    return TRUE;
}

int main(){
    int p1_queue[SIZE];
    int p2_queue[SIZE];
    int p3_queue[SIZE];
    int head[3]={-1,-1,-1};
    int tail[3]={-1,-1,-1};
    
    //TEST FOR SIMULATING TRAFFIC
    simulate_traffic(p1_queue, p2_queue, p3_queue, head, tail);
   


}