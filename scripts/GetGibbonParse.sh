#!/bin/bash
#=============================================================================
INITALS="GB";
MAX=26;
WGETOP=" --trust-server-names -q ";
ONWAY="ftp://ftp.ncbi.nlm.nih.gov/genomes/Nomascus_leucogenys/Assembled_chromosomes/seq/nle_ref_Nleu_3.0_chr"
#-----------------------------------------------------------------------------
function downloadEach
  {
  PATTERN="unexpected";
  for((;;)); 
    do
    sleep 2;
    xtmp="`wget $1 $2 -O $4-X$3`"
    if [[ "$xtmp" == *"$PATTERN"* ]];  
      then
      echo "Unexpected EOF found, re-downloading C$3 ...";
      continue;
    else
      echo "wget stderr:$xtmp";
      echo "Downloaded $4 C$3 with success!";
      break;
    fi
    done
  }

echo "Downloading and filtering $INITALS sequences ..."
for((x=1 ; x <= $MAX ; ++x)); 
  do
  if [ $x -ne "1" ] && [ $x -eq "7" ] && [ $x -eq "22" ] ;
    then
    ZPATH="$ONWAY$x.fa.gz";
    downloadEach "$WGETOP" "$ZPATH" "$x" "$INITALS";
    zcat $INITALS-X$x > $INITALS$x;
    echo "$INITALS C$x filtered!";
  fi
  done

ZPATH=$ONWAY"1a.fa.gz";
downloadEach "$WGETOP" "$ZPATH" "1a" "$INITALS";
zcat $INITALS-X1a > $INITALS"1";
echo "$INITALS C1a filtered";

ZPATH=$ONWAY"7b.fa.gz";
downloadEach "$WGETOP" "$ZPATH" "7b" "$INITALS";
zcat $INITALS-X7b > $INITALS"7";
echo "$INITALS C7b filtered";

ZPATH=$ONWAY"22a.fa.gz";
downloadEach "$WGETOP" "$ZPATH" "22a" "$INITALS";
zcat $INITALS-X22a > $INITALS"22";
echo "$INITALS C22a filtered";

CHR=26;
FIELD="X";
ZPATH="$ONWAY$FIELD.fa.gz";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
zcat $INITALS-X$CHR > $INITALS$CHR;
echo "$INITALS CX filtered";

CHR=27;
downloadEach "$WGETOP" "ftp://ftp.ncbi.nlm.nih.gov/genomes/Nomascus_leucogenys/Assembled_chromosomes/seq/nle_ref_Nleu_3.0_unplaced.fa.gz" "$CHR" "$INITALS";
zcat $INITALS-X$CHR > $INITALS$CHR;
echo "$INITALS UNPLACED filtered";

CHR=28;
downloadEach "$WGETOP" "ftp://ftp.ncbi.nlm.nih.gov/genomes/Nomascus_leucogenys/Assembled_chromosomes/seq/nle_ref_Nleu_3.0_unlocalized.fa.gz" "$CHR" "$INITALS";
zcat $INITALS-X$CHR > $INITALS$CHR;
echo "$INITALS UNLOCALIZED filtered";

rm -f *GB-*;
cat GB* > XERT;
mv XERT GB;
echo "Done!"

