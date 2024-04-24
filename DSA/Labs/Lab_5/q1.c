#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
    int N;
    scanf("%d", &N);
    int arr[N][26];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            arr[i][j] = 0;
        }
    }
    
    char c;
    scanf("%c", &c);
    for (int i = 0; i < N; i++) {
        char txt[1000] = "";

        scanf("%s", txt);
        // printf("%s\n", txt);

        for (int j = 0; j < 1000; j++) {
            if (97 <= txt[j] && txt[j] <= 122) {
                arr[i][txt[j]-97] = 1;
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < 26; j++) {
    //         printf("%d", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    int ans = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            int flag = 1;
            for (int k = 0; k < 26; k++) {
                if (arr[i][k] != arr[j][k]) {
                    flag = 0;
                }
            }

            if (flag) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}