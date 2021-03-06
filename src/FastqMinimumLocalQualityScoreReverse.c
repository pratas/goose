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
  // REVERSE CHAIN
  fprintf(stderr, "                                                   \n"
                  "Usage: %s [OPTIONS] < input > output               \n"
                  "                                                   \n"
                  "  -k <int>       Window size (sw) to filter QS,    \n"
                  "  -w <int>       Minimum average QS with k-sw.     \n"
                  "  -m <int>       Minimum quality score ascii (33). \n"
                  "                                                   \n"
                  "It works for Reverse chain (Paired End reads).     \n"
                  "                                                   \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  int32_t seqSize = 0, x, n;
  uint64_t cutted = 0, totalReads = 0;

  if(argc < 2 || ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }
  
  int k             = ArgNum(5,  argv, argc, "-k", 0, 9999999);
  int min_QS_window = ArgNum(25, argv, argc, "-w", 0, 9999999);
  int min_QS        = ArgNum(33, argv, argc, "-m", 0, 9999999);

  fprintf(stderr, "Minimum QS: %d\n", min_QS);
 
  uint32_t position = 0;
  while(GetRead(stdin, Read)){

    seqSize = strlen((char *) Read->bases) - 1;

    for(x = seqSize ; x >= 0 ; x--){
      if(x >= k){

        int tmp_QS = 0;
        for(n = 0 ; n < k ; ++n){
          tmp_QS += ((int) Read->scores[x - 1 - n]) - min_QS;
          }

        if(((double) tmp_QS / k) < (double) min_QS_window){
          ++cutted;
          position = x;
          break;
          }
        }
      }

    ++totalReads;

    if(x > seqSize - k) continue;

    // PRINT READ
    fprintf(stdout, "@");
    for(n = 0 ; n < strlen((char *) Read->header1) ; ++n)
      fprintf(stdout, "%c", Read->header1[n]);
    for(n = position ; n < seqSize ; ++n)
      fprintf(stdout, "%c", Read->bases[n]);
    fprintf(stdout, "\n+\n");
    for(n = position ; n < seqSize ; ++n)
      fprintf(stdout, "%c", Read->scores[n]);
    fprintf(stdout, "\n");
    }

  fprintf(stderr, "Total reads    : %"PRIu64"\n", totalReads);
  fprintf(stderr, "Trimmed reads  : %"PRIu64"\n", cutted);

  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


