#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"
#include "hashmap.h"

int main(int argc, char **argv)
{
  int num_terms = argc-1;
  Term_ptr terms[num_terms];
  map_t my_map;

  if(argc < 2) {
    exit(EXIT_SUCCESS);
  }

  parse_terms(argc, argv, terms);
  my_map = hashmap_new();
  combine_terms(terms, num_terms, mymap);
  hashmap_iterate(mymap, print_term, NULL);

  terms_free(terms, num_terms);
  hashmap_free(mymap);

  exit(EXIT_SUCCESS);
}
