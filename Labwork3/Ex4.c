#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
	int key;
	struct Node* next;
};

struct Stack {
	struct Node* head;
};

struct Node* initNode(int key){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->next = NULL;
	return node;
}

struct Stack* initStack(){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->head = NULL;
	return stack;
}

void push(struct Stack* stack, int name){
	struct Node* temp = initNode(name);
	temp->next = stack->head;
	stack->head = temp;
	return;
}

void pop(struct Stack* stack){
	struct Node* temp = stack->head;
	stack->head = stack->head->next;
	free(temp);
	return;
}

bool* initVisitList(int size){
	bool* visitList = (bool*)malloc(size*sizeof(bool));
	for(int i = 0; i < size; i++)
		visitList[i] = false;
	return visitList;
}

int getNext(int V, int adjMatrix[V][V], bool* visitList, int src){
	for(int i = 0; i < V; i++){
		if((visitList[i] == false) && (adjMatrix[src][i] != 0))
			return i;
	}
	return -1;
}

void printSpanningTree(int V, int** spanningTree){
	for(int i = 0; i<V; i++){
		for(int j = 0; j<V; j++){
			printf("%d\t",spanningTree[i][j]);
		}
		printf("\n");
	}
}

int** initAdjMatrix(int V){
	int** adjMatrix = (int**)malloc(V*sizeof(int*));
	for (int i = 0; i < V; i++){
		adjMatrix[i] = (int*)malloc(V*sizeof(int));
	}
	for (int i = 0; i < V; ++i){
		for(int j = 0; j < V; j++){
			adjMatrix[i][j] = 0;
		}
	}
	return adjMatrix;
}


int** getSpanningTree(int V, int adjMatrix[V][V], int src){
	int** spanningTree = initAdjMatrix(V);
	bool* visitList = initVisitList(V);
	struct Stack* stack = initStack();
	visitList[src] = true;
	push(stack, src);
	while(stack->head != NULL){
		int next = getNext(V, adjMatrix, visitList, stack->head->key);
		if(next == -1){
			pop(stack);
		}
		else{
			visitList[next] = true;
			spanningTree[stack->head->key][next] = 1; //simple graph is unweighted
			spanningTree[next][stack->head->key] = 1;
			push(stack, next);
		}
	}
	return spanningTree;
}


int main(){
	int adjMatrix[5][5] = {{0,1,0,0,1},
							{1,0,1,1,1},
							{0,1,0,1,0},
							{0,1,1,0,1},
							{1,1,0,1,0}};
	int** spanningTree = getSpanningTree(5, adjMatrix, 0);
	printSpanningTree(5, spanningTree);
}