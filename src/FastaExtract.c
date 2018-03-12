#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "defs.h"
#include "misc.h"
#include "buffer.h"

#define END  100

/*
 * This application extracts sequences from a FASTA file.
 */
int main(int argc, char *argv[])
{
  uint32_t streamSize, index;
  uint64_t counter = 0, init = 0, end = END;
  uint8_t  value, header = 1;
  BUF *Buffer;

  if(argc < 3)
  {
    fprintf(stderr, "Usage: %s -i <init> -e <end> < input.fasta >" 
    " out.seq\nIt extracts sequences from a FASTA file.\n", argv[0]);
    return EXIT_SUCCESS;
  }

  for(index = 1; index < argc; index++)
  {
    if(strcmp("-i",argv[index]) == 0)
    {
      init = atol(argv[index + 1]);
      break;
    }
  }

  for(index = 1; index < argc; index++)
  {
    if(strcmp("-e",argv[index]) == 0)
    {
      end = atol(argv[index + 1]);
      break;
    }
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

      if(init <= counter && end > counter)
        putchar(value);
      ++counter;
    }
  }

  RemoveBuffer(Buffer);
  return EXIT_SUCCESS;
}
