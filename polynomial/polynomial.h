
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#define TERM_ERR -1  /* No term created */
#define TERM_OK 0 	/* Term successfully created */

typedef struct term {
  long coefficient;
  char base;
  long exponent;
} Term, *TermPtr;

int createTerm(const char *str, TermPtr *terms);
int printTerm(const char *key, long value, bool isFirst);
void destroyTerms(TermPtr *terms, int length);

#endif
