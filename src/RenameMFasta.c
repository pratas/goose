#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

int main(int argc, char *argv[]){
  BUF *B;
  int64_t header = 0, k = 0, i = 0;
  uint8_t s, chrs[30][4] = {"1", "2", "3", "4", "5", "6", "7", "8", 
                            "9", "10", "11", "12", "13", "14", "15",
                            "16", "17", "18", "19", "20", "21", "22",
                            "X", "Y", "MT", "UN", "UP", "?", "?", "?"};

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.fasta > output.fasta\n"
    "It changes the headers of FASTA to simple chr$1 by order.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);
  int idx = 0;
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      if(s == '>'){
        header = 1;
        }

      if(header == 1 && s == '\n'){   
        fprintf(stdout, ">chr%s\n", chrs[idx]);
        if(idx < 29)
          ++idx;
        header = 0;
        continue;
        }

      if(header == 0)
        putchar(s);
      }
  RemoveBuffer(B);

  return EXIT_SUCCESS;
  }

