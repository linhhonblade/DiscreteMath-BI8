#include <stdio.h>
#include <stdlib.h>

struct Node {
	int Vname;
	struct Node* next;
};

struct List {
	struct Node* head;
};

struct Graph {
	int V;
	struct List* Varray;
};

struct Graph* initGraph(int V){
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->Varray = (struct List*)malloc(V*sizeof(struct List));
	for(int i = 0; i < V; i++){
		graph->Varray[i].head = NULL;
	}
	return graph;
}

struct Node* initNode(int Vname){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Vname = Vname;
	return newNode;
}

void addEdge(struct Graph* graph, int src, int dest){
	struct Node* newNode = initNode(src);
	newNode->next = graph->Varray[dest].head;
	graph->Varray[dest].head = newNode;
	newNode = initNode(dest);
	newNode->next = graph->Varray[src].head;
	graph->Varray[src].head = newNode;
}

void printAdjList(struct Graph* graph){
	for(int i = 0; i < graph->V; i++){
		struct Node* temp = graph->Varray[i].head;
		printf("Addjacency List of vertex %d\nhead ", i);
		while(temp!=NULL){
			printf("-> %d ",temp->Vname);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	struct Graph* graph = initGraph(5);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	printAdjList(graph);
}