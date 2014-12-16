#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "filter.h"
#include "args.h"
#include "misc.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

static double CalcMean(Entry *entries, int nEntries, int n, int M, double *w){
  int k;
  double sum = 0, wSum = 0;
  for(k = -M ; k <= M ; k++)
    if(n + k >= 0 && n + k < nEntries){
      sum += w[M+k] * entries[n+k].value;
      wSum += w[M+k];
      }
  return sum / wSum;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){
  char **p = *&argv, oneCol, p1, reverse;
  int n, k, nEntries, position, M, drop, wType;
  double value, *w;
  Entry *entries = NULL;
  FILE *F = NULL;

  if(argc < 3){
    fprintf(stderr,
    "Usage: filter <OPTIONS>... [FILE]                              \n"
    "a tool for filtering numerical sequences                       \n"
    "                                                               \n"
    "Non-mandatory arguments:                                       \n"
    "                                                               \n"
    "  -w  <M>       window sie (def: 0),                           \n"
    "  -d  <drop>    discard elements (def: 0),                     \n"
    "  -wt <type>    window type (0=Hamm, 1=Hann, 2=Black, 3=rec),  \n"
    "  -1            read from one column,                          \n"
    "  -p1           print one column,                              \n"
    "  -r            reverse mode.                                  \n"
    "                                                               \n"
    "  <FILE>       file to compress (last argument).               \n"
    "                                                               \n"
    "Report bugs to <{pratas,ap}@ua.pt>.                            \n");
    return EXIT_SUCCESS;
    }

  M       = (int32_t) ArgNum(0,          p, argc, "-w",  0, 10000000);
  drop    = (int32_t) ArgNum(0,          p, argc, "-d",  0, 10000000);
  wType   = (int32_t) ArgNum(W_HAMMING,  p, argc, "-wt", 0, 3);
  oneCol  =           ArgBin(0,          p, argc, "-1");
  p1      =           ArgBin(0,          p, argc, "-p1");
  reverse =           ArgBin(0,          p, argc, "-r");

  F = Fopen(argv[argc-1], "r");
 
  nEntries = 0;
  if(oneCol == 1){
    while(fscanf(F, "%lf", &value) == 1){
      entries = (Entry *) Realloc(entries, (nEntries+1) * sizeof(Entry), 
      sizeof(Entry));
      entries[nEntries].position = nEntries;
      entries[nEntries].value = value;
      ++nEntries;
      }
    }
  else{
    while(fscanf(F, "%d%lf", &position, &value) == 2){
      entries = (Entry *) Realloc(entries, (nEntries+1) * sizeof(Entry),
      sizeof(Entry));
      entries[nEntries].position = position;
      entries[nEntries].value = value;
      ++nEntries;
      }
    }

  fclose(F);
  fprintf(stderr, "Got %d entries from file\n", nEntries);

  w = (double *) Malloc((2*M+1) * sizeof(double));

  switch(wType){
    case W_HAMMING:
      for(k = -M ; k <= M ; k++)
        w[M+k] = 0.54 + 0.46 * cos((2 * M_PI * k) / (2 * M + 1));
    break;
    case W_HANN:
      for(k = -M ; k <= M ; k++)
        w[M+k] = 0.5 * (1 + cos((2 * M_PI * k) / (2 * M + 1)));
    break;
    case W_BLACKMAN:
      for(k = -M ; k <= M ; k++)
        w[M+k] = 0.42 + 0.5 * cos((2 * M_PI * k) / (2 * M + 1)) +
	0.08 * cos((4 * M_PI * k) / (2 * M + 1));
    break;
    case W_RECTANGULAR:
      for(k = -M ; k <= M ; k++)
        w[M+k] = 1;
    break;
    }

  if(reverse == 1){
    for(n = nEntries - 1 ; n >= 0 ; n--)
      if(n % (drop + 1) == 0){
        if(p1 == 0){
          printf("%d\t%.3f\n", entries[nEntries - n - 1].position,
	  CalcMean(entries, nEntries, n, M, w));
          }
        else{
          printf("%.3f\n", CalcMean(entries, nEntries, n, M, w));
          }
        }
    }
  else
    for(n = 0 ; n < nEntries ; n++)
      if(n % (drop + 1) == 0){
        if(p1 == 0){
          printf("%d\t%.3f\n", entries[n].position, CalcMean(entries, nEntries, 
          n, M, w));
          }
        else{
          printf("%.3f\n", CalcMean(entries, nEntries, n, M, w));
          }
        }

  return 0;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
