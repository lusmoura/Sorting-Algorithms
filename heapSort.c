/*-------------Heap Sort - O(nlogn)-------------*/
/*Build a max heap out of the array (heapify it)*/
/*Since the greatest value is in the root, put it*/
/*in the last spot of the array and heapify it  */
/*leaving out the last position. Reapeat these  */
/*steps while the heap's size is greater than 1 */

/* Example:
	7   2   3   9   5

			7
		  /   \	
		2		3
	  /   \
	9	   5

	After heapifying:
	9   7   3   2   5
	
			9
		  /   \
		7		3
	  /   \
	2		5
	
	Sorting the root:
	5   7   3   2   9

			5
		  /   \
		7		3
	  / 
	2		
	
	Heapifying again:
	7   5   3   2   9
			
			7
		  /   \
		5		3
	  / 
	2		

	Sorting the root:
	2   5   3   7   9
			2
		  /   \
		5		3

	Heapifying again:
	5   2   3   7   9
			5
		  /   \
		2		3		

	Sorting the root:
	3   2   5   7   9
			3
		  /   
		2
	
	It's heapifyied, so sorting:
	2   3   5   7   9
*/

#define Right(x) x << 1
#define Left(x) x << 1 | 1

void swap(int* a, int* b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return;
}

void heapify(int* v, int n, int pos){
	int largest = pos;
	int right = Right(pos);
	int left = Left(pos);

	// try to find a child that is greater than the root
	if(left < n && v[left] > v[largest]) largest = left;
	if(right < n && v[right] > v[largest]) largest = right;

	// is largest is not root, swap them and heapify again
	if(largest != pos){
		swap(&v[pos], &v[largest]);
		heapify(v, n, largest);
	}
	return;
}

void heapSort(int* v, int n){
	// heapify the array
	for(int i = n/2-1; i >=0; i--)
		heapify(v, n, i);

	for(int i = n-1; i >= 0; i--){
		swap(&v[0], &v[i]);
		heapify(v, i, 0);
	}
	return;
}

int main(int argc, char const *argv[]){

	return 0;
}