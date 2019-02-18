// build random binary search tree from list

#include <stdlib.h>
#include <stdio.h>

struct Tree {
	struct Node* root;
};

struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	struct Node* p;
};

struct Tree* initTree(){
	struct Tree* tree = (struct Tree*)malloc(sizeof(struct Tree));
	tree->root = NULL;
	return tree;
}

struct Node* initNode(int key){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->p = NULL;
	return node;
}

void inOrder(struct Node* root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d\n",root->key);
		inOrder(root->right);
	}
	return;
}

void insertTree(struct Tree* tree, int key){
	struct Node* node = initNode(key);
	struct Node* temp0 = NULL;
	struct Node* temp1 = tree->root;
	while(temp1!=NULL){
		temp0 = temp1;
		if(node->key < temp1->key)
			temp1 = temp1->left;
		else temp1 = temp1->right;
	}
	node->p = temp0;
	if (temp0==NULL)
		tree->root = node;
	else if(node->key < temp0->key)
		temp0->left = node;
	else temp0->right = node;
	return;
}

int main(){
	int A[] = {1,4,2,5,3,33,22,42,14,25,11,9,31};
	struct Tree* T = initTree();
	int size = sizeof(A)/sizeof(int);
	for(int i = 0; i < size ; i++){
		insertTree(T, A[i]);
	}
	inOrder(T->root);
	return 0;
}