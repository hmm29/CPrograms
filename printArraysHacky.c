#include <stdio.h>

int main()
{
  int i;

  char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
  int int_array[5] = {1, 2, 3, 4, 5};

  unsigned long int hacky_nonptr;

  hacky_nonptr = (unsigned long int) char_array;

  for(i = 0; i < 5; i++)
  {
    printf("[char ptr] points to %p, which contains the char %c\n",
      (void *) hacky_nonptr, *((char *) hacky_nonptr));
    hacky_nonptr = hacky_nonptr + sizeof(char);
  }

  hacky_nonptr = (unsigned long int) int_array;

  for(i = 0; i < 5; i++)
  {
    printf("[int ptr] points to %p, which contains the int %d\n", (void *) hacky_nonptr, *((int *) hacky_nonptr));
    hacky_nonptr = hacky_nonptr + sizeof(int);
  }

  return 0;
}
