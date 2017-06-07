#include <stdio.h>

void insertion_sort(int *arr, int num) {
	int i, j, key;

	for(i = 1; i < num; i++){
		key = arr[i];
		j = i-1;

		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];  
			j--;
		}

		arr[j+1] = key;
	}
}

int main(){
	int vals[7] = {1,2,7,3,2,3,4};

	insertion_sort(vals, 7);
	for(int i = 0; i < 7; i++) {
		printf("%d\t%d\n", i, vals[i]);
	}
	return 1;
}
