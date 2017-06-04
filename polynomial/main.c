#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "polynomial.h"
#include "hashmap.h"

int main(int argc, char **argv)
{
  int i;
  int error;
  int numTerms = argc-1;
  map_t mymap;
  char key_string[KEY_MAX_LENGTH];
  TermPtr terms[numTerms];
  TermPtr *nextTerm = terms;
  TermPtr currTermPtr;

  if(argc <= 1)
  {
    printf("Usage: %s, invalid number of arguments", argv[0]);
    exit(EXIT_FAILURE);
  }

  for(int i = 1; i < argc; i++)
  {
    createTerm(argv[i], nextTerm);
    nextTerm++;
  }

  mymap = hashmap_new();

  for(i = 0; i < numTerms; i++)
  {
    currTermPtr = terms[i];
    snprintf(key, KEY_MAX_LENGTH, "%c^%ld", currTermPtr->base, currTermPtr->exponent);
    error = hashmap_put(mymap, key_string, value);
    assert(error==MAP_OK);
  }

  hashmap_iterate(mymap, printTerm, NULL);
  destroyTerms(terms, numTerms);
  hashmap_free(mymap);
  exit(EXIT_SUCCESS);
}
