#include "std_lib.h"

int div(int a, int b) {
    int quotient = 0;
    while (a >= b) {
        a -= b;
        quotient++;
    }
    return quotient;
}

int mod(int a, int b) {
    while (a >= b) {
        a -= b;
    }
    return a;
}

void memcpy(byte* src, byte* dst, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

unsigned int strlen(char* str) {
    unsigned int length = 0;
    while (str[length] != 0) {
        length++;
    }
    return length;
}

bool strcmp(char* str1, char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 == *(unsigned char*)str2;
}

void strcpy(char* src, char* dst) {
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
}

void clear(byte* buf, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        buf[i] = 0;
    }
}

