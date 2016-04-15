#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <unistd.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define VERSION 1
#define RELEASE 1

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

uint32_t garbage;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// SYSTEM VALUES:
//
#define BUFFER_SIZE            65535
#define BUFFER_SIZE_WS         512
#define MAX_ALPHABET           256
#define PROGRESS_MIN           1000000
#define DEFAULT_HELP           0
#define DEFAULT_VERBOSE        0
#define DEFAULT_IR             0
#define DEFAULT_CTX            13
#define BGUARD                 32
#define DEFAULT_MAX_COUNT      ((1 << (sizeof(ACCounter) * 8)) - 1)
#define MX_PMODEL              65535
#define ALPHABET_SIZE          4
#define MATCH_SYMBOL           48 //88
#define UNIQUE_SYMBOL          49 //45
#define N_SYMBOL               78 //'N'
#define NO_MATCH_REGION        0             
#define MATCHED_REGION         1               
#define DEFAULT_SUBSAMPLE      -1
#define DEFAULT_SAMPLE_RATIO   50000 // 10000

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

