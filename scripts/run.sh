#!/bin/bash
##### PARAMETERS ###############################################################
GPARAMETERS=" -tm 1:1:0 -tm 3:1:0 -tm 5:1:0 -tm 7:1:0 -tm 9:1:0 -tm 16:20:1 "
VBASE="base"
##### DOWNLOAD COMPRESSOR ######################################################
wget https://github.com/pratas/geco/archive/master.zip
unzip master.zip
cd geco-master/src/
make
cp GeCo ../../
cd ../../
rm -fr master.zip geco-master; 
##### DOWNLOAD GOOSE ###########################################################
wget https://github.com/pratas/goose/archive/master.zip
unzip master.zip
cd goose-master/src/
make
cp Info ../../
cd ../../
rm -fr master.zip goose-master; 
##### DOWNLOAD DATA ############################################################
mkdir $VBASE
cd $VBASE
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Viruses/all.fna.tar.gz
tar -xvf all.fna.tar.gz
mv all.fna.tar.gz ..
cd ..
##### RUNNING ##################################################################
echo "running ..."
rm -f REDUNDANCY ;
rm -f ORGANISMS ;
VPATH=($(ls $VBASE));
for((p=0; p<$(echo ${#VPATH[@]}); ++p));
  do
  echo "Running ${VPATH[$p]} ...";
  rm -f $VBASE/${VPATH[$p]}/*.run $VBASE/${VPATH[$p]}/*.co ;
  VIRUS=($(ls $VBASE/${VPATH[$p]}));
  for((v=0; v<$(echo ${#VIRUS[@]}); ++v));
    do
    printf "${VPATH[$p]}\t${VIRUS[$v]}\n" >> ORGANISMS;
    cat $VBASE/${VPATH[$p]}/${VIRUS[$v]} | grep -v ">" | tr -d -c "ACGT" > \
        $VBASE/${VPATH[$p]}/${VIRUS[$v]}.run
    VSIZE=$(echo $(./Info "$VBASE/${VPATH[$p]}/${VIRUS[$v]}.run" | grep \
          "ber of symbol"| awk '{print $4;}'));
    (./GeCo -v $GPARAMETERS $VBASE/${VPATH[$p]}/${VIRUS[$v]}.run) &> \
    REPORT.run; 
    VBITS=$(echo $(cat REPORT.run | grep "Total bytes:" | awk '{ print $3;}'));
    echo "$(echo "scale=6;($VBITS*8)/($VSIZE*2)" | bc)" >> REDUNDANCY;
    done
    echo "DONE!";
  done
###############################################################################
