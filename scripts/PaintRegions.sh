#!/bin/bash
#
# USAGE: . PaintRegions.sh CACAGAGTTTAACCTTTCTTTTCATAGAGCAGTTAGGAAACA
#
#==============================================================================
GET_GOOSE=1;
GET_CHESTER=1;
GET_GECO=1;
DWD_SEQS=1;
RUN_GECO=1;
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
  NCBIC="ftp://ftp.ncbi.nlm.nih.gov/genomes/H_sapiens/Assembled_chromosomes";
  echo "$1" > REFERENCE;
  wget $NCBIC/seq/hs_ref_GRCh38.p7_chr1.fa.gz
  gunzip hs_ref_GRCh38.p7_chr1.fa.gz
  cat hs_ref_GRCh38.p7_chr1.fa | grep -v ">" | tr -d -c "ACGTN" > TARGET;
fi
#==============================================================================
# RUN_GECO
if [[ "$RUN_GECO" -eq "1" ]]; then
  ./GeCo -e -c 5 -rm 18:100:1:0/0 -r REFERENCE TARGET;
fi
#==============================================================================
# FILTER
if [[ "$FILTER" -eq "1" ]]; then
  ./CHESTER-filter -v -t 1.5 TARGET.iae
fi
#==============================================================================
# PAINT
if [[ "$PAINT" -eq "1" ]]; then
  #
  #
fi
#==============================================================================
