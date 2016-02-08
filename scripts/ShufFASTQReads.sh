#!/bin/bash
# Shuffle FASTQ Reads
# usage . ShufFASTQReads.sh file.fq > out
cat $1            | \
awk '{ printf("%s",$0); n++; if(n%4==0) { printf("\n");} else { printf("\t\t");} }' |\
shuf              | \
sed 's/\t\t/\n/g' | \
awk '{print $1}'
