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
                  "Usage: %s [VALUE] < input > output                      \n"
                  "                                                        \n"
                  "Ignores FASTQ reads with size above the [value].        \n"
                  "If present, it will erase the second header (after +).  \n"
                  "                                                        \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  uint32_t seqSize = 0, n;
  uint64_t okReads = 0, totalReads = 0;

  if(argc < 2 || ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }
  
  int min_read_size = atoi(argv[1]);
 
  while(GetRead(stdin, Read)){

    seqSize = strlen((char *) Read->bases) - 1;
    ++totalReads;

    // EVALUATE TO DISCARD:
    if(seqSize > min_read_size) continue;

    // PRINT READ
    fprintf(stdout, "@");
    for(n = 0 ; n < strlen((char *) Read->header1) ; ++n)
      fprintf(stdout, "%c", Read->header1[n]);
    for(n = 0 ; n < seqSize ; ++n)
      fprintf(stdout, "%c", Read->bases[n]);
    fprintf(stdout, "\n+\n");
    for(n = 0 ; n < seqSize ; ++n)
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


