
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct term {
  long coefficient;
  char base;
  long exponent;
} Term, *TermPtr;

TermPtr* createTerm(const char *str, TermPtr *terms);
int printTerm(const char *key, long value, bool isFirst);
void destroyTerms(TermPtr *terms, int length);

#endif
