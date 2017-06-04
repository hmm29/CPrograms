#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "polynomial.h"
#include "hashmap.h"

#define KEY_COUNT (1024*1024)
#define KEY_MAX_LENGTH (256)

int parse_terms(int argc, char **argv, Term_ptr* terms)
{
  if(terms == NULL)
    return TERM_ERR;

  Term_ptr *remaining_terms = terms;

  for(int i = 1; i < argc; i++)
  {
    error = create_term(argv[i], *remaining_terms);
    assert(error==TERM_OK);
    remaining_terms++;
  }

  return TERM_OK;
}

int create_term(const char *str, Term_ptr term)
{
  if(str == NULL || term == NULL || !isdigit(*str))
    return TERM_ERR;

  Term_ptr new_term_ptr;
  int count = 0;
  const char *tmp = str;

  new_term_ptr = (Term_ptr) malloc(sizeof(Term));

  if(isalpha(*tmp))
  {
    new_term_ptr->coefficient = 1;
  } else {
    while(isdigit(*tmp))
    {
      tmp++;
      count++;
    }

    char coeffStr[count+1];
    strncpy(coeffStr, str, count);
    coeffStr[count] = '\0';

    new_term_ptr->coefficient = (long) atol(coeffStr);
  }

  new_term_ptr->base = *tmp;
  tmp++;

  new_term_ptr->exponent = (long) atol(tmp);

  term = new_term_ptr;

  return TERM_OK;
}

int combine_terms(Term_ptr *terms, int num_terms, map_t mymap)
{
  int error;
  long value;
  char key_string[KEY_MAX_LENGTH];
  Term_ptr curr_term_ptr;

  for(int i = 0; i < num_terms; i++)
  {
    curr_term_ptr = terms[i];
    snprintf(key, KEY_MAX_LENGTH, "%c^%ld", curr_term_ptr->base, curr_term_ptr->exponent);
    error = hashmap_put(mymap, key_string, (long *) &value);
    assert(error==MAP_OK);
  }

  return TERM_SUCC;
}

int print_term(const char *key, long value, bool is_first)
{
  if(key == NULL)
  {
    return MAP_MISSING;
  }

  if(value >= 0 && !is_first)
  {
    printf("+");
  }

  printf("%ld%s", value, key);
  return MAP_OK;
}

void terms_free(Term_ptr *terms, int length)
{
  for(int i = 0; i < length; i++)
  {
    free(terms[i]);
  }
}
