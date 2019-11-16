#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 26
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct VerticeNode{
    char vertice;
    int weight;
}graph_vertice_t;

int getIndex(char val){
    return int(val)-65;
}

int createNewEdge(graph_vertice_t graph[][MAX], char vertice, char connectedTo, int weight){
    graph[getIndex(vertice)][getIndex(connectedTo)].weight = weight;
    graph[getIndex(vertice)][getIndex(connectedTo)].vertice=connectedTo;
    graph[getIndex(connectedTo)][getIndex(vertice)].weight=weight;
    graph[getIndex(connectedTo)][getIndex(vertice)].vertice=vertice;
    return TRUE;
}

int read_csv(char* file_name, graph_vertice_t graph[][MAX]){
    FILE* inputFile;
    char vertice1;
    char vertice2;
    int weight;
    inputFile=fopen("test.csv","r");
    if(inputFile==NULL){
        cout<<"Error reading the file"<<endl;
        return 0;
    }
    while(fscanf(inputFile, "%c,%c,%d\n", &vertice1, &vertice2, &weight)==3){
        cout<<vertice1<<vertice2<<weight<<endl;
        createNewEdge(graph, vertice1, vertice2, weight);
    }
    fclose(inputFile);
    return 1;
}

void init_graph(graph_vertice_t arr[][MAX]){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            arr[i][j].weight = 0;
        }
    }
}

int isZero(graph_vertice_t arr[][MAX], int row){
    int flag=1;
    for(int i=0; i<MAX; i++){
        if((arr[row][i]).weight!=0) flag=0;
    }
    return flag;
}

void print_vertice_and_edge(graph_vertice_t arr[][MAX],int row){
    for(int i=0; i<MAX; i++){
        if((arr[row][i]).weight>0) cout<<arr[row][i].weight <<" ";
        else cout<<0<<" ";
    }
    cout<<endl;
}

void Display(graph_vertice_t graph[][MAX]){
    for(int i=0; i<MAX; i++){
        if(!isZero(graph, i)){
            print_vertice_and_edge(graph, i);
        }
    }
}

void initialize_algorithm(int set_of_vertices[], int distance_from_source[], int source){
    for(int i=0 ; i<MAX ; i++){
        set_of_vertices[i]=FALSE;
        distance_from_source[i]=INT_MAX;
    }
    distance_from_source[source]=0;
}

int findMinimumDistance(int set_of_vertices[], int distance_from_source[]){
    int minimum_val = INT_MAX;
    int minimum_index;
    for(int i=0; i<MAX; i++){
        if(distance_from_source[i]<=minimum_val && set_of_vertices[i]==false){
            minimum_val=distance_from_source[i];
            minimum_index=i;

        }
    }
    return minimum_index;
}

void Shortest_path(graph_vertice_t graph[][MAX], int source){
    int set_of_vertices[MAX];
    int distance_from_source[MAX];

    initialize_algorithm(set_of_vertices, distance_from_source, source);


}

int main(){
    graph_vertice_t graph[MAX][MAX];
    init_graph(graph);
    char filename[]="test.csv";
    read_csv(filename, graph);
    Display(graph);
    return 0;
}