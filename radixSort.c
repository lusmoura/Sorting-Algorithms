/*-------Radix Sort - O(n)-------*/
/*Use the counting sort algorithm*/
/* to each digit of the numbers  */

/* Example:
	1   205   120   54   23

	Sorting by least significant digit
	120   1   23   54   205
	
	Sorting by the next digit:
	1   205   120  23   54   

	Sorting by the next digit:
	1   23   54   120    205

*/

#include <string.h>
#include <stdio.h>
const int maxSize = 100005;

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

void countingSort(int* v, int n, int pot) { 
    int out[n];
    int count[10];
    memset(count, 0, sizeof(count));
  
  	// frequency of each digit
    for (int i = 0; i < n; i++) {
        count[ (v[i]/pot) % 10 ]++;
    }
 
 	//  accumulated sum	to know where the number must be in the array
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }
  
  	// auxiliary array to store the values
    for (int i = n - 1; i >= 0; i--) { 
        out[count[ (v[i]/pot) % 10 ] - 1] = v[i]; 
        count[ (v[i]/pot) % 10 ]--; 
    } 
  
  	// copying the auxilixary array to the original one
    for (int i = 0; i < n; i++) {
        v[i] = out[i]; 
    }

    return;
} 

void radixSort(int* v, int n){
	int greatest = findMax(v, n);

	for(int i = 1; greatest/i > 0; i *= 10){
		countingSort(v, n, i);
	}
	
    return;
}

int main(int argc, char const *argv[]){
	
	int n, v[maxSize];
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
	}

	radixSort(v, n);
	printVet(v, n);

	return 0;
}