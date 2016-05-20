#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

#define MAX_HEADER 16384

int main(int argc, char *argv[]){
  uint32_t k, i, idxH = 0, len = 0, x;
  uint64_t pos;
  uint8_t  s, header = 1, write = 0;
  uint8_t  *hName = (uint8_t *) Calloc(MAX_HEADER+1, sizeof(uint8_t));
  BUF  *B;
  CBUF *DNA;

  if(argc != 2){
    fprintf(stderr, "Usage: %s <pattern> < input.fasta > output.coords\n"
    "It extracts the header & coordinates from a Multi-FASTA file format\ngiven "
    "a pattern/motif in the sequence.\n", 
    argv[0]);
    return EXIT_SUCCESS;
    }

  pos = 0;
  B   = CreateBuffer(BUF_SIZE);
  len = strlen(argv[argc-1]);
  DNA = CreateCBuffer(BUF_SIZE, len+1);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      if(s == '>'){ 
        idxH = 0;
        hName[idxH] = s;
        header = 1; 
        pos = 0;
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
          }
        continue;
        }

      DNA->buf[DNA->idx] = s;

      if(++pos >= len){
        write = 1;
        for(x = 0 ; x < len ; ++x){
          //if(DNA->buf[DNA->idx-x] != argv[argc-1][x]){ // REVERSE PATTERN
          if(DNA->buf[DNA->idx-len+1+x] != argv[argc-1][x]){ // REVERSE PATTERN
            write = 0;
            break;
            }
          }       
 
        if(write == 1){
          fprintf(stdout, "%"PRIu64"\t%"PRIu64"\t%s\n", pos-len+1, pos, hName);
          }
        }
      
      UpdateCBuffer(DNA);
      }

  RemoveBuffer(B); 
  RemoveCBuffer(DNA); 
  Free(hName, 0);
  return EXIT_SUCCESS;
  }

