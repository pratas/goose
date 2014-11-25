#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void     *Malloc     (size_t);
void     *Calloc     (size_t, size_t);
void     *Realloc    (void *, size_t);
void     Free        (void *, size_t);
size_t   TotalMem    (void);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif

