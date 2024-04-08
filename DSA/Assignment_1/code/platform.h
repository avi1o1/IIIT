#ifndef PLATFORM
#define PLATFORM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "post.h"

typedef struct postList {
    Post* post;
    struct postList* next; 
} postList;

typedef struct Platform {
    postList* pstList;
    Post* lastViewedPost; // Address
} Platform;

Platform* createPlatform();

bool addPost(char* user, char* cptn);
bool deletePost(int n);
Post* viewPost(int n);
Post* currPost();
Post* nextPost();
Post* previousPost();

bool addComment(char* user, char* cntnt);
bool deleteComment(int n);
commentList* viewComments();

bool addReply(char* user, char* cntnt, int n);
bool deleteReply(int n, int m);

#endif
