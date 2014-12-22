#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  quickSort
//
//  This public-domain C implementation by Darel Rex Finley.
//  quickSort(&myArray[0],5); // sorts elements 0, 1, 2, 3, and 4
//  quickSort(&myArray[3],5); // sorts elements 3, 4, 5, 6, and 7

void QuickSort(int *arr, int elements){
  #define  MAX_LEVELS  300
  int piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R, swap;
  beg[0]=0; 
  end[0]=elements;

  while(i >=0){
    L = beg[i]; 
    R = end[i]-1;
    if(L < R){
      piv = arr[L];
      while(L < R){
        while (arr[R] >= piv && L < R) R--; 
        if(L < R) arr[L++] = arr[R];
        while (arr[L] <= piv && L < R) L++; 
        if(L < R) arr[R--] = arr[L]; 
        }
      arr[L] = piv; beg[i+1] = L+1; end[i+1] = end[i]; end[i++] = L;
      if(end[i]-beg[i] > end[i-1]-beg[i-1]){
        swap = beg[i]; beg[i] = beg[i-1]; beg[i-1] = swap;
        swap = end[i]; end[i] = end[i-1]; end[i-1] = swap; 
        }
      } 
    else{
      --i; 
      }
    }
  }

int main(int argc, char *argv[]){
  uint32_t k, i;
  uint8_t  s, line = 0;
  BUF *B;
  uint64_t *X, *Y;
  uint64_t size = 1<<16;

  if(argc != 1){
    fprintf(stderr, "\nUsage: ./FastqClustReads < input.fq > output.fq\n"
    "                                                                 \n"
    "FastqClustReads agroups reads and creates an index file.         \n"
    "It cluster reads in therms of entropy                            \n");
    return EXIT_SUCCESS;
    }

  B = CreateBuffer(BUF_SIZE);
  X = (uint64_t *) Calloc(size * sizeof(uint64_t));
  Y = (uint64_t *) Calloc(size * sizeof(uint64_t));

  while((k = fread(B->buf, 1, B->size, stdin)))
    for(i = 0 ; i < k ; ++i){
      s = B->buf[i];
      switch(line){ 
        case 0: 
          if(s == '\n') line = 1;
        break;
        case 1: 
          if(s == '\n') line = 2;
        break;
        case 2:
          if(s == '\n') line = 3;
        break;
        case 3:
          if(s == '\n') line = 0;
        break;
        } 
      }

  RemoveBuffer(B); 
  return EXIT_SUCCESS;
  }

