#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

int main(int argc, char *argv[]){
  int64_t n, k, i;
  char c;
  BUF *B;

  for(n = 1 ; n < argc ; ++n)
    if(strcmp(argv[n], "-h") == 0){
      argc = 0;
      }

  if(argc == 0 || argc > 1){
    fprintf(stderr, "Usage: %s < in.prot > out.dna\n"
    "It converts a protein sequence to a pseudo DNA sequence.\n"
    "Table:\n"
    "Prot\tDNA\n"
    "A\tGCA\n"
    "C\tTGC\n"
    "D\tGAC\n"
    "E\tGAG\n"
    "F\tTTT\n"
    "G\tGGC\n"
    "H\tCAT\n"
    "I\tATC\n"
    "K\tAAA\n"
    "L\tCTG\n"
    "M\tATG\n"
    "N\tAAC\n"
    "P\tCCG\n"
    "Q\tCAG\n"
    "R\tCGT\n"
    "S\tTCT\n"
    "T\tACG\n"
    "V\tGTA\n"
    "W\tTGG\n"
    "Y\tTAC\n"
    "*\tTAG\n"
    "X\tGGG\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      putchar(B->buf[i]);
      c = B->buf[i];
      switch(c){
        case 'A': fprintf(stdout, "GCA"); break;
        case 'C': fprintf(stdout, "TGC"); break;
        case 'D': fprintf(stdout, "GAC"); break;
        case 'E': fprintf(stdout, "GAG"); break;
        case 'F': fprintf(stdout, "TTT"); break;
        case 'G': fprintf(stdout, "GGC"); break;
        case 'H': fprintf(stdout, "CAT"); break;
        case 'I': fprintf(stdout, "ATC"); break;
        case 'K': fprintf(stdout, "AAA"); break;
        case 'L': fprintf(stdout, "CTG"); break;
        case 'M': fprintf(stdout, "ATG"); break;
        case 'N': fprintf(stdout, "AAC"); break;
        case 'P': fprintf(stdout, "CCG"); break;
        case 'Q': fprintf(stdout, "CAG"); break;
        case 'R': fprintf(stdout, "CGT"); break;
        case 'S': fprintf(stdout, "TCT"); break;
        case 'T': fprintf(stdout, "ACG"); break;
        case 'V': fprintf(stdout, "GTA"); break;
        case 'W': fprintf(stdout, "TGG"); break;
        case 'Y': fprintf(stdout, "TAC"); break;
        case '*': fprintf(stdout, "TAG"); break;
        case 'X': fprintf(stdout, "GGG"); break;
        }
      }
  RemoveBuffer(B);

  return EXIT_SUCCESS;
  }


