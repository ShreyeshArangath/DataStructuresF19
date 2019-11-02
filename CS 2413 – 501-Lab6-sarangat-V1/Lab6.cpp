// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab6.cpp
// SPECIFICATION: Implement a BST and its supplementary functions
// FOR: CS 2413 Data Structure 001 501
//
//TEST CASES in the output file. 
// --------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cmath>
#define TRUE 1
#define FALSE 0
#define SIZE 100

using namespace std;
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}tree_node_t;

// NAME: isEmpty
// INPUT PARAMETERS: queue(an array), head (integer), tail (integer)
// OUTPUT: Returns 1 if the queue is empty. Else, returns 0
// PURPOSE: The functions returns a flag value to indicate if a queue is empty.
int isFull(int queue[], int head, int tail){
    if((tail==head-1) || (head==0 && tail==SIZE-1)) return TRUE;
    return FALSE;
}

// NAME: isFull
// INPUT PARAMETERS: queue(an array), head (integer), tail (integer)
// OUTPUT: Returns 1 if the queue is full. Else, returns 0
// PURPOSE: The functions returns a flag value to indicate if a queue is full.
int isEmpty(int queue[], int head, int tail){
    if (head==-1 && tail==-1){
        return TRUE;
    }
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


// NAME: createTreeNode
// INPUT PARAMETERS: data
// OUTPUT: Returns a new node
// PURPOSE: To create a new node
tree_node_t* createTreeNode(int data){
    tree_node_t *new_node = (tree_node_t *)malloc(sizeof(tree_node_t)); //New node for BST
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

// NAME: insert
// INPUT PARAMETERS: data, pointer to the root
// OUTPUT: Returns the pointer to the node
// PURPOSE: To insert a node into a BST
tree_node_t* insert(int data, tree_node_t *root){
    tree_node_t* new_node = createTreeNode(data); //Creates a new node with data
    if(root==NULL){
        return new_node;
    }
    else{
        if(data<=root->data)
            root->left=insert(data, root->left);
        else
            root->right=insert(data,root->right);
    }
    return root;
}

// NAME: search
// INPUT PARAMETERS: dataToSearch, pointer to the root
// OUTPUT: Returns the pointer to the node with the same value
// PURPOSE: To search for a node in BST
tree_node_t* search(int dataToSearch, tree_node_t *root){
    if(root==NULL){
        return root;
    }
    else {
        cout<<root->data<<" ";
        if(root->data==dataToSearch)
        {   
            return root;
        }
        else if(dataToSearch<root->data)
       {   
            return search(dataToSearch,root->left);
       }
        else{
            return search(dataToSearch, root->right);
        }
            
    }
}

// NAME: findMin
// INPUT PARAMETERS: pointer to the root
// OUTPUT: Returns the pointer to the node
// PURPOSE: To find the leftmost node in a BST
tree_node_t* findMin(tree_node_t* root){
    tree_node_t*temp = root; //Used to traverse the tree
    while (temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
    
}

// NAME: deleteFromTree
// INPUT PARAMETERS: dataToDelete, pointer to the root
// OUTPUT: Returns the pointer to the node
// PURPOSE: To delete the node from the BST
tree_node_t* deleteFromTree( int dataToDelete, tree_node_t *root) {
	if(root == NULL) return root; 
	else if(dataToDelete < root->data) root->left = deleteFromTree(dataToDelete, root->left);
	else if (dataToDelete > root->data) root->right = deleteFromTree(dataToDelete, root->right);
	else {
		if(root->left == NULL && root->right == NULL) { 
            root=NULL;
			free(root);
		}
		else if(root->left == NULL) {
			tree_node_t *temp=root; //temp node for deleting
			root=root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			tree_node_t *temp=root; //temp node for deleting
			root=root->left;
			free(temp);
		}
		else { 
			tree_node_t *temp=findMin(root->right); //Stores the min value in the right sub tree
			root->data=temp->data;
			root->right=deleteFromTree(temp->data, root->right);
		}
	}
	return root;
}
 

// NAME: findHeightOfTree
// INPUT PARAMETERS: pointer to the root
// OUTPUT: Returns the height 
// PURPOSE: To find the height of the BST
int findHeightOfTree(tree_node_t* root){
    if(root==NULL) return 0;
    else {
        int left_height=findHeightOfTree(root->left); //Height of the left subtree
        int right_height=findHeightOfTree(root->right); //Height of the right subtree
        if (left_height>right_height) return left_height+1; 
        else return right_height+1;
    }
}

// NAME: printSubLevel
// INPUT PARAMETERS: pointer to the root, sublevel, queue (an array), pointer to head, pointer to tail
// OUTPUT: Prints out a sublevel
// PURPOSE: To print a sublevel
void printSubLevel(tree_node_t* root, int sublevel, int queue[], int* head, int* tail)  
{  
    if (root == NULL) {
        enqueue(0, queue, head, tail) ; 
        return ;}

    if (sublevel == 1) enqueue(root->data,queue,head,tail); 
    else{  
        printSubLevel(root->left, sublevel-1, queue, head, tail);  
        printSubLevel(root->right, sublevel-1, queue, head, tail); 

    }  
}  


// NAME: print_queue
// INPUT PARAMETERS: queue(an array), head (pointer to integer), tail (pointer to integer)
// OUTPUT: Prints the queue to both the console and the output file.
// PURPOSE: To print a queue. 
void print_queue(int queue[], int height, int head, int tail){
    int i=head; //Stores the value of head for iteration
    int j=tail; //Stores the value of tail for iteration
    int levels=0; //Stores the level of the iteration
    if (!(isEmpty(queue, head, tail)))
    {    while(i<=j && i!=-1 && j!=-1){
            for(int k=0; k<pow(2,levels); k++){
                if (queue[i]==0) cout<<" ";
                else cout<<queue[i]<<" ";
                i++;
            }
            levels++;
            cout<<endl;
        }
    }
}
// NAME: breadthFirstTraversal
// INPUT PARAMETERS: pointer to the root, queue, pointer to head, pointer to tail
// OUTPUT: Traverses the BST breadth wise
// PURPOSE: To traverse through a BST
void breadthFirstTraversal(tree_node_t* root, int queue[], int*head, int*tail)  
{  
    int height = findHeightOfTree(root);   //Stores the height of the root
    for (int i=1; i<=height; i++) printSubLevel(root, i, queue, head, tail);  
    print_queue(queue, height, *head, *tail);
    memset(queue, 0, SIZE*sizeof(int));
    *head=-1;
    *tail=-1;
}  

int main(){
    tree_node_t* root=NULL;
    tree_node_t *temp =NULL;
    int queue[SIZE]; //Queue for printing
    int head=-1;
    int tail=-1;
    tree_node_t* status; //Stores the status
    int option;  //User option
    int data;
    do {
        cout<<"\n";
        cout<<"1. Insert into the tree"<< endl;
        cout<<"2. Delete from the tree"<< endl;
        cout<<"3. Search the tree"<< endl;
        cout<<"4. Display" <<endl;
        cout<<"-1. To quit"<<endl;
        cin>>option;
        switch(option){
            case 1: {
                cout<<"What would you want to insert?: ";
                cin>>data;
                root=insert(data, root);
                break;
            }
            case 2: {
                cout<<"What would you like to delete?: ";
                cin>>data;
                status=deleteFromTree(data, root);
                if (status==NULL) cout<<"the item is not found"<<endl; 
                break;
            }
            case 3: {
                cout<<"What would you like to search for?: ";
                cin>>data;
                status=search(data, root);
                if (status==NULL) cout<<"the item is not found"<<endl; 
                break;
            }
            case 4: {
                breadthFirstTraversal(root, queue, &head, &tail);
                break;
            }
        }
    }while(option!=-1);

    return 0;
}