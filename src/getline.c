#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    char *buf = *lineptr;
    size_t size = *n;
    int c = 0;
    size_t i = 0;

    if (buf == NULL || size == 0) {
        size = 128;
        buf = (char *)malloc(size);
        if (buf == NULL) {
            return -1;
        }
    }

    while ((c = fgetc(stream)) != EOF) {
        if (i >= size - 1) {
            size *= 2;
            char *newbuf = (char *)realloc(buf, size);
            if (newbuf == NULL) {
                free(buf);
                return -1;
            }
            buf = newbuf;
        }
        buf[i++] = (char)c;
        if (c == '\n') {
            break;
        }
    }

    if (i == 0) {
        return -1;
    }

    buf[i] = '\0';
    *lineptr = buf;
    *n = size;
    return i;
}
