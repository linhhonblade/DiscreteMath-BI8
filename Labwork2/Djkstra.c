#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INF 1000000;

int V = 0;

void printSolution(int distList[]){
	for(int i = 0; i < V; i++){
		printf("%d\t%d\n",i, distList[i]);
	}
}

int getMinIndex(int distList[], bool visitList[]){
	int min_index = -1;
	int minDist = INF;
	for(int i = 0; i < V; i++){
		if(distList[i] < minDist && visitList[i] == false ){
			minDist = distList[i];
			min_index = i;
		}
	}
	return min_index;
}


void dijkstra(int graph[V][V], int src){
	bool visitList[V];
	int distList[V];
	for(int i = 0; i < V; i++){
		visitList[i] = false;
		distList[i] = INF;
	}
	distList[src] = 0;
	for(int count = 0; count < V; count++){
		int min_index = getMinIndex(distList, visitList);
		visitList[min_index] = true;
		for(int i = 0; i < V; i++){
			if((graph[min_index][i] != 0) && (visitList[i] == false) && (graph[min_index][i] + distList[min_index] < distList[i]))
				distList[i] = graph[min_index][i] + distList[min_index];
		}
	}
	printSolution(distList);
}

int main(){
	V = 9;
	int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                       {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                       {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                       {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                       {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                       {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                       {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                       {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}}; 
    dijkstra(graph, 0);
  	return 0;
}