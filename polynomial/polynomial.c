#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#include "hashmap.h"
#include "polynomial.h"

#define KEY_MAX_LENGTH (256)

int parse_terms(int argc, char **argv, Term_ptr* terms){
  if(terms == NULL)
    return TERM_ERR;

  int status;
  Term_ptr *remaining_terms = terms;

  for(int i = 1; i < argc; i++){
    status = create_term(argv[i], *remaining_terms);
    assert(status == TERM_OK);
    remaining_terms++;
  }

  return TERM_OK;
}

int create_term(const char *str, Term_ptr term){
  if(str == NULL || term == NULL)
    return TERM_ERR;

  int count = 0;
  int sign = 1;
  const char *tmp = str;
  Term_ptr new_term_ptr;

  new_term_ptr = (Term_ptr) malloc(sizeof(Term));

  if(isalpha(*tmp)){
    new_term_ptr->coefficient = 1;
  } else {
    if(*tmp == '-') {
      sign = -1;
      tmp++;
    }

    if(!isdigit(*tmp)) {
      return TERM_ERR;
    }

    while(isdigit(*tmp)){
      count++;
      tmp++;
    }

    char coeff_str[count+1];
    strncpy(coeff_str, str, count);
    coeff_str[count] = '\0';

    new_term_ptr->coefficient = (long) ((long) atol(coeff_str)) * sign;
    sign = 1;
  }

  if(isalpha(*tmp)) {
    new_term_ptr->base = *(tmp++);
  } else {
    return TERM_ERR;
  }

  if(*tmp == '-') {
    sign = -1;
    tmp++;
  }

  if(!isdigit(*tmp)) {
    return TERM_ERR;
  }

  new_term_ptr->exponent = (long) ((long) atol(tmp)) * sign;
  term = new_term_ptr;

  return TERM_OK;
}

int combine_terms(Term_ptr *terms, int num_terms, map_t my_map){
  int status;
  long value;
  char key_string[KEY_MAX_LENGTH];
  Term_ptr curr_term_ptr;

  for(int i = 0; i < num_terms; i++){
    curr_term_ptr = terms[i];
    snprintf(key_string, KEY_MAX_LENGTH, "%c^%ld", curr_term_ptr->base, curr_term_ptr->exponent);
    status = hashmap_put(my_map, key_string, (long *) &value);
    assert(status == MAP_OK);
  }

  return TERM_OK;
}

int print_term(const char *key, long value, bool is_first){
  if(key == NULL){
    return MAP_MISSING;
  }

  if(value >= 0 && !is_first){
    printf("+");
  }

  printf("%ld%s", value, key);
  return MAP_OK;
}

void terms_free(Term_ptr *terms, int num_terms) {
  for(int i = 0; i < num_terms; i++){
    free(terms[i]);
  }
}
