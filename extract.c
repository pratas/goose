#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "defs.h"
#include "misc.h"

int main(int argc, char *argv[]){
  uint32_t n;
  uint64_t cnt = 0, init = 0, end = 0;
  char c;

  if(argc < 9){
    fprintf(stderr, "Use: %s -s <position> -l <position> < inFile > outFile\n"
    "Example: %s -s 1 -l 1000000 < ch3 > ch3_1M\n", argv[0], argv[0]);
    return EXIT_SUCCESS;
    }

  for(n = 1; n < argc; n++)
    if(strcmp("-s", argv[n]) == 0){	
      init = atol(argv[n+1]);
      break;
      }

  for(n = 1; n < argc; n++)
    if(strcmp("-l", argv[n]) == 0){      
      end = atol(argv[n+1]);
      break;
      }

  do{
    c = fgetc(stdin);
    if(init <= cnt && end > cnt)
      fprintf(stdout, "%c", c);		
    if(cnt++ >= end) break;
    }
  while(c != EOF);

  return EXIT_SUCCESS;
  }
