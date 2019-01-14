#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

struct Queue{
	struct Node* head;
	struct Node* tail;
	int size;
};

struct Queue* initQueue(){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
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


bool* initCheckVisit(int size){
	bool* CheckVisit = (bool*)malloc(size*sizeof(bool));
	for(int i = 0; i < size; i++){
		CheckVisit[i] = false;
	}
	return CheckVisit; 
}

void enQueue(struct Queue* queue,struct Node* vertex){
	if(queue->size == 0){
		queue->tail = vertex;
		queue->head = vertex;
		queue->size++;
	}
	else{
		queue->tail->next = vertex;
		queue->tail = vertex;
		queue->size++;
	}
}

void deQueue(struct Queue* queue){
	struct Node* temp = queue->head->next;
	queue->head->next = NULL;
	free(queue->head);
	queue->head = temp;
	queue->size--;

}



void BFS(struct Graph* graph, int start){
	bool* checkVisitList = initCheckVisit(graph->V);
	struct Queue* queue = initQueue();
	struct Node* startNode = initNode(start);
	enQueue(queue, startNode);
	checkVisitList[startNode->Vname] = true;
	while(queue->size!=0){
		struct Node* temp = graph->Varray[queue->head->Vname].head;
		while(temp != NULL){
			if(checkVisitList[temp->Vname] == true){
				temp = temp->next;
			}
			else{
				struct Node* temp2 = initNode(temp->Vname);
				enQueue(queue, temp2);
				checkVisitList[temp2->Vname] = true;
				temp = temp->next;
			}
		}
		printf("%d\n",queue->head->Vname );
		deQueue(queue);
	}
}


int main(){
	int V = 5;
	struct Graph* graph = initGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	BFS(graph, 3);
	return 0;

}