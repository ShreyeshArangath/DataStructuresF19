#include <iostream>
#define SIZE 100

using namespace std;

void max_heapify(int heap[], int root, int size){
    int temp;
    int left_child_index = 2*root+1;
    int right_child_index = 2*root+2;
    int largest=root;
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

        max_heapify(heap, largest, size);
    }
}

void build_heap(int heap[], int size){
    int i = size/2 -1;
    while(i>=0){
        max_heapify(heap, i, size);
        i--;
    }
}


void print_arr(int heap[], int last){
    for(int i=0; i<last; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int get_array(int heap[]){
    int val;
    int i=0;
    cout<<"Please enter a number (-1 to quit): "<<endl;
    cin>>val;
    while(val!=-1 && i<SIZE){
        heap[i]=val;
        i++;
        cout<<"Please enter a number (-1 to quit): "<<endl;
        cin>>val;
    }
    return i+1;
}

int main(){
    int heap[SIZE];
    int heap_size;
    heap_size=get_array(heap);
    print_arr(heap,heap_size);
    build_heap(heap,heap_size);
    print_arr(heap,heap_size);
    return 0;

}