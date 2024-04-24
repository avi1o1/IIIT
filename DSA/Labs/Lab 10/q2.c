#include <stdio.h>


int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int arr[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    while (Q) {
        Q--;
        int a, b;
        scanf("%d %d", &a, &b);
        int infected = 0;

        int visited[N];
        for (int i = 0; i < N; i++) {
            visited[i] = 0;
        }

        int stack[10000];
        for (int i = 0; i < 10000; i++) {
            stack[i] = -1;
        }
        stack[0] = a;
        int stackPointer = 0;
        int totalElements = 1;
        
        while (totalElements > 0) {
            int curr = stack[stackPointer++];
            totalElements--;
            // printf("%d\n", curr);

            if (curr == b) {
                infected = 1;
                break;
            }

            for (int j = 0; j < N; j++) {
                if (arr[curr][j] == 1 && visited[j] == 0) {
                    stack[stackPointer + totalElements] = j;
                    visited[j] = 1;
                    totalElements++;
                }
            }
        }

        printf("%d\n", infected);
    }


    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }


    return 0;
}
