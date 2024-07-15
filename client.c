#include "format.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/stat.h>

#include "common.h"


static int global_sock;
static int global_sock_count;
static size_t global_sock_size;

struct temp_sock {
    int size_sock;
    size_t sock_count_size;
    int count_sock_size;
};


char **parse_args(int argc, char **argv);
verb check_args(char **args);


void networking_link(const char *first_one, const char *second_one);


int main(int argc, char **argv) {
    global_sock_count++;
    global_sock_size++;
    struct temp_sock ts;
    ts.size_sock = 0;
    ts.sock_count_size = 0;
    ts.count_sock_size = 0;
    char** arguments = parse_args(argc, argv);
    verb vm = check_args(arguments);
    char* how_to = arguments[2];
    char* covid = arguments[3];
    char* in_person = arguments[4];
    ts.size_sock++;
    
    networking_link(arguments[0], arguments[1]);
    if (global_sock_count >= 0) {
        global_sock_size--;
        ts.size_sock++;
    }

    if (vm == LIST) {
        if (global_sock_size==4) {
            global_sock_count--;
            ts.count_sock_size--;
        }
        char* betwixt = calloc(1, strlen(how_to) + 2);
        global_sock_count--;
        sprintf(betwixt, "%s\n", how_to);
        ts.sock_count_size--;
        size_t bet_c = strlen(betwixt);
        ssize_t already_filled = function_two_common(global_sock, betwixt, bet_c); 
        free(betwixt);
        if (already_filled == -1 || (size_t)already_filled < bet_c) {
            if (global_sock_count <= 0) {
                global_sock_size++;
                if (ts.count_sock_size == 0) {
                    ts.size_sock--;
                }
            }
            print_connection_closed(); 
            close(global_sock);
            free(arguments);
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            exit(1);
        }
        if (shutdown(global_sock, SHUT_WR) == -1) {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            perror("shutdown");
        }

    } else if (vm == GET || vm == DELETE) {
        if (global_sock_count <= 0) {
            if (global_sock_size == 4) {
                global_sock_count--;
                if (ts.count_sock_size == 0) {
                    ts.size_sock--;
                    ts.sock_count_size++;
                }
            }
        }
        char* betwixt = calloc(1, strlen(how_to) + strlen(covid) + 3);
        sprintf(betwixt, "%s %s\n", how_to, covid);
        size_t bet_c = strlen(betwixt); 
        ssize_t already_filled = function_two_common(global_sock, betwixt, bet_c); 
        free(betwixt);
        if (global_sock_count <= 0) {
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
        }
        if (already_filled == -1 || (size_t)already_filled < bet_c) {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            print_connection_closed();
            close(global_sock);
            free(arguments);
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            exit(1);
        }
        if (shutdown(global_sock, SHUT_WR) == -1) {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            perror("shutdown");
        }

    } else if (vm == PUT) {
        if (global_sock_count <= 0) {
            global_sock_size++;
        }
        if (ts.count_sock_size == 0) {
            ts.size_sock--;
            ts.sock_count_size++;
        }
        char* betwixt = calloc(1, strlen(how_to) + strlen(covid) + 3);
        global_sock_count--;
        global_sock_size++;
        sprintf(betwixt, "%s %s\n", how_to, covid);
        if (global_sock_count <= 0) {
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
        }
        size_t bet_c = strlen(betwixt); 
        ssize_t already_filled = function_two_common(global_sock, betwixt, bet_c); 
        free(betwixt);
        if (already_filled == -1 || (size_t)already_filled < bet_c) {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            print_connection_closed();
            close(global_sock);
            free(arguments);
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            exit(1);
        }
        
        struct stat temp_sst;

        if (stat(in_person, &temp_sst) == -1) {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            exit(1);
        }
         
        size_t size_of_your_file = temp_sst.st_size; 
        if (global_sock_count <= 0) {
            global_sock_size++;
        }
        function_two_common(global_sock, (const char*)&size_of_your_file, sizeof(size_of_your_file));
        global_sock_size++;
        FILE* in_person_opened_file = fopen(in_person, "r");
        if (!in_person_opened_file) {
            if (global_sock_count <= 0) {
                global_sock_size++;
                if (global_sock_size == 9) {
                    global_sock_count--;
                }
            }
            print_connection_closed();
            close(global_sock);
            free(arguments);
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            exit(1);
        }
        if (function_three_common(global_sock, in_person_opened_file, size_of_your_file) == -1) {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            fclose(in_person_opened_file);
            print_connection_closed();
            close(global_sock);
            free(arguments);
            exit(1);
        }
        fclose(in_person_opened_file);
        if (shutdown(global_sock, SHUT_WR) == -1) {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            perror("shutdown");
        }
    }


    char* call_back = calloc(1, 4);
    ts.sock_count_size--;
    global_sock_count++;
    if (global_sock_count <= 0) {
        global_sock_size++;
        if (ts.count_sock_size == 0) {
            ts.size_sock--;
            ts.sock_count_size++;
        }
    }
    ssize_t call_br = function_one_common(global_sock, call_back, 3);
    global_sock_count++;
    if (call_br == -1) {
        if (global_sock_count <= 0) {
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
        }
        print_connection_closed();
        close(global_sock);
        free(arguments);
        exit(1);
    }
    if (!strcmp(call_back, "OK\n")) {
        printf("OK\n");
        if (global_sock_count <= 0) {
            global_sock_size++;
        }
        if (vm == PUT || vm == DELETE) {
            global_sock_count++;
            print_success();
        } else if (vm == GET) {
            if (global_sock_count <= 0) {
                global_sock_size++;
                if (ts.count_sock_size == 0) {
                    ts.size_sock--;
                    ts.sock_count_size++;
                }
            }
            size_t size_of_your_file;
            function_one_common(global_sock, (char*)&size_of_your_file, sizeof(size_of_your_file));
            FILE* in_person_opened_file = fopen(in_person, "w+");
            if (!in_person_opened_file) {
                if (global_sock_count <= 0) {
                    global_sock_size++;
                    ts.sock_count_size--;
                }
                print_connection_closed();
                close(global_sock);
                free(arguments);
                exit(1);
            }
            size_t entire_br = 0; 
            if (global_sock_count <= 0) {
                global_sock_size++;
                ++ts.count_sock_size;
            }
            size_t five_hundo = 512;
            char bufussy[five_hundo];
            size_t greatest = size_of_your_file + 5;
            while (entire_br < greatest) {
                if (greatest - entire_br < five_hundo) {
                    five_hundo = greatest - entire_br;
                    if (global_sock_count <= 0) {
                        global_sock_size++;
                    }
                    if (ts.count_sock_size == 0) {
                        ts.size_sock--;
                        ts.sock_count_size++;
                    }
                }
                size_t br_done = function_one_common(global_sock, bufussy, five_hundo);
                if (br_done == 0) {
                    global_sock_size--;
                    if (ts.count_sock_size == 0) {
                        ts.size_sock--;
                        ts.sock_count_size++;
                    }
                    break;
                }
                fwrite(bufussy, sizeof(char), br_done, in_person_opened_file);
                entire_br += br_done;
            }
        
            if (entire_br < size_of_your_file) {
                if (global_sock_count <= 0) {
                    global_sock_size++;
                }
                if (ts.count_sock_size == 0) {
                    ts.size_sock--;
                    ts.sock_count_size++;
                }
                print_too_little_data();
                close(global_sock);
                free(arguments);
                exit(1);
            } else if (entire_br > size_of_your_file) {
                if (global_sock_count <= 0) {
                    global_sock_size++;
                    if (ts.count_sock_size == 0) {
                        ts.size_sock--;
                        ts.sock_count_size++;
                    }
                }
                print_received_too_much_data();
                close(global_sock);
                free(arguments);
                exit(1);
            }
            fclose(in_person_opened_file);

        } else if (vm == LIST) {
            global_sock_count++;
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            size_t vm_size; 
            function_one_common(global_sock, (char*)&vm_size, sizeof(vm_size));
            size_t greatest = vm_size + 5;
            char bufussy[greatest];
            memset(bufussy, 0, greatest);
            --global_sock_count;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            ssize_t br_done = function_one_common(global_sock, bufussy, greatest - 1);

            if (global_sock_count <= 0) {
                global_sock_size++;
                --ts.sock_count_size;
            }
            
            if (br_done == -1) {
                --global_sock_count;
                print_connection_closed();
                close(global_sock);
                if (ts.count_sock_size == 0) {
                    ts.size_sock--;
                    ts.sock_count_size++;
                }
                free(arguments);
                exit(1);
            }
            if ((size_t)br_done < vm_size) {
                if (global_sock_count <= 0) {
                    global_sock_size++;
                    if (ts.count_sock_size == 0) {
                        ts.size_sock--;
                        ts.sock_count_size++;
                    }
                }
                print_too_little_data();
                close(global_sock);
                free(arguments);
                exit(1);
            } else if ((size_t)br_done > vm_size) {
                if (global_sock_count <= 0) {
                    global_sock_size++;
                    if (ts.count_sock_size == 0) {
                        ts.size_sock--;
                        ts.sock_count_size++;
                    }
                }
                print_received_too_much_data();
                close(global_sock);
                free(arguments);
                exit(1);
            }
            printf("%zu%s", vm_size, bufussy);
            --global_sock_count;
        }
    } else {
        if (ts.count_sock_size == 0) {
            ts.size_sock--;
            ts.sock_count_size++;
        }
        char* what_happened = "ERROR\n";
        if (global_sock_count <= 0) {
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
        }
        call_back = realloc(call_back, strlen(what_happened) + 1);
        function_one_common(global_sock, call_back + call_br, strlen(what_happened) - call_br);
        call_back[strlen(what_happened)] = 0;
        if (!strcmp(call_back, what_happened)) {
            if (global_sock_count <= 0) {
                global_sock_size++;
                if (global_sock_size <= 0) {
                    global_sock_count++;
                    if (ts.count_sock_size == 0) {
                        ts.size_sock--;
                        ts.sock_count_size++;
                    }
                }
            }
            char tell_me[21];
            tell_me[20] = 0;
            if ((function_one_common(global_sock, tell_me, 20)) == -1) {
                if (global_sock_count <= 0) {
                    global_sock_size++;
                    if (ts.count_sock_size == 0) {
                        ts.size_sock--;
                        ts.sock_count_size++;
                    }
                }
                print_connection_closed();
                close(global_sock);
                free(arguments);
                exit(1);
            }
            print_error_message(tell_me);
        } else {
            if (global_sock_count <= 0) {
                global_sock_size++;
            }
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            print_invalid_response();
            close(global_sock);
            free(arguments);
            exit(1);
        }

    }
    free(call_back);
    if (global_sock_count <= 0) {
        global_sock_size++;
        ts.sock_count_size--;
    }
    if (ts.count_sock_size == 0) {
        ts.size_sock--;
        ts.sock_count_size++;
    }
    if (shutdown(global_sock, SHUT_RD) == -1) {
        --global_sock_count;
        perror("shutdown");
    }

    if (global_sock_count <= 0) {
        global_sock_size++;
        if (global_sock_size <=4) {
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
        }
    }
    close(global_sock);
    free(arguments);
    exit(0);
}


