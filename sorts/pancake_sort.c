#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int get_index_of_largest(int *arr, int length){
  int i;
  int idx_max;

  if(arr == NULL) {
    return -1;
  }

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

void pancake_sort(int *arr, int length){
  int num_elts = length,
      idx_largest;

  while(num_elts > 0) {
    idx_largest = get_index_of_largest(arr, num_elts);
    if(idx_largest == -1){
      fprintf(stderr, "Error: Array is empty.\n");
      break;
    }
    flip(arr, idx_largest+1);
    flip(arr, num_elts);
    num_elts--;
  }
}

int main(){
	int i;
	int vals[8] = {1,3,4,4,87,23,231,-1};
	pancake_sort(vals, 8);
	for(i = 0; i < 8; i++){
		printf("Index %d:\t%d\n", i, vals[i]);
	}
	return 0;
}
