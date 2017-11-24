#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main(int argc, char *argv[]){
  fprintf(stdout, "\n  GOOSE TOOLKIT v%u.%u, UNIVERSITY OF AVEIRO, 2013-2018\n",
  VERSION, RELEASE);
  fprintf(stdout, "  A toolkit for DNA sequences analysis and manipulation\n\n");
  fprintf(stdout, "  Sub-programs:\n\n");
  fprintf(stdout, 
  "  goose-AminoAcidToGroup\n"
  "  goose-char2line\n"
  "  goose-comparativemap\n"
  "  goose-count\n"
  "  goose-extract\n"
  "  goose-extractreadbypattern\n"
  "  goose-fasta2seq\n"
  "  goose-fastaextract\n"
  "  goose-fastainfo\n"
  "  goose-fastq2fasta\n"
  "  goose-fastq2mfasta\n"
  "  goose-fastqclustreads\n"
  "  goose-FastqExcludeN\n"
  "  goose-FastqExtractQualityScores\n"
  "  goose-FastqInfo\n"
  "  goose-FastqMaximumReadSize\n"
  "  goose-FastqMinimumLocalQualityScoreForward\n"
  "  goose-FastqMinimumLocalQualityScoreReverse\n"
  "  goose-FastqMinimumQualityScore\n"
  "  goose-FastqMinimumReadSize\n"
  "  goose-fastqpack\n"
  "  goose-fastqsimulation\n"
  "  goose-FastqSplit\n"
  "  goose-FastqTrimm\n"
  "  goose-fastqunpack\n"
  "  goose-filter\n"
  "  goose-findnpos\n"
  "  goose-geco\n"
  "  goose-gede\n"
  "  goose-genrandomdna\n"
  "  goose-getunique\n"
  "  goose-info\n"
  "  goose-max\n"
  "  goose-mfmotifcoords\n"
  "  goose-min\n"
  "  goose-minus\n"
  "  goose-mutatedna\n"
  "  goose-mutatefasta\n"
  "  goose-mutatefastq\n"
  "  goose-newlineonnewx\n"
  "  goose-period\n"
  "  goose-permuteseqbyblocks\n"
  "  goose-ProteinToPseudoDNA\n"
  "  goose-randfastaextrachars\n"
  "  goose-randfastqextrachars\n"
  "  goose-randseqextrachars\n"
  "  goose-real2binthreshold\n"
  "  goose-reducematrixbythreshold\n"
  "  goose-renamehumanheaders\n"
  "  goose-reverse\n"
  "  goose-reverselm\n"
  "  goose-searchphash\n"
  "  goose-segment\n"
  "  goose-seq2fasta\n"
  "  goose-seq2fastq\n"
  "  goose-splitreads\n"
  "  goose-sum\n"
  "  goose-wsearch\n");
  fprintf(stdout, "\n");
  return EXIT_SUCCESS;
  }

