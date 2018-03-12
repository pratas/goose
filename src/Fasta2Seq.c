#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "misc.h"
#include "mem.h"
#include "buffer.h"

/*
 * This application converts a FASTA or Multi-FASTA file format to a seq.
 */
int main(int argc, char *argv[])
{
  uint32_t streamSize, index;
  uint8_t  value, header = 1;
  BUF *Buffer;

  if(argc != 1)
  {
    fprintf(stderr, "Usage: %s < input.fasta > output.seq\n"
    "It converts a FASTA or Multi-FASTA file format to a seq.\n", argv[0]);
    return EXIT_SUCCESS;
  }

  Buffer = CreateBuffer(BUF_SIZE);

  while((streamSize = fread(Buffer->buf, 1, Buffer->size, stdin)))
  {
    for(index = 0 ; index < streamSize ; ++index)
    {
      value = Buffer->buf[index];
      if(value == '>'){ header = 1; continue; }
      if(value == '\n' && header == 1){ header = 0; continue; }
      if(value == '\n') continue;
      if(header == 1) continue;
      if(value < 65 || value > 122) continue;
      putchar(value);
    }
  }

  RemoveBuffer(Buffer); 
  return EXIT_SUCCESS;
}

