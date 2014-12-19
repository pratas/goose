#include <stdio.h>
#include <stdlib.h>
#include "alpha.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

ALPHA *CreateAlphabet(void){
  ALPHA *A    = (ALPHA *) Calloc(1, sizeof(ALPHA));
  A->symbolic = (char  *) Calloc(MAX_ALPHA, sizeof(char));
  A->numeric  = (char  *) Calloc(MAX_ALPHA, sizeof(char));
  A->mask     = (char  *) Calloc(MAX_ALPHA, sizeof(char));
  return A;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void DeleteAlphabet(ALPHA *A){
  Free(A->symbolic, MAX_ALPHA * sizeof(char));
  Free(A->numeric,  MAX_ALPHA * sizeof(char));
  Free(A->mask,     MAX_ALPHA * sizeof(char));
  Free(A, sizeof(char));
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

