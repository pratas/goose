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
  fprintf(stderr, "                                                   \n"
                  "Usage: %s [max] < input > output                   \n"
                  "                                                   \n"
                  "It analyses the quality-scores of a FASTQ file.    \n"
                  "max stands for the lenght of the maximum window.   \n",
  name);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){

  Read *Read = CreateRead(65536+GUARD, 65535+GUARD);
  int32_t seqSize = 0, x;
  uint64_t totalReads = 0, minSeq = 65535, maxSeq = 0;
  int minQS = 255, maxQS = 0, tmp_QS;
  uint64_t nScores = 0, *QS = (uint64_t *) Calloc(65536, sizeof(uint64_t)),
           *QN = (uint64_t *) Calloc(65536, sizeof(uint64_t));

  if(ArgBin(0, argv, argc, "-h") || ArgBin(0, argv, argc, "?")){
    PrintArgs(argv[0]);
    return EXIT_SUCCESS;
    }

  while(GetRead(stdin, Read)){

    seqSize = strlen((char *) Read->bases) - 1;

    if(seqSize < minSeq)
      minSeq = seqSize;

    if(seqSize > maxSeq)
      maxSeq = seqSize;
 

    for(x = 0 ; x < seqSize ; ++x){
      tmp_QS = (int) Read->scores[x];

      if(tmp_QS < minQS)
        minQS = tmp_QS;

      if(tmp_QS > maxQS)
        maxQS = tmp_QS;

      if(x == 65535){
        fprintf(stderr, "Error: read to long. Increase buffer!\n");
        exit(1);
        }
      
      QS[x] += tmp_QS;
      QN[x] += 1;
 
      ++nScores;
      }

    ++totalReads;
    }

  fprintf(stdout, "Total reads     : %"PRIu64"\n", totalReads);
  fprintf(stdout, "Max read length : %"PRIu64"\n", maxSeq);
  fprintf(stdout, "Min read length : %"PRIu64"\n", minSeq);
  fprintf(stdout, "Min QS value    : %d\n", minQS);
  fprintf(stdout, "Max QS value    : %d\n", maxQS);
  fprintf(stdout, "QS range        : %d\n", maxQS-minQS + 1);
  
  int maxs = atoi(argv[argc-1]);

  int tmp_min = maxQS;
  for(x = 0 ; x < maxs ; ++x){
    QS[x] /= (double) QN[x];
    if(tmp_min > (int) QS[x])
      tmp_min = (int) QS[x];
    }

  for(x = 0 ; x < maxs ; ++x)
    fprintf(stdout, "%2d ", x+1);
  fprintf(stdout, "\n");
  for(x = 0 ; x < maxs ; ++x)
    fprintf(stdout, "--+");
  fprintf(stdout, "\n");
  for(x = 0 ; x < maxs ; ++x)
    fprintf(stdout, "%2d ", (int) QS[x]);
  fprintf(stdout, "\n");

  int line = (int) maxQS;
  while(line > tmp_min){

    for(x = 0 ; x < maxs ; ++x){
      if((int) QS[x] < line)
        fprintf(stdout, " * ");
      else
        fprintf(stdout, "   ");
      }

    fprintf(stdout, "\n");
    line -= 1;
    }

  Free(QS, 0);
  Free(QN, 0);
  FreeRead(Read);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


