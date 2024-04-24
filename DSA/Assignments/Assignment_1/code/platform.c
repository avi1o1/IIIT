#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "platform.h"

Platform* app;

Platform* createPlatform() {
    // Mallocing the neccesary memory space for the ADT.
    Platform* newNode = (Platform*) malloc(sizeof(Platform));

    // Checking if memory is allocated, or not.
    if (newNode == NULL) {
        printf("Error goes brrr : Couldn't initialise Post!");
        return NULL;
    }

    // Initialising the ADT.
    newNode->lastViewedPost = NULL;
    newNode->pstList = NULL;

    // Returning the ADT.
    return newNode;
}

bool addPost(char* username, char* caption) {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No Platform initialised!\n");
        return false;
    }

    // Creating the Post ADT.
    Post* pst = createPost(username, caption);

    // Mallocing the neccesary memory space for the Post.
    postList* newNode = (postList*) malloc(sizeof(postList));

    // Checking if memory is allocated, or not.
    if (newNode == NULL) {
        printf("Error goes brrr : Couldn't initialise Post!");
        return false;
    }

    // Initialising the Post.
    newNode->post = pst;
    newNode->next = app->pstList;
    app->pstList = newNode;

    return true;
}

bool deletePost(int n) {
    postList* deletingPost;

    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No Platform initialised!\n");
        return false;
    }

    // Checking for bogus input.
    else if (n == 0) {
        printf("Error Goes Brrr : Index should be a natural number!\n");
        return false;
    }

    // Checking for existence of any posts.
    else if (app->pstList == NULL) {
        printf("Error Goes Brrr : No post found!\n");
        return false;
    }
    
    // Solving the edge case of first Post deletion
    else if (n == 1) {
        deletingPost = app->pstList;
        app->pstList = deletingPost->next;
    }

    else {
        postList* iter = app->pstList;

        // Traversing to one node before the Post that need to be deleted.
        for (int i = 0; i < n-2; i++) {
            iter = iter->next;

            // Keeping check to not overrun the linked-list.
            if (iter == NULL) {
                printf("Error Goes Brrr : Index Out of Range!\n");
                return false;
            }
        }

        // Marking the node to be deleted
        deletingPost = iter->next;

        // Final checks for any over-runs or inappropriate indexing.
        if (deletingPost == NULL) {
            printf("Error Goes Brrr : Index Out of Range!\n");
            return false;
        }

        // Connecting the remaining Post lists
        iter->next = deletingPost->next;
    }

    // Updating the lastViewedPost in case of its deletion.
    if (deletingPost->post == app->lastViewedPost) {
        if (app->pstList) {
            app->lastViewedPost = app->pstList->post;
        }
        else {
            app->lastViewedPost = NULL;
        }
    }

    // Freeing up the memory.
    commentList* postCmnts = deletingPost->post->cmntList;
    
    // Traversing Comments and clearing each individual node.
    while (postCmnts != NULL) {
        commentList* deletingComment = postCmnts;
        postCmnts = postCmnts->next;
        replyList* cmntReply = deletingComment->comment->rplyList;

        // Traversing Replies and clearing each individual node.
        while (cmntReply != NULL) {
            replyList* deletingReply = cmntReply;
            cmntReply = cmntReply->next;

            free(deletingReply->reply);
            free(deletingReply);
        }
        free(deletingComment->comment);
        free(deletingComment);
    }
    // Finally, freeing the post node.
    free(deletingPost->post);
    free(deletingPost);

    return true;
}

Post* viewPost(int n) {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return NULL;
    }

    // Checking for any bogus input.
    else if (n == 0) {
        printf("Error Goes Brrr : Index should be a natural number!\n");
        return false;
    }

    postList* temp = app->pstList;
    // Checking for the existence of any posts on the platform.
    if (temp == NULL) {
        printf("Error Goes Brrr : No post on the platform!\n");
        return NULL;
    }

    // Traversing to the node to be viewed.
    for (int i = 0; i < n-1; i++) {
        temp = temp->next;

        // Keeping a check to not overrun the linkedlist.
        if (temp == NULL) {
            printf("Error Goes Brrr : Index out of range!\n");
            return NULL;
        }
    }

    // Updating the lastViewedPost.
    app->lastViewedPost = temp->post;

    // Returning the post, to be displayed in appropriate format by other functions.
    return temp->post;
}

