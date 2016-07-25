#include "msg-cmap.h"
#include <stdio.h>
#include <stdlib.h>

void PrintMenuGVisual(void){
  fprintf(stderr,
  "Usage: ./goose-comparativemap [OPTION]... [FILE]                         \n"
  "Visualisation of comparative maps.                                       \n"
  "                                                                         \n"
  "Non-mandatory arguments:                                                 \n"
  "                                                                         \n"
  "  -h                         give this help,                             \n"
  "  -V                         display version number,                     \n"
  "  -v                         verbose mode (more information),            \n"
  "  -l <link>                  link type between maps [0;4],               \n"
  "  -w <width>                 chromosome width,                           \n"
  "  -s <space>                 space between chromosomes,                  \n"
  "  -m <mult>                  color id multiplication factor,             \n"
  "  -b <begin>                 color id beggining,                         \n"
  "  -c <minimum>               minimum block size to consider,             \n"
  "  -i                         do NOT show inversion maps,                 \n"
  "  -r                         do NOT show regular maps,                   \n"
  "  -o <FILE>                  output image filename with map,             \n"
  "                                                                         \n"
  "Mandatory arguments:                                                     \n"
  "                                                                         \n"
  "  <FILE>                     contigs filename with positions (.pos),     \n"
  "                                                                         \n");
  }

