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
  uint32_t n, k, i, pos = 0, lineSize;
  BUF *B;

  for(n = 1 ; n < argc ; ++n)
    if(strcmp(argv[n], "-h") == 0){
      argc = 0;
      }

  if(argc == 0 || argc > 5){
    fprintf(stderr, "Usage: %s -l <lineSize> -n <name> < in.seq > out.fa\n"
    "It converts a genomic sequence to pseudo FASTA file format.\n", argv[0]);
    return EXIT_SUCCESS;
    }
  
  lineSize = BREAKER;
  for(n = 1 ; n < argc ; ++n)
    if(strcmp(argv[n], "-l") == 0){
      lineSize = atoi(argv[n+1]);
      break;
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
      if(++pos == lineSize){
        putchar('\n');
        pos = 0;
        }
      }
  RemoveBuffer(B); 

  return EXIT_SUCCESS;
  }

