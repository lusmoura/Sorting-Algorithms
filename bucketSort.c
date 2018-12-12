/*--------Bucket Sort - O(n)--------*/
/*Buckets are used to store elements*/
/*sorted with the same value. After */
/*that, the precedure is repeated with*/
/*all the values                      */

#include <stdlib.h>
#include <stdio.h>

const int maxSize = 100005;

typedef struct _elems {
	int key;
	float value;
} elem;

typedef struct _node {
	elem info;
	struct _node* next;
} node;

typedef struct _bucket {
	node* begin;
	node* end;
} bucket;

void printVet(int* v, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int max(int a, int b){
	return a > b ? a : b;
}

int findMax(int* v, int n){
	int ret = v[0];
	for(int i = 0; i < n; i++){
		ret = max(ret, v[i]);
	}
	return ret;
}

void bucketSort(int* v, int n){
	int greatest = findMax(v, n);
	
	bucket *b = calloc(maxSize+1, sizeof(bucket));

	for(int i = 0; i < n; i++){
		int key = v[i];

		node* newNode = malloc(sizeof(node));
		newNode->info = v[i];
		newNode->next = NULL;

		if(b[key].begin == NULL)
			b[key].begin = newNode;
		else
			(b[key].end)->next = newNode;
		b[key].end = newNode;
	}

	int j = 0;
	for(int i = 0; i < maxSize; i++){
		node* pos = b[i].begin;
		while(pos != NULL){
			v[j] = pos->info;
			j++;

			node* remove = pos;
			pos = pos->next;
			b[i].begin = pos;
			free(remove);
		}
	}
	free(b);
}

int main(int argc, char const *argv[]){
	int n, v[maxSize];
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
	}

	bucketSort(v, n);

	printVet(v, n);

	return 0;
}
