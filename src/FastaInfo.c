#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

/*
 * This application shows the readed information of a FASTA or Multi-FASTA file format.
 */
int main(int argc, char *argv[])
{
  uint32_t streamSize, index;
  uint8_t  value, header = 1;
  BUF *Buffer;

  if(argc != 1)
  {
    fprintf(stderr, "Usage: %s < input.fasta > output\n"
    "It shows read information of a FASTA or Multi-FASTA file format.\n", argv[0]);
    return EXIT_SUCCESS;
  }

  Buffer = CreateBuffer(BUF_SIZE);

  uint64_t min_number_bases = UINT_MAX, max_number_bases = 0, reads_counter = 0,
           cumulative_number_bases = 0, bases_in_current_read = 0;

  while((streamSize = fread(Buffer->buf, 1, Buffer->size, stdin)))
  {
    for(index = 0 ; index < streamSize ; ++index)
    {
      value = Buffer->buf[index];
      if(value == '>')
      { 
        header = 1; 
        if(bases_in_current_read != 0)
        {
          cumulative_number_bases += bases_in_current_read;
          if(bases_in_current_read > max_number_bases) max_number_bases = bases_in_current_read;        
          if(bases_in_current_read < min_number_bases) min_number_bases = bases_in_current_read;        
        }
        ++reads_counter;
        bases_in_current_read = 0;
        continue; 
      }

      if(value == '\n' && header == 1){ header = 0; continue; }
      if(value == '\n') continue;
      if(header == 1) continue;
      if(value < 65 || value > 122) continue;

      ++bases_in_current_read;
    }
  }

  //To consider the last read
  if(value != '>') 
  {
    cumulative_number_bases += bases_in_current_read;
    if(bases_in_current_read > max_number_bases) max_number_bases = bases_in_current_read;        
    if(bases_in_current_read < min_number_bases) min_number_bases = bases_in_current_read; 
  }

  fprintf(stdout, "Number of reads      : %"PRIu64"\n", reads_counter);
  fprintf(stdout, "Number of bases      : %"PRIu64"\n", cumulative_number_bases);
  fprintf(stdout, "MIN of bases in read : %"PRIu64"\n", min_number_bases);
  fprintf(stdout, "MAX of bases in read : %"PRIu64"\n", max_number_bases);
  fprintf(stdout, "AVG of bases in read : %.4lf\n", (double) cumulative_number_bases / 
  reads_counter);

  RemoveBuffer(Buffer); 
  return EXIT_SUCCESS;
}

