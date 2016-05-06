#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/mman.h>
#include "mem.h"
#include "defs.h"
#include "parser.h"
#include "buffer.h"
#include "common.h"

//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - R E F E R E N C E - - - - - - - - - - - - -

void LoadReference(char *fn){
  FILE     *F = Fopen(fn, "r");
  uint64_t nBases = 0, info[6] = {0, 0, 0, 0, 0, 0};
  char     type[3][20] = {"DNA", "FASTA", "FASTQ"};
  PARSER   *PA = CreateParser();
  uint8_t  sym, *buf;
  FileType(PA, F);
  fclose(F);
  struct   stat s;
  size_t   size, k;
  long     fd;

  if((fd = open(fn, O_RDONLY)) == -1){
    fprintf(stderr, "[x] Error: unable to open file\n");
    exit(1);
    }

  fstat(fd, &s);
  size = s.st_size;
  buf = (uint8_t *) mmap(0, size, PROT_READ, MAP_PRIVATE|MAP_POPULATE, fd, 0);
  madvise(buf, s.st_size, MADV_SEQUENTIAL);
  for(k = 0 ; k < size ; ++k){
    if(ParseSym(PA, (sym = *buf++)) == -1)
      continue; 
    info[DNASymToNum(sym)]++;
    ++nBases;
    }

  fprintf(stdout, "File type        : %s\n", type[PA->type]);
  fprintf(stdout, "Number of bases  : %"PRIu64"\n", nBases);
  fprintf(stdout, "Number of a/A    : %"PRIu64"\n", info[0]);
  fprintf(stdout, "Number of c/C    : %"PRIu64"\n", info[1]);
  fprintf(stdout, "Number of g/G    : %"PRIu64"\n", info[2]);
  fprintf(stdout, "Number of t/T    : %"PRIu64"\n", info[3]);
  fprintf(stdout, "Number of n/N    : %"PRIu64"\n", info[4]);
  fprintf(stdout, "Number of others : %"PRIu64"\n", info[5]);

  RemoveParser(PA);
  close(fd);
  }


//////////////////////////////////////////////////////////////////////////////
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - M A I N - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int32_t main(int argc, char *argv[]){
  if(argc != 2){
    fprintf(stderr, "Usage: ./goose-count <file>\n");
    fprintf(stderr, "It counts the number of bases (seq, FASTA, FASTQ)\n");
    exit(1);
    }
  LoadReference(argv[argc-1]);  
  return EXIT_SUCCESS;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
