#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include "mem.h"
#include "defs.h"
#include "labels.h"
#include "common.h"

//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - M A I N - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int32_t main(int argc, char *argv[]){
  char fname[4096];
  uint64_t nSeq, n, unique;
  uint32_t filtered;
  int sym;

  SLABELS *SL = CreateSLabels();
  // tested at: https://regex101.com/
  char *regexString = ".*\\|.*\\|.*\\|_([a-z A-Z]*_[a-z A-Z]*)";
  regex_t regexCompiled;
  regmatch_t groupArray[2];
  if(regcomp(&regexCompiled, regexString, REG_EXTENDED)){
    fprintf(stderr, "  [x] Error: regular expression compilation!\n");
    return 1;
    }

  nSeq = 0;
  unique = 0;
  filtered = 0;
  while((sym = fgetc(stdin)) != EOF){

    if(sym == '>'){

      HD:
      if(fscanf(stdin, "%s", fname) != 1){
        fprintf(stderr, "  [x] Error: unknown type of file!\n");
        exit(1);
        }

      if(regexec(&regexCompiled, fname, 2, groupArray, 0) == 0){
        char sourceCopy[strlen(fname) + 1];
        strcpy(sourceCopy, fname);
        sourceCopy[groupArray[1].rm_eo] = 0;
        if(SearchSLabels(SL, sourceCopy + groupArray[1].rm_so) == 0){
          ++unique;
          AddSLabel(SL, sourceCopy + groupArray[1].rm_so);
          UpdateSLabels(SL);
          }
        else{
          ++filtered;
          continue;
          }
        }
      ++nSeq;

      fprintf(stdout, "%s", fname);
      while(((sym = fgetc(stdin)) != EOF)){
        if(sym == '>')
          goto HD;
        fputc(sym, stdout);
        }
      }
    }

  fprintf(stderr, "Number of unique existing species: %"PRIu64".\n", unique);
  fprintf(stderr, "Unique species:\n");
  for(n = 0 ; n < SL->idx ; ++n)
    fprintf(stderr, "  [+] %s\n", SL->names[n]);
  DeleteSLabels(SL);
  
  return EXIT_SUCCESS;
  }
