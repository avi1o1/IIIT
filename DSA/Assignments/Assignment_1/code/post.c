#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "post.h"

Post* createPost(char* username, char* caption) {
    // Allocate memory for the new post
    Post* newNode = (Post*) malloc(sizeof(Post));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Error goes brrr : Couldn't initialise Post!");
    }

    // Assign the username and caption to the post
    strcpy(newNode->caption, caption);
    strcpy(newNode->username, username);
    newNode->cmntList = NULL;

    // Return the new post
    return newNode;
}
