#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "reply.h"

Reply* createReply(char* username, char* content) {
    // Allocate memory for the new reply
    Reply* newNode = (Reply*) malloc(sizeof(Reply));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Error goes brrr : Couldn't initialise Post!");
    }

    // Assign the username and content to the reply
    strcpy(newNode->content, content);
    strcpy(newNode->username, username);

    // Return the new reply
    return newNode;
}
