/*-------Quick Sort - Average:O(nlogn) - Worst:O(n²)-------*/
/*Using one of the possible methods a pivot is chosen.     */
/*The array is partitioned and all the elements before the */
/*pivot are smaller than it and the elements after the pivot*/
/*are greatter. It can be performed through a series of swaps*/

/* Example: 
	Using the middle element as pivot:
	7   2   3   9   5
	
	7   2  *3*  9   5
   *3*  2   7   9   5
    2  *3*  7   9   5
	
    2   3   7  *9*  5
    2   3   7   5  *9*
	
	2   3   7  *5*  9
	2   3  *5*  7   9

	2   3   5   7   9
*/

void swap(int* a, int* b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}

int partition(int*v, int left, int right){
	int mid = (left+right)/2;
	int pivot = v[mid];

	while(left <= right){
		while(v[left] < pivot) left++; // find element greater that is on left
		while(v[right] > pivot) right--; // find element smaller that is on rigth

		// swap these elements
		if(left <= right){
			swap(&v[left], &v[right]);
			left++;
			right--;
		}
	}

	return left;
}

void quickort(int* v, int left, int right){
	int index = partition(v, left, right);

	if(left < index - 1) quickort(v, left, index-1);
	if(right > index) quickort(v, index, right);
	
	return;
}