Post* currPost() {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return NULL;
    }

    // Checking if any post has been viewed yet.
    if (app->lastViewedPost == NULL) {
        if (app->pstList->post == NULL) {
            printf("Error Goes Brrr : No posts on the platform!\n");
            return NULL;
        }
        app->lastViewedPost = app->pstList->post;
    }

    // Returning the lastViewedPost.
    return app->lastViewedPost;
}

Post* nextPost() {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return NULL;
    }

    postList* iter = app->pstList;

    // Checking for the existence of any post on the platform.
    if (iter == NULL) {
        printf("Error Goes Brrr : No post on the platform!\n");
        return NULL;
    }

    // Accessing the lastViewedPost.
    Post* lastPostViewed = app->lastViewedPost;

    // Finding the lastViewedPost in the post linkedlist.
    while (iter->post->caption != lastPostViewed->caption || iter->post->username != lastPostViewed->username) {
        iter = iter->next;

        // Keeping check to not overrun the linkedlist.
        if (iter == NULL) {
            printf("Error Goes Brrr : No post found!\n");
            return NULL;
        }
    }

    // In case post is not found.
    if (iter->next == NULL) {
        printf("Error Goes Brrr : No post found!\n");
        return NULL;
    }

    // Updating lastViewedPost.
    app->lastViewedPost = iter->next->post;

    // Returning the required post.
    return app->lastViewedPost;
}

Post* previousPost() {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return NULL;
    }

    // Checking for the last viewed post.
    if (app->lastViewedPost == NULL) {
        printf("Error Goes Brrr : No post viewed!\n");
        return NULL;
    }

    if (app->lastViewedPost == app->pstList->post) {
        return app->lastViewedPost;
    }

    postList* iter = app->pstList;
    postList* prev = NULL;

    // Checking for the existence of any post on the platform.
    if (iter == NULL) {
        printf("Error Goes Brrr : No post on the platform!\n");
        return NULL;
    }

    // Accessing the lastViewedPost.
    Post* lastPostViewed = app->lastViewedPost;

    // Finding the lastViewedPost in the post linkedlist.
    while (strcmp(iter->post->caption, lastPostViewed->caption) != 0 || strcmp(iter->post->username, lastPostViewed->username) != 0) {
        prev = iter;
        iter = iter->next;

        // Keeping check to not overrun the linkedlist.
        if (iter == NULL) {
            printf("Error Goes Brrr : No post found!\n");
            return NULL;
        }
    }

    // In case post is not found.
    if (prev == NULL) {
        printf("Error Goes Brrr : No post found!\n");
        return NULL;
    }

    // Updating lastViewedPost.
    app->lastViewedPost = prev->post;

    // Returning the required post.
    return app->lastViewedPost;
}

bool addComment(char* username, char* content) {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return false;
    }

    // Checking if any post has been viewed.
    if (app->lastViewedPost == NULL) {
        printf("Error Goes Brrr : No post viewed, yet!\n");
        return false;
    }

    commentList* cL = app->lastViewedPost->cmntList;

    commentList* newNode = (commentList*) malloc(sizeof(commentList));

    // Verifying appropriate memory allocation.
    if (newNode == NULL) {
        printf("Error goes brrr : Couldn't initialise comment!");
        return false;
    }

    // Initialising the new comment.
    newNode->comment = createComment(username, content);
    newNode->next = cL;

    // Updating the post.
    app->lastViewedPost->cmntList = newNode;
    return true;   
}

bool deleteComment(int n) {
    commentList* deletingComment;

    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return false;
    }

    // Checking for the lastViewedPost.
    if (app->lastViewedPost == NULL) {
        printf("Error Goes Brrr : No post viewed, yet!\n");
        return false;
    }

    // Checking for any bogus input.
    else if (n == 0) {
        printf("Error Goes Brrr : Index should be a natural number!\n");
        return false;
    }

    // Checking if post linkedlist is empty.
    else if (app->pstList == NULL) {
        printf("Error Goes Brrr : No post found!\n");
        return false;
    }

    // Solving for the edge case, where first comment is to be deleted.
    else if (n == 1) {
        deletingComment = app->lastViewedPost->cmntList;
        app->lastViewedPost->cmntList = deletingComment->next;
    }

    // General case deletion.
    else {
        commentList* iter = app->lastViewedPost->cmntList;

        // Iterating to the comment that needs to be deleted.
        for (int i = 0; i < n-2; i++) {
            iter = iter->next;

            if (iter == NULL) {
                return false;
            }
        }

        // Marking the comment that needs to be deleted.
        deletingComment = iter->next;

        // Updating the comment linkedlist.
        iter->next = deletingComment->next;
    }

    // Freeing up the unneccesary memory.
    replyList* cmntReply = deletingComment->comment->rplyList;

    // Iterating over each reply and deleting each individual node.
    while (cmntReply != NULL) {
        replyList* deletingReply = cmntReply;
        cmntReply = cmntReply->next;

        free(deletingReply->reply);
        free(deletingReply);
    }

    // Freeing up the comment node.
    free(deletingComment->comment);
    free(deletingComment);

    return true;
}

