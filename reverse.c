#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"

int main(int argc, char *argv[]){
  FILE     *F;
  uint8_t  *seq;
  int c;
  uint64_t i, size;

  if(argc != 2){
    fprintf(stderr, "Usage: reverse file\n");
    return EXIT_SUCCESS;
    }

  F    = Fopen(argv[argc - 1], "r");
  size = FNBytes(F);
  seq  = (uint8_t *) Calloc(size, sizeof(uint8_t));

  i = 0;
  while((c = getc(F)) != EOF) seq[i++] = c;
  while(i) putchar(seq[--i]);

  Free(seq, size * sizeof(uint8_t));
  fclose(F);
  return EXIT_SUCCESS;
  }

