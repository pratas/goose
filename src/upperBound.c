#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"

int UpperB(double upper){	
  double value;
  while(fscanf(stdin, "%lf", &value) == 1)
    fprintf(stdout, "%lf\n", value > upper ? upper : value);
  return 0;
  }

void Usage(char *f){
  printf("Usage: %s <upperbound> < [stdin] > [stdout]\n", f);
  printf("Set an upper bound in a file with a value per line.\n");
  }

int main(int argc, char *argv[]){
  if(argc != 2){ Usage(argv[0]); exit(1); }
  
  if(UpperB(atof(argv[2])) == -1){
    perror("Error on computing upperbound!");
    exit(1);
    }
  return EXIT_SUCCESS;
  }
