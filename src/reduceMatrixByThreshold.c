#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "misc.h"

#define MAX_LINE 65535

uint32_t CountNumberOfLines(void){
  char c;
  uint32_t n_lines = 0;
  while((c = fgetc(stdin)) != EOF){
    if(c == '\n') n_lines++;
    }
  rewind(stdin);
  return n_lines;
  }

void Usage(char *f){
  printf("Usage: %s <threshold> < stdin > stdout\n", f);
  }

int Split(const char *str, char c, char ***arr){
  int count = 1, token_len = 1, i = 0;
  char *p, *t;

  p = str;
  while(*p != '\0'){
    if(*p == c)
      count++;
    p++;
    }

  *arr = (char **) malloc(sizeof(char *) * count);

  p = str;
  while(*p != '\0'){
    if(*p == c){
      (*arr)[i] = (char *) malloc(sizeof(char) * token_len);
      token_len = 0;
      i++;
      }
    p++;
    token_len++;
  }

  (*arr)[i] = (char *) malloc(sizeof(char) * token_len);

  i = 0;
  p = str;
  t = ((*arr)[i]);
  while(*p != '\0'){
    if(*p != c && *p != '\0'){
      *t = *p;
      t++;
      }
    else{
      *t = '\0';
      i++;
      t = ((*arr)[i]);
      }
    p++;
    }

  return count;
  }

int main(int argc, char *argv[]){

  if(argc != 2){ Usage(argv[0]); exit(1); }

  double threshold = atof(argv[argc-1]);
  uint32_t max_lines = CountNumberOfLines(), id_lines = 0, n, pos = 0;
  char line[MAX_LINE];
  int *print = (int *) calloc(max_lines, sizeof(int));

  while(fgets(line, MAX_LINE, stdin)){
    char *tmp = strdup(line);
    if(id_lines != 0){
      char **fields = NULL;
      int c = Split(tmp, '\t', &fields);
      fprintf(stderr, "Found %d fields\n", c);
      for(n = 0 ; n < c ; ++n){
        fprintf(stderr, "Field #%d: %s\n", n, fields[n]);
        if(threshold < atof(fields[n]))
          print[n] = 1;
        }
      }
    free(tmp);
    ++id_lines;
    }
 
  pos = 0; 
  for(n = 0 ; n < max_lines ; ++n)
    if(print[n] == 0)
      ++pos;

  fprintf(stderr, "Found %u elements of %u higher than the threshold\n",
  max_lines-pos, max_lines-1);

  int x, y, matrix[max_lines][max_lines-1];

  for(x = 0 ; x < max_lines ; ++x)
    for(y = 0 ; y < max_lines-1 ; ++y)
      matrix[x][y] = 0;

  for(y = 0 ; y < max_lines-1 ; ++y)
    if(print[y] == 1)
      matrix[0][y] = 1;

  for(x = 0 ; x < max_lines ; ++x){
    for(y = 0 ; y < max_lines-1 ; ++y){
      if(print[x] == 1 && print[y] == 1)
        matrix[x+1][y] = 1;
      }
    }   

  /* for(x = 0 ; x < max_lines ; ++x){
    for(y = 0 ; y < max_lines-1 ; ++y)
      fprintf(stderr, "%u\t", matrix[x][y]);
    fprintf(stderr, "\n");
    }
  fprintf(stderr, "\n"); */

  rewind(stdin);
  id_lines = 0;
  while(fgets(line, MAX_LINE, stdin)){
    char *tmp = strdup(line);
    char **fields = NULL;
    int c = Split(tmp, '\t', &fields);
    
    if(matrix[id_lines][0] == 1)
      fprintf(stdout, "%s", fields[0]);

    for(n = 1 ; n < c ; ++n){
      if(matrix[id_lines][n] == 1){
        fprintf(stdout, "\t%s", fields[n]);
        }
      }
    free(tmp);
    ++id_lines;
    }

  /* for(n = 0 ; n < max_lines ; ++n)
    fprintf(stdout, "%u ", print[n]);
  fprintf(stdout, "\n"); */

  free(print);
  return EXIT_SUCCESS;
  }
