#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"

int main(int argc, char *argv[]){
  FILE *IN = Fopen(argv[argc-1], "r");
  int64_t i, size;

  if(argc != 2){
    fprintf(stderr, "Reverse huge file using very low memory.\n");
    fprintf(stderr, "Usage: %s file\n", argv[0]);
    return EXIT_SUCCESS;
    }

  fseeko(IN, 0, SEEK_END);
  size = ftello(IN);
    
  i = 0; 
  while(i++ < size){
    fseeko(IN, -i, SEEK_END);
    printf("%c", fgetc(IN));
    }
  printf("\n");
  fclose(IN);

  return EXIT_SUCCESS;
  }

