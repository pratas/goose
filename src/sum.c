#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"

double SumFile(char *f){	
  FILE *F = Fopen(f, "r");
  double sum = 0, v = 0; 

  while(fscanf(F, "%lf", &v) == 1)
    sum += v;

  fprintf(stdout, "%lf\n", sum);

  if(F) fclose(F);
  return 0;
  }

void Usage(char *f){
  printf("Usage: %s <file>\n", f);
  }

int main(int argc, char *argv[]){
  if(argc != 2){ Usage(argv[0]); exit(1); }
  
  if(SumFile(argv[1]) == -1){
    perror("Error on computing sum!");
    exit(1);
    }

  return EXIT_SUCCESS;
  }
