#!/bin/bash
################################################################################
#
# INSTALLATION OF SPADES (ASSEMBLER) (FOR OTHER, SEE MEGAHIT)
# "Assembling genomes and mini-metagenomes from highly chimeric reads"
# DOI: 10.1007/978-3-642-37195-0_13
#
################################################################################
# If you wish to compile SPAdes by yourself you will need the following libraries to be pre-installed:
#   g++ (version 4.8.2 or higher)
#   cmake (version 2.8.12 or higher)
#   zlib
#   libbz2
#
# If you meet these requirements, you can download the SPAdes source code:
#
wget http://cab.spbu.ru/files/release3.10.1/SPAdes-3.10.1.tar.gz
tar -xzf SPAdes-3.10.1.tar.gz
cd SPAdes-3.10.1
#
# and build it with the following script:
#
./spades_compile.sh
#
# SPAdes will be built in the directory ./bin. If you wish to install SPAdes into another directory, you can specify full path of destination folder by running the following command in bash or sh:
#
# PREFIX=<destination_dir> ./spades_compile.sh
#
# for example:
#
PREFIX=/usr/local ./spades_compile.sh
#
# which will install SPAdes into /usr/local/bin.
#
# After installation you will get the same files in ./bin (or <destination_dir>/bin if you specified PREFIX) directory:
#
#    spades.py (main executable script)
#    dipspades.py (main executable script for dipSPAdes)
#    metaspades.py (main executable script for metaSPAdes)
#    plasmidspades.py (main executable script for plasmidSPAdes)
#    rnaspades.py (main executable script for rnaSPAdes)
#    truspades.py (main executable script for truSPAdes)
#    hammer (read error correcting module for Illumina reads)
#    ionhammer (read error correcting module for IonTorrent reads)
#    spades (assembly module)
#    bwa-spades (BWA alignment module which is required for mismatch correction)
#    corrector (mismatch correction module)
#    dipspades (assembly module for highly polymorphic diploid genomes)
#    scaffold_correction (executable used in truSPAdes pipeline)
#
# We also suggest adding SPAdes installation directory to the PATH variable. 
#
################################################################################
