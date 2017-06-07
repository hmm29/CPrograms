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
	int vals[8] = {1,3,4,4,87,23,231,-1};

	status = selection_sort(vals, 8);

	if(status == SORT_ERR) {
		fprintf(stderr, "Error: Array is empty.\n");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < 8; i++){
		printf("Index %d:\t%d\n", i, vals[i]);
	}

	exit(EXIT_SUCCESS);
}
