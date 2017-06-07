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
	int arr[8] = {1,2,7,3,2,3,54,-2};

	printf("Array arr before insertion sort:\n\n");
	for(i = 0; i < 8; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");

	status = insertion_sort(arr, 8);

	if(status != SORT_OK) {
		fprintf(stderr, "Error: must pass non-NULL array pointer and non-negative array length to function insertion_sort.\n");
		exit(EXIT_FAILURE);
	}

	printf("Array arr after insertion sort:\n\n");

	for(i = 0; i < 8; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");

	exit(EXIT_SUCCESS);
}
