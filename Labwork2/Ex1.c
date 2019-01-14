#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Vertex {
	char name;
	int color; // uncolored is 0 // red is 1 // blue is -1
};

struct Edge {
	struct Vertex* v1;
	struct Vertex* v2;
};

//int size = 5;
//int edgeNum = 4;
//struct Vertex** unColoredVertices[] = (struct Vertex**)malloc(size*sizeof(struct Vertex*));
//void addToUncoloredList(struct Vertex* vertexPtr, struct Vertex** vertices[], int size){
//	for (int i = 0; i < size; i++){
//		if (*vertices[i] == NULL){
//			*vertices[i] = vertexPtr;
//			break;
//		}
//	}
//} 


// return 0 means skip coloring (due to lack of information)
// return -1 means same color occurs
// return 1 means done coloring
int colorEdge(struct Edge* edgePtr){
	if (edgePtr->v1->color == 0 && edgePtr->v2->color == 0){
		//addToUncoloredList(edgePtr->v1, &unColoredVertices, size);
		//addToUncoloredList(edgePtr->v2, &unColoredVertices, size);
		return 0;
	}
	else if (edgePtr->v1->color != edgePtr->v2->color){
		if(edgePtr->v1->color*edgePtr->v2->color == 0){
			if(edgePtr->v1->color != 0){
				edgePtr->v2->color = 0 - edgePtr->v1->color;
			}
			else if (edgePtr->v1->color == 0){
				edgePtr->v1->color = 0 - edgePtr->v2->color;
			}
			return 1;
		}
		return 1;
	}
	else if (edgePtr->v1->color == edgePtr->v2->color){
		return -1;
	}
}



bool isBiPartite(struct Edge* E[], int size){
	for(int i = 0; i < size; i++){
		if (i == 0){
			E[i]->v1->color = 1;
			E[i]->v2->color = -1;
		}

		if (colorEdge(E[i])==0 || colorEdge(E[i])==1){
			;
		}
		else if(colorEdge(E[i]) == -1){
			return false;
		}
	}
	return true;
}




int main(){
	struct Vertex a = {'a', 0};
	struct Vertex b = {'b', 0};
	struct Vertex c = {'c', 0};
	struct Vertex d = {'d', 0};
	struct Vertex e = {'e', 0};

	struct Edge e1 = {&a, &c};
	struct Edge e2 = {&a, &d};

	struct Edge e3 = {&a, &e};
	struct Edge e4 = {&b, &e};
	struct Edge e5 = {&b, &a};
	struct Edge* edges[] = {&e1, &e2, &e3, &e4, &e5};

	//a.color = 1;
	if(isBiPartite(edges, 5)==true){
		printf("Yes\n");
	}
	else printf("No\n");
}


