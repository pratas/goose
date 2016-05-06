#ifndef ALPHA_H_INCLUDED
#define ALPHA_H_INCLUDED

#include "defs.h"
#include "misc.h"
#include "buffer.h"

#define MAX_ALPHA ((1<<(sizeof(char)*8))-1)

typedef struct{
  char *symbolic;
  char *numeric;
  char *mask;
  int  nSym;
  }
ALPHA;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

ALPHA   *CreateAlphabet  (void);
void    LoadAlphabet     (ALPHA *, BUF *);
void    DeleteAlphabet   (ALPHA *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

