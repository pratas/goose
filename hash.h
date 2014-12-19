#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "defs.h"

typedef struct{
  uint32_t k;        // NUMBER OF HASHES 
  uint32_t *a;       // A SEED
  uint32_t *b;       // B SEED
  uint32_t p;        // PRIME
  }
HFAM;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

HFAM      *CreateHFamily (uint32_t, uint32_t);
void      DeleteHFamily  (HFAM *);
uint32_t  Hash           (HFAM *, uint64_t, uint32_t);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

