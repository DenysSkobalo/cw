#include <stdio.h>
#include <stdlib.h>
#include "../include/buf.h"

int main() {
    size_t len = 64;
    buf_t *buf = buf_malloc(len);
    if (!buf) {
        printf("Allocation failed!\n");
        return 1;
    }
    printf("First info\n");
    buf_info(buf);
    printf("===================\n");

    push(buf, 10);
    push(buf, 20);
    push(buf, 30);

    printf("Second info\n");
    buf_info(buf);
    printf("===================\n");

    free_buf(buf);

    return 0;
}

