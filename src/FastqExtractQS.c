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
  fprintf(stderr, "                                                        \n"
                  "Usage: %s < input > output                              \n"
                  "                                                        \n"
                  "Extract all the quality-scores from FASTQ reads.        \n"
                  "                                                        \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  uint32_t seqSize = 0, n;
  uint64_t totalReads = 0, totalQS = 0;

  if(argc < 2 || ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }
  
  while(GetRead(stdin, Read)){
    seqSize = strlen((char *) Read->scores) - 1;
    ++totalReads;
    for(n = 0 ; n < seqSize ; ++n){
      fprintf(stdout, "%c", Read->scores[n]);
      ++totalQS;
      }
    fprintf(stdout, "\n");
    }

  fprintf(stderr, "Total reads          : %"PRIu64"\n", totalReads);
  fprintf(stderr, "Total Quality-Scores : %"PRIu64"\n", totalQS);

  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


