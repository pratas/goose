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
  
  // SE - SINGLE ENDED FASTQ
  // PE - PAIRED ENDED FASTQ : FORWARD READ vs REVERSE READ
  // 
  // PAIRED ENDED FILE -> INVERT FOR
  // 
  // REMOVE ADAPTORS

  // kmer QS
  // Ns
  // min_size

  fprintf(stderr, "Usage: %s [OPTIONS] < input > output             \n"
                  "                                                 \n"
                  "                                                 \n"
                  "                                                 \n"
                  "                                                 \n"
                  "                                                 \n"
                  "                                                 \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  uint32_t seqSize = 0, totalQS = 0, N = 0, x, n;
  uint64_t okReads = 0, totalReads = 0;

  if(argc > 3 || ArgBin(0, argv, argc, "-h")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }
  
  int max_n         = 0;
  int k             = 5;
  int min_avg_qs    = 25;
  int min_QS_window = 25;
  int min_read_size = 35;
 
  // LOAD PARAMETERS
 
  while(GetRead(stdin, Read)){

    seqSize = strlen((char *) Read->bases) - 1;
    totalQS = 0;
    N       = 0;

    for(x = 0 ; x < seqSize ; ++x){
      if(Read->bases[x] == 'N'){
        ++N;
        }
      totalQS += ((int) Read->scores[x]) - 33; // PHRED +33

      if(x < seqSize - k){
        int tmp_QS = 0;
        for(n = 0 ; n < k ; ++n)
          tmp_QS += ((int) Read->scores[x + n]) - 33;
        if(tmp_QS / k < min_QS_window)
          break;
        }
      }

    ++totalReads;

    // EVALUATE TO DISCARD:
    if(N > max_n)                        continue;
    if((totalQS / seqSize) < min_avg_qs) continue;
    if(x < min_read_size)                continue;


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


