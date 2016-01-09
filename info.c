#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include "defs.h"
#include "mem.h"
#include "misc.h"

int main(int32_t argc, char *argv[]){
  FILE *IN  = NULL;
  uint32_t  n, k, idxPos, nSym;
  uint64_t  nBytes, *counts;
  uint8_t   *buf, *mask, *norm_alp, *alp, sym;

  if(argc < 2){
    fprintf(stderr, "Usage: %s [0|1] file\n", argv[0]);
    return EXIT_SUCCESS;
    }

  buf       = (uint8_t  *) Calloc(BUFFER_SIZE,  sizeof(uint8_t ));
  alp       = (uint8_t  *) Calloc(MAX_ALPHABET, sizeof(uint8_t ));
  norm_alp  = (uint8_t  *) Calloc(MAX_ALPHABET, sizeof(uint8_t ));
  mask      = (uint8_t  *) Calloc(MAX_ALPHABET, sizeof(uint8_t ));
  counts    = (uint64_t *) Calloc(MAX_ALPHABET, sizeof(uint64_t));
  nBytes    = 0;
  IN = Fopen(argv[argc-1], "rb");  

  while((k = fread(buf, 1, BUFFER_SIZE, IN)))
    for(idxPos = 0 ; idxPos != k ; ++idxPos){
      sym = *(buf+idxPos);
      mask[sym] = 1;
      ++counts[sym];
      ++nBytes;
      }

  nSym = 0;
  for(n = MAX_ALPHABET ; --n ; )
    if(mask[n] == 1){
      norm_alp[nSym] = n;
      alp[n] = nSym++;
      }
    else alp[n] = MAX_ALPHABET-1;
  fclose(IN);

  printf("Number of symbols: %"PRIu64"\n", nBytes);
  printf("Alphabet size: %u\n", nSym);
  printf("Alphabet:");
  for(n = 0 ; n != nSym ; ++n)
    norm_alp[n] == 10 ? printf("\\n") : printf("%c", norm_alp[n]);
  printf("\n");
  printf("Symbol distribution:\n");
  for(n = 0 ; n != nSym ; ++n)
    if(atoi(argv[argc-2]) == 0)
      norm_alp[n] == 10 ? printf("\\n : %"PRIu64"\n", counts[norm_alp[n]]) : 
      printf("%-2c : %"PRIu64"\n", norm_alp[n], counts[norm_alp[n]]);
    else
      printf("%-2d : %"PRIu64"\n", norm_alp[n], counts[norm_alp[n]]);

  Free(buf,      BUFFER_SIZE  * sizeof(uint8_t ));
  Free(alp,      MAX_ALPHABET * sizeof(uint8_t ));
  Free(norm_alp, MAX_ALPHABET * sizeof(uint8_t ));
  Free(mask,     MAX_ALPHABET * sizeof(uint8_t ));
  Free(counts,   MAX_ALPHABET * sizeof(uint64_t));
      
  return EXIT_SUCCESS;
  }

