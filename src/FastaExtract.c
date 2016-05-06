#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "buffer.h"

int main(int argc, char *argv[]){
  uint32_t n, k, i;
  uint64_t cnt = 0, init = 0, end = 100;
  uint8_t  s, header = 1;
  BUF *B;

  if(argc < 3){
    fprintf(stderr, "Usage: %s -i <init> -e <end> < input.fasta >" 
    " out.seq\nIt extracts sequences from a FASTA file.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  for(n = 1; n < argc; n++)
    if(strcmp("-i",argv[n]) == 0){
      init = atol(argv[n+1]);
      break;
      }

  for(n = 1; n < argc; n++)
    if(strcmp("-e",argv[n]) == 0){
      end = atol(argv[n+1]);
      break;
      }

  B = CreateBuffer(BUF_SIZE);

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      if(s == '>'){ header = 1; continue; }
      if(s == '\n' && header == 1){ header = 0; continue; }
      if(s == '\n') continue;
      if(header == 1) continue;
      if(s < 65 || s > 122) continue;

      if(init <= cnt && end > cnt)
        putchar(s);
      ++cnt;
      }

  RemoveBuffer(B);
  return EXIT_SUCCESS;
  }
