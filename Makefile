#============================================================================#
#               GOOSE 2015-2016, IEETA/DETI, UNIVERSITY OF AVEIRO            #
#============================================================================#
BIN    = .
CC     = gcc
CPLP   = -fstrict-aliasing -ffast-math -msse2
#-----------------------------------------------------------------------------
CFLAGS = -O3 -Wall $(CPLP)
#-----------------------------------------------------------------------------
LIBS   = -lm
DEPS   = defs.h
PROGS  = $(BIN)/goose-extract \
         $(BIN)/goose-fastaextract \
         $(BIN)/goose-info \
         $(BIN)/goose-min \
         $(BIN)/goose-minus \
         $(BIN)/goose-wsearch \
         $(BIN)/goose-reverse \
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
         $(BIN)/goose-period \
	 $(BIN)/goose-genrandomdna \
         $(BIN)/goose-mutatedna \
         $(BIN)/goose-char2line
OBJS   = mem.o misc.o args.o hash.o alpha.o csmodel.o dna.o reads.o fcm.o \
         phash.o
#-----------------------------------------------------------------------------
all:
	$(MAKE) progs
progs: $(PROGS)
$(BIN)/goose-extract: extract.c $(DEPS) $(OBJS) 
	$(CC) $(CFLAGS) -o $(BIN)/goose-extract extract.c $(OBJS) $(LIBS)
$(BIN)/goose-fastaextract: FastaExtract.c $(DEPS) $(OBJS) 
	$(CC) $(CFLAGS) -o $(BIN)/goose-fastaextract FastaExtract.c $(OBJS) $(LIBS)
$(BIN)/goose-info: info.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-info info.c $(OBJS) $(LIBS)
$(BIN)/goose-min: min.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-min min.c $(OBJS) $(LIBS)
$(BIN)/goose-minus: minus.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-minus minus.c $(OBJS) $(LIBS)
$(BIN)/goose-wsearch: wsearch.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-wsearch wsearch.c $(OBJS) $(LIBS)
$(BIN)/goose-reverse: reverse.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-reverse reverse.c $(OBJS) $(LIBS)
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
$(BIN)/RandSeqExtraChars: RandSeqExtraChars.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/RandSeqExtraChars RandSeqExtraChars.c $(OBJS) $(LIBS)
$(BIN)/RandFastqExtraChars: RandFastqExtraChars.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/RandFastqExtraChars RandFastqExtraChars.c $(OBJS) $(LIBS)
$(BIN)/SearchPHash: SearchPHash.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/SearchPHash SearchPHash.c $(OBJS) $(LIBS)
$(BIN)/FindNPos: FindNPos.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/FindNPos FindNPos.c $(OBJS) $(LIBS)
$(BIN)/PermuteSeqByBlocks: PermuteSeqByBlocks.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/PermuteSeqByBlocks PermuteSeqByBlocks.c $(OBJS) $(LIBS)
$(BIN)/FastqClustReads: FastqClustReads.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/FastqClustReads FastqClustReads.c $(OBJS) $(LIBS)
$(BIN)/FastqPack: FastqPack.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/FastqPack FastqPack.c $(OBJS) $(LIBS)
$(BIN)/FastqUnpack: FastqUnpack.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/FastqUnpack FastqUnpack.c $(OBJS) $(LIBS)
$(BIN)/Period: Period.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/Period Period.c $(OBJS) $(LIBS)
$(BIN)/GenRandomDNA: GenRandomDNA.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/GenRandomDNA GenRandomDNA.c $(OBJS) $(LIBS)
$(BIN)/MutateDNA: MutateDNA.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/MutateDNA MutateDNA.c $(OBJS) $(LIBS)
$(BIN)/CharToLine: CharToLine.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/CharToLine CharToLine.c $(OBJS) $(LIBS)
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
#fhash.o: fhash.c fhash.h $(DEPS)
#	$(CC) -c $(CFLAGS) fhash.c
fcm.o: fcm.c fcm.h $(DEPS)
	$(CC) -c $(CFLAGS) fcm.c
clean: 
	/bin/rm -f *.o
cleanall:
	/bin/rm -f *.o $(PROGS)
#-----------------------------------------------------------------------------
