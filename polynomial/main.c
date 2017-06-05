#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hashmap.h"
#include "polynomial.h"

int main(int argc, char **argv){
  int status;
  int num_terms = argc-1;
  Term_ptr terms[num_terms];
  map_t my_map;

  if(argc < 2) {
    exit(EXIT_SUCCESS);
  }

  status = parse_terms(num_terms, argv, terms);
  if(status == TERM_ERR){
    DIE("Usage: ./polynomial <coefficient><base><exponent> [...]\n");
  }
  my_map = hashmap_new();

  combine_terms(terms, num_terms, my_map);
  hashmap_sort(my_map);
  hashmap_iterate(my_map, print_term);

  terms_free(terms, num_terms);
  hashmap_free(my_map);

  exit(EXIT_SUCCESS);
}
