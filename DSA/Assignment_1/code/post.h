#ifndef POST
#define POST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "comment.h"

typedef struct commentList {
    Comment* comment;
    struct commentList* next;
} commentList;

typedef struct Post {
    char username[64];
    char caption[256];
    commentList* cmntList;
} Post;

Post* createPost(char* username, char* caption);

#endif
