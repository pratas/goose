#============================================================================#
#               GOOSE 2013-2017, IEETA/DETI, UNIVERSITY OF AVEIRO            #
#============================================================================#
BIN    = .
CC     = gcc
CPLP   = -ffast-math -msse2 #fgnu89-inline 
#-----------------------------------------------------------------------------
CFLAGS = -O3 -Wall $(CPLP)
#-----------------------------------------------------------------------------
LIBS   = -lm
DEPS   = defs.h
DEPSXS = xsdefs.h xsinit.h
DEPSCMAP = defs-cmap.h param-cmap.h
DEPSGECO = defs-geco.h
PROGS  = $(BIN)/goose \
         $(BIN)/goose-extract \
         $(BIN)/goose-fastaextract \
         $(BIN)/goose-info \
         $(BIN)/goose-count \
         $(BIN)/goose-newlineonnewx \
         $(BIN)/goose-mfmotifcoords \
         $(BIN)/goose-min \
         $(BIN)/goose-max \
         $(BIN)/goose-minus \
         $(BIN)/goose-sum \
         $(BIN)/goose-wsearch \
         $(BIN)/goose-reverse \
         $(BIN)/goose-reverselm \
         $(BIN)/goose-filter \
         $(BIN)/goose-fastq2fasta \
         $(BIN)/goose-fastq2mfasta \
         $(BIN)/goose-fasta2seq \
         $(BIN)/goose-seq2fasta \
         $(BIN)/goose-seq2fastq \
         $(BIN)/goose-randfastaextrachars \
         $(BIN)/goose-randseqextrachars \
         $(BIN)/goose-randfastqextrachars \
         $(BIN)/goose-searchphash \
         $(BIN)/goose-findnpos \
         $(BIN)/goose-permuteseqbyblocks \
         $(BIN)/goose-fastqclustreads \
         $(BIN)/goose-fastqpack \
         $(BIN)/goose-fastqunpack \
         $(BIN)/goose-extractreadbypattern \
         $(BIN)/goose-period \
 	 $(BIN)/goose-genrandomdna \
         $(BIN)/goose-mutatedna \
         $(BIN)/goose-mutatefastq \
         $(BIN)/goose-mutatefasta \
         $(BIN)/goose-renamehumanheaders \
         $(BIN)/goose-char2line \
         $(BIN)/goose-splitreads \
         $(BIN)/goose-fastqsimulation \
         $(BIN)/goose-getunique \
         $(BIN)/goose-comparativemap \
         $(BIN)/goose-geco \
         $(BIN)/goose-gede \
         $(BIN)/goose-segment \
         $(BIN)/goose-fastainfo \
         $(BIN)/goose-real2binthreshold \
         $(BIN)/goose-reducematrixbythreshold \
         $(BIN)/goose-FastqTrimm \
         $(BIN)/goose-FastqExcludeN \
         $(BIN)/goose-FastqMaximumReadSize \
         $(BIN)/goose-FastqMinimumReadSize \
         $(BIN)/goose-FastqMinimumQualityScore \
       	 $(BIN)/goose-FastqMinimumLocalQualityScoreForward \
         $(BIN)/goose-FastqMinimumLocalQualityScoreReverse \
         $(BIN)/goose-FastqInfo \
         $(BIN)/goose-FastqSplit \
         $(BIN)/goose-ProteinToPseudoDNA \
         $(BIN)/goose-FastqExtractQualityScores \
         $(BIN)/goose-AminoAcidToGroup \
         $(BIN)/goose-SequenceToGroupSequence \
         $(BIN)/goose-BruteForceString \
         $(BIN)/goose-UpperBound \
         $(BIN)/goose-fastaextractbyread \
         $(BIN)/goose-QSInfo \
         $(BIN)/goose-QSMin \
         $(BIN)/goose-QSMax \
         $(BIN)/goose-FastqCut

OBJS     = mem.o misc.o args.o hash.o alpha.o csmodel.o dna.o reads.o fcm.o \
         phash.o parser.o xsmisc.o xsmsg.o s454.o common.o buffer.o labels.o \
         argparse.o
OBJSCMAP = common-cmap.o mem-cmap.o msg-cmap.o paint-cmap.o time-cmap.o
OBJSGECO = arith_aux-geco.o arith-geco.o bitio-geco.o buffer-geco.o \
         common-geco.o context-geco.o mem-geco.o levels-geco.o msg-geco.o
