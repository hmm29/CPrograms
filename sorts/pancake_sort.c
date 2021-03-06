#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int get_index_of_largest(int *arr, int length){
  int i;
  int idx_max;

  idx_max = 0;

  for(i = 1; i < length; i++){
    if(arr[i] > arr[idx_max]) {
      idx_max = i;
    }
  }

  return idx_max;
}

void flip(int *arr, int num_elts){
  int start = 0,
      end = num_elts-1;

  while(start < end){
    swap(&arr[start], &arr[end]);
    start++;
    end--;
  }
}

int pancake_sort(int *arr, int num){
  int num_elts,
      idx_largest;

	if(arr == NULL || num < 0) {
		  return SORT_ERR;
	}

	num_elts = num;

  while(num_elts > 0) {
    idx_largest = get_index_of_largest(arr, num_elts);
    flip(arr, idx_largest+1);
    flip(arr, num_elts);
    num_elts--;
  }

	return SORT_OK;
}

int main(){
	int i, status;
	int arr[8] = {1,3,4,4,87,23,231,-1};

	printf("Array arr before pancake sort:\n\n");
	for(i = 0; i < 8; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");

	status = pancake_sort(arr, 8);

	if(status != SORT_OK) {
		fprintf(stderr, "Error: must pass non-NULL array pointer and non-negative array length to function pancake_sort.\n");
		exit(EXIT_FAILURE);
	}

	printf("Array arr after pancake sort:\n\n");
	for(i = 0; i < 8; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");

	exit(EXIT_SUCCESS);
}
