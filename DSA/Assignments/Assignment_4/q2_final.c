#include <stdio.h>
#include <stdlib.h>

// Defining the node structure
typedef struct Node {
    int index;
    int required;
    int change;
} Node;

int main() {
    // Taking inputs
    int N, K;
    scanf("%d %d", &N, &K);

    // Creating an array for all rooms
    Node* arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = NULL;
    }

    // Getting the required oxygen levels to access each room
    for (int j = 0; j < N; j++) {
        int req;
        scanf("%d", &req);

        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->index = j;
        newNode->required = req;
        newNode->change = 0;
        arr[j] = newNode;
    }

    // Getting the change in oxygen levels for each room
    for (int k = 0; k < N; k++) {
        int diff;
        scanf("%d", &diff);
        arr[k]->change = diff;
    }

    // Calculating the maximum oxygen level attainable
    for (int l = 0; l < N; l++) {
        for (int m = 0; m < N; m++) {
            if (arr[m]) {
                if ((arr[m]->required <= K) && (arr[m]->change > 0)) {
                    K += arr[m]->change;
                    arr[m] = NULL;
                }
            }
        }
    }
    // printf("%d\n", K);

    // Sorting array based on required oxygen
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (arr[i] && arr[j]) {
                if (arr[i]->required < arr[j]->required) {
                    Node* temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // Calculating the maximum use of oxygen
    for (int l = 0; l < N; l++) {
        for (int m = 0; m < N; m++) {
            if (arr[m]) {
                if (arr[m]->required <= K) {
                    K += arr[m]->change;
                    arr[m] = NULL;
                }
            }
        }
    }

    // Checking if the oxygen level has gone negative
    if (K < 0) {
        printf("NO\n");
        return 0;
    }

    // Checking if any room has not been visited
    for (int x = 0; x < N; x++) {
        if (arr[x]) {
            printf("NO\n");
            return 0;
        }
    }

    // If all rooms have been visited
    printf("YES\n");
    return 0;
}