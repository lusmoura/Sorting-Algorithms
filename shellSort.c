/*---------Shell Sort - O(n²)---------*/
/*Variation of insertion sort. Instead*/
/*of comparing the element with the   */
/*previous one, compares it with the  */
/*one with distance being the gap     */

/* Example:
	29   41   7   23   5

	gap = 2
	29   41  *7*  23   5
	*7*  41  29   23   5

	 7   41  29   23  *5*
	 7   41  *5*  23   29
	*5*  41   7   23   29

	gap = 1
	 5  *41*  7   23   29
	
	 5   41   *7*   23   29
	 5   *7*   41   23   29

	 5    7   *41*  23   29

	 5    7    41  *23*  29
	 5    7   *23*  41   29

	 5    7    23   41  *29*
	 5    7    23  *29*  41

	 5    7    23   29   41
*/

#include <stdio.h>

const int maxSize = 100005;	

void printVet(int* v, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

void shellSort(int* v, int n){
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			int aux = v[i];

			int j;
			for(j = i; j >= gap; j -= gap){
				if(v[j-gap] <= aux) break;
				v[j] = v[j-gap];
			}

			v[j] = aux;
		}
	}
}

int main(int argc, char const *argv[]){
	int n, v[maxSize];
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
	}

	shellSort(v, n);

	printVet(v, n);

	return 0;
}