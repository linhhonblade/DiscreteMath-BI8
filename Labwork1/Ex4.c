// Just implement the EFF(Earliest Finish First) strategy
// Keyword for Google: Interval Scheduling
#include <stdio.h>
#include <stdlib.h>

struct Talk {
	float startTime;
	float finishTime;
};

struct Talk* getTalkInfo(){
	struct Talk* talk = (struct Talk*)malloc(sizeof(struct Talk));
	printf("Start time: ");
	scanf("%f", &talk->startTime);
	printf("Finish time: ");
	scanf("%f", &talk->finishTime);
	return talk;
}


void showTalksInfo(struct Talk* talks[], int talkNum){
	for(int i = 0; i < talkNum; i ++){
		if (talks[i] == NULL){
			printf("Talk number %d: NULL\n", i);
			continue;	
		}
		printf("Talk number %d:\nStart: %.1f\nFinish: %.1f\n",i, talks[i]->startTime, talks[i]->finishTime);
	}
}

void swap(struct Talk** a, struct Talk** b){
	struct Talk* c = *a;
	*a = *b;
	*b = c;
}

// sort talks by bubble sort
void sortTalks(struct Talk* talks[], int size){ 
	int i, j;
	j = size-1;
	while(j > 0){
		for(i = 0; i < j; i++){
			if(talks[i]->finishTime > talks[i+1]->finishTime){
				swap(&talks[i], &talks[i+1]);
			}
		}
		j--;
	}
}

int main(){
	int n, i, j, k;
	printf("How many talks today?: ");
	scanf("%d", &n);
	struct Talk* talks[n];	
	//struct Talk* talksScheduled[n];
	// get talks info
	for (i = 0; i < n; i++){
		printf("Talk number %d:\n",i );
		talks[i] = getTalkInfo();
	}
	// sort talks
	sortTalks(talks, n);

	//showTalksInfo(talks, n);

	// scheduling
	//choose earliest finish time
	//croos off the overlaps
	i = 0;
	k = 0;
	while (i < n){
		if (talks[i] == NULL){
			i++;
			continue;
		}
		if (talks[i] != NULL){
			for(j = i+1; j < n; j++){
				if (talks[j]==NULL){
					continue;
				}
				if (talks[j]->startTime < talks[i]->finishTime){
					free(talks[j]);
					talks[j]=NULL;

				}
			}
			i++;
		}
	}
	showTalksInfo(talks, n);
	return 0;
}
