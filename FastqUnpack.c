#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "reads.h"
#include "args.h"

#define ESCAPE 127

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[]){
  uint8_t s;
  uint32_t i, k, pos = 0, line = 0;
  BUF  *B = CreateBuffer(BUF_SIZE);
  Read *R = CreateRead(65536+GUARD, 65535+GUARD);

  if(argc > 3 || ArgBin(0, argv, argc, "-h")){
    fprintf(stderr, "\nUsage: ./FastqUnpack < input > output\n");
    return EXIT_SUCCESS;
    }
  
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      switch(line){
        case 0: 
          if(s == ESCAPE || s == '\n'){
            R->bases[pos++] = '\n';
            R->bases[pos]   = '\0';
            pos  = 0;
            line = 1;
            break;
            }
          else
            R->bases[pos++] = s;
        break;       

        case 1:  
          if(s == ESCAPE || s == '\n'){
            R->scores[pos++] = '\n';
            R->scores[pos]   = '\0';
            pos  = 0;
            line = 2;
            break;
            }
          else
            R->scores[pos++] = s;
        break;

        case 2:        
          if(s == ESCAPE || s == '\n'){
            R->header1[pos++] = '\n';
            R->header1[pos]   = '\0';
            pos  = 0;
            line = 3;
            break;
            }
          else
            R->header1[pos++] = s;
        break;

        case 3:        
          if(s == '\n'){
            R->header2[pos++] = '\n';
            R->header2[pos]   = '\0';
            pos  = 0;
            line = 0;
            fprintf(stdout, "@%s", R->header1);
            fprintf(stdout, "%s",  R->bases);
            fprintf(stdout, "%s",  R->header2);
            fprintf(stdout, "%s",  R->scores);
            break;
            }
          else
            R->header2[pos++] = s;
        break;
        }
      }

  FreeRead(R);
  RemoveBuffer(B);
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
