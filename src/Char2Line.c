#include <stdio.h>

int main(void){
  char c;
  while((c = fgetc(stdin)) != EOF)
    fprintf(stdout, "%c\n", c);
  return 0;
  }
