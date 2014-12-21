#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

HASH *CreateHash(uint64_t s, uint64_t c){
  HASH *H     = (HASH *) Calloc(1, sizeof(HASH));
  H->seed     = s;
  H->cardinal = c;
  return H;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void DeleteHash(HASH *H){
  Free(H, sizeof(HASH));
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint64_t Hash(HASH *H){
  return (H->p1 * H->seed + H->p2) % H->cardinal;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

