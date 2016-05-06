#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

int main(int argc, char *argv[]){
  uint32_t k, i;
  uint32_t idxHeader = 0;
  uint64_t idxSymbol = 0;
  uint8_t  s;
  BUF *B;

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.mfasta\n"
    "It splits a Multi-FASTA file to multiple FASTA files.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  idxHeader = 0;
  FILE *OUT = NULL;
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      if(++idxSymbol == 1 && s == '\n')
        continue;
      if(s == '>'){
        if(++idxHeader > 1) 
          fclose(OUT);
        char name[500];
        sprintf(name, "out%u.fa", idxHeader);
        fprintf(stderr, "%u : Splitting to file:%s\n", idxHeader, name);
        OUT = Fopen(name, "w");
        }
      fprintf(OUT, "%c", s);
      }
  if(!OUT) fclose(OUT);

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

