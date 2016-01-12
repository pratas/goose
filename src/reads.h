#ifndef READS_H_INCLUDED
#define READS_H_INCLUDED

#include "defs.h"

#define DEF_HEADER_SIZE  512
#define DEF_READ_SIZE    1024
#define READ_LGUARD      32

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct{
  uint8_t    *header1;
  uint8_t    *bases;
  uint8_t    *header2;
  uint8_t    *scores;
  uint32_t   headerMaxSize;
  uint32_t   readMaxSize;
  uint32_t   solidData;
  uint32_t   header2Present;
  uint32_t   skipNs;
  uint8_t    lowestScore;
  }
Read;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint8_t  PseudoDna2Solid  (uint8_t);
uint8_t  Solid2PseudoDna  (uint8_t);
Read     *CreateRead      (uint32_t, uint32_t);
void     FreeRead         (Read *);
Read     *GetRead         (FILE *, Read *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif
