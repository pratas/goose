#!/bin/bash
#==============================================================================
WGETOP=" --trust-server-names -q ";
SPATH="ftp://ftp.plantbiology.msu.edu/pub/data/Eukaryotic_Projects/o_sativa";
VPATH5="annotation_dbs/pseudomolecules/version_5.0"
VER1="5";
# =============================================================================
# VERSION 5
echo "Downloading RICE V$VER1";
wget $WGETOP $SPATH/$VPATH5/chr01.dir/chr01.seq.gz  -O OS$VER1-1.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr02.dir/chr02.seq.gz  -O OS$VER1-2.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr03.dir/chr03.seq.gz  -O OS$VER1-3.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr04.dir/chr04.seq.gz  -O OS$VER1-4.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr05.dir/chr05.seq.gz  -O OS$VER1-5.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr06.dir/chr06.seq.gz  -O OS$VER1-6.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr07.dir/chr07.seq.gz  -O OS$VER1-7.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr08.dir/chr08.seq.gz  -O OS$VER1-8.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr09.dir/chr09.seq.gz  -O OS$VER1-9.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr10.dir/chr10.seq.gz -O OS$VER1-10.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr11.dir/chr11.seq.gz -O OS$VER1-11.fa.gz
wget $WGETOP $SPATH/$VPATH5/chr12.dir/chr12.seq.gz -O OS$VER1-12.fa.gz
gunzip OS$VER1-1.fa.gz
gunzip OS$VER1-2.fa.gz
gunzip OS$VER1-3.fa.gz
gunzip OS$VER1-4.fa.gz
gunzip OS$VER1-5.fa.gz
gunzip OS$VER1-6.fa.gz
gunzip OS$VER1-7.fa.gz
gunzip OS$VER1-8.fa.gz
gunzip OS$VER1-9.fa.gz
gunzip OS$VER1-10.fa.gz
gunzip OS$VER1-11.fa.gz
gunzip OS$VER1-12.fa.gz
# =============================================================================
echo "Done!"
# =============================================================================
