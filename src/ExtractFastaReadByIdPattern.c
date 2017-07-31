#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

#define MAX_HEADER 4096

int main(int argc, char *argv[]){
  uint32_t k, i, idxH = 0;
  uint8_t  s, header = 1, write = 0;
  uint8_t  *hName = (uint8_t *) Calloc(MAX_HEADER+1, sizeof(uint8_t));
  BUF *B;

  if(argc != 2){
    fprintf(stderr, "Usage: %s <pattern> < input.mfasta > output.fasta\n"
    "It extracts reads from a Multi-FASTA file format given "
    "a pattern in the header (ID). It ignores case (upper/lower).\n", 
    argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      if(s == '>'){ 
        idxH = 0;
        hName[idxH] = s;
        header = 1; 
        write = 0;
        continue; 
        }
      
      if(header == 1){
        if(s != '\n'){
          if(++idxH < MAX_HEADER){
            hName[idxH] = s;
            }
          else{
            hName[idxH] = '\0';
            }            
          }
        else{
          header = 0; 
          hName[idxH+1] = '\0';
          if(strcasestr(hName,(char *) argv[argc-1]) != NULL){
            fprintf(stdout, "%s\n", hName);
            write = 1;
            }
          }
        continue;
        }

      if(write == 1) putchar(s);
      }

  RemoveBuffer(B); 
  Free(hName, 0);
  return EXIT_SUCCESS;
  }

