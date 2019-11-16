#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 26
#define TRUE 1
#define FALSE 0
#define INFINITY INT_MAX

using namespace std;

char max_val;
typedef struct VerticeNode{
    char vertice;
    int weight;
}graph_vertice_t;

int getIndex(char val){
    return int(val)-65;
}

char getChar(int val){
    return char(val+65);
}

int createNewEdge(graph_vertice_t graph[][MAX], char vertice, char connectedTo, int weight){
    graph[getIndex(vertice)][getIndex(connectedTo)].weight = weight;
    graph[getIndex(vertice)][getIndex(connectedTo)].vertice=connectedTo;
    graph[getIndex(connectedTo)][getIndex(vertice)].weight=weight;
    graph[getIndex(connectedTo)][getIndex(vertice)].vertice=vertice;
    return TRUE;
}

char maxIndexFromFile(char ver1, char ver2){
    return (ver1>ver2)?ver1:ver2;
}

int read_csv(char* file_name, graph_vertice_t graph[][MAX]){
    FILE* inputFile;
    char vertice1;
    char vertice2;
    int weight;
    inputFile=fopen(file_name,"r");
    if(inputFile==NULL){
        cout<<"Error reading the file"<<endl;
        return 0;
    }
    while(fscanf(inputFile, "%c,%c,%d\n", &vertice1, &vertice2, &weight)==3){
        cout<<vertice1<<vertice2<<weight<<endl;
        if(max_val<maxIndexFromFile(vertice1, vertice2)){
            max_val=maxIndexFromFile(vertice1, vertice2);
        }
        createNewEdge(graph, vertice1, vertice2, weight);
    }
    fclose(inputFile);
    return 1;
}

void init_graph(graph_vertice_t arr[][MAX]){
    int max_index = getIndex(max_val);
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
        set_of_vertices[i]=0;
        distance_from_source[i]=INT_MAX;
    }
    distance_from_source[source]=0;
}

int findMinimumDistance(int set_of_vertices[], int distance_from_source[]){
    int minimum_val = INT_MAX;
    int minimum_index;
    for(int i=0; i<MAX; i++){
        if(distance_from_source[i]<=minimum_val && set_of_vertices[i]==0){
            minimum_val=distance_from_source[i];
            minimum_index=i;

        }
    }
    return minimum_index;
}

int updatePathLength(graph_vertice_t graph[][MAX], int set_of_vertices[], int distance_from_source[], int min_index, int edge){
    return (set_of_vertices[edge]==FALSE && 
    graph[min_index][edge].weight &&  
    distance_from_source[min_index]!=INFINITY && 
    distance_from_source[edge]>(distance_from_source[min_index]+graph[min_index][edge].weight));
}

void printShortestDistance(int distance_from_source[], int source){
    char source_val = getChar(source);
    int index=0;
    cout<<"Source"<<"\t\t\t"<<"Vertex"<<"\t\t\t"<<"Shortest Distance from Source Node"<<endl;
    do{
        cout<<source_val<<"\t\t\t"<<getChar(index)<<"\t\t\t"<<distance_from_source[index]<<endl;
        index++;
    }while(index<MAX);
}

void Shortest_Distance(graph_vertice_t graph[][MAX], int source){
    int set_of_vertices[MAX];
    int distance_from_source[MAX];
    int min_index;

    initialize_algorithm(set_of_vertices, distance_from_source, source);

    for(int i=0; i<MAX-1; i++){
        min_index = findMinimumDistance(set_of_vertices, distance_from_source);
        set_of_vertices[min_index]=1;

        for(int j=0; j<MAX; j++){
            if(updatePathLength(graph, set_of_vertices, distance_from_source, min_index, j)){
                distance_from_source[j]=distance_from_source[min_index]+graph[min_index][j].weight;
            }
        }
    }
    printShortestDistance(distance_from_source, source);

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
                init_graph(graph);
                read_csv(filename, graph);
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