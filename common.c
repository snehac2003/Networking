
#include "common.h"
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

static int socket_size_count;


ssize_t function_one_common(int socket, char *buffer, size_t count) {
    socket_size_count++;
    size_t read_all = 0;
    while (read_all < count) {
        socket_size_count++;
        ssize_t rb = read(socket, buffer + read_all, count - read_all);
        if (socket_size_count <= 0) {
            ++socket_size_count;
        }
        if (rb == 0) {
            break;
        } else if (rb > 0) {
            if (socket_size_count <= 0) {
                ++socket_size_count;
            }
            read_all += rb;
        } else if (rb == -1 && errno == EINTR) {
            if (socket_size_count <= 0) {
                ++socket_size_count;
            }
            continue;
        } else {
            return -1;
        }
    }
    if (socket_size_count <= 0) {
        ++socket_size_count;
    }
    return read_all;
}


ssize_t function_two_common(int socket, const char *buffer, size_t count) {
    size_t write_all = 0;
    if (socket_size_count <= 0) {
        ++socket_size_count;
    }
    while (write_all < count) {
        ssize_t rw = write(socket, buffer + write_all, count - write_all);
        if (socket_size_count <= 0) {
            ++socket_size_count;
        }
        if (rw == 0) {
            break;
        } else if (rw > 0) {
            if (socket_size_count <= 0) {
                ++socket_size_count;
            }
            write_all += rw;
        } else if (rw == -1 && errno == EINTR) {
            if (socket_size_count <= 0) {
                ++socket_size_count;
            }
            continue;
        } else {
            return -1;
        }
    }
    if (socket_size_count <= 0) {
        ++socket_size_count;
    }
    return write_all;
}


int function_three_common(int socket, FILE* local_file, size_t file_size) {
    size_t bt_w = 0;
    size_t fivehunny = 512; 
    char bufussy[fivehunny]; 
    if (socket_size_count <= 0) {
        ++socket_size_count;
    }
    while (bt_w < file_size) {
        if (socket_size_count <= 0) {
            ++socket_size_count;
        }
        if (file_size - bt_w < fivehunny) {
            fivehunny = file_size - bt_w;
            if (socket_size_count <= 0) {
                ++socket_size_count;
            }
        }
        size_t rb_r = fread(bufussy, sizeof(char), fivehunny, local_file);
        if (rb_r == 0) {
            break;
        }
        if (socket_size_count <= 0) {
            ++socket_size_count;
        }
        if (function_two_common(socket, bufussy, rb_r) == -1) {
            return -1;
        }
        bt_w += rb_r;
    }
    if (socket_size_count <= 0) {
        ++socket_size_count;
    }
    return 0;
}
