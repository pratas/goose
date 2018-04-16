#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "reads.h"
#include "args.h"

void PrintArgs(char *name){
  fprintf(stderr, "                                                   \n"
                  "Usage: %s [max] < input > output                   \n"
                  "                                                   \n"
                  "It analyses the maximal scores of a FASTQ file.    \n"
                  "max stands for the lenght of the maximum window.   \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  int32_t  seqSize = 0, x;
  uint64_t *QS = (uint64_t *) Calloc(65536, sizeof(uint64_t));
  
  if(ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }

  while(GetRead(stdin, Read)){
    seqSize = strlen((char *) Read->bases) - 1;
    for(x = 0 ; x < seqSize ; ++x){
      int tmp_QS = (int) Read->scores[x];
      if(QS[x] < tmp_QS)
      QS[x] = tmp_QS;
      if(x == 65535){
        fprintf(stderr, "Error: read to long. Increase buffer!\n");
        exit(1);
        }
      }
    }

  int maxs = atoi(argv[argc-1]);

  for(x = 0 ; x < maxs ; ++x)
    fprintf(stdout, "%2d ", x+1);
  fprintf(stdout, "\n");
  for(x = 0 ; x < maxs ; ++x)
    fprintf(stdout, "--+");
  fprintf(stdout, "\n");
  for(x = 0 ; x < maxs ; ++x)
    fprintf(stdout, "%2d ", (int) QS[x]);
  fprintf(stdout, "\n");

  Free(QS, 0);
  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


