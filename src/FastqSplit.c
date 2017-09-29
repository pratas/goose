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
  fprintf(stderr, "                                                      \n"
                  "Usage: %s <output_forward> <output_reverse> < input   \n"
                  "                                                      \n"
                  "It splits Paired End files according to the           \n"
                  "direction of the strand ('/1' or '/2').               \n"
                  "                                                      \n"
                  "Example: ./%s HN_r1.fq HN_r2.fq < HN.fq               \n"
                  "                                                      \n",
  name, name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read      *Read = CreateRead(65536+GUARD, 65535+GUARD);
  uint64_t  total = 0, forward = 65535, reverse = 0;

  if(argc < 2 || ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }

  FILE *F = Fopen(argv[argc-2], "w");
  FILE *R = Fopen(argv[argc-1], "w");

  while(GetRead(stdin, Read)){

    switch(Read->header1[strlen((char *) Read->header1)-2]){
      case '1':
        PrintRead(Read, F);
        ++forward;
      break;
      case '2':
        PrintRead(Read, R);
        ++reverse;   
      break;
      default:
        fprintf(stderr, "Error: Unknown file type (%d)!\n",
        (int) Read->header1[strlen((char *) Read->header1)-2]);
      }

    ++total;
    }

  fprintf(stderr, "Total reads     : %"PRIu64"\n", total);
  fprintf(stderr, "Forward reads   : %"PRIu64"\n", forward);
  fprintf(stderr, "Reverse reads   : %"PRIu64"\n", reverse);

  fclose(F);
  fclose(R);
  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


