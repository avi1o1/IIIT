#ifndef COMMENT
#define COMMENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "reply.h"

typedef struct replyList {
    Reply* reply;
    struct replyList* next;
} replyList;

typedef struct Comment {
    char username[64];
    char content[256];
    replyList* rplyList;
} Comment;

Comment* createComment(char* username, char* content);

#endif
