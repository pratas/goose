#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "defs.h"

typedef struct{
  uint64_t hash;     // CURRENT HASH
  uint64_t seed;     // CURRENT SEED
  uint64_t cardinal; // CARDINALITY OF THE ELEMENTS
  uint64_t p1;       // PRIME 1
  uint64_t p2;       // PRIME 2
  }
HASH;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

HASH      *CreateHash (uint64_t, uint64_t);
void      DeleteHash  (HASH *);
uint64_t  Hash        (HASH *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

