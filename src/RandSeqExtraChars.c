#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"

static void RandIfExtra(uint8_t s, char *b){
  if(s == 'A' || s == 'C' || s == 'G' || s == 'T'){
    putchar(s);
    return;
    }
  putchar(b[rand()%4]);
  }

int main(int argc, char *argv[]){
  uint32_t k, i, seed = 0;
  uint8_t  s;
  char     *bases = "ACGT";
  BUF *B;
  srand(seed);
  

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.seq > output.seq\nIt substitues in the "
    "DNA sequence the outside ACGT chars\nby random ACGT symbols.\nIt works in "
    "Sequence domain.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      RandIfExtra(s, bases);
      } 

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

