#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int insertion_sort(int *arr, int num) {
	int i, j, key;

	if(arr == NULL || num < 0) {
		  return SORT_ERR;
	}

	for(i = 1; i < num; i++){
		key = arr[i];
		j = i-1;

		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
	}

	return SORT_OK;
}

int main(){
	int i, status;
	int vals[7] = {1,2,7,3,2,3,4};

	status = insertion_sort(vals, 7);
	if(status != SORT_OK) {
		fprintf(stderr, "Error: invalid inputs for insertion_sort.\n");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < 7; i++) {
		printf("%d\t%d\n", i, vals[i]);
	}

	exit(EXIT_SUCCESS);
}
