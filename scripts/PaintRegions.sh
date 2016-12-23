#!/bin/bash
#
# USAGE: . PaintRegions.sh CACAGAGTTTAACCTTTCTTTTCATAGAGCAGTTAGGAAACA
#
#==============================================================================
GET_GOOSE=0;
GET_CHESTER=0;
GET_GECO=0;
DWD_SEQS=0;
RUN_GECO=0;
FILTER=1;
PAINT=1;
#==============================================================================
# GET GOOSE
if [[ "$GET_GOOSE" -eq "1" ]]; then
  rm -fr goose*
  git clone https://github.com/pratas/goose.git
  cd goose/src/
  make
  cp goose-* ../../
  cd ../../
fi
#==============================================================================
# GET CHESTER
if [[ "$GET_CHESTER" -eq "1" ]]; then
  rm -fr chester*
  git clone https://github.com/pratas/chester.git
  cd chester/src/
  cmake .
  make
  cp CHESTER-filter ../../
  cp CHESTER-visual ../../
  cd ../../
fi
#==============================================================================
# GET GECO
if [[ "$GET_GECO" -eq "1" ]]; then
  rm -fr geco*
  git clone https://github.com/pratas/geco.git
  cd geco/src/
  cmake .
  make
  cp GeCo ../../
  cd ../../
fi
#==============================================================================
# DOWNLOAD SEQUENCES
if [[ "$DWD_SEQS" -eq "1" ]]; then
  rm -f hs_ref_GRCh38.p7_chr1.fa.gz hs_ref_GRCh38.p7_chr1.fa
  NCBIC="ftp://ftp.ncbi.nlm.nih.gov/genomes/H_sapiens/Assembled_chromosomes";
  echo "$1" > REFERENCE;
  wget $NCBIC/seq/hs_ref_GRCh38.p7_chr1.fa.gz
  gunzip hs_ref_GRCh38.p7_chr1.fa.gz
  cat hs_ref_GRCh38.p7_chr1.fa | grep -v ">" | tr -d -c "ACGTN" \
  | ./goose-randseqextrachars > TARGET;
fi
#==============================================================================
# RUN_GECO
if [[ "$RUN_GECO" -eq "1" ]]; then
  ./GeCo -v -e -c 5 -rm 18:100:1:0/0 -r REFERENCE TARGET;
fi
#==============================================================================
# FILTER
if [[ "$FILTER" -eq "1" ]]; then
  ./goose-real2binthreshold 1.5 < TARGET.iae > TARGET.bin
  ./CHESTER-filter -v -t 0.9 TARGET.bin
fi
#==============================================================================
# PAINT
if [[ "$PAINT" -eq "1" ]]; then
  ./CHESTER-visual -e 1 TARGET.bin.seg
fi
#==============================================================================
