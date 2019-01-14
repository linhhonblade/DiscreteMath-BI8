#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


///////// basic components of graph with adjacency list /////////
struct Node {
	int Vname;
	struct Node* next;
};

struct List {
	struct Node* head;
	int size;
};

struct Graph {
	int V;
	struct List* Varray;
};

struct Node* initNode(int Vname){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Vname = Vname;
	return newNode;
}

struct Graph* initGraph(int V){
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->Varray = (struct List*)malloc(V*sizeof(struct List));
	for(int i = 0; i < V; i++){
		graph->Varray[i].head = NULL;
		graph->Varray[i].size = 0;
	}
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
	struct Node* newNode = initNode(src);
	newNode->next = graph->Varray[dest].head;
	graph->Varray[dest].head = newNode;
	graph->Varray[dest].size++;
	newNode = initNode(dest);
	newNode->next = graph->Varray[src].head;
	graph->Varray[src].head = newNode;
	graph->Varray[src].size++;
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
////////////////////////////////////////////////////////////


/////////// basic components of checking Eulerian ///////////
bool* initCheckVisit(int size){
	bool* CheckVisit = (bool*)malloc(size*sizeof(bool));
	for(int i = 0; i < size; i++){
		CheckVisit[i] = false;
	}
	return CheckVisit; 
}
void resetCheckVisit(bool** checkVisitList, int size){
	for(int i = 0; i < size; i++){
		checkVisitList[i] = false;
	}
	return;
}
void BFS(struct Graph* graph, bool* checkVisit, int vertex){
	if(checkVisit[vertex] == true){;}
	else{
		checkVisit[vertex] = true;
		struct Node* temp = graph->Varray[vertex].head;
		while(temp != NULL){
			BFS(graph, checkVisit, temp->Vname);
			temp = temp->next;
		}
	}
	return;
}

bool isConnected(struct Graph* graph){
	bool* checkVisitList = initCheckVisit(graph->V);
	int i = 0;
	while(true){
		if(graph->Varray[i].size == 0){
			continue;
		}
		else{
			BFS(graph, checkVisitList, i);
			for(int j = 0; j < graph->V; j++){
				if(graph->Varray[j].size == 0){;}
				else if (graph->Varray[j].size != 0 && checkVisitList[j] == true){;}
				else return false;
			}
			return true;
		}
	}
}

int countOdd(struct Graph* graph){
	int count = 0;
	for(int i = 0; i < graph->V; i++){
		if(graph->Varray[i].size % 2 == 1){
			count++;
		}
	}
	return count;
}
void checkEulerian(struct Graph* graph){
	if (isConnected(graph) == false){
		printf("graph is not Eulerian\n");
		return;
	}
	else{
			int odd = countOdd(graph);
			if(odd == 2){
				printf("graph has Eulerian Path\n");
			}
			else if(odd == 0){
				printf("graph has Eulerian circuit\n");
			}
			else{
				printf("Something wrong !!!\n");
			}
			return;
	}
}
//////////////////////////////////////////////////////////////

int main(){
	struct Graph* g1 = initGraph(5);
	addEdge(g1, 1, 0); 
    addEdge(g1, 0, 2); 
    addEdge(g1, 2, 1); 
    addEdge(g1, 0, 3); 
    addEdge(g1, 3, 4); 
    checkEulerian(g1);

    struct Graph* g2 = initGraph(5);
    addEdge(g2, 1, 0); 
    addEdge(g2, 0, 2); 
    addEdge(g2, 2, 1); 
    addEdge(g2, 0, 3); 
    addEdge(g2, 3, 4); 
    addEdge(g2, 4, 0); 
    checkEulerian(g2);
}