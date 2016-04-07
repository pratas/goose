#!/bin/bash
#=============================================================================
WGETOP=" --trust-server-names -q ";
#-----------------------------------------------------------------------------
echo "Downloading and filtering HS C12 sequences ..."
wget "$WGETOP" "ftp://ftp.ncbi.nlm.nih.gov/genomes/Homo_sapiens/Assembled_chromosomes/seq/hs_ref_GRCh38.p2_chr12.fa.gz" -O C12.fa.gz;
zcat C12.fa.gz | grep -v ">" | tr -d -c "ACGTN" > C12
echo "Done!";
#-----------------------------------------------------------------------------
echo "Downloading and filtering HS C12 sequences ..."
wget "$WGETOP" "ftp://ftp.ncbi.nlm.nih.gov/genomes/Homo_sapiens/Assembled_chromosomes/seq/hs_ref_GRCh38.p2_chr18.fa.gz" -O C18.fa.gz;
zcat C18.fa.gz | grep -v ">" | tr -d -c "ACGTN" > C18
echo "Done!";
#=============================================================================
