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
    "It converts a amino acid sequence to a group sequence.\n"
    "Table:\n"
    "Prot\tGroup\n"
    "R\tP\n"
    "H\tP  Amino acids with electric charged side chains: POSITIVE\n"
    "K\tP\n"
    "-\t-\n"
    "D\tN\n"
    "E\tN  Amino acids with electric charged side chains: NEGATIVE\n"
    "-\t-\n"
    "S\tU\n"
    "T\tU\n"
    "N\tU  Amino acids with electric UNCHARGED side chains\n"
    "Q\tU\n"
    "-\t-\n"
    "C\tS\n"
    "U\tS\n"
    "G\tS  Special cases\n"
    "P\tS\n"
    "-\t-\n"
    "A\tH\n"
    "V\tH\n"
    "I\tH\n"
    "L\tH\n"
    "M\tH  Amino acids with hydrophobic side chains\n"
    "F\tH\n"
    "Y\tH\n"
    "W\tH\n"
    "-\t-\n"
    "*\t*  Others\n"
    "X\tX  Unknown\n", argv[0]);
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      c = B->buf[i];
      switch(c){
        case 'R': putchar('P'); break;
        case 'H': putchar('P'); break;
        case 'K': putchar('P'); break;

        case 'D': putchar('N'); break;
        case 'E': putchar('N'); break;

        case 'S': putchar('U'); break;
        case 'T': putchar('U'); break;
        case 'N': putchar('U'); break;
        case 'Q': putchar('U'); break;

        case 'C': putchar('S'); break;
        case 'U': putchar('S'); break;
        case 'G': putchar('S'); break;
        case 'P': putchar('S'); break;

        case 'A': putchar('H'); break;
        case 'V': putchar('H'); break;
        case 'I': putchar('H'); break;
        case 'L': putchar('H'); break;
        case 'M': putchar('H'); break;
        case 'F': putchar('H'); break;
        case 'Y': putchar('H'); break;
        case 'W': putchar('H'); break;

        case '*': putchar('*'); break;
        case 'X': putchar('X'); break;
        }
      }
  RemoveBuffer(B);

  return EXIT_SUCCESS;
  }


