#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"

int MaxFile(char *fn1, char *fn2){	
  FILE *F1 = Fopen(fn1, "r"), *F2 = Fopen(fn2, "r");
  double max1, max2; 

  while(fscanf(F1, "%lf", &max1) == 1 && fscanf(F2, "%lf", &max2) == 1)
    fprintf(stdout, "%lf\n", max1 > max2 ? max1 : max2);

  if(F1) fclose(F1);
  if(F2) fclose(F2);
  return 0;
  }

void Usage(char *f){
  printf("Usage: %s <file> <file>\n", f);
  }

int main(int argc, char *argv[]){
  if(argc != 3){ Usage(argv[0]); exit(1); }
  
  if(MaxFile(argv[1], argv[2]) == -1){
    perror("Error on computing maximum!");
    exit(1);
    }
  return EXIT_SUCCESS;
  }
