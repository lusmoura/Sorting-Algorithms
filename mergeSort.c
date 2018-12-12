/*-----------Merge Sort - O(nlogn)-----------*/
/*Divides the array in the middle recursively*/
/*until there's only one element. Then, the  */
/*smaller arrays are merged and sorted in an */
/*auxiliary array, which is copied to the    */
/*original when the process is over          */

/* Example: 
	Recursive calls:
	   			7   2   3   9   5   1   6   8

			7   2   3   9    |     5   1   6   8

		7   2    |    3   9    |    5   1    |    6   8

	7   |   2   |   3   |   9   |   5   |   1   |   6   |   8

	Merging:
	2   7   |   3   9   |    1   5   |    6   8

		2   3   7   9   |   1   5   6   8

		 1   2   3   5   6   7   8   9
*/


void alternativeMergeSort(int* vet, int* aux, int start, int end){
	// base case
	if(start >= end) return;
	
	int mid = (start+end)/2;

	// recursive call for both sides of the current position
	alternativeMergeSort(vet, aux, start, mid);
	alternativeMergeSort(vet, aux, mid+1, end);

	int i = start;
	int j = mid+1;
	int k = 0;

	// merge both sides
	while(i <= mid || j <= end){
		if(j > end || i <= mid && vet[i] < vet[j])
			aux[k++] = vet[i++];
		else
			aux[k++] = vet[j++];	
	}

	// copy the auxiliary array to the original one
	for(int i = start; i <= end; ++i){
		vet[i] = aux[i-start];
	}
}

void mergeSort(int* vet, int start, int end){
	//base case
	if (start >= end) return;
	
	int mid = (start+end)/2;
	
	//recursion step
	mergeSort(vet, start, mid);
	mergeSort(vet, mid+1, end);
	
	//combination of the partial results
	int i = start;
	int j = mid+1;
	int k = 0;

	int* aux = malloc((end - start + 1) * sizeof(int));


	//while there are elements to compare, copy them
	while(i <= mid && j <= end){
		if(vet[i] < vet[j])
			aux[k++] = vet[i++];
		else
			aux[k++] = vet[j++];
	}

	//copy the rest of the list
	while(i <= mid){
		aux[k++] = vet[i++];
	}
	
	while(j <= end){
		aux[k++] = vet[j++];
	}

	
	// copy the auxiliary array to the original one
	for(i = start; i <= end; i++){
		vet[i] = aux[i-start];
	}

	free(aux);
}