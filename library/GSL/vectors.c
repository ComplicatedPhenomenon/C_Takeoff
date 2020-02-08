/**
 * gcc vectors.c  -lgsl -lgslcblas -lm
 **/
#include <stdio.h>
#include <gsl/gsl_block.h>
#include <gsl/gsl_rng.h>

gsl_rng * r;  /* global generator */

int main (void) {
    gsl_block * b = gsl_block_alloc (100);

    printf ("length of block = %zu\n", b->size);
    printf ("block data address = %p\n", b->data);
    gsl_block_free (b);

    const gsl_rng_type * T;
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);
    printf ("generator type: %s\n", gsl_rng_name (r));
    printf ("seed = %lu\n", gsl_rng_default_seed);
    printf ("first value = %lu\n", gsl_rng_get (r));
    gsl_rng_free (r);
    return 0;
}