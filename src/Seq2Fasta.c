#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "args.h"
#include "mem.h"
#include "buffer.h"

#define BREAKER 100

int main(int argc, char *argv[]){
  uint32_t n, k, i, pos = 0;
  BUF *B;

  if(argc == 0 || argc > 3){
    fprintf(stderr, "Usage: %s -n <name> < input.seq > output.fasta\nIt "
    "converts a genomic sequence to pseudo FASTA file format.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  for(n = 1 ; n < argc ; ++n)
    if(strcmp(argv[n], "-n") == 0){
      fprintf(stdout, ">%s\n", argv[n+1]);
      goto XPS;
      }
  fprintf(stdout, ">Computed_with_%s\n", argv[0]);
   
  XPS:
  B = CreateBuffer(BUF_SIZE);
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

