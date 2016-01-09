#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "defs.h"
#include "args.h"

int main(int argc, char *argv[]){
  int n, k, seqSize, seed = 0;
  char *bases = "ACGT";
  double freqs[4] = {0.25, 0.25, 0.25, 0.25}, cum[4], val, totalFreq;

  if(ArgBin(0, argv, argc, "-h")){
    fprintf(stderr, "Usage: %s < input > output\n", argv[0]);
    fprintf(stderr, "Arguments:                         \n");
    fprintf(stderr, " -s  <seed>,                       \n");
    fprintf(stderr, " -f  <fa,fc,fg,ft>  (def: uniform),\n");
    fprintf(stderr, " -n  <nSymbols>     (def: 100).    \n");
    return EXIT_SUCCESS;
    }

  seed    = ArgNum(0,   argv, argc, "-s", 1, UINT_MAX); 
  seqSize = ArgNum(100, argv, argc, "-n", 1, UINT_MAX); 

  for(n = 1 ; n < argc ; n++)
    if(!strcmp("-f", argv[n])){
      if(sscanf(argv[n+1], "%lf,%lf,%lf,%lf", &freqs[0], &freqs[1],
        &freqs[2], &freqs[3]) != 4)
        freqs[0] = freqs[1] = freqs[2] = freqs[3] = 0.25;
      totalFreq = freqs[0] + freqs[1] + freqs[2] + freqs[3];
      freqs[0] /= totalFreq;
      freqs[1] /= totalFreq;
      freqs[2] /= totalFreq;
      freqs[3] /= totalFreq;
      break;
      }

  cum[0] = freqs[0];
  cum[1] = cum[0] + freqs[1];
  cum[2] = cum[1] + freqs[2];
  cum[3] = 1;

  srand(seed);
  for(n = 0 ; n < seqSize ; n++){
    val = rand() / (RAND_MAX + 1.0);
    for(k = 0 ; k < 4 ; k++)
      if(val <= cum[k])
        break;
    putchar(bases[k]);
    }

  return 0;
  }

