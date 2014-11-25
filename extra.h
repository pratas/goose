#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include "defs.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

FILE        *Fopen           (const char *, const char *);
void        FillLogTable     (uint32_t, uint32_t, uint32_t);
double      SearchLog        (uint32_t );
double      Power            (double, double);
uint32_t    FLog2            (uint64_t );
uint8_t     DNASymToNum      (uint8_t  );
uint8_t     NumToDNASym      (uint8_t  );
uint8_t     GetCompNum       (uint8_t  );
uint8_t     GetCompSym       (uint8_t  );
uint64_t    NDNASyminFile    (FILE *);
uint64_t    NBytesInFile     (FILE *);
uint64_t    FopenBytesInFile (const char *);
uint8_t     *ReverseStr      (uint8_t *, uint32_t);
char        *CloneString     (char *   );
uint32_t    ArgsNumber       (uint32_t , char *[], uint32_t, char *);
double      ArgsDouble       (double, char *[], uint32_t, char *);
uint8_t     ArgsState        (uint8_t  , char *[], uint32_t, char *);
char        *ArgsString      (char    *, char *[], uint32_t, char *);
char        *ArgsFiles       (char *[], uint32_t, char *);
void        TestReadFile     (char *);
uint8_t     CmpCheckSum      (uint32_t, uint32_t);
void        FAccessWPerm     (char    *);
inline void CalcProgress     (uint64_t , uint64_t);
char        *concatenate     (char *   , char *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif
