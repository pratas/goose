#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"

int SearchFile(char *fn, char *str){	
  FILE     *F = Fopen(fn, "r");
  uint64_t line = 0, found = 0;
  char     buf[BUFFER_SIZE_WS];
  while(fgets(buf, BUFFER_SIZE_WS, F)){
    if(strstr(buf, str)){
      printf("Found match in range [ %"PRIu64" : %"PRIu64" ]\n", 
      line*BUFFER_SIZE_WS, (line+1)*BUFFER_SIZE_WS);
      printf("%s\n\n", buf);
      ++found;
      }
    ++line;
    }
  if(!found) printf("NO matches found!\n");
  if(F) fclose(F);
  return 0;
  }

void Usage(char *f){
  printf("Usage: %s <file> <string>\n", f);
  }

int main(int argc, char *argv[]){
  if(argc != 3){ Usage(argv[0]); exit(1); }
  if(SearchFile(argv[1], argv[2]) == -1){
    perror("Error on running search!");
    exit(1);
    }
  return EXIT_SUCCESS;
  }
