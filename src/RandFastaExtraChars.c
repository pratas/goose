#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

static void RandIfExtra(uint8_t s, char *b){
  if(s == 'A' || s == 'C' || s == 'G' || s == 'T'){
    putchar(s);
    return;
    }
  putchar(b[rand()%4]);
  }

int main(int argc, char *argv[]){
  uint32_t k, i, seed = 0;
  uint8_t  s, line = 0, pos = 1;
  char     *bases = "ACGT";
  BUF *B;
  srand(seed);
  

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.fasta > output.fasta\nIt substitues in "
    "the DNA sequence the outside ACGT chars by random ACGT symbols.\nIt works "
    "both in FASTA and Multi-FASTA file formats\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      switch(line){
        case 0: 
          if(pos == 0 && s != '>'){
            RandIfExtra(s, bases);
            line = 1;
            break;
            }
          if(s == '\n'){ 
            line = 1;
            putchar(s);
            break;
            }
          if(pos++ == 0 && s == '>'){
            putchar(s);
            break;
            }
          putchar(s);
        break;
        case 1: 
          if(s == '\n'){ 
            line   = 0; 
            pos    = 0;
            putchar(s);
            break; 
            }
          RandIfExtra(s, bases);
        break;
        } 
      }

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

