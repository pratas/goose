#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "reads.h"
#include "args.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PrintArgs(char *name){
  fprintf(stderr, "Usage: %s [NUMBER] < input > output                     \n"
                  "                                                        \n"
                  "Discard reads below the minimum number of \"N\" symbols.\n"
                  "                                                        \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  uint32_t seqSize = 0, N = 0, x, n;
  uint64_t okReads = 0, totalReads = 0;

  if(argc < 2 || ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }
  
  int max_n = atoi(argv[1]);
 
  // LOAD PARAMETERS
  while(GetRead(stdin, Read)){
    seqSize = strlen((char *) Read->bases) - 1;
    N = 0;
    for(x = 0 ; x < seqSize ; ++x){
      if(Read->bases[x] == 'N'){
        ++N;
        }
      }
    ++totalReads;

    // EVALUATE TO DISCARD:
    if(N > max_n) continue;

    // PRINT READ
    for(n = 0 ; n < strlen((char *) Read->header1) ; ++n)
      fprintf(stdout, "%c", Read->header1[n]);
    for(n = 0 ; n < x ; ++n)
      fprintf(stdout, "%c", Read->bases[n]);
    fprintf(stdout, "\n+\n");
    for(n = 0 ; n < x ; ++n)
      fprintf(stdout, "%c", Read->scores[n]);
    fprintf(stdout, "\n");

    ++okReads;
    }

  fprintf(stderr, "Total reads    : %"PRIu64"\n", totalReads);
  fprintf(stderr, "Filtered reads : %"PRIu64"\n", totalReads-okReads);

  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


