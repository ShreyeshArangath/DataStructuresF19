// --------------------------------------------------------------------------------
// AUTHOR: Shreyesh Arangath
// FILENAME: Lab9.cpp
// SPECIFICATION: Implement a graph and Dijsktra's Algorithm
// FOR: CS 2413 Data Structure 001 501
//
//TEST CASES in the output file. 
// --------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 26
#define TRUE 1
#define FALSE 0
#define INFINITY INT_MAX

using namespace std;

char max_val;

int max_index;

typedef struct VerticeNode{
    char vertice;
    int weight;
}graph_vertice_t;

// NAME: getIndex
// INPUT PARAMETERS: val (a character)
// OUTPUT: An integer that indicates the index for the specific value
// PURPOSE: To get the index of a character value for the graph
int getIndex(char val){
    return int(val)-65;
}

// NAME: getChar
// INPUT PARAMETERS: val (a integer)
// OUTPUT: A character representing the value at the particular index of the graph
// PURPOSE: To get value at the vertex of the graph
char getChar(int val){
    return char(val+65);
}

// NAME: createNewEdge
// INPUT PARAMETERS: graph (an array of graph_vertice_t), vertice (a char), connectedTo (a char), weight(int)
// OUTPUT: Adds weight to the edges 
// PURPOSE: To create an edge between two vertices
int createNewEdge(graph_vertice_t graph[][MAX], char vertice, char connectedTo, int weight){
    graph[getIndex(vertice)][getIndex(connectedTo)].weight = weight;
    graph[getIndex(vertice)][getIndex(connectedTo)].vertice=connectedTo;
    graph[getIndex(connectedTo)][getIndex(vertice)].weight=weight;
    graph[getIndex(connectedTo)][getIndex(vertice)].vertice=vertice;
    return TRUE;
}

// NAME: maxIndexFromFile
// INPUT PARAMETERS: ver1, ver 2 (a char)
// OUTPUT: Returns the max index in the file 
// PURPOSE: To get the max index from the file
char maxIndexFromFile(char ver1, char ver2){
    return (ver1>ver2)?ver1:ver2;
}

// NAME: read_csv
// INPUT PARAMETERS: file_name (char array), graph 
// OUTPUT: The graph from the .csv file
// PURPOSE: To create the graph from .csv file
int read_csv(char* file_name, graph_vertice_t graph[][MAX]){
    FILE* inputFile; //Input file pointer
    char vertice1; //Value of the first vertex
    char vertice2; //Value of the second vertex
    int weight; //Weight of the edge
    inputFile=fopen(file_name,"r");
    if(inputFile==NULL){
        cout<<"Error reading the file"<<endl;
        return 0;
    }
    while(fscanf(inputFile, "%c,%c,%d\n", &vertice1, &vertice2, &weight)==3){
        if(max_val<maxIndexFromFile(vertice1, vertice2)){
            max_val=maxIndexFromFile(vertice1, vertice2);
        }
        createNewEdge(graph, vertice1, vertice2, weight);
    }
    max_index = getIndex(max_val);
    fclose(inputFile);
    return 1;
}

// NAME: init_graph
// INPUT PARAMETERS: arr (multi dimensional graph)
// OUTPUT: Initializes the graph with all zero values
// PURPOSE: To intialize the graph
void init_graph(graph_vertice_t arr[][MAX]){
    int max_index = getIndex(max_val);
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            arr[i][j].weight = 0;
        }
    }
}

// NAME: isZero
// INPUT PARAMETERS: arr( graph_vertice_t), row(an integer)
// OUTPUT: Returns FALSE if a row is not zero, true otherwise
// PURPOSE: To check if a row is zero or not
int isZero(graph_vertice_t arr[][MAX], int row){
    int flag=1;
    for(int i=0; i<MAX; i++){
        if((arr[row][i]).weight!=0) flag=0;
    }
    return flag;
}

// NAME: print_vertice_and_edge
// INPUT PARAMETERS: arr( multi dimensional graph_vertice_t array), row(an integer)
// OUTPUT: Prints out a row of the adjacency matrix
// PURPOSE: To print a row of the adjacency matrix
void print_vertice_and_edge(graph_vertice_t arr[][MAX],int row){
    for(int i=0; i<=max_index; i++){
        if((arr[row][i]).weight>0) cout<<arr[row][i].weight <<"\t";
        else cout<<0<<"\t";
    }
    cout<<endl;
}

// NAME: Display
// INPUT PARAMETERS: graph( multi dimensional graph_vertice_t array )
// OUTPUT: Prints out the adjancency matrix
// PURPOSE: To print out the adjacency matrix
void Display(graph_vertice_t graph[][MAX]){
    for(int i=0; i<=max_index; i++){
        if(!isZero(graph, i)){
            print_vertice_and_edge(graph, i);
        }
    }
}

