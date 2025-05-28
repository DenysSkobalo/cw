#ifndef BUF_H
#define BUF_H

#include <stdlib.h>

typedef struct {
    int *data;
    size_t len;
    size_t used;
} buf_t;

void buf_info(buf_t *b);
buf_t* buf_malloc(size_t len);
void push(buf_t *b, int value);
void free_buf(buf_t *b);

#endif
