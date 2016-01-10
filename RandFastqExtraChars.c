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
  uint8_t  s, line = 0;
  char     *bases = "ACGT";
  BUF *B;
  srand(seed);

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.fastq > output.fastq\nIt substitues in "
    "the DNA sequence the outside ACGT chars by random ACGT symbols.\n", 
    argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      switch(line){
        case 0:
          putchar(s);
          if(s == '\n') line = 1;
        break;

        case 1: 
          if(s == '\n'){
            putchar('\n');
            line = 2;
            break;
            }
          RandIfExtra(s, bases);
        break;

        case 2:
          putchar(s); 
          if(s == '\n') line = 3; 
        break;
        
        case 3: 
          putchar(s);
          if(s == '\n') line = 0; 
        break;
        } 
      }

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

