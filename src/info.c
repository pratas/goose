#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "defs.h"
#include "mem.h"
#include "misc.h"
#include "args.h"

int main(int32_t argc, char *argv[]){
  uint32_t  n, k, idxPos, nSym;
  uint64_t  nBytes, *counts;
  uint8_t   *buf, *mask, *norm_alp, *alp, sym;

  for(n = 1 ; n < argc ; ++n)
    if(strcmp(argv[n], "-h") == 0){
      argc = 0;
      }

  if(argc < 1 || argc > 2){
    fprintf(stderr, "Usage: %s [0|1] < file\n", argv[0]);
    return EXIT_SUCCESS;
    }

  buf       = (uint8_t  *) Calloc(BUFFER_SIZE,  sizeof(uint8_t ));
  alp       = (uint8_t  *) Calloc(MAX_ALPHABET, sizeof(uint8_t ));
  norm_alp  = (uint8_t  *) Calloc(MAX_ALPHABET, sizeof(uint8_t ));
  mask      = (uint8_t  *) Calloc(MAX_ALPHABET, sizeof(uint8_t ));
  counts    = (uint64_t *) Calloc(MAX_ALPHABET, sizeof(uint64_t));
  nBytes    = 0;

  while((k = fread(buf, 1, BUFFER_SIZE, stdin)))
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

  printf("Number of symbols: %"PRIu64"\n", nBytes);
  printf("Alphabet size: %u\n", nSym);
  printf("Alphabet:");
  for(n = 0 ; n != nSym ; ++n)
    norm_alp[n] == 10 ? printf("\\n") : printf("%c", norm_alp[n]);
  printf("\n");
  printf("Symbol distribution:\n");
  for(n = 0 ; n < nSym ; ++n)
    if(atoi(argv[argc-1]) == 0)
      norm_alp[n] == 10 ? printf("\\n : %"PRIu64"\t%.8g\n", counts[norm_alp[n]], (double) counts[norm_alp[n]]/nBytes*100) : 
      printf("%-2c : %"PRIu64"\t%.8g\n", norm_alp[n], counts[norm_alp[n]], (double) counts[norm_alp[n]]/nBytes*100);
    else
      printf("%-2d : %"PRIu64"\t%.8g\n", norm_alp[n], counts[norm_alp[n]], (double) counts[norm_alp[n]]/nBytes*100);

  Free(buf,      BUFFER_SIZE  * sizeof(uint8_t ));
  Free(alp,      MAX_ALPHABET * sizeof(uint8_t ));
  Free(norm_alp, MAX_ALPHABET * sizeof(uint8_t ));
  Free(mask,     MAX_ALPHABET * sizeof(uint8_t ));
  Free(counts,   MAX_ALPHABET * sizeof(uint64_t));
      
  return EXIT_SUCCESS;
  }

