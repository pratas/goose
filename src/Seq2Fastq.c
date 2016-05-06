#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

#define BREAKER 100

int main(int argc, char *argv[]){
  uint32_t k, i, pos = 0;
  uint64_t idx = 1;
  uint8_t *scores = (uint8_t *) Calloc(BREAKER+1, sizeof(uint8_t));
  BUF *B;

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.seq > output.fastq\nIt converts a "
    "genomic sequence to pseudo FASTQ file format.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  for(i = 0 ; i < BREAKER ; ++i)
    scores[i] = 'F';
  scores[i] = '\0';

  B = CreateBuffer(BUF_SIZE);

  fprintf(stdout, "@Header1\n");
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      putchar(B->buf[i]);
      if(++pos == BREAKER){
        fprintf(stdout, "\n+\n%s\n@Header%"PRIu64"\n", scores, idx);
        pos = 0;
        ++idx;
        }
      }
  fprintf(stdout, "\n+\n%s\n", scores);

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

