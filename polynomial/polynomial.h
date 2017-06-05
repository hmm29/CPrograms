#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#define TERM_ERR -1  /* No term created */
#define TERM_OK 0 	/* Term successfully created */
#define DIE(msg) exit (fprintf (stderr, "%s\n", msg));  /* Print message to stderr and exit */
#define KEY_MAX_LENGTH (256)
#define VARIABLE_MAX_NUM (256)

typedef struct term {
  long coefficient;
  char base[VARIABLE_MAX_NUM];
  long exponent[VARIABLE_MAX_NUM];
  int num_variables;
} Term, *Term_ptr;

typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];
    int number;
} data_struct_t;

int parse_terms(int num_terms, char **argv, Term_ptr *terms);
Term_ptr create_term(const char *str);
void combine_terms(Term_ptr *terms, int num_terms, map_t my_map);
int print_term(const char *key, any_t value, bool is_first);
void terms_free(Term_ptr *terms, int num_terms);

#endif
