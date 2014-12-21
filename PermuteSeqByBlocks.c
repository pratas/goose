#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include "defs.h"
#include "misc.h"
#include "args.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct{
  uint8_t  *buf;
  uint64_t size;
  }
Seq;

typedef struct{
  int      idx;
  uint64_t x;
  }
Pair;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int Compare(const Pair *a, const Pair *b){
  return a->x>b->x;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void ReadSeq(Seq *seq){
  int c;
  uint64_t size = BUF_SIZE;
  seq->buf  = (uint8_t *) Calloc(BUF_SIZE, sizeof(uint8_t));
  seq->size = 0;
  while((c = getc(stdin)) != EOF){
    if(c == '>'){
      while((c = fgetc(stdin)) != EOF && c != '\n')
        ;
      continue;
      }
    if(c == '\n')
      continue;

    if(seq->size == size)
      seq->buf = (uint8_t *) Realloc(seq->buf, (size += BUF_SIZE) * 
      sizeof(uint8_t), BUF_SIZE * sizeof(uint8_t));

    seq->buf[seq->size++] = c;
    }
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){
  int n, k, bSize, nBlocks;
  uint32_t seed;
  char **p = *&argv;
  Pair *pair;
  Seq  *seq = (Seq *) Calloc(1, sizeof(Seq));

  if(ArgBin(0, argv, argc, "-h")){
    fprintf(stderr, "Usage: PermuteSeqByBlocs [ -bs <bSize> (def 100) ]\n"
    "                         [ -s  <seed> ]                           \n"
    "                                                                  \n"
    "PermuteSeqByBlocs -bs 100 -s 7 < input.fasta > output.fasta       \n"
    "It works on Seq, FASTA and Multi-FASTA file formats               \n");
    return EXIT_SUCCESS;
    }

  bSize = ArgNum(100, p, argc, "-bs",  1, UINT_MAX);
  seed  = ArgNum(0,   p, argc, "-s",   0, UINT_MAX);
  srand(seed);

  ReadSeq(seq);
  nBlocks = (seq->size - 1) / bSize + 1;

  pair = (Pair *) Calloc(nBlocks, sizeof(Pair));
  for(n = 0 ; n < nBlocks ; ++n){
    pair[n].idx = n;
    pair[n].x   = rand();
    }

  qsort(pair, nBlocks, sizeof(Pair), (int (*) (const void *, const void *)) 
  Compare);

  for(n = 0 ; n < nBlocks ; ++n)
    for(k = 0 ; k < bSize ; ++k)
      if(bSize * pair[n].idx + k < seq->size)
        putchar(seq->buf[bSize * pair[n].idx + k]);

  Free(seq->buf, seq->size * sizeof(uint8_t));
  Free(seq, sizeof(Seq));
  Free(pair, nBlocks * sizeof(Pair));
  return EXIT_SUCCESS;
  }

