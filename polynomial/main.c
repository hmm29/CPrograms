#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"
#include "hashmap.h"

int main(int argc, char **argv){
  int status;
  int num_terms = argc-1;
  Term_ptr terms[num_terms];
  map_t my_map;

  if(argc < 2) {
    exit(EXIT_SUCCESS);
  }

  status = parse_terms(argc, argv, terms);
  if(status == TERM_ERR){
    DIE("Usage: %s <coefficient><base><exponent> [...]\n", argv[0]);
  }

  my_map = hashmap_new();
  combine_terms(terms, num_terms, my_map);
  hashmap_iterate(my_map, print_term, NULL);

  terms_free(terms, num_terms);
  hashmap_free(mymap);

  exit(EXIT_SUCCESS);
}
