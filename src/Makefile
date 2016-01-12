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
PROGS  = $(BIN)/goose \
         $(BIN)/goose-extract \
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
         $(BIN)/goose-mutatefastq \
         $(BIN)/goose-mutatefasta \
         $(BIN)/goose-char2line
OBJS   = mem.o misc.o args.o hash.o alpha.o csmodel.o dna.o reads.o fcm.o \
         phash.o parser.o
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
$(BIN)/goose-char2line: Char2Line.c $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN)/goose-char2line Char2Line.c $(OBJS) $(LIBS)
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
parsero: parser.c parser.h $(DEPS)
	$(CC) -c $(CFLAGS) parser.c
clean: 
	/bin/rm -f *.o
cleanall:
	/bin/rm -f *.o $(PROGS)
#-----------------------------------------------------------------------------
