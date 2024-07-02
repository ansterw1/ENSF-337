/*
 * lab3exe_B.c
 * Implementation file for complex number module
 *
 * ENSF 337 - Lab 3 Exercise B
 */

#include "lab3exe_B.h"

void
cplx_add(struct cplx *z1, struct cplx *z2, struct cplx *result)
{

  result->real = z1->real + z2->real;
  result->imag = z1->imag + z2->imag;
}

void
cplx_subtract(struct cplx *z1, struct cplx *z2,  struct cplx *difference)
{
	difference->real = z1->real - z2->real;
	difference->imag = z1->imag - z2->imag;
}

void
cplx_multiply(const struct cplx *pz1,
              const struct cplx *pz2, 
              struct cplx *product)
{
	product->real = pz1->real * pz2->real - pz1->imag * pz2->imag;
	product->imag = pz1->real * pz2->imag + pz1->imag * pz2->real;
	
}
				  