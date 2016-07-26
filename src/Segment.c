#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

int main(int argc, char *argv[]){
  double  val, threshold;
  ULL     pos, initPosition, lastPosition;
  int     region;

  if(argc < 2){
    fprintf(stderr, "usage: %s <threshold> < inFile\n", argv[0]);
    fprintf(stderr, "It segments a filtered sequence.\n");
    exit(1);
    }
  
  threshold    = atof(argv[1]);
  initPosition = 0;
  lastPosition = 0;
  if(fscanf(stdin, "%llu\t%lf", &pos, &val) == 2)
    region = val < threshold ? 0 : 1;
  else{
    fprintf(stderr, "Error: unknown format\n");
    exit(1);
    }

  while(fscanf(stdin, "%llu\t%lf", &pos, &val) == 2){
    if(val > threshold && region == 0){
      if(lastPosition != initPosition){
        fprintf(stdout, "%llu:%llu\n", initPosition, lastPosition);
        region = 1;
        }
      }

    if(region == 1 && val < threshold){
      region = 0;
      initPosition = pos;
      }
    lastPosition = pos;
    }

  if(region == 0 && (lastPosition > (initPosition + 10)))
    fprintf(stdout, "%llu:%llu\n", initPosition, lastPosition);

  return 0;
  }
