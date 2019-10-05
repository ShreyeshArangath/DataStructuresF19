#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}stack_record_t;

int isEmpty(stack_record_t **top){
    return (*top==NULL);
}

void PUSH(int data,stack_record_t **top){
    stack_record_t *new_node = (stack_record_t *)malloc(sizeof(stack_record_t*));
    new_node->data=data;
    new_node->next=*top;
    *top=new_node;
}

int POP(stack_record_t **top){
    if(isEmpty(top)){
        cout<<"Cannot pop from an empty stack.";
        return -1;
    }
    else {
        stack_record_t *temp;
        int data;
        temp=*top;
        data=temp->data;
        *top=(*top)->next;
        free(temp);
        return data;
    }
}

int PEEK(stack_record_t **top){
    return (*top)->data;
}

int convertToBase2To9(int value_to_convert){

}

int main(){
    stack_record_t *top=NULL;
   

}