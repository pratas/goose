#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mem.h"

// "abcdefghijklmnopqrstuvwxyz"
// "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// "0123456789";
// "|!"#$%&/()=?»,.-~º'+«}][{¬½§£@¹¬"

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

void Brute(int max_k, char *alpha, int alpha_size){
  int64_t x;  
  char *buf = (char *) Malloc((max_k + 1) * sizeof(char));

  for(x = max_k ; x <= max_k ; ++x){ // x = 1 to generate from k=1 to k=max_k
    x = max_k;
    memset(buf, 0, max_k + 1);
    BruteForce(buf, 0, x, alpha, alpha_size);
    }

  Free(buf, 0);
  }

int main(int argc, char *argv[]){
  int n;
   
  for(n = 0 ; n < argc ; ++n)
    if(argc != 3){
      fprintf(stderr, "Usage: %s <alphabet> <k> > out   \n"
      "It generates all combinations, line by line, for \n"
      "an inputed alphabet and specific k size.         \n",
      argv[0]);
      return EXIT_SUCCESS;
      }

  int size = strlen(argv[argc-2]);
  Brute(atoi(argv[argc-1]), argv[argc-2], size);

  return EXIT_SUCCESS;
  }
