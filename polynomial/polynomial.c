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
    if(new_term_ptr == NULL){
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
  int base_idx = 0;
  int exponent_idx = 0;
  const char *tmp, *tmp2;
  Term_ptr new_term_ptr;

  new_term_ptr = (Term_ptr) malloc(sizeof(Term));

  if(*str == '-'){
    sign = -1;
    str++;
  }

  tmp = str;

  while(isdigit(*tmp)){
    count++;
    tmp++;
  };

  if(count == 0) {
    new_term_ptr->coefficient = 1 * sign;
  } else {
    char coeff_str[count+1];
    strncpy(coeff_str, str, count);
    coeff_str[count] = '\0';

    // printf("my coefficient string is %s\n", coeff_str);
    new_term_ptr->coefficient = (long) ((long) atol(coeff_str)) * sign;
    // printf("my coefficient is %ld\n", new_term_ptr->coefficient);
  }

  // Reset the sign
  sign = 1;

  new_term_ptr->base[base_idx++] = *(tmp++);
  // printf("the char after my base is %c\n", *(tmp-1));

  while(strlen(tmp) > 0) {
    while(*tmp != 0 && !isdigit(*(tmp+1))) {
      new_term_ptr->base[base_idx++] = *tmp;
      new_term_ptr->exponent[exponent_idx++] = 1;
      tmp++;
    }

    // printf("tmp is now %c after the line 72 while loop\n", *tmp);

    if(strlen(tmp) == 0) {
      new_term_ptr->num_variables = base_idx;
      break;
    }

    if(isalpha(*tmp)) {
      return NULL;
    }

    if(*tmp == '-' && sign > 0) {
      // printf("I encountered a negative sign\n");
      sign = -1;
      tmp++;
    }

    count = 0;
    tmp2 = tmp;

    while(isdigit(*tmp2)){
      count++;
      tmp2++;
    }

    char exponent_str[count+1];
    strncpy(exponent_str, tmp, count);
    exponent_str[count] = '\0';

    // printf("my sign is %i\n", sign);
    new_term_ptr->exponent[exponent_idx++] = (long) ((long) atol(exponent_str)) * sign;
    // printf("my exponent is %ld\n", new_term_ptr->exponent[exponent_idx-1]);

    sign = 1;
    tmp = tmp2;
  }

  if(base_idx != exponent_idx) {
    return NULL;
  }

  new_term_ptr->num_variables = base_idx;

  return new_term_ptr;
}

void combine_terms(Term_ptr *terms, int num_terms, map_t my_map){
  int idx, status;
  char key[KEY_MAX_LENGTH], exponent_str[KEY_MAX_LENGTH], c[2];
  data_struct_t *value;
  Term_ptr curr_term_ptr;

  for(int i = 0; i < num_terms; i++){
    curr_term_ptr = terms[i];
    value = malloc(sizeof(data_struct_t));

    // Copy over first base and exponent before using strcat
    c[0] = curr_term_ptr->base[0];
    c[1] = 0;

    strcpy(key, c);
    strcat(key, "^");
    if(curr_term_ptr->exponent[0] < 0) {
      sprintf(exponent_str, "(%ld)", curr_term_ptr->exponent[0]);
    } else {
      sprintf(exponent_str, "%ld", curr_term_ptr->exponent[0]);
    }
    strcat(key, exponent_str);

    // Copy over remaining bases and exponents
    for(idx = 1; idx < curr_term_ptr->num_variables; idx++) {
      c[0] = curr_term_ptr->base[idx];
      c[1] = 0;

      strcat(key, c);
      strcat(key, "^");
      if(curr_term_ptr->exponent[idx] < 0) {
        sprintf(exponent_str, "(%ld)", curr_term_ptr->exponent[idx]);
      } else {
        sprintf(exponent_str, "%ld", curr_term_ptr->exponent[idx]);
      }
      strcat(key, exponent_str);
    }

    strcpy(value->key_string, key);
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
