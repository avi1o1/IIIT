#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("--> Task 1 starting...\n\n");
    // Task 1 : Create a child process and print the process ID of the parent and child process
    int x = 25;
    int child1 = fork();
    if (child1 == -1) {
        // Error creating child process
        printf("--> Oopsie Woopsie. UwU. Couldn't create the child process\n");
        return -1;
    }
    else if (child1 == 0) {
        // Child process
        int childID = getpid();
        printf("Child ID: %d\n", childID);

        // Task 1(a) : Get the value of x for the child process
        printf("Value of x for child: %d\n", x);
        x = 69;
        printf("Value of x for child after change: %d\n", x);

        printf("Child process 1 exiting\n");
        return 0;
    }
    else {
        // Parent process
        int parentID = getpid();
        printf("Parent ID: %d\n", parentID);

        // Task 1(b) : Get the value of x for the parent process
        printf("Value of x for parent: %d\n", x);
        x = 420;
        printf("Value of x for parent after change: %d\n", x);
    }

    sleep(1);
    printf("\n--> Task 1 completed.\n\n");
    printf("--> Task 2 starting...\n\n");

    // Task 2 : Create a new file through a child process, and store the parent PID
    int child2 = fork();

    if (child2 == -1) {
        // Error creating child process
        printf("--> Oopsie Woopsie. UwU. Couldn't create the child process\n");
        return -1;
    }
    else if (child2 == 0) {
        // Child process creating a file
        int pid = getppid();
        char pid_str[8];
        sprintf(pid_str, "%d", pid);
        char cmnd[32];
        snprintf(cmnd, sizeof(cmnd), "echo %s > newfile.txt", pid_str);
        printf("%s\n", cmnd);

        char *args[] = {"/bin/sh", "-c", cmnd, NULL};
        if (execvp(args[0], args) == -1) {
            printf("--> Oopsie Woopsie. UwU. Something fucked up!\n");
        }
        printf("--> Parent process ID stored in file.");
    }
    else {
        // Parent process waiting for child to finish
        sleep(1);
    }

    sleep(1);
    printf("\n--> Task 2 completed.\n\n");
    printf("--> Task 3 starting...\n\n");

    // Task 3 : Create a child process 
    int child3 = fork();

    if (child3 == -1) {
        // Error creating child process
        printf("--> Oopsie Woopsie. UwU. Couldn't create the child process\n");
        return -1;
    }
    else if (child3 == 0) {
        // Parent ID of an orphaned child process
        sleep(1);
        int parentID = getppid();
        printf("\nParent ID of orphaned child: %d\n", parentID);
    }
    else {
        // Terminating the parent process
        return 0;
    }

    printf("\n--> Task 3 completed.\n\n");
    return 0;
}