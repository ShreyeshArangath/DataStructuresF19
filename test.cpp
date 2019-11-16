#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 26
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct VerticeNode{
    int weight;
}graph_vertice_t;

int getIndex(char val){
    return int(val)-65;
}

int read_csv(char* file_name, graph_vertice_t graph[MAX][MAX]){
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

int createNewEdge(graph_vertice_t graph[MAX][MAX], char vertice, char connectedTo, int weight){
    graph[getIndex(vertice)][getIndex(connectedTo)].weight = weight;
    return TRUE;
}

int main(){
    graph_vertice_t graph[MAX][MAX];
    char filename[]="test.csv";
    read_csv(filename, graph);
    return 0;
}