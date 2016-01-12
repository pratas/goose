#ifndef ARGS_H_INCLUDED
#define ARGS_H_INCLUDED

#include "defs.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint32_t ArgNum    (uint32_t, char *[], uint32_t, char *, uint32_t, uint32_t);
double   ArgDbl    (double,   char *[], uint32_t, char *);
uint8_t  ArgBin    (uint8_t,  char *[], uint32_t, char *);
int32_t  StrToArgv (char *,   char ***);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

