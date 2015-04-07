#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"

int main(int argc, char *argv[]){
  uint32_t k, i;
  uint8_t  s, header = 1;
  BUF *B;

  if(argc != 1){
    fprintf(stderr, "\nUsage: ./Fasta2Seq < input.fasta > output.seq      \n"
    "                                                                     \n"
    "Fasta2Seq converts a FASTA or Multi-FASTA file format to a sequence. \n");
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      if(s == '>'){ header = 1; continue; }
      if(s == '\n' && header == 1){ header = 0; continue; }
      if(s == '\n') continue;
      if(header == 1) continue;
      if(s < 65 || s > 122) continue;
      putchar(s);
      }

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

