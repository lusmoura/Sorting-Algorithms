/*--------Bubble Sort - O(n²)---------*/
/*Swap the adjecent elements if they  */
/*are in the wrong order              */

/*Example:
	7   2   3   9   5

	*7* *2*   3   9   5
	 2   7    3   9   5

	 2   *7* *3*   9   5
	 2    3   7    9   5

	 2   3   *7* *9*   5
	 2   3    7   9    5

	 2   3    7  *9* *5*
	 2   3    7   5   9 

	*2* *3*   7   5   9
	 2   3    7   5   9

	 2  *3* *7*   5   9
	 2   3   7    5   9

	 2   3   *7* *5*   9
	 2   3    5   7    9
*/

void swap(int* a, int* b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}

void bubbleSort(int* v, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-i-1; j++){
			if(v[j] > v[j+1]){
				swap(&v[j], &v[j+1]);
			}
		}
	}
}