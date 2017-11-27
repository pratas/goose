#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"
#include "alpha.h"

static const char alphabet[] = 
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789";

void BruteForce(char *str, int idx, int max_depth, char *alpha, int alpha_size){
  int64_t x;

  for(x = 0 ; x < alpha_size ; ++x){
    str[idx] = alpha[x];
    if(idx == max_depth - 1)
      printf("%s\n", str);
    else
      BruteForce(str, idx + 1, max_depth, alpha, alpha_size);
    }
  }

int64_t CountCombinations(int cardinality, int groups){
  int64_t c, g, combinations = 0;
/*
  char matrix[cardinality][groups];



  for(c = 0 ; c < cardinality ; ++c){
    
    for(g = 0 ; g < cardinality ; ++g){


      matrix[c][g] = alphabet[g];

      fprintf(stderr, "%c", matrix[c][g]);
      }

    fprintf(stderr, "\n");
    }  
*/

  return combinations;
  }

int main(int argc, char *argv[]){
  int64_t n;
  char c;
  BUF *B;
  int n_groups;

  for(n = 0 ; n < argc ; ++n)
    if(argc != 2){
      fprintf(stderr, "Usage: %s <n_groups> < in.seq \n"
      "It converts a sequence into group sequences.  \n"
      "It writes to out#combinations.                \n",
      argv[0]);
      return EXIT_SUCCESS;
      }

  // LOADING NUMBER OF GROUPS
  n_groups = atoi(argv[argc-1]);
  fprintf(stderr, "Running for %d groups\n", n_groups);

  // LOADING ALPHABET
  ALPHA *A = CreateAlphabet();
  B = CreateBuffer(BUF_SIZE);
  LoadAlphabet(A, B);
  PrintAlphabet(A);
  RemoveBuffer(B);
  
  // LOADING COMBINATIONS
  uint64_t n_combinations = CountCombinations(A->nSym, n_groups);
  char **matrix = (char **) Calloc(A->nSym, sizeof(char *));
  for(n = 0 ; n < A->nSym ; ++n)
    matrix[n] = (char *) Calloc(n_combinations, sizeof(char));

  // BUILD OUTPUT FILES WITH COMBINATIONS
  FILE **FILES = (FILE **) Calloc(n_combinations, sizeof(FILE *));

/*
  B = CreateBuffer(BUF_SIZE);
  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      c = B->buf[i];
      switch(c){
        case 'R': putchar('P'); break;
        case 'N': putchar('P'); break;

        case 'F': putchar('H'); break;
        case 'Y': putchar('H'); break;
        case 'W': putchar('H'); break;

        case '*': putchar('*'); break;
        case 'X': putchar('X'); break;
        }
      }
  RemoveBuffer(B);
*/


  DeleteAlphabet(A);
  return EXIT_SUCCESS;
  }


