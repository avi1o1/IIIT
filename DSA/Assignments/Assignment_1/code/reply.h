#ifndef REPLY
#define REPLY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Reply {
    char username[64];
    char content[256];
} Reply;

Reply* createReply(char* username, char* content);

#endif
