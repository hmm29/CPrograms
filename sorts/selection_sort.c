#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int selection_sort(int *arr, int num){
	int i, j, min_idx;

	if(arr == NULL || num < 0) {
		  return SORT_ERR;
	}

	for(i = 0; i < num-1; i++){
		min_idx = i;
		for(j = i+1; j < num; j++){
			if(arr[j] < arr[min_idx]){
				min_idx = j;
			}
		}
		swap(&arr[i], &arr[min_idx]);
	}

	return SORT_OK;
}

int main(){
	int i, status;
	int arr[8] = {1,3,4,4,87,23,231,-1};

	printf("Array arr before selection sort:\n\n");
	for(i = 0; i < 8; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");

	status = selection_sort(arr, 8);

	if(status != SORT_OK) {
		fprintf(stderr, "Error: must pass non-NULL array pointer and non-negative array length to function selection_sort.\n");
		exit(EXIT_FAILURE);
	}

	printf("Array arr after selection sort:\n\n");
	for(i = 0; i < 8; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");

	exit(EXIT_SUCCESS);
}
