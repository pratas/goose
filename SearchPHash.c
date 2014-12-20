#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "hash.h"
#include "alpha.h"
#include "mem.h"

uint64_t *LoadPrimes(uint32_t n){
  uint64_t  i = 3, count, c, k = 0;
  uint64_t *primes = (uint64_t *) Calloc(n++, sizeof(uint64_t)); 
  primes[0] = 2;
  for(count = 2 ; count < n ; ++i){
    for(c = 2 ; c < i ; c++)
      if(i % c) break;
    if(c == i){
      primes[++k] = i;
      ++count;
      }
    }
  return primes;
  }

int main(int argc, char *argv[]){
  BUF      *B;
  ALPHA    *A;
  uint64_t *primes, nPrimes = 5000;
  uint32_t k;
  
  if(argc != 1){
    fprintf(stderr, "\nUsage: ./SearchPHash < input.seq > output.param    \n"
    "                                                                     \n"
    "SearchPHash search for the best two primes that approximate a hash "
    "family function (a.p1 + b.p2) on a sequence.                         \n");
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);
  A = CreateAlphabet();

  LoadAlphabet(A, B);
  primes = LoadPrimes(nPrimes);

  for(k = 0 ; k < nPrimes ; ++k)
    printf("%"PRIu64"\n", primes[k]);


  Free(primes, nPrimes * sizeof(uint64_t));
  DeleteAlphabet(A);
  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

