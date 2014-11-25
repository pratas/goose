#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "defs.h"
#include "extra.h"

int main(int argc, char *argv[]){
  FILE *IN = NULL, *OUT = NULL;
  uint32_t n;
  uint64_t cnt = 0, init = 0, end = 0;
  char c;

  if(argc < 9){
    fprintf(stderr, "USAGE:\n%s -i IN_FILE -o OUT_FILE -pS FIRST_POSITIO"
    "N_NUMBER -pL LAST_POSITION_NUMBER\nCOMMON USAGE:\nDNAExt -i input -o ou"
    "tput -pS 1000 -pL 1000000\n", argv[0]);
    return EXIT_SUCCESS;
    }

  fprintf(stderr, "[>] Starting Extract ...\n");

  for(n = 1 ; n < argc ; n++)
    if(strcmp("-i", argv[n]) == 0){
      IN = Fopen(argv[n+1], "r");
      break;
      }

  for(n = 1 ; n < argc ; n++)
    if(strcmp("-o", argv[n]) == 0){
      OUT = Fopen(argv[n+1], "w");
      break;
      }

  for(n = 1; n < argc; n++)
    if(strcmp("-pS",argv[n]) == 0){	
      init = atol(argv[n+1]);
      break;
      }

  for(n = 1; n < argc; n++)
    if(strcmp("-pL",argv[n]) == 0){      
      end = atol(argv[n+1]);
      break;
      }

  do{
    c = fgetc(IN);
    if(init <= cnt && end > cnt)
      fprintf(OUT, "%c", c);		
    if(cnt++ >= end) break;
    }
  while(c != EOF);

  fprintf(stderr, "[>] Done!\n");
  fclose(IN); fclose(OUT);
  return EXIT_SUCCESS;
  }
