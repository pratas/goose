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
                  "Usage: %s [VALUE] [VALUE] < input > output              \n"
                  "                                                        \n"
                  "Cut (select) read sequence from base/score x1 to x2.    \n"
                  "                                                        \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  uint32_t seqSize = 0, x1, x2, n;

  if(argc < 3 || ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }
  
  x1 = atoi(argv[1]);
  x2 = atoi(argv[2]);
 
  while(GetRead(stdin, Read)){

    seqSize = strlen((char *) Read->bases) - 1;

    // PRINT READ
    fprintf(stdout, "@");
    for(n = 0 ; n < strlen((char *) Read->header1) ; ++n)
      fprintf(stdout, "%c", Read->header1[n]);
    for(n = 0 ; n < seqSize ; ++n){
      if(n >= x1 && n <= x2){
        fprintf(stdout, "%c", Read->bases[n]);
        }
      }
    fprintf(stdout, "\n+\n");
    for(n = 0 ; n < seqSize ; ++n){
      if(n >= x1 && n <= x2){
        fprintf(stdout, "%c", Read->scores[n]);
        }
      }
    fprintf(stdout, "\n");
    }

  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


