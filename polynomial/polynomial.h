#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#define TERM_ERR -1  /* No term created */
#define TERM_OK 0 	/* Term successfully created */
#define DIE(msg) exit (fprintf (stderr, "%s\n", msg));  /* Print message to stderr and exit */

typedef struct term {
  long coefficient;
  char base;
  long exponent;
} Term, *Term_ptr;

int parse_terms(int argc, char **argv, Term_ptr *terms);
int create_term(const char *str, Term_ptr term);
int combine_terms(Term_ptr *terms, int num_terms, map_t my_map)
int print_term(const char *key, long value, bool is_first);
void terms_free(Term_ptr *terms, int num_terms);

#endif
