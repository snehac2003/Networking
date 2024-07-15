#pragma once
#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>

#define LOG(...)                      \
    do {                              \
        fprintf(stderr, __VA_ARGS__); \
        fprintf(stderr, "\n");        \
    } while (0);

typedef enum { GET, PUT, DELETE, LIST, V_UNKNOWN } verb;


ssize_t function_one_common(int socket, char *buffer, size_t count); 
ssize_t function_two_common(int socket, const char *buffer, size_t count);
int function_three_common(int socket, FILE* local_file, size_t file_size);
