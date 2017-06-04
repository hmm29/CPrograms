
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#define TERM_ERR -1  /* No term created */
#define TERM_OK 0 	/* Term successfully created */

typedef struct term {
  long coefficient;
  char base;
  long exponent;
} Term, *Term_ptr;

int parse_terms(int argc, char **argv, Term_ptr *terms);
int createTerm(const char *str, Term_ptr term);
int combineTerms(Term_ptr *terms, int num_terms, map_t my_map)
int printTerm(const char *key, long value, bool is_first);
void destroyTerms(Term_ptr *terms, int num_terms);

#endif