commentList* viewComments() {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return false;
    }

    // Checking if any posts have been viewed.
    if (app->lastViewedPost == NULL) {
        printf("Error Goes Brrr : No post viewed, yet!\n");
        return false;
    }

    // Returning the comment linkedlist of the lastViewedPost.
    return app->lastViewedPost->cmntList;
}

bool addReply(char* username, char* content, int n) {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return false;
    }

    // Checking if any post has been viewed..
    if (app->lastViewedPost == NULL) {
        printf("Error Goes Brrr : No post viewed, yet!\n");
        return false;
    }

    // Checking for bogus input.
    if (n == 0) {
        printf("Error Goes Brrr : Index should be a natural number!");
    }

    commentList* iter = app->lastViewedPost->cmntList;

    // Checking if any comment exists on the post.
    if (iter == NULL) {
        printf("Error Goes Brrr : No comment exists!");
        return false;
    }

    // Traversing to the required comment.
    for (int i = 0; i < n-1; i++) {
        iter = iter->next;

        // Keeping check of not overrunning the list.
        if (iter == NULL) {
            printf("Error Goes Brrr : Index out of range!");
            return false;
        }
    }

    // Mallocing a new node for the reply.
    replyList* newNode = (replyList*) malloc(sizeof(replyList));

    // Verifying the malloc
    if (newNode == NULL) {
        printf("Error Goes Brrr : Unable to initialise reply!");
    }

    // Initialising the new reply node.
    newNode->reply = createReply(username, content);
    newNode->next = iter->comment->rplyList;

    // Adding the reply to the linkedlist.
    iter->comment->rplyList = newNode;

    return true;
}

bool deleteReply(int n, int m) {
    // Checking for the existence of Platform ADT.
    if (app == NULL) {
        printf("Error Goes Brrr : No platform initialised!\n");
        return false;
    }

    // Checking for the last viewed post.
    if (app->lastViewedPost == NULL) {
        printf("Error Goes Brrr : No post viewed, yet!\n");
        return false;
    }

    // Checking for any bogus input.
    if (n == 0 || m == 0) {
        printf("Error Goes Brrr : Indices must be natural numbers90\n");
        return false;
    }

    commentList* cmnt = app->lastViewedPost->cmntList;

    // Checking for the comments on the post.
    if (cmnt == NULL) {
        printf("Error Goes Brrr : No comments on the post!\n");
        return false;
    }
    
    // Traversing to the required comment
    for (int i = 1; i < n; i++) {
        cmnt = cmnt->next;

        // Keeping check to not overrun the linkedlist.
        if (cmnt == NULL) {
            printf("Error Goes Brrr : Index out of range!\n");
            return false;
        }
    }

    replyList* deletingReply;

    // Edge case of deleting the latest reply.
    if (m == 1) {
        deletingReply = cmnt->comment->rplyList;

        // Checking for the existence of the reply.
        if (deletingReply == NULL) {
            printf("Error Goes Brrr : Index out of range!\n");
            return false;
        }

        // Updating the reply list.
        cmnt->comment->rplyList = deletingReply->next;
    }

    // General case deletion.
    else {
        replyList* rply = cmnt->comment->rplyList;

        // Checking for empty reply list.
        if (rply == NULL) {
            printf("Error Goes Brrr : No replies on the comment!\n");
            return false;
        }

        // Traversing to the required reply.
        for (int j = 0; j < m-2; j++) {
            rply = rply->next;

            // Keeping check to not overrun the linkedlist.
            if (rply == NULL) {
                printf("Error Goes Brrr : Index out of range!\n");
                return false;
            }
        }

        replyList* deletingReply = rply->next;

        // Checking for the existence of the reply.
        if (deletingReply == NULL) {
            printf("Error Goes Brrr : Index out of range!\n");
            return false;
        }

        // Updating the reply list.
        rply->next = rply->next->next;

    }

    // Freeing the reply node.
    free(deletingReply);
    return true;
}
