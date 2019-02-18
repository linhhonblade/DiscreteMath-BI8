
// many thanks to GeeksforGeeks

#include <stdio.h>
#include <stdbool.h>
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

bool* initCheckVisit(int size){
	bool* CheckVisit = (bool*)malloc(size*sizeof(bool));
	for(int i = 0; i < size; i++){
		CheckVisit[i] = false;
	}
	return CheckVisit; 
}

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

bool isCyclic(struct Graph* graph, int v, bool* CheckVisit, int parent){
	CheckVisit[v] = true;
	struct Node* temp = graph->Varray[v].head;
	while(temp!=NULL){
		if(CheckVisit[temp->Vname]==false){
			if(isCyclic(graph, temp->Vname, CheckVisit, v))
				return true;
		}

		else if(temp->Vname != parent)
			return true;
		temp = temp->next;
	}
	return false;
}

bool isTree(struct Graph* graph){
	bool* CheckVisitList = initCheckVisit(graph->V);
	if(isCyclic(graph, 1, CheckVisitList, -1))
		return false;
	for(int i = 0; i < graph->V; i++){
		if(CheckVisitList[i] == false)
			return false;
	}
	return true;
}

int main(){
	struct Graph* graph = initGraph(5);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 4);
	//addEdge(graph, 2, 3);
	//addEdge(graph, 1, 3);
	if(isTree(graph))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}