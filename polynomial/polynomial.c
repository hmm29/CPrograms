#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#include "hashmap.h"
#include "polynomial.h"

int parse_terms(int num_terms, char **argv, Term_ptr* terms){
  if(terms == NULL)
    return TERM_ERR;

  Term_ptr *remaining_terms = terms;
  Term_ptr new_term_ptr;

  for(int i = 1; i <= num_terms; i++){
    new_term_ptr = create_term(argv[i]);
    if(new_term_ptr == NULL) {
      return TERM_ERR;
    }
    *remaining_terms = new_term_ptr;
    remaining_terms++;
  }

  return TERM_OK;
}

Term_ptr create_term(const char *str){
  if(str == NULL)
    return NULL;

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
      return NULL;
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
    return NULL;
  }

  if(*tmp == '-') {
    sign = -1;
    tmp++;
  }

  if(!isdigit(*tmp)) {
    return NULL;
  }

  new_term_ptr->exponent = (long) ((long) atol(tmp)) * sign;

  return new_term_ptr;
}

void combine_terms(Term_ptr *terms, int num_terms, map_t my_map){
  int status;
  data_struct_t *value;
  Term_ptr curr_term_ptr;

  for(int i = 0; i < num_terms; i++){
    curr_term_ptr = terms[i];
    value = malloc(sizeof(data_struct_t));

    snprintf(value->key_string, KEY_MAX_LENGTH, "%c^%ld", curr_term_ptr->base, curr_term_ptr->exponent);
    value->number = curr_term_ptr->coefficient;
    status = hashmap_put(my_map, value->key_string, value);
    assert(status == MAP_OK);
  }
}

int print_term(const char *key, any_t value, bool is_first){
  if(key == NULL){
    return MAP_MISSING;
  }

  if(((data_struct_t *)value)->number >= 0 && !is_first){
    printf("+");
  }

  if(((data_struct_t *)value)->number != 1) {
    printf("%d%s", ((data_struct_t *)value)->number, key);
  } else {
    printf("%s", key);
  }

  return MAP_OK;
}

void terms_free(Term_ptr *terms, int num_terms) {
  for(int i = 0; i < num_terms; i++){
    free(terms[i]);
  }
}