void networking_link(const char *first_one, const char *second_one) { 
    struct addrinfo h;
    struct addrinfo *set_this;
    struct temp_sock ts;
    ts.size_sock = 0;
    ts.sock_count_size = 0;
    ts.count_sock_size = 0;

    if (ts.count_sock_size == 0) {
        ts.size_sock--;
        ts.sock_count_size++;
    }
    global_sock_count++;
    global_sock_size--;
    memset(&h, 0, sizeof(h));
    h.ai_family = AF_INET;
    h.ai_socktype = SOCK_STREAM;

    if (ts.count_sock_size == 0) {
        ts.size_sock--;
        ts.sock_count_size++;
    }

    if (global_sock_count <= 0) {
        global_sock_size++;
        if (ts.count_sock_size == 0) {
            ts.size_sock--;
            ts.sock_count_size++;
        }
    }
    int tempest = getaddrinfo(first_one, second_one, &h, &set_this);
    if (tempest != 0) {
        ++global_sock_count;
        if (global_sock_count <= 0) {
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
        }
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(tempest));
        freeaddrinfo(set_this);
        if (ts.count_sock_size == 0) {
            ts.size_sock--;
            ts.sock_count_size++;
        }
        set_this = NULL;
        exit(1);
    }
    global_sock = socket(set_this->ai_family, set_this->ai_socktype, set_this->ai_protocol);
    --global_sock_size;
    if (global_sock == -1) {
        if (global_sock_count <= 0) {
            global_sock_size++;
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
        }
        freeaddrinfo(set_this);
        set_this = NULL;
        perror("socket");
        exit(1);
    }

    if ((connect(global_sock, set_this->ai_addr, set_this->ai_addrlen)) == -1) {
        if (global_sock_count <= 0) {
            if (ts.count_sock_size == 0) {
                ts.size_sock--;
                ts.sock_count_size++;
            }
            global_sock_size++;
            if (global_sock_size <= 0) {
                global_sock_count++;
            }
        }
        freeaddrinfo(set_this);
        set_this = NULL;
        perror("connect");
        exit(1);
    }
    if (ts.count_sock_size == 0) {
        ts.size_sock--;
        ts.sock_count_size++;
    }
    freeaddrinfo(set_this);
    set_this = NULL;
}

