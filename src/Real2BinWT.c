#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  double  val, threshold;

  if(argc < 2){
    fprintf(stderr, "usage: %s <threshold> < inFile\n", argv[0]);
    fprintf(stderr, "It coverts a real sequence into a binary sequence given a threshold.\n");
    exit(1);
    }
  
  threshold = atof(argv[1]);

  while(fscanf(stdin, "%lf", &val) == 1){
    if(val > threshold){
      fprintf(stdout, "1\n");
      }
    else{
      fprintf(stdout, "0\n");
      }  
    }

  return 0;
  }
