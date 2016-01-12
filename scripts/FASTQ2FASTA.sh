#!/bin/bash
echo "WARNING: NOTICE THIS DOES NOT ASSEMBLE THE SEQUENCE...";
cat $1 | awk 'BEGIN {X=0} {if(X++%4==1) print $0;}' > TMP-F2F;
echo "> SEQ" > OUT.fasta ; cat TMP-F2F >> OUT.fasta;
rm -f TMP-F2F;
echo "CREATED OUT.FASTA WITH SUCCESS!";
