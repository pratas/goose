#!/bin/bash
WGETOP=" --trust-server-names -q ";
function downloadEach
  {
  PATTERN="unexpected";
  while :
    do
    sleep 2;
    xtmp="`wget $1 $2 -O $3`";
    if [[ "$xtmp" == *"$PATTERN"* ]];
      then
      echo "Unexpected EOF found, re-downloading ...";
      continue;
    else
      echo "wget stderr:$xtmp";
      echo "Downloaded $3 with success!";
      break;
    fi
    done
  }
echo "Starting Donwloads ...";
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101001/duck.scafSeq.gapFilled.noMito" "B1"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101002/Egretta_garzetta.fa.gz" "B2"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101003/Nipponia_nippon.fa.gz" "B3"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101004/Calypte_anna.fa.gz" "B4"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101005/Chaetura_pelagica.fa.gz" "B5"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101006/peregrine.FG.2011.0223_sca.bk.fa" "B6"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101007/Charadrius_vociferus.fa.gz" "B7"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101008/Corvus_brachyrhynchos.fa.gz" "B8"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101009/Cuculus_canorus.fa.gz" "B9"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101010/Manacus_vitellinus.fa.gz" "B10"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101011/Opisthocomus_hoazin.fa.gz" "B11"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101012/Picoides_pubescens.fa.gz" "B12"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101013/Struthio_camelus.20130116.OM.fa.gz" "B13"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101014/Tinamus_guttatus.fa.gz" "B14"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101015/Acanthisitta_chloris.fa.gz" "B15"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101016/Apaloderma_vittatum.fa.gz" "B16"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101017/Balearica_regulorum.fa.gz" "B17"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101018/Buceros_rhinoceros.fa.gz" "B18"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101019/Antrostomus_carolinensis.fa.gz" "B19"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101020/Cariama_cristata.fa.gz" "B20"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101021/Cathartes_aura.fa.gz" "B21"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101022/Chlamydotis_macqueenii.fa.gz" "B22"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101023/Colius_striatus.fa.gz" "B23"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101024/Eurypyga_helias.fa.gz" "B24"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101025/Fulmarus_glacialis.fa.gz" "B25"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101026/Gavia_stellata.fa.gz" "B26"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101027/Haliaeetus_albicilla.fa.gz" "B27"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101028/Leptosomus_discolor.fa.gz" "B28"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101029/Merops_nubicus.fa.gz" "B29"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101030/Mesitornis_unicolor.fa.gz" "B30"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101031/Nestor_notabilis.fa.gz" "B31"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101032/Pelecanus_crispus.fa.gz" "B32"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101033/Phaethon_lepturus.fa.gz" "B33"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101034/Phalacrocorax_carbo.fa.gz" "B34"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101035/Phoenicopterus_ruber.fa.gz" "B35"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101036/Podiceps_cristatus.fa.gz" "B36"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101037/Pterocles_gutturalis.fa.gz" "B37"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101038/Tauraco_erythrolophus.fa.gz" "B38"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101039/Tyto_alba.fa.gz" "B39"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/101001_102000/101040/Haliaeetus_leucocephalus.fa.gz" "B40"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/100001_101000/100005/phylogeny_study_update/Aptenodytes_forsteri.fa.gz" "B41"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/100001_101000/100006/phylogeny_study_update/Pygoscelis_adeliae.fa.gz" "B42"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/100001_101000/100059/phylogeny_study_update/Melopsittacus_undulatus.fa.gz" "B43"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/100001_101000/100007/phylogeny_study_update/Columba_livia.fa.gz" "B44"
downloadEach "$WGETOP" "ftp://climb.genomics.cn/pub/10.5524/100001_101000/100040/Geospiza_fortis.scaf.noBacterial.fa.gz" "B45"
#
### #Gallus gallus      PRJNA13342      SRA030184       SRP005856       NA      B46
### GALLUS GALLUS COVERAGE 12x (NOT 7x)
for((x=1 ; x<33 ; ++x));
  do
  wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Gallus_gallus/Assembled_chromosomes/seq/gga_ref_Gallus_gallus-4.0_chr$x.fa.gz -O TMP$x
  done
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Gallus_gallus/Assembled_chromosomes/seq/gga_ref_Gallus_gallus-4.0_chrZ.fa.gz -O TMP33
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Gallus_gallus/Assembled_chromosomes/seq/gga_ref_Gallus_gallus-4.0_chrW.fa.gz -O TMP34
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Gallus_gallus/Assembled_chromosomes/seq/gga_ref_Gallus_gallus-4.0_unlocalized.fa.gz -O TMP35
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Gallus_gallus/Assembled_chromosomes/seq/gga_ref_Gallus_gallus-4.0_unplaced.fa.gz -O TMP36
rm -f FB46;
for((x=1 ; x<37 ; ++x));
  do
  zcat TMP$x >> FB46;
  done
