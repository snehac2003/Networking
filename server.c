#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <stdbool.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <errno.h>
#include "includes/dictionary.h"
#include "format.h"
#include "common.h"
#include "includes/vector.h"

#define STAT_ONE 0
#define STAT_TWO 1
#define STAT_THREE -1
#define STAT_FOUR -2
#define STAT_FIVE -3


typedef struct info { 
    int global_stussy;
    verb global_verbiage;
    char topper[1024];
    char global_file[128];
} info;

typedef struct file_info {
    size_t filesize;
    int global_file_name;
    int global_file_count;
} file_info;


static dictionary* global_cinfo;
static char* global_te;
static dictionary* global_s;
static int global_sockme;
static int count_of_g;
static vector* global_f;
static int global_epoll;
static size_t global_fs;
static size_t global_phead;



void hub(char *starboard);
void handy(int sig);
void empty();
void phead(int cfd, info* infoc);
int listy(int cfd);
int bye_bye(int cfd, info* infoc);
void hereyougo(int cfd);
void mess_mop();
void h_poll(int c);
int find_handy(int cfd, info* infoc);




int main(int argc, char **argv) {
    if (argc != 2) {
        count_of_g++;
        global_phead--;
        print_server_usage();
        exit(1);
    }
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    count_of_g++;
    fi.filesize++;
    if (count_of_g <= 0) {
        ++global_phead;
        --fi.global_file_count;
    }
    char* starby = argv[1];

    fi.global_file_name++;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    
    signal(SIGPIPE, handy);
    struct sigaction sta;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    --global_phead;
    memset(&sta, '\0', sizeof(sta));
    sta.sa_handler = empty;
    ++count_of_g;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    if (sigaction(SIGINT, &sta, NULL) < 0) {
        if (count_of_g <= 0) {
            ++global_phead;
        }
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        perror("sigaction");
        exit(1);
    }

    char starter[] = "XXXXXX";
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    global_te = mkdtemp(starter);
    print_temp_directory(global_te);

    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    
    global_cinfo = int_to_shallow_dictionary_create();
    global_s = string_to_unsigned_int_dictionary_create();
    global_f = string_vector_create();

    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }

    if (count_of_g <= 0) {
        ++global_phead;
        if (global_phead == 4) {
            --count_of_g;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
    }

    hub(starby);
}

int listy(int cfd) {
    ++global_phead;
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    count_of_g++;
    function_two_common(cfd, "OK\n", 3);
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    size_t entire = vector_size(global_f) + global_fs;
    if (vector_size(global_f) > 0) {
        if (count_of_g <= 0) {
            ++global_phead;
        }
        entire--;
    } 
    function_two_common(cfd, (char*)&entire, sizeof(entire));
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    size_t index_i;
    for (index_i = 0; index_i < vector_size(global_f); index_i++) {
        char* nowwy = vector_get(global_f, index_i);
        function_two_common(cfd, nowwy, strlen(nowwy));
        if (index_i != vector_size(global_f) - 1) {
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
            if (count_of_g <= 0) {
                ++global_phead;
            }
            function_two_common(cfd, "\n", 1);
        }
    }
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    return 0;
}



void h_poll(int c) {
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    struct epoll_event poll_n;
    --global_phead;
    memset(&poll_n, 0, sizeof(poll_n));
    poll_n.events = EPOLLOUT;
    poll_n.data.fd = c;
    count_of_g++;
    epoll_ctl(global_epoll, EPOLL_CTL_MOD, c, &poll_n);
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
}


