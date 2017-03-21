#!/bin/bash
# $1 FASTA filename containning the reference
# $2 FASTQ reads
./bowtie-build $1 index_file
./bowtie index_file $2 > OUTPUT
