#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  double fix = 0, x, y, z;
  int new = 1;

  if(argc != 1){
    fprintf(stderr, "Usage: %s < inFile > outFile\n", argv[0]);
    return EXIT_SUCCESS;
    }

  while(fscanf(stdin, "%lf %lf %lf\n", &x, &y, &z) == 3){
   if(x != fix){
     if(new == 0)
       fprintf(stdout, "\n");
     fix = x;
     new = 0;
     }
   fprintf(stdout, "%lf\t%lf\t%lf\n", x, y, z);
   }

  return EXIT_SUCCESS;
  }