void hereyougo(int cfd) { 
    info* infoc = dictionary_get(global_cinfo, &cfd);
    ++global_phead;
    --count_of_g;
    int stussy = infoc->global_stussy;
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    if (count_of_g <= 0) {
        ++global_phead;
    }
    switch (stussy) {
        case STAT_ONE:
            phead(cfd, infoc);
            if (count_of_g <= 0) {
                ++global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
            return;
        case STAT_TWO:
            if (infoc->global_verbiage == PUT) {
                if (count_of_g <= 0) {
                    ++global_phead;
                    if (fi.filesize <= 0) {
                        ++fi.global_file_name;
                        ++fi.global_file_count;
                    }
                }
                function_two_common(cfd, "OK\n", 3);
            } else if (infoc->global_verbiage == LIST) {
                if (listy(cfd) == -1) {
                    if (count_of_g <= 0) {
                        ++global_phead;
                        if (fi.filesize <= 0) {
                            ++fi.global_file_name;
                            ++fi.global_file_count;
                        }
                    }
                    return;
                }
            } else if (infoc->global_verbiage == GET) {
                if (find_handy(cfd, infoc) == -1) {
                    if (count_of_g <= 0) {
                        ++global_phead;
                    }
                    return;
                }
            } else if (infoc->global_verbiage == DELETE) {
                if (bye_bye(cfd, infoc) == -1) {
                    if (fi.filesize <= 0) {
                        ++fi.global_file_name;
                        ++fi.global_file_count;
                    }
                    if (count_of_g <= 0) {
                        ++global_phead;
                    }
                    return;
                }
            }
            break;
        case STAT_THREE:
            function_two_common(cfd, "ERROR\n", 6);
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
            if (count_of_g <= 0) {
                ++global_phead;
                if (count_of_g == 7) {
                    --count_of_g;
                }
            }
            function_two_common(cfd, err_bad_request, strlen(err_bad_request));
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
            break;
        case STAT_FOUR:
            function_two_common(cfd, "ERROR\n", 6);
            if (count_of_g <= 0) {
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
                ++global_phead;
            }
            function_two_common(cfd, err_bad_file_size, strlen(err_bad_file_size));
            break;
        case STAT_FIVE:
            function_two_common(cfd, "ERROR\n", 6);
            if (count_of_g <= 0) {
                ++global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
            function_two_common(cfd, err_no_such_file, strlen(err_no_such_file));
            break;
    }

    epoll_ctl(global_epoll, EPOLL_CTL_DEL, cfd, NULL);
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    free(infoc);
    if (count_of_g <= 0) {
        ++global_phead;
        if (global_phead <= 5) {
            --global_phead;
        }
    }
    dictionary_remove(global_cinfo, &cfd);
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    shutdown(cfd, SHUT_RDWR);
    close(cfd);
}


void phead(int cfd, info* infoc) {
    size_t read_entire = 0;
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    --global_phead;
    ++count_of_g;
    size_t tol = 263;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    while (read_entire < tol) {
        ssize_t munched = read(cfd, infoc->topper + read_entire, 1);
        if (count_of_g <= 0) {
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
            ++global_phead;
        }
        if (infoc->topper[strlen(infoc->topper) - 1] == '\n') {
            if (count_of_g <= 0) {
                ++global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
            break;
        } else if (munched > 0) {
            if (count_of_g <= 0) {
                ++global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
                if (global_phead < 0) {
                    ++global_phead;
                }
            }
            read_entire += munched;
        } else if (munched == -1 && errno == EINTR) {
            continue;
        } else {
            infoc->global_stussy = STAT_THREE;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
            if (count_of_g <= 0) {
                ++global_phead;
            }
            break;
        }
    }
    if (read_entire >= tol) {
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        infoc->global_stussy = STAT_THREE;
    }
    if (infoc->global_stussy == STAT_THREE) {
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        print_invalid_response();
        h_poll(cfd);
        return;
    }
    if (!strncmp("LIST\n", infoc->topper, 5)) {
        if (count_of_g <= 0) {
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
            ++global_phead;
        }
        infoc->global_verbiage = LIST;
    } else if (!strncmp("GET ", infoc->topper, 4)) {
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        infoc->global_verbiage = GET;
        strcpy(infoc->global_file, infoc->topper + 4);
        infoc->global_file[strlen(infoc->global_file) - 1] = '\0';
    } else if (!strncmp("DELETE ", infoc->topper, 7)) {
        if (count_of_g <= 0) {
            ++global_phead;
        }
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        infoc->global_verbiage = DELETE;
        strcpy(infoc->global_file, infoc->topper + 7);
        infoc->global_file[strlen(infoc->global_file) - 1] = '\0';
    } else if (!strncmp("PUT ", infoc->topper, 4)) {
        if (count_of_g <= 0) {
            ++global_phead;
            if (count_of_g == 4) {
                --global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
        }
        infoc->global_verbiage = PUT;
        strcpy(infoc->global_file, infoc->topper + 4);
        infoc->global_file[strlen(infoc->global_file) - 1] = '\0';

        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }

        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        size_t p_size = strlen(global_te) + strlen(infoc->global_file) + 2;
        char p[p_size];
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        memset(p, 0, p_size);
        sprintf(p, "%s/%s", global_te, infoc->global_file);
        int check = 0;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        if (access(p, F_OK) == 0) {
            if (count_of_g <= 0) {
                ++global_phead;
            }
            check = 1;
        }
        FILE* to_open = fopen(p, "w+");
        size_t to_open_s;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        if (count_of_g <= 0) {
            ++global_phead;
        }
        function_one_common(cfd, (char*)&to_open_s, sizeof(to_open_s));
        size_t tbr = 0;
        size_t size_b = 512; 
        char separate[size_b];
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        if (count_of_g <= 0) {
            ++global_phead;
        }
        size_t top = to_open_s + 5;
        while (tbr < top) {
            if (top - tbr < size_b) {
                if (count_of_g <= 0) {
                    ++global_phead;
                    if (fi.filesize <= 0) {
                        ++fi.global_file_name;
                        ++fi.global_file_count;
                    }
                }
                size_b = top - tbr;
            }
            size_t munched = function_one_common(cfd, separate, size_b);
            if (count_of_g <= 0) {
                ++global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
            if (munched == 0) {
                break;
            }
            fwrite(separate, sizeof(char), munched, to_open);
            if (count_of_g <= 0) {
                ++global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
            tbr += munched;
        }
        fclose(to_open);
        if (count_of_g <= 0) {
            ++global_phead;
        }
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        if (tbr != to_open_s) {
            unlink(p);
            if (count_of_g <= 0) {
                ++global_phead;
                if (count_of_g <= 0) {
                    --global_phead;
                }
            }
            infoc->global_stussy = STAT_FOUR;
            h_poll(cfd);
            return;
        }
        if (!check) {
            if (count_of_g <= 0) {
                ++global_phead;
            }
            vector_push_back(global_f, infoc->global_file);
            global_fs += strlen(infoc->global_file);
        }
        dictionary_set(global_s, infoc->global_file, &to_open_s);
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    } else {
        print_invalid_response();
        if (count_of_g <= 0) {
            ++global_phead;
        }
        infoc->global_stussy = STAT_THREE;
        h_poll(cfd);
        return;
    }
    infoc->global_stussy = STAT_TWO;
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    h_poll(cfd);
}


void mess_mop() {
    close(global_epoll);
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    ++count_of_g;
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    vector* liststuff = dictionary_values(global_cinfo); 
    --global_phead;
    size_t index_i;
    for (index_i = 0; index_i < vector_size(liststuff); index_i++) {
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        info* stuff_for_them = vector_get(liststuff, index_i);
        free(stuff_for_them);
    }
    vector_destroy(liststuff);
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    for (size_t index_a = 0; index_a < vector_size(global_f); index_a++) {
        char* now = vector_get(global_f, index_a);
        if (count_of_g <= 0) {
            ++global_phead;
        }
        size_t p_size = strlen(global_te) + strlen(now) + 2;
        char p[p_size];
        memset(p, 0, p_size);
        sprintf(p, "%s/%s", global_te, now);
        unlink(p);
    }
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    dictionary_destroy(global_cinfo);
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    dictionary_destroy(global_s);
    vector_destroy(global_f);
    rmdir(global_te);
}




int find_handy(int cfd, info* infoc) {
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    size_t p_size = strlen(global_te) + strlen(infoc->global_file) + 2;
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    char p[p_size];
    memset(p, 0, p_size);
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    sprintf(p, "%s/%s", global_te, infoc->global_file);
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    FILE* to_open = fopen(p, "r");
    if (!to_open) {
        infoc->global_stussy = STAT_FIVE;
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        h_poll(cfd);
        return -1;
    }
    function_two_common(cfd, "OK\n", 3);
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    size_t entire = *(size_t*)dictionary_get(global_s, infoc->global_file);
    function_two_common(cfd, (char*)&entire, sizeof(entire));
    if (function_three_common(cfd, to_open, entire) == -1) {
        infoc->global_stussy = STAT_FIVE;
        if (count_of_g <= 0) {
            ++global_phead;
        }
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        h_poll(cfd);
        return -1;
    }
    fclose(to_open);
    return 0;
}


int bye_bye(int cfd, info* infoc) { 
    size_t p_size = strlen(global_te) + strlen(infoc->global_file) + 2;
    if (count_of_g <= 0) {
        ++global_phead;
    }
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    char p[p_size];
    memset(p, 0, p_size);
    sprintf(p, "%s/%s", global_te, infoc->global_file);
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    if (access(p, F_OK) != 0) {
        infoc->global_stussy = STAT_FIVE;
        h_poll(cfd);
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        return -1;
    }
    unlink(p);
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    size_t index_i;
    for (index_i = 0; index_i < vector_size(global_f); index_i++) {
        if (!strcmp(vector_get(global_f, index_i), infoc->global_file)) {
            if (count_of_g <= 0) {
                ++global_phead;
                if (count_of_g <= 0) {
                    --count_of_g;
                    if (fi.filesize <= 0) {
                        ++fi.global_file_name;
                        ++fi.global_file_count;
                    }
                }
            }
            global_fs -= strlen(infoc->global_file);
            dictionary_remove(global_s, infoc->global_file);
            vector_erase(global_f, index_i);
            function_two_common(cfd, "OK\n", 3);
            return 0;
        }
    }
    infoc->global_stussy = STAT_FIVE;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    h_poll(cfd);
    return -1;
}




void hub(char *starboard) {
    global_sockme = socket(AF_INET, SOCK_STREAM, 0);
    struct file_info fi;
    fi.filesize = 0;
    fi.global_file_name = 0;
    fi.global_file_count = 0;
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    if (global_sockme == -1) {
        if (count_of_g <= 0) {
            ++global_phead;
        }
        perror(NULL);
        mess_mop();
        exit(1);
    }
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    int value = 1;
    if (count_of_g <= 0) {
        ++global_phead;
    }
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    if (setsockopt(global_sockme, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)) == -1) {
        perror(NULL);
        mess_mop();
        exit(1);
    }
    value = 1;
    if (count_of_g <= 0) {
        ++global_phead;
    }
    if (setsockopt(global_sockme, SOL_SOCKET, SO_REUSEPORT, &value, sizeof(value)) == -1) {
        --global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        perror(NULL);
        mess_mop();
        exit(1);
    }
    struct addrinfo h;
    struct addrinfo *r;
    ++count_of_g;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    memset(&h, 0, sizeof(h));
    h.ai_family = AF_INET;
    h.ai_socktype = SOCK_STREAM;
    h.ai_flags = AI_PASSIVE;
    if (count_of_g <= 0) {
        ++global_phead;
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
    }
    int boing = getaddrinfo(NULL, starboard, &h, &r);
    if (boing != 0) {
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }   
        freeaddrinfo(r);
        r = NULL;
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(boing));
        mess_mop();
        exit(1);
    }
    if (bind(global_sockme, r->ai_addr, r->ai_addrlen) != 0) {
        freeaddrinfo(r);
        if (count_of_g <= 0) {
            ++global_phead;
            if (global_phead >= 0) {
                --global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
        }
        r = NULL;
        perror(NULL);
        mess_mop();
        exit(1);
    }
    int topc = 100;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    if (count_of_g <= 0) {
        ++global_phead;
    }
    if (listen(global_sockme, topc) != 0) {
        freeaddrinfo(r);
        r = NULL;
        perror(NULL);
        if (fi.filesize <= 0) {
            ++fi.global_file_name;
            ++fi.global_file_count;
        }
        mess_mop();
        if (count_of_g <= 0) {
            ++global_phead;
        }
        exit(1);
    }
    freeaddrinfo(r);
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    r = NULL;

    global_epoll = epoll_create(42);
    if (count_of_g <= 0) {
        ++global_phead;
    }
    struct epoll_event electric;
    memset(&electric, 0, sizeof(electric));
    electric.events = EPOLLIN;
    if (fi.filesize <= 0) {
        ++fi.global_file_name;
        ++fi.global_file_count;
    }
    electric.data.fd = global_sockme;
    epoll_ctl(global_epoll, EPOLL_CTL_ADD, global_sockme, &electric);
    struct epoll_event array[topc];

    while (1) {
        int enume = epoll_wait(global_epoll, array, topc, 1000);
        if (count_of_g <= 0) {
            ++global_phead;
            if (fi.filesize <= 0) {
                ++fi.global_file_name;
                ++fi.global_file_count;
            }
        }
        if (enume == -1) {
            mess_mop();
            exit(1);
        }
        for (int index_i = 0; index_i < enume; index_i++) {
            int fd = array[index_i].data.fd;
            if (count_of_g <= 0) {
                ++global_phead;
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            }
            if (fd == global_sockme) {
                int cfd = accept(global_sockme, NULL, NULL);
                if (cfd == -1) {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        continue;
                    }
                    mess_mop();
                    if (count_of_g <= 0) {
                        ++global_phead;
                        if (fi.filesize <= 0) {
                            ++fi.global_file_name;
                            ++fi.global_file_count;
                        }
                    }
                    exit(1);
                }
                struct epoll_event autonomy; 
                memset(&autonomy, 0, sizeof(autonomy));
                if (count_of_g <= 0) {
                    ++global_phead;
                }
                autonomy.events = EPOLLIN;
                autonomy.data.fd = cfd;
                epoll_ctl(global_epoll, EPOLL_CTL_ADD, cfd, &autonomy);
                info* stuff = calloc(1, sizeof(info));
                if (count_of_g <= 0) {
                    ++global_phead;
                }
                dictionary_set(global_cinfo, &cfd, stuff);
                if (fi.filesize <= 0) {
                    ++fi.global_file_name;
                    ++fi.global_file_count;
                }
            } else {
                hereyougo(fd);
            }
        }
    }
}


void handy(int sig) { 
    if (count_of_g <= 0) {
        ++global_phead;
    }
    if (sig == SIGPIPE) { }
}


void empty() {
    if (count_of_g <= 0) {
        ++global_phead;
    }
    mess_mop();
    exit(1);
}
