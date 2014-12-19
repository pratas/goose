#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"

int main(int argc, char *argv[]){
  uint32_t k, i;
  uint8_t  s, line = 0, pos = 1;
  BUF *B;

  if(argc != 1){
    fprintf(stderr, "\nUsage: ./Fasta2Seq < input.fasta > output.seq      \n"
    "                                                                     \n"
    "Fasta2Seq converts a FASTA or Multi-FASTA file format to a sequence. \n");
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      switch(line){
        case 0: 
          if(pos == 0 && s != '>'){
            putchar(s);
            line = 1;
            break;
            }

          if(s == '\n'){ 
            line = 1;
            break;
            }
          
          if(pos++ == 0 && s == '>')
            break;

        break;
        case 1: 
          if(s == '\n'){ 
            line   = 0; 
            pos    = 0;
            break; 
            }
          putchar(s);
        break;
        } 
      }

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

