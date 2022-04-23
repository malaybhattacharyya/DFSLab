#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>

#define UNDEF -1
#define BUF_LEN 256
#define INFTY 1000000
#define EPS 0.0001

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef SQR
#define SQR(x) ((x) * (x))
#endif

#ifndef DURATION
#define DURATION(start, end) ((end.tv_sec - start.tv_sec)*1000000 + (end.tv_nsec - start.tv_nsec)/1000);
#endif

#ifndef _STATUS_
#define SUCCESS 0
#define FAILURE -1
#define TRUE 1
#define FALSE 0
#endif

#define ERR_MESG(x) { perror(x);  exit(-1); }
#if DEBUG
//#ifdef __GNUC__
#define dprintf(format, ...) fprintf(stderr, format, ## __VA_ARGS__)
#else
#define dprintf(format, ...)
#endif

#define Malloc(n,type) (type *) malloc( (unsigned) ((n)*sizeof(type)))
#define Realloc(loc,n,type) (type *) realloc( (char *)(loc), \
                                              (unsigned) ((n)*sizeof(type)))

#define matrix_alloc(mat,rows,cols,type) {                        \
    int ii;                                                       \
    type *temp;                                                   \
                                                                  \
    if (NULL == (temp = (type *) malloc(rows*cols*sizeof(type))) || \
        NULL == (mat = (type **) malloc(rows * sizeof(type *))))  \
        ERR_MESG("Out of memory");                                \
    for (ii = 0; ii < rows; temp += cols, ii++)                   \
        mat[ii] = temp;                                           \
  }

#define matrix_free(mat) {                      \
    free(mat[0]);                               \
    free(mat);                                  \
  }

#endif
