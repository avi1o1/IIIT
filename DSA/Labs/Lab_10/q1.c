#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int arr[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }

    while (Q) {
        int a, b;
        char query;
        Q--;

        scanf("%c", &query);
        scanf("%c", &query);

        if (query == 'I') {
            for (int x = 0; x < 5; x++) {
                scanf("%c", &query);
            }
            scanf("%d %d", &a, &b);

            arr[a][b] = 1;
            arr[b][a] = 1;
        }

        else if (query == 'E') {
            for (int x = 0; x < 9; x++) {
                scanf("%c", &query);
            }
            scanf("%d %d", &a, &b);
            int found = 0;

            if (arr[a][b]) {
                found = 1;
                printf("1\n");
            }

            else {
                for (int i = 0; i < N; i++) {
                    if (arr[a][i] && arr[i][b]) {
                        found = 1;
                        printf("1\n");
                        break;
                    }
                }
            }

            if (!found) {
                printf("0\n");
            }
        }

        else if (query == 'D') {
            for (int x = 0; x < 5; x++) {
                scanf("%c", &query);
            }

            scanf("%d %d", &a, &b);


            if (arr[a][b]) {
                arr[a][b] = 0;
                arr[b][a] = 0;
            }
            else {
                printf("-1\n");
            }
        }
        else {
            printf("urmomgey\n");
        }
    }
    return 0;
}