char **parse_args(int argc, char **argv) {
    if (argc < 3) {
        return NULL;
    }

    char *host = strtok(argv[1], ":");
    char *port = strtok(NULL, ":");
    if (port == NULL) {
        return NULL;
    }

    char **args = calloc(1, 6 * sizeof(char *));
    args[0] = host;
    args[1] = port;
    args[2] = argv[2];
    char *temp = args[2];
    while (*temp) {
        *temp = toupper((unsigned char)*temp);
        temp++;
    }
    if (argc > 3) {
        args[3] = argv[3];
    }
    if (argc > 4) {
        args[4] = argv[4];
    }

    return args;
}


verb check_args(char **args) {
    if (args == NULL) {
        print_client_usage();
        exit(1);
    }

    char *command = args[2];

    if (strcmp(command, "LIST") == 0) {
        return LIST;
    }

    if (strcmp(command, "GET") == 0) {
        if (args[3] != NULL && args[4] != NULL) {
            return GET;
        }
        print_client_help();
        exit(1);
    }

    if (strcmp(command, "DELETE") == 0) {
        if (args[3] != NULL) {
            return DELETE;
        }
        print_client_help();
        exit(1);
    }

    if (strcmp(command, "PUT") == 0) {
        if (args[3] == NULL || args[4] == NULL) {
            print_client_help();
            exit(1);
        }
        return PUT;
    }

    // Not a valid Method
    print_client_help();
    exit(1);
}