rm -f TMP*;
#
### #Meleagris gallopavo        PRJNA42129      Unknown Unknown NA      B47
### MELEAGRIS GALLOPAVO COVERAGE ?
for((x=1 ; x<31 ; ++x));
  do
  wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Meleagris_gallopavo/Assembled_chromosomes/seq/mga_ref_Turkey_5.0_chr$x.fa.gz -O TMP$x
  done
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Meleagris_gallopavo/Assembled_chromosomes/seq/mga_ref_Turkey_5.0_chrZ.fa.gz -O TMP31
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Meleagris_gallopavo/Assembled_chromosomes/seq/mga_ref_Turkey_5.0_chrW.fa.gz -O TMP32
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Meleagris_gallopavo/Assembled_chromosomes/seq/mga_ref_Turkey_5.0_unlocalized.fa.gz -O TMP33
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Meleagris_gallopavo/Assembled_chromosomes/seq/mga_ref_Turkey_5.0_unplaced.fa.gz -O TMP34
rm -f FB47;
for((x=1 ; x<35 ; ++x));
  do
  zcat TMP$x >> FB47;
  done
rm -f TMP*;
#
# guttata               PRJNA17289      SRA010067       SRP001389       NA      B48
for((x=1 ; x<29 ; ++x));
  do
  wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Taeniopygia_guttata/Assembled_chromosomes/seq/tgu_ref_Taeniopygia_guttata-3.2.4_chr$x.fa.gz -O TMP$x
  done
# 1A and 1B
# 4 and 4A
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Taeniopygia_guttata/Assembled_chromosomes/seq/tgu_ref_Taeniopygia_guttata-3.2.4_chr1A.fa.gz -O TMP101A
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Taeniopygia_guttata/Assembled_chromosomes/seq/tgu_ref_Taeniopygia_guttata-3.2.4_chr1B.fa.gz -O TMP101B
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Taeniopygia_guttata/Assembled_chromosomes/seq/tgu_ref_Taeniopygia_guttata-3.2.4_chr4A.fa.gz -O TMP104A
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Taeniopygia_guttata/Assembled_chromosomes/seq/tgu_ref_Taeniopygia_guttata-3.2.4_chrZ.fa.gz -O TMP29
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Taeniopygia_guttata/Assembled_chromosomes/seq/tgu_ref_Taeniopygia_guttata-3.2.4_unlocalized.fa.gz -O TMP30
wget ftp://ftp.ncbi.nlm.nih.gov/genomes/Taeniopygia_guttata/Assembled_chromosomes/seq/tgu_ref_Taeniopygia_guttata-3.2.4_unplaced.fa.gz -O TMP31
rm -f FB48;
zcat TMP101A >> FB48;
zcat TMP101B >> FB48;
zcat TMP104A >> FB48;
for((x=1 ; x<32 ; ++x));
  do
  zcat TMP$x >> FB48;
  done
rm -f TMP*;
###
### REMOVE HEADERS
for((x=1; x<49 ; ++x));
  do
  zcat B$x > FB$x.fa;
  rm -f FB;
  done
#
