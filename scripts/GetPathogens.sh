#!/bin/bash
###############################################################################
rm -fr goose/ goose-*
git clone https://github.com/pratas/goose.git
cd goose/src/
make
cp goose-* ../../
cd ../../
cp goose/scripts/*.pl .
perl DownloadArchaea.pl
perl DownloadBacteria.pl
perl DownloadFungi.pl
perl DownloadViruses.pl
cat bacteria.fa | grep -v -e "ERROR" -e "eFetchResult" -e "DOCTYPE" -e "xml version" -e "Unable to obtain" | grep -v -x ">" > bacteria.fna
mv bacteria.fna bacteria.fa
cat viruses.fa bacteria.fa archaea.fa fungi.fa | tr ' ' '_' | ./goose-extractreadbypattern complete_genome | ./goose-getunique > DB.fa
###############################################################################
