#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include "defs.h"
#include "misc.h"

#define UNDEF_BASE 1

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int GetBase(void){
  int  base;
  char *alphabet = "ACGT";
  while((base = fgetc(stdin)) != EOF){
    if(base == '>'){
      while((base = fgetc(stdin)) != EOF && base != '\n')
        ;
      continue;
      }
    if(base == '\n') 
      continue;
    if(!(strchr(alphabet, toupper(base)))) 
      return UNDEF_BASE;
    else 
      return !UNDEF_BASE;
    }
  return EOF;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){
  uint64_t start, nBases;
  int undefSegment = 0, base;

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.fasta > output.seq\n"
    "It reports the 'N' regions in a sequence or FASTA (seq) file.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  nBases = 1;
  while((base = GetBase()) != EOF){
    if(base == UNDEF_BASE){
      if(!undefSegment){
        undefSegment = 1;
        start = nBases;
        }
      }
    else{
      if(undefSegment){
        undefSegment = 0;
        fprintf(stdout, "%"PRIu64"\t%"PRIu64"\t%"PRIu64"\n", start, nBases-1, 
        nBases-start);
        }
      }
    nBases++;
    }
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
