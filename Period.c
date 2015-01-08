#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "fcm.h"
#include "dna.h"
#include "misc.h"
#include "mem.h"

int main(int argc, char *argv[]){
  uint32_t k, i, order = 1, max = 20;
  uint8_t  s;
  uint64_t info[2][max];
  BUF      *B;
  CBUF     *CB;
  FCM      *Fcm;
  FILE     *PLOT = popen("gnuplot -p", "w");

  if(argc != 1){
    fprintf(stderr, "\nUsage: ./Period < input > output\n"
    "                                                                  \n"
    "Period calculates the best order depth (using FCMs) of a sequence.\n"
    "It only works with \"ACGT\", while the rest will be discarded. \n"
    "The Output is given by log_2(4)*K(x)/|x|)\n");
    return EXIT_SUCCESS;
    }

  // SEQUENCE
  for(order = 1 ; order <= max ; ++order){
    fprintf(stderr, "Running order: %u ... ", order);
    rewind(stdin);
    info[0][order] = 0;
    info[1][order] = 0;
    B   = CreateBuffer (BUF_SIZE);
    CB  = CreateCBuffer(BUF_SIZE, GUARD);
    Fcm = Create4DnaFCM(order, 1, 0, 4);

    while((k = fread(B->buf, 1, B->size, stdin)))
      for(i = 0 ; i < k ; ++i){
        s = B->buf[i];
        if(s == 'A' || s == 'C' || s == 'G' || s == 'T'){
          s = S2N(s);
          CB->buf[CB->idx] = s;
          GetIdx4Dna(CB->buf+CB->idx-1, Fcm);
          Compute4DnaFCM(Fcm);
          info[0][order] += CompProbs(Fcm, s);
          info[1][order]++;
          Update4DnaFCM(Fcm, s, 0);
          UpdateCBuffer(CB);
          }
        }

    fprintf(stderr, "Done!\n");
    RemoveBuffer (B);
    RemoveCBuffer(CB);
    Free4DnaModel(Fcm);
    }
  
  fprintf(PLOT, "plot '-' with lines\n");
  for(order = 1 ; order <= max ; ++order){
    fprintf(stdout, "%2u\t%.4g\n", order, (double) (2 * info[0][order]) /
    info[1][order]); 
    fprintf(PLOT,   "%2u\t%.4g\n", order, (double) (2 * info[0][order]) /
    info[1][order]); 
    }

  fprintf(PLOT, "e\n");
  fflush(PLOT);
  fclose(PLOT);

  return EXIT_SUCCESS;
  }

