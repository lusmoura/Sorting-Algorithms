/*-------Selection Sort - O(n²)--------*/
/*Find the smallest number and swap it */
/*with the value in the first position */
/*Find the second smallest and move it */
/*to the second position. Keep doing it*/
/*until everything's sorted            */

/* Example:
	7   2   3   9   5

	7  *2*  3   9   5
	2   7   3   9   5

	2   7  *3*  9   5
	2   3   7   9   5

	2   3   7   9  *5*
	2   3   5   9   7

	2   3   5   9  *7*
	2   3   5   7   9
*/

void swap(int* a, int* b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}

void selectionSort(int* v, int n){
	for(int i = 0; i < n; i++){
		int minIndex;

		for(int j = i+1; j < n; j++){
			if(v[j] < v[minIndex]) minIndex = j;
		}

		swap(&v[minIndex], &v[i]);
	}
	return;
}