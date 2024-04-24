#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "post.h"
#include "reply.h"
#include "comment.h"
#include "platform.h"

extern Platform* app;

int main() {
    char create_platform[64] = "create_platform";

    char add_post[64] = "add_post";
    char view_post[64] = "view_post";
    char next_post[64] = "next_post";
    char delete_post[64] = "delete_post";
    char current_post[64] = "current_post";
    char previous_post[64] = "previous_post";

    char add_comment[64] = "add_comment";
    char view_comments[64] = "view_comments";
    char delete_comment[64] = "delete_comment";

    char add_reply[64] = "add_reply";
    char delete_reply[64] = "delete_reply";
    
    char quit[64] = "quit";


    while (69) {
        // printf("\n");
        char cmnd[64];
        fgets(cmnd, sizeof(cmnd), stdin);
        char* token = strtok(cmnd, " \n");

        if (strcmp(token, quit) == 0) {
            break;
        }

        else if (strcmp(token, create_platform) == 0) {
            app = createPlatform();
        }

        else if (strcmp(token, add_post) == 0) {
            token = strtok(NULL, " \n");
            char* user = token;
            token = strtok(NULL, " \n");
            char* caption = token;

            bool result = addPost(user, caption);
        }

        else if (strcmp(token, delete_post) == 0) {
            token = strtok(NULL, " \n");
            int n = atoi(token);

            bool result = deletePost(n);
        }

        else if (strcmp(token, view_post) == 0) {
            token = strtok(NULL, " \n");
            int n = atoi(token);

            Post* post = viewPost(n);

            if (post) {
                printf("%s %s\n", post->username, post->caption);
            }
        }

        else if (strcmp(token, current_post) == 0) {
            Post* post = currPost();

            if (post) {
                printf("%s %s\n", post->username, post->caption);
            }
        }

        else if (strcmp(token, next_post) == 0) {
            Post* post = nextPost();

            if (post) {
                printf("%s %s\n", post->username, post->caption);
            }
        }

        else if (strcmp(token, previous_post) == 0) {
            Post* post = previousPost();

            if (post) {
                printf("%s %s\n", post->username, post->caption);
            }
        }

        else if (strcmp(token, add_comment) == 0) {
            token = strtok(NULL, " \n");
            char* user = token;
            token = strtok(NULL, " \n");
            char* content = token;

            bool result = addComment(user, content);
        }

        else if (strcmp(token, delete_comment) == 0) {
            token = strtok(NULL, " \n");
            int n = atoi(token);

            bool result = deleteComment(n);
        }

        else if (strcmp(token, view_comments) == 0) {
            commentList* cmnts = viewComments();

            if (cmnts) {
                while (cmnts != NULL) {
                    printf("%s %s\n", cmnts->comment->username, cmnts->comment->content);

                    replyList* rpls = cmnts->comment->rplyList;
                    while (rpls != NULL) {
                        printf("     %s %s\n", rpls->reply->username, rpls->reply->content);
                        rpls = rpls->next;
                    }

                    cmnts = cmnts->next;
                }
            }

            else {
                printf("Error Goes Brrr : No comments added, yet!\n");
            }
        }

        else if (strcmp(token, add_reply) == 0) {
            token = strtok(NULL, " \n");
            char* user = token;
            token = strtok(NULL, " \n");
            char* reply = token;
            token = strtok(NULL, " \n");
            int n = atoi(token);

            bool result = addReply(user, reply, n);
        }

        else if (strcmp(token, delete_reply) == 0) {
            token = strtok(NULL, " \n");
            int n = atoi(token);
            token = strtok(NULL, " \n");
            int m = atoi(token);

            bool result = deleteReply(n, m);
        }

        else {
            printf("Error Goes Brrr : Learn typing, nube!\n");
        }
    }
}