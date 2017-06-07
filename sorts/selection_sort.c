#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selection_sort(int *arr, int num){
	int i, j, min_idx;

	for(i = 0; i < num-1; i++){
		min_idx = i;
		for(j = i+1; j < num; j++){
			if(arr[j] < arr[min_idx]){
				min_idx = j;
			}
		}
		swap(&arr[i], &arr[min_idx]);
	}
}

int main(){
	int i;
	int vals[8] = {1,3,4,4,87,23,231,-1};
	selection_sort(vals, 8);
	for(i = 0; i < 8; i++){
		printf("Index %d:\t%d\n", i, vals[i]);
	}
	return 0;
}
