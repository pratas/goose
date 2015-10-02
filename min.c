#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"

int MinFile(char *fn1, char *fn2){	
  FILE *F1 = Fopen(fn1, "r"), *F2 = Fopen(fn2, "r");
  double min1, min2; 

  while(fscanf(F1, "%lf", &min1) == 1 && fscanf(F2, "%lf", &min2) == 1)
    fprintf(stdout, "%lf\n", min1 < min2 ? min1 : min2);

  if(F1) fclose(F1);
  if(F2) fclose(F2);
  return 0;
  }

void Usage(char *f){
  printf("Usage: %s <file> <file>\n", f);
  }

int main(int argc, char *argv[]){
  if(argc != 3){ Usage(argv[0]); exit(1); }
  
  if(MinFile(argv[1], argv[2]) == -1){
    perror("Error on computing minimum!");
    exit(1);
    }
  return EXIT_SUCCESS;
  }
