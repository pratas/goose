#!/bin/bash
#==============================================================================
INITALS="HN";
MAX=22;
WGETOP=" --trust-server-names -q ";
ONWAY="http://cdna.eva.mpg.de/neandertal/altai/AltaiNeandertal/bam/AltaiNea.hg19_1000g.";
#------------------------------------------------------------------------------
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
      =26;
FIELDS="NIOBE_0139_A_D0B5GACXX_7_unmapped.bam"
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";
      echo "Downloaded $4 C$3 with success!";
      break;
    fi
    done
  }

echo "Downloading and filtering $INITALS sequences ...";
for((x=1 ; x <= $MAX ; ++x));
  do
  ZPATH="$ONWAY$x.dq.bam";
  downloadEach "$WGETOP" "$ZPATH" "$x" "$INITALS";
  samtools view $INITALS-X$x | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$x;
  echo "$INITALS C$x filtered!";
  done

CHR=23;
FIELD="X";
ZPATH="$ONWAY$FIELD.dq.bam";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS CX filtered";

CHR=24;
FIELD="Y";
ZPATH="$ONWAY$FIELD.dq.bam";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS CY filtered";

#===============================================================================
# UNMAPPED DATA
ONWAY2="http://cdna.eva.mpg.de/neandertal/altai/AltaiNeandertal/bam/unmapped_qualfail/";

CHR=25;FIELDS="NIOBE_0139_A_D0B5GACXX_6_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=26;FIELDS="NIOBE_0139_A_D0B5GACXX_7_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=27;FIELDS="NIOBE_0139_A_D0B5GACXX_8_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=28;FIELDS="SN928_0068_BB022WACXX_1_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=29;FIELDS="SN928_0068_BB022WACXX_2_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=30;FIELDS="SN928_0068_BB022WACXX_3_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=31;FIELDS="SN928_0068_BB022WACXX_4_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=32;FIELDS="SN928_0068_BB022WACXX_5_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=33;FIELDS="SN928_0068_BB022WACXX_6_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=34;FIELDS="SN928_0068_BB022WACXX_7_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=35;FIELDS="SN928_0068_BB022WACXX_8_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=36;FIELDS="SN928_0073_BD0J78ACXX_1_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=37;FIELDS="SN928_0073_BD0J78ACXX_2_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=38;FIELDS="SN928_0073_BD0J78ACXX_3_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=39;FIELDS="SN928_0073_BD0J78ACXX_4_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=40;FIELDS="SN928_0073_BD0J78ACXX_5_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=41;FIELDS="SN928_0073_BD0J78ACXX_6_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=42;FIELDS="SN928_0073_BD0J78ACXX_7_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=43;FIELDS="SN928_0073_BD0J78ACXX_8_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=44;FIELDS="SN7001204_0130_AC0M6HACXX_PEdi_SS_L9302_L9303_1_1_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=45;FIELDS="SN7001204_0130_AC0M6HACXX_PEdi_SS_L9302_L9303_1_2_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=46;FIELDS="SN7001204_0130_AC0M6HACXX_PEdi_SS_L9302_L9303_1_3_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=47;FIELDS="SN7001204_0130_AC0M6HACXX_PEdi_SS_L9302_L9303_1_5_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=48;FIELDS="SN7001204_0130_AC0M6HACXX_PEdi_SS_L9302_L9303_1_6_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=49;FIELDS="SN7001204_0130_AC0M6HACXX_PEdi_SS_L9302_L9303_1_7_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=50;FIELDS="SN7001204_0130_AC0M6HACXX_PEdi_SS_L9302_L9303_1_8_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=51;FIELDS="SN7001204_0131_BC0M3YACXX_PEdi_SS_L9302_L9303_2_1_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=52;FIELDS="SN7001204_0131_BC0M3YACXX_PEdi_SS_L9302_L9303_2_2_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=53;FIELDS="SN7001204_0131_BC0M3YACXX_PEdi_SS_L9302_L9303_2_3_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=54;FIELDS="SN7001204_0131_BC0M3YACXX_PEdi_SS_L9302_L9303_2_5_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=55;FIELDS="SN7001204_0131_BC0M3YACXX_PEdi_SS_L9302_L9303_2_6_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=56;FIELDS="SN7001204_0131_BC0M3YACXX_PEdi_SS_L9302_L9303_2_7_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

CHR=57;FIELDS="SN7001204_0131_BC0M3YACXX_PEdi_SS_L9302_L9303_2_8_unmapped.bam";
ZPATH="$ONWAY2$FIELDS";
downloadEach "$WGETOP" "$ZPATH" "$CHR" "$INITALS";
samtools view $INITALS-X$CHR | awk '{OFS="\t"; print ">"$1"\n"$10}' > $INITALS$CHR;
echo "$INITALS $FIELDS filtered";

#==============================================================================
