#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"

#define BREAKER 100

int main(int argc, char *argv[]){
  uint32_t k, i, pos = 0;
  BUF *B;

  if(argc != 1){
    fprintf(stderr, "\nUsage: ./Seq2Fasta < input.seq > output.fasta      \n"
    "                                                                     \n"
    "Seq2Fasta converts a genomic sequence to pseudo FASTA file format.   \n");
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);
  fprintf(stdout, "> Computed with Seq2Fasta\n");
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      putchar(B->buf[i]);
      if(++pos == BREAKER){
        putchar('\n');
        pos = 0;
        }
      }

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