#-----------------------------------------------------------------------------
all:
	$(MAKE) progs
progs: $(PROGS)
$(BIN)/goose: goose.c $(DEPS) $(OBJS) 
	$(CC) $(CFLAGS) -o $(BIN)/goose goose.c $(OBJS) $(LIBS)
$(BIN)/goose-extract: extract.c $(DEPS) $(OBJS) 
	$(CC) $(CFLAGS) -o $(BIN)/goose-extract extract.c $(OBJS) $(LIBS)
$(BIN)/goose-fastaextract: FastaExtract.c $(DEPS) $(OBJS) 
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastaextract FastaExtract.c $(OBJS) $(LIBS)
$(BIN)/goose-fastaextractbyread: FastaExtractByRead.c $(DEPS) $(OBJS) 
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastaextractbyread FastaExtractByRead.c $(OBJS) $(LIBS)
$(BIN)/goose-info: info.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-info info.c $(OBJS) $(LIBS)
$(BIN)/goose-count: count.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-count count.c $(OBJS) $(LIBS)
$(BIN)/goose-newlineonnewx: newLine4NewValue.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-newlineonnewx newLine4NewValue.c $(OBJS) $(LIBS)
$(BIN)/goose-mfmotifcoords: ExtractMFPatternCoords.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-mfmotifcoords ExtractMFPatternCoords.c $(OBJS) $(LIBS)
$(BIN)/goose-min: min.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-min min.c $(OBJS) $(LIBS)
$(BIN)/goose-max: max.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-max max.c $(OBJS) $(LIBS)
$(BIN)/goose-minus: minus.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-minus minus.c $(OBJS) $(LIBS)
$(BIN)/goose-sum: sum.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-sum sum.c $(OBJS) $(LIBS)
$(BIN)/goose-wsearch: wsearch.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-wsearch wsearch.c $(OBJS) $(LIBS)
$(BIN)/goose-reverse: reverse.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-reverse reverse.c $(OBJS) $(LIBS)
$(BIN)/goose-reverselm: reverselm.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-reverselm reverselm.c $(OBJS) $(LIBS)
$(BIN)/goose-filter: filter.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-filter filter.c $(OBJS) $(LIBS)
$(BIN)/goose-fastq2fasta: Fastq2Fasta.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastq2fasta Fastq2Fasta.c $(OBJS) $(LIBS)
$(BIN)/goose-fastq2mfasta: Fastq2MFasta.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastq2mfasta Fastq2MFasta.c $(OBJS) $(LIBS)
$(BIN)/goose-fasta2seq: Fasta2Seq.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fasta2seq Fasta2Seq.c $(OBJS) $(LIBS)
$(BIN)/goose-seq2fasta: Seq2Fasta.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-seq2fasta Seq2Fasta.c $(OBJS) $(LIBS)
$(BIN)/goose-seq2fastq: Seq2Fastq.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-seq2fastq Seq2Fastq.c $(OBJS) $(LIBS)
$(BIN)/goose-randfastaextrachars: RandFastaExtraChars.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-randfastaextrachars RandFastaExtraChars.c $(OBJS) $(LIBS)
$(BIN)/goose-randseqextrachars: RandSeqExtraChars.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-randseqextrachars RandSeqExtraChars.c $(OBJS) $(LIBS)
$(BIN)/goose-randfastqextrachars: RandFastqExtraChars.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-randfastqextrachars RandFastqExtraChars.c $(OBJS) $(LIBS)
$(BIN)/goose-searchphash: SearchPHash.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-searchphash SearchPHash.c $(OBJS) $(LIBS)
$(BIN)/goose-findnpos: FindNPos.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-findnpos FindNPos.c $(OBJS) $(LIBS)
$(BIN)/goose-permuteseqbyblocks: PermuteSeqByBlocks.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-permuteseqbyblocks PermuteSeqByBlocks.c $(OBJS) $(LIBS)
$(BIN)/goose-fastqclustreads: FastqClustReads.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastqclustreads FastqClustReads.c $(OBJS) $(LIBS)
$(BIN)/goose-fastqpack: FastqPack.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastqpack FastqPack.c $(OBJS) $(LIBS)
$(BIN)/goose-fastqunpack: FastqUnpack.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastqunpack FastqUnpack.c $(OBJS) $(LIBS)
$(BIN)/goose-extractreadbypattern: ExtractFastaReadByIdPattern.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-extractreadbypattern ExtractFastaReadByIdPattern.c $(OBJS) $(LIBS)
$(BIN)/goose-period: Period.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-period Period.c $(OBJS) $(LIBS)
$(BIN)/goose-genrandomdna: GenRandomDNA.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-genrandomdna GenRandomDNA.c $(OBJS) $(LIBS)
$(BIN)/goose-mutatedna: MutateDNA.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-mutatedna MutateDNA.c $(OBJS) $(LIBS)
$(BIN)/goose-mutatefastq: MutateFastq.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-mutatefastq MutateFastq.c $(OBJS) $(LIBS)
$(BIN)/goose-mutatefasta: MutateFasta.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-mutatefasta MutateFasta.c $(OBJS) $(LIBS)
$(BIN)/goose-renamehumanheaders: RenameMFasta.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-renamehumanheaders RenameMFasta.c $(OBJS) $(LIBS)
$(BIN)/goose-char2line: Char2Line.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-char2line Char2Line.c $(OBJS) $(LIBS)
$(BIN)/goose-splitreads: SplitReads.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-splitreads SplitReads.c $(OBJS) $(LIBS)
$(BIN)/goose-fastqsimulation: ReadSimulator.c $(DEPSXS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastqsimulation ReadSimulator.c $(OBJS) $(LIBS)
$(BIN)/goose-getunique: GetUnique.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-getunique GetUnique.c $(OBJS) $(LIBS)
$(BIN)/goose-comparativemap: ComparativeMap.c $(DEPSCMAP) $(OBJSCMAP)
	$(CC) $(CFLAGS) -o $(BIN)/goose-comparativemap ComparativeMap.c $(OBJSCMAP) $(LIBS)
$(BIN)/goose-geco: geco.c $(DEPSGECO) $(OBJSGECO)
	$(CC) $(CFLAGS) -o $(BIN)/goose-geco geco.c $(OBJSGECO) $(LIBS)
$(BIN)/goose-gede: gede.c $(DEPSGECO) $(OBJSGECO)
	$(CC) $(CFLAGS) -o $(BIN)/goose-gede gede.c $(OBJSGECO) $(LIBS)
$(BIN)/goose-segment: Segment.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-segment Segment.c $(OBJS) $(LIBS)
$(BIN)/goose-fastainfo: FastaInfo.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastainfo FastaInfo.c $(OBJS) $(LIBS)
$(BIN)/goose-real2binthreshold: Real2BinWT.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-real2binthreshold Real2BinWT.c $(OBJS) $(LIBS)
$(BIN)/goose-reducematrixbythreshold: reduceMatrixByThreshold.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-reducematrixbythreshold reduceMatrixByThreshold.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqTrimm: FastqTrimm.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqTrimm FastqTrimm.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqExcludeN: FastqExcludeN.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqExcludeN FastqExcludeN.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqMaximumReadSize: FastqMaximumReadSize.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqMaximumReadSize FastqMaximumReadSize.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqMinimumReadSize: FastqMinimumReadSize.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqMinimumReadSize FastqMinimumReadSize.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqMinimumQualityScore: FastqMinimumQualityScore.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqMinimumQualityScore FastqMinimumQualityScore.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqMinimumLocalQualityScoreForward: FastqMinimumLocalQualityScoreForward.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqMinimumLocalQualityScoreForward FastqMinimumLocalQualityScoreForward.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqMinimumLocalQualityScoreReverse: FastqMinimumLocalQualityScoreReverse.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqMinimumLocalQualityScoreReverse FastqMinimumLocalQualityScoreReverse.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqInfo: FastqInfo.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqInfo FastqInfo.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqSplit: FastqSplit.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqSplit FastqSplit.c $(OBJS) $(LIBS)
$(BIN)/goose-ProteinToPseudoDNA: ProteinToPseudoDNA.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-ProteinToPseudoDNA ProteinToPseudoDNA.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqExtractQualityScores: FastqExtractQS.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqExtractQualityScores FastqExtractQS.c $(OBJS) $(LIBS)
$(BIN)/goose-AminoAcidToGroup: AminoAcidToGroup.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-AminoAcidToGroup AminoAcidToGroup.c $(OBJS) $(LIBS)
$(BIN)/goose-SequenceToGroupSequence: SequenceToGroupSequence.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-SequenceToGroupSequence SequenceToGroupSequence.c $(OBJS) $(LIBS)
$(BIN)/goose-BruteForceString: BruteForceString.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-BruteForceString BruteForceString.c $(OBJS) $(LIBS)
$(BIN)/goose-UpperBound: upperBound.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-UpperBound upperBound.c $(OBJS) $(LIBS)
$(BIN)/goose-QSInfo: QSInfo.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-QSInfo QSInfo.c $(OBJS) $(LIBS)
$(BIN)/goose-QSMin: QSMin.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-QSMin QSMin.c $(OBJS) $(LIBS)
$(BIN)/goose-QSMax: QSMax.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-QSMax QSMax.c $(OBJS) $(LIBS)
$(BIN)/goose-FastqCut: FastqCut.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-FastqCut FastqCut.c $(OBJS) $(LIBS)
argparse.o: argparse.c argparse.h $(DEPS)
	$(CC) -c $(CFLAGS) argparse.c
mem.o: mem.c mem.h $(DEPS)
	$(CC) -c $(CFLAGS) mem.c
misc.o: misc.c misc.h $(DEPS)
	$(CC) -c $(CFLAGS) misc.c
args.o: args.c args.h $(DEPS)
	$(CC) -c $(CFLAGS) args.c
hash.o: hash.c hash.h $(DEPS)
	$(CC) -c $(CFLAGS) hash.c
alpha.o: alpha.c alpha.h $(DEPS)
	$(CC) -c $(CFLAGS) alpha.c
csmodel.o: csmodel.c csmodel.h $(DEPS)
	$(CC) -c $(CFLAGS) csmodel.c
dna.o: dna.c dna.h $(DEPS)
	$(CC) -c $(CFLAGS) dna.c
reads.o: reads.c reads.h $(DEPS)
	$(CC) -c $(CFLAGS) reads.c
phash.o: phash.c phash.h $(DEPS)
	$(CC) -c $(CFLAGS) phash.c
fcm.o: fcm.c fcm.h $(DEPS)
	$(CC) -c $(CFLAGS) fcm.c
parser.o: parser.c parser.h $(DEPS)
	$(CC) -c $(CFLAGS) parser.c
s454.o: s454.c s454.h $(DEPSXS)
	$(CC) -c $(CFLAGS) s454.c
xsmsg.o: xsmsg.c xsmsg.h $(DEPSXS)
	$(CC) -c $(CFLAGS) xsmsg.c
xsmisc.o: xsmisc.c xsmisc.h $(DEPSXS)
	$(CC) -c $(CFLAGS) xsmisc.c
buffer.o: buffer.c buffer.h $(DEPS)
	$(CC) -c $(CFLAGS) buffer.c
labels.o: labels.c labels.h $(DEPS)
	$(CC) -c $(CFLAGS) labels.c
#
common-cmap.o: common-cmap.c common-cmap.h $(DEPSCMAP)
	$(CC) -c $(CFLAGS) common-cmap.c
mem-cmap.o: mem-cmap.c mem-cmap.h $(DEPSCMAP)
	$(CC) -c $(CFLAGS) mem-cmap.c
msg-cmap.o: msg-cmap.c msg-cmap.h $(DEPSCMAP)
	$(CC) -c $(CFLAGS) msg-cmap.c
paint-cmap.o: paint-cmap.c paint-cmap.h $(DEPSCMAP)
	$(CC) -c $(CFLAGS) paint-cmap.c
time-cmap.o: time-cmap.c time-cmap.h $(DEPSCMAP)
	$(CC) -c $(CFLAGS) time-cmap.c
#
common-geco.o: common-geco.c common-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) common-geco.c
arith_aux-geco.o: arith_aux-geco.c arith_aux-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) arith_aux-geco.c
arith-geco.o: arith-geco.c arith-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) arith-geco.c
bitio-geco.o: bitio-geco.c bitio-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) bitio-geco.c
msg-geco.o: msg-geco.c msg-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) msg-geco.c
mem-geco.o: mem-geco.c mem-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) mem-geco.c
context-geco.o: context-geco.c context-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) context-geco.c
levels-geco.o: levels-geco.c levels-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) levels-geco.c
buffer-geco.o: buffer-geco.c buffer-geco.h $(DEPSGECO)
	$(CC) -c $(CFLAGS) buffer-geco.c
##############################################################################
clean: 
	/bin/rm -f *.o
cleanall:
	/bin/rm -f *.o $(PROGS)
##############################################################################
