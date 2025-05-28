#include <stdalign.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/buf.h"

void buf_info(buf_t *b) {
    printf("Total size: %zu\n", b->len);
    printf("Used:       %zu\n", b->used);
    printf("Free:       %zu\n", b->len - b->used);
    for (size_t i = 0; i < b->used; ++i) {
        printf("buf[%zu] = %d\n", i, b->data[i]);
    }
}

buf_t* buf_malloc(size_t len) {
    buf_t *buf = malloc(sizeof(buf_t));
    if (!buf) return NULL;

    buf->data = malloc(len*sizeof(int));
    if (!buf->data) {
        free(buf);
        return NULL;
    }
    buf->len = len;
    buf->used = 0;

    return buf;
}

void push(buf_t *b, int value) {
    if (b->used >= b->len) {
        printf("Buffer is full! Cannot push more.\n");
        return;
    }
    b->data[b->used++] = value;
}

void free_buf(buf_t *b) {
    free(b->data);
    free(b);
}

