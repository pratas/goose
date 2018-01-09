#!/bin/bash
#=============================================================================
INITALS="AN";
MAX=20;
WGETOP=" --trust-server-names -q ";
ONWAY="ftp://ftp.ncbi.nlm.nih.gov/genomes/Papio_anubis/Assembled_chromosomes/seq/pan_ref_Panu_3.0_chr"
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
  ZPATH="$ONWAY$x.fa.gz";
  downloadEach "$WGETOP" "$ZPATH" "$x" "$INITALS";
  zcat $INITALS-X$x > $INITALS$x;
  echo "$INITALS C$x filtered!";
  done

CHR=21;
FIELD="X";
ZPATH="$ONWAY$FIELD.fa.gz";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
zcat $INITALS-X$CHR > $INITALS$CHR;
echo "$INITALS CX filtered";

CHR=22;
downloadEach "$WGETOP" "ftp://ftp.ncbi.nlm.nih.gov/genomes/Papio_anubis/Assembled_chromosomes/seq/pan_ref_Panu_3.0_unplaced.fa.gz" "$CHR" "$INITALS";
zcat $INITALS-X$CHR > $INITALS$CHR;
echo "$INITALS UNPLACED filtered";

rm -f *AN-*;
cat AN* > XERT;
mv XERT AN;
echo "Done!"

