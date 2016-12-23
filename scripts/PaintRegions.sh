#!/bin/bash
#
# USAGE: . PaintRegions.sh CACAGAGTTTAACCTTTCTTTTCATAGAGCAGTTAGGAAACA
#
#==============================================================================
echo "$1" > REFERENCE;
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
  rm -f hs_ref_GRCh38.p7_chr1.fa.gz hs_ref_GRCh38.p7_chr1.fa
  NCBIC="ftp://ftp.ncbi.nlm.nih.gov/genomes/H_sapiens/Assembled_chromosomes";
  wget $NCBIC/seq/hs_ref_GRCh38.p7_chr1.fa.gz
  gunzip hs_ref_GRCh38.p7_chr1.fa.gz
  cat hs_ref_GRCh38.p7_chr1.fa | grep -v ">" | tr -d -c "ACGTN" \
  | ./goose-randseqextrachars > TARGET;
fi
#==============================================================================
# RUN_GECO
if [[ "$RUN_GECO" -eq "1" ]]; then
  ./GeCo -v -c 5 -e -rm 18:500:1:3/50 -r REFERENCE TARGET;
fi
#==============================================================================
# FILTER
if [[ "$FILTER" -eq "1" ]]; then
  ./goose-real2binthreshold 1.5 < TARGET.iae | tr -d -c "01" > TARGET.bin
  ./CHESTER-filter -v -w 10 -u 5 -t 0.5 TARGET.bin
fi
#==============================================================================
# PAINT
if [[ "$PAINT" -eq "1" ]]; then
  ./CHESTER-visual -e 50000 TARGET.bin.seg
fi
#==============================================================================
