/*-------Counting Sort - O(n)-------*/
/*Count the number of repetitions of*/
/*a certain key and then reconstruct*/
/*the array using the counting array*/

/* Exemple:
	v =       7   2   3   9   5   2   3
	
	index  =  0   1   2   3   4   5   6   7
	number =  2   3   4   5   6   7   8   9
	count  =  2   2   0   1   0   1   0   1

	Reconstructing:
	v = 2   2   3   3   5   7   9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxSize = 100005;

void printVet(int* v, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int min(int a, int b){
	return a > b ? b : a;
}

int max(int a, int b){
	return a > b ? a : b;
}

int findMax(int*v, int n){
	int ret = v[0];
	for(int i = 0; i < n; i++){
		ret = max(ret, v[i]);
	}
	return ret;
}

int findMin(int*v, int n){
	int ret = v[0];
	for(int i = 0; i < n; i++){
		ret = min(ret, v[i]);
	}
	return ret;
}

void countingSort(int* v, int n){
	int greatest = findMax(v, n);
	int smallest = findMin(v, n);
	int size = greatest - smallest + 2;
	int count[size];
	memset(count, 0, sizeof(count));

	for(int i = 0; i < n; i++){
		count[v[i] - smallest + 1]++;
	}

	printVet(count, size);
	int j = 0;
	for(int i = 0; i < size; i++){
		while(count[i]){
			v[j] = i + smallest - 1;
			count[i]--;
			j++;
		}
	}
}

int main(int argc, char const *argv[]){
	int n, v[maxSize];
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
	}

	countingSort(v, n);

	printVet(v, n);

	return 0;
}