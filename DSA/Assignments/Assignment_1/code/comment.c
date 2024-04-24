#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "comment.h"

Comment* createComment(char* username, char* content) {
    // Allocate memory for the new comment
    Comment* newNode = (Comment*) malloc(sizeof(Comment));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Error goes brrr : Couldn't initialise Post!");
    }

    // Assign the username and content to the comment
    strcpy(newNode->username, username);
    strcpy(newNode->content, content);
    newNode->rplyList = NULL;

    // Return the new comment
    return newNode;
}