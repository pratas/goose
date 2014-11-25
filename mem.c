#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CURRENT MEMORY TRACK
//
static size_t DM = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// WARN ERROR AND QUIT
//
static void ErrorQuit(size_t s){
  fprintf(stderr, "[x] Error allocating %zu bytes.\n", s);
  exit(1);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MALLOC AND INCREMENT MEMORY TRACK
//
void *Malloc(size_t s){
  void *p = malloc(s);
  if(p == NULL) ErrorQuit(s);
  DM += s;
  return p;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CALLOC AND INCREMENT MEMORY TRACK
//
void *Calloc(size_t n, size_t s){
  void *p = calloc(n, s);
  if(p == NULL) ErrorQuit(s);
  DM += n*s;
  return p;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// REALLOC AND INCREMENT MEMORY TRACK
//
void *Realloc(void *r, size_t s){
  void *p = realloc(r, s);
  if(p == NULL) ErrorQuit(s);
  DM += s;
  return p;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FREE POINTER AND DECREMENT MEMORY VALUE
//
void Free(void *p, size_t s){
  DM -= s;
  free(p);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// RETURN CURRENT MEMORY USGE
//
size_t TotalMem(){
  return DM;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


