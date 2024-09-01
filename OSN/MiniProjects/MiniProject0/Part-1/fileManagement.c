#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    // Creating a file
    int newFile = creat("newfile.txt", 0644);
    if (newFile == -1) {
        printf("--> Oopsie Woopsie. UwU. Couldn't create the file\n");
        return -1;
    }

    char command[16];
    char content[4096];
    strcpy(command, "OSNTASUCKS");

    while (1) {
        printf("Enter a command (INPUT, PRINT, STOP): ");
        scanf("%s", command);

        if (strcmp(command, "STOP") == 0) {
            break;
        }

        else if (strcmp(command, "INPUT") == 0) {
            printf("   --> ");
            scanf(" %[^\n]s", content);

            int original = dup(1);
            dup2(newFile, 1);
            printf("%s\n", content);
            dup2(original, 1);
            close(original);
        }

        else if (strcmp(command, "PRINT") == 0) {
            FILE* file = fopen("newfile.txt", "r");
            if (file == NULL) {
                printf("--> Oopsie Woopsie. UwU. Couldn't read the file\n");
                return -1;
            }

            while (fgets(content, 256, file) != NULL) {
                printf("   --> %s", content);
            }
        }

        else {
            printf("--> Oopsie Woopsie. UwU. Couldn't fetch that command.\n");
        }
    }
    
    close(newFile);
    return 0;
}