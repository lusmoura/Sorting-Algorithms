/*---------Insertion Sort - O(n²)---------*/
/*Starting from the second element in the */
/*array, compares each element with all   */
/*the previous ones, until the right palce*/
/*to insert it is found                   */

/* Example: 
	7   2   3   9   5   1

	7  *2*  3   9   5   1
	*2* 7   3   9   5   1

	2   7  *3*  9   5   1
	2  *3*  7   9   5   1

	2   3   7  *9*  5   1

	2   3   7   9  *5*  1
	2   3   7  *5*  9   1
	2   3  *5*  7   9   1
	
	2   3   5   7   9  *1*
	2   3   5   7  *1*  9
	2   3   5  *1*  7   9
	2   3  *1*  5   7   9
	2  *1*  3   5   7   9
   *1*  2   3   5   7   9

    1   2   3   5   7   9
*/

void insertionSort(int* vet, int length){
	int i = 1;

	while(i < length){
		
		// set an element to sort
		int key = vet[i];

		// shift all the elements until the key's right position
		int j = i-1;
		while(j>= 0 && key < vet[j]){
			vet[j+1] = vet[j]; 
			j--;
		}

		// insert the key in it's right position
		vet[j+1] = key;
		i++;
	}
}

void insertionSortRec(int* vet, int length){
	// same thing but recursively 
	if(length < 1) return;
	insertionSortRec(vet, length - 1);

	int i = 1;
	while(i < length){
		int key = vet[i]; 

		int j = i-1;		
		while(j>= 0 && key < vet[j]){
			vet[j+1] = vet[j]; 
			j--;
		}

		vet[j+1] = key;
	}
}