#ifndef XSMISC_H_INCLUDED
#define XSMISC_H_INCLUDED

#include "xsdefs.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct
  {
  uint32_t      number;                                   // Number of repeats
  uint32_t      minSize;                                // Minimum repeat size
  uint32_t      maxSize;                                // Maximum repeat size
  double        mutation;                        // Average mutation by repeat
  uint8_t       rcr;                      // Reverse complement repeats on|off
  }
Repeats;

typedef struct
  {
  int32_t       size;
  int32_t       *position;
  int32_t       deepestPosition;
  }
T;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint32_t        complement(uint32_t base);
double          gaussRand(double mean, double sDev);
char            numbToChar(uint32_t n, uint32_t type);
void            sortIntVect(uint32_t vector[], uint32_t size);
uint32_t        toABISOLID(uint32_t previous, uint32_t current);
void            IncreaseTemplateStorage(T *t, int additionalSize);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

