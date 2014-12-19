#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

HFAM *CreateHFamily(uint32_t k, uint32_t p){
  int n;
  srand(0);
  HFAM *H = (HFAM *) Calloc(1, sizeof(HFAM));
  H->k = k;
  H->a = (uint32_t *)  Calloc(k, sizeof(uint32_t));
  H->b = (uint32_t *)  Calloc(k, sizeof(uint32_t));
  for(n = 0 ; n < k ; ++n){
    H->a[n] = rand() % UINT32_MAX;
    H->b[n] = rand() % UINT32_MAX;
    }
  H->p = p;
  return H;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void DeleteHFamily(HFAM *H){
  Free(H->a, H->k * sizeof(uint32_t));
  Free(H->b, H->k * sizeof(uint32_t));
  Free(H, sizeof(HFAM));
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint32_t Hash(HFAM *H, uint64_t i, uint32_t n){
  return (H->a[n] * i + H->b[n]) % H->p;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

