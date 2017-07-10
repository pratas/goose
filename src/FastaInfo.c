#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

int main(int argc, char *argv[]){
  uint32_t k, i;
  uint8_t  s, header = 1;
  BUF *B;

  if(argc != 1){
    fprintf(stderr, "Usage: %s < input.fasta > output\n"
    "It shows read information of a FASTA or Multi-FASTA file format.\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);

  uint64_t min_n_bases = UINT_MAX, max_n_bases = 0, cum_n_bases = 0, 
           i_bases = 0, n_reads = 0;

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      if(s == '>'){ 
        header = 1; 
        if(i_bases != 0){
          cum_n_bases += i_bases;
          if(i_bases > max_n_bases)
            max_n_bases = i_bases;        
          if(i_bases < min_n_bases)
            min_n_bases = i_bases;        
          }
        ++n_reads;
        i_bases = 0;
        continue; 
        }
      if(s == '\n' && header == 1){ header = 0; continue; }
      if(s == '\n') continue;
      if(header == 1) continue;
      if(s < 65 || s > 122) continue;

      ++i_bases;
      }

  fprintf(stdout, "Number of reads      : %"PRIu64"\n", n_reads);
  fprintf(stdout, "Number of bases      : %"PRIu64"\n", cum_n_bases);
  fprintf(stdout, "MIN of bases in read : %"PRIu64"\n", min_n_bases);
  fprintf(stdout, "MAX of bases in read : %"PRIu64"\n", max_n_bases);
  fprintf(stdout, "AVG of bases in read : %.4lf\n", (double) cum_n_bases / 
  n_reads);

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

