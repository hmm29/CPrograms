#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "polynomial.h"
#include "hashmap.h"

#define KEY_COUNT (1024*1024)
#define KEY_MAX_LENGTH (256)

int createTerm(const char *str, TermPtr *terms)
{
  if(str == NULL || terms == NULL || !isdigit(*str))
    return TERM_ERR;

  TermPtr newTermPtr;
  int count = 0;
  const char *tmp = str;

  newTermPtr = (TermPtr) malloc(sizeof(Term));

  if(isalpha(*tmp))
  {
    newTermPtr->coefficient = 1;
  } else {
    while(isdigit(*tmp))
    {
      tmp++;
      count++;
    }

    char coeffStr[count+1];
    strncpy(coeffStr, str, count);
    coeffStr[count] = '\0';

    newTermPtr->coefficient = (long) atol(coeffStr);
  }

  newTermPtr->base = *tmp;
  tmp++;

  newTermPtr->exponent = (long) atol(tmp);

  *terms = newTermPtr;

  return TERM_OK;
}

int printTerm(const char *key, long value, bool isFirst)
{
  if(key == NULL)
  {
    return MAP_MISSING;
  }

  if(value >= 0 && !isFirst)
  {
    printf("+");
  }

  printf("%ld%s", value, key);
  return MAP_OK;
}

void destroyTerms(TermPtr *terms, int length)
{
  for(int i = 0; i < length; i++)
  {
    free(terms[i]);
  }
}
