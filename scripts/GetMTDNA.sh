#!/bin/bash
wget ftp://ftp.ncbi.nlm.nih.gov/refseq/release/mitochondrion/mitochondrion.1.1.genomic.fna.gz
gunzip mitochondrion.1.1.genomic.fna.gz
mv mitochondrion.1.1.genomic.fna MITO.fna
