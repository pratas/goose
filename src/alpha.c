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

void LoadAlphabet(ALPHA *A, BUF *B){
  int i, k;
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      A->mask[B->buf[i]] = 1;
      } 

  A->nSym = 0;
  for(k = 0 ; k < MAX_ALPHA ; ++k){
    if(A->mask[k] == 1){ 
      A->symbolic[A->nSym] = k;
      A->numeric[k] = A->nSym++;
      }
    }
  rewind(stdin);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void DeleteAlphabet(ALPHA *A){
  Free(A->symbolic, MAX_ALPHA * sizeof(char));
  Free(A->numeric,  MAX_ALPHA * sizeof(char));
  Free(A->mask,     MAX_ALPHA * sizeof(char));
  Free(A, sizeof(char));
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

