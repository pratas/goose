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
                  "Usage: %s < input > output                         \n"
                  "                                                   \n"
                  "It analyses a FASTQ file for basic informations.   \n"
                  "                                                   \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  int32_t seqSize = 0, x;
  uint64_t totalReads = 0, minSeq = 65535, maxSeq = 0;
  int minQS = 255, maxQS = 0, tmp_QS;

  if(ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }

  while(GetRead(stdin, Read)){

    seqSize = strlen((char *) Read->bases) - 1;

    if(seqSize < minSeq)
      minSeq = seqSize;

    if(seqSize > maxSeq)
      maxSeq = seqSize;

    for(x = 0 ; x < seqSize ; ++x){
      tmp_QS = (int) Read->scores[x];

      if(tmp_QS < minQS)
        minQS = tmp_QS;

      if(tmp_QS > maxQS)
        maxQS = tmp_QS;
      }

    ++totalReads;
    }

  fprintf(stderr, "Total reads     : %"PRIu64"\n", totalReads);
  fprintf(stderr, "Max read length : %"PRIu64"\n", maxSeq);
  fprintf(stderr, "Min read length : %"PRIu64"\n", minSeq);
  fprintf(stderr, "Min QS value    : %d\n", minQS);
  fprintf(stderr, "Max QS value    : %d\n", maxQS);
  fprintf(stderr, "QS range        : %d\n", maxQS-minQS + 1);

  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