// NAME: initialize_algorithm
// INPUT PARAMETERS: set_of_vertices(an array of boolean ints),
// distance_from_source(an integer array representing distance), source(an integer)
// OUTPUT: Initialize the arrays required for Dijsktra's Algorithm
// PURPOSE: To initialize the requirements for Dijkstra's Algorithm
void initialize_algorithm(int set_of_vertices[], int distance_from_source[], int source){
    for(int i=0 ; i<MAX ; i++){
        set_of_vertices[i]=0;
        distance_from_source[i]=INFINITY;
    }
    distance_from_source[source]=0;
}

// NAME: findMinimumDistance
// INPUT PARAMETERS: set_of_vertices(an array of boolean ints),
// distance_from_source(an integer array representing distance)
// OUTPUT: Returns the index of the minimum distance value
// PURPOSE: To find theindex of the minimum distance value
int findMinimumDistance(int set_of_vertices[], int distance_from_source[]){
    int minimum_val = INFINITY;
    int minimum_index;
    for(int i=0; i<MAX; i++){
        if(distance_from_source[i]<=minimum_val && set_of_vertices[i]==0){
            minimum_val=distance_from_source[i];
            minimum_index=i;

        }
    }
    return minimum_index;
}

// NAME: updatePathLength
// INPUT PARAMETERS: graph, set_of_vertices(an array of boolean ints),
// distance_from_source(an integer array representing distance), min_index, edge 
// OUTPUT: Returns a boolean if the path should be updated
// PURPOSE: To check if the path has to be updated
int updatePathLength(graph_vertice_t graph[][MAX], int set_of_vertices[], int distance_from_source[], int min_index, int edge){
    return (set_of_vertices[edge]==FALSE && 
    graph[min_index][edge].weight &&  
    distance_from_source[min_index]!=INFINITY && 
    distance_from_source[edge]>(distance_from_source[min_index]+graph[min_index][edge].weight));
}

// NAME: printShortestDistance
// INPUT PARAMETERS:distance_from_source(an integer array representing distance), source
// OUTPUT: Prints out the source, vertex, and the shortest distance from the source node. 
// PURPOSE: To print out the results from the Dijsktra's algorithm 
void printShortestDistance(int distance_from_source[], int source){
    char source_val = getChar(source);
    int index=0;
    cout<<"Source"<<"\t\t\t"<<"Vertex"<<"\t\t\t"<<"Shortest Distance from Source Node"<<endl;
    do{
        cout<<source_val<<"\t\t\t"<<getChar(index)<<"\t\t\t"<<distance_from_source[index]<<endl;
        index++;
    }while(index<=max_index);
}

// NAME: Shortest_Distance
// INPUT PARAMETERS: graph,source
// OUTPUT: Formulates the shortest distance from the source to the node
// PURPOSE: To find the shortest distance from the source to the node
void Shortest_Distance(graph_vertice_t graph[][MAX], int source){
    int set_of_vertices[MAX]; //Set of vertices that are marked/unmarked
    int distance_from_source[MAX]; //Distance from the source
    int min_index; //Index of the minimum value from the marked node

    initialize_algorithm(set_of_vertices, distance_from_source, source);

    for(int i=0; i<=max_index-1; i++){
        min_index = findMinimumDistance(set_of_vertices, distance_from_source);
        set_of_vertices[min_index]=1;

        for(int j=0; j<=max_index; j++){
            if(updatePathLength(graph, set_of_vertices, distance_from_source, min_index, j)){
                distance_from_source[j]=distance_from_source[min_index]+graph[min_index][j].weight;
            }
        }
    }
    printShortestDistance(distance_from_source, source);

}

// NAME: Create_Graph
// INPUT PARAMETERS: graph,filename(a char array)
// OUTPUT: Initializes the graph with the elements from the csv file
// PURPOSE: To initialize a graph from csv file. 
void Create_Graph(graph_vertice_t graph[][MAX], char* filename){
    init_graph(graph);
    read_csv(filename, graph);
}   

int main(){
    graph_vertice_t graph[MAX][MAX];
    int option;
    char val;
    char filename[]="test.csv";
    do{
        cout<<"1. Create a graph"<<endl;
        cout<<"2. Display the graph"<< endl;
        cout<<"3. Shortest Distance from Source"<<endl;
        cout<<"-1. Quit"<<endl;
        cin>>option;
        switch(option){
            case 1: {
                cout<<"Please enter the name of the CSV file: ";
                cin>>filename;
                Create_Graph(graph, filename);
                break;
            }
            case 2: {
                Display(graph);
                break;
            }
            case 3: {
                cout<<"Please enter the source: ";
                cin>>val;
                int source = getIndex(val);
                Shortest_Distance(graph, source);
                break;
            }
        }
    }while(option!=-1);
    return 0;
}