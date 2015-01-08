#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "args.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// READ NUMBER FROM ARGS & CHECK BOUNDS
//
uint32_t ArgNum(uint32_t d, char *a[], uint32_t n, char *s, uint32_t l,
uint32_t u){
  uint32_t x;
  for( ; --n ; ) if(!strcmp(s, a[n])){
    if((x = atol(a[n+1])) < l || x > u){
      fprintf(stderr, "[x] Invalid number! Interval: [%u;%u].\n", l, u);
      exit(EXIT_FAILURE);
      }
    return x;
    }
  return d;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// READ DOUBLE FROM ARGS
//
double ArgDbl(double d, char *a[], uint32_t n, char *s){
  for( ; --n ; ) if(!strcmp(s, a[n])) return atof(a[n+1]);
  return d;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// READ BINARY STATE FROM ARGS
//
uint8_t ArgBin(uint8_t d, char *a[], uint32_t n, char *s){
  for( ; --n ; ) if(!strcmp(s, a[n])) return d==0?1:0;
  return d;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// GET STRING TO ARGV
//
int32_t StrToArgv(char *s, char ***v){
  int32_t n = 0, c = 2;
  char *d = strdup(s);   // STRDUP <=> CLONE STR
  while(d[n]) if(d[n++] == ' ') ++c;
  *v = (char **) Calloc(c, sizeof(char *));
  n = 0; (*v)[0] = d; c = 1;
  do if(d[n] == ' '){
       d[n] = '\0';
       (*v)[c++] = d+n+1;
       }
  while(d[++n]);
  return c;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
