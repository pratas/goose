#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main(int argc, char *argv[]){
  fprintf(stderr, "\n GOOSE v%u.%u, UNIVERSITY OF AVEIRO, 2013-2016\n",
  VERSION, RELEASE);
  fprintf(stderr, " A framework for DNA analysis and manipulation\n\n");
  fprintf(stderr, " Programs:\n");
  fprintf(stderr, "   [+] goose-char2line\n");
  fprintf(stderr, "   [+] goose-extract\n");
  fprintf(stderr, "   [+] goose-fasta2seq\n");
  fprintf(stderr, "   [+] goose-fastaextract\n");
  fprintf(stderr, "   [+] goose-fastq2fasta\n");
  fprintf(stderr, "   [+] goose-fastq2mfasta\n");
  fprintf(stderr, "   [+] goose-fastqclustreads\n");
  fprintf(stderr, "   [+] goose-fastqpack\n");
  fprintf(stderr, "   [+] goose-fastqunpack\n");
  fprintf(stderr, "   [+] goose-filter\n");
  fprintf(stderr, "   [+] goose-findnpos\n");
  fprintf(stderr, "   [+] goose-genrandomdna\n");
  fprintf(stderr, "   [+] goose-info\n");
  fprintf(stderr, "   [+] goose-max\n");
  fprintf(stderr, "   [+] goose-min\n");
  fprintf(stderr, "   [+] goose-minus\n");
  fprintf(stderr, "   [+] goose-mutatedna\n");
  fprintf(stderr, "   [+] goose-mutatefasta\n");
  fprintf(stderr, "   [+] goose-mutatefastq\n");
  fprintf(stderr, "   [+] goose-period\n");
  fprintf(stderr, "   [+] goose-permuteseqbyblocks\n");
  fprintf(stderr, "   [+] goose-randfastaextrachars\n");
  fprintf(stderr, "   [+] goose-randfastqextrachars\n");
  fprintf(stderr, "   [+] goose-randseqextrachars\n");
  fprintf(stderr, "   [+] goose-reverse\n");
  fprintf(stderr, "   [+] goose-reverselm\n");
  fprintf(stderr, "   [+] goose-searchphash\n");
  fprintf(stderr, "   [+] goose-seq2fasta\n");
  fprintf(stderr, "   [+] goose-seq2fastq\n");
  fprintf(stderr, "   [+] goose-splitreads\n");
  fprintf(stderr, "   [+] goose-splitReads\n");
  fprintf(stderr, "   [+] goose-wsearch\n");
  fprintf(stderr, "\n");
  return EXIT_SUCCESS;
  }

