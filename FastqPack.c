#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "reads.h"
#include "args.h"

void PrintStream(uint8_t *b, uint32_t n, uint8_t terminator){
  int k;
  for(k = 0 ; k < n ; ++k)
    if(b[k] == '\n' /* && terminator == 0*/) 
      putchar(127);
    else 
      putchar(b[k]);
  }

void PrintID(uint32_t i){
  fprintf(stdout, "\t%u\n", i);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){
  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  uint32_t i = 0, scores = 0;

  if(argc > 3 || ArgBin(0, argv, argc, "-h")){
    fprintf(stderr, "\nUsage: ./FastqPack < input > output\n");
    fprintf(stderr, " -s use scores as first chars (default: dna sequence)\n");
    return EXIT_SUCCESS;
    }
  
  scores = ArgBin(0, argv, argc, "-s");
  
  while(GetRead(stdin, Read)){
    if(scores == 0){
      PrintStream(Read->bases,  strlen((char *) Read->bases ),  0);
      PrintStream(Read->scores, strlen((char *) Read->scores),  0);
      }
    else{
      PrintStream(Read->scores, strlen((char *) Read->scores),  0);
      PrintStream(Read->bases,  strlen((char *) Read->bases ),  0);
      }
    PrintStream(Read->header1,  strlen((char *) Read->header1), 0);
    PrintStream(Read->header2,  strlen((char *) Read->header2), 0);
    PrintID(i++);
    }

  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
