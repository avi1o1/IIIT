#include <stdio.h>
#include <string.h>

int main() {
    int arr[26];
    for (int i = 0; i < 26; i++) {
        arr[i] = 0;
    }

    int N;
    scanf("%d", &N);
    char txt[100069];
    scanf("%s", txt);
    // printf("%s\n", txt);

    int start = 0;
    int ans = 1;

    for (int curr = 0; curr < N; curr++) {
        if (!arr[txt[curr]-97]) {
            arr[txt[curr]-97] = 1;
        }

        else {
            if (curr-start > ans) {
                ans = curr-start;
            }
            if (txt[start] != txt[curr]) {
                while (txt[start] != txt[curr]) {
                    arr[txt[start]-97] = 0;
                    start++;
                }
            }
            arr[txt[start]-97] = 0;
            start++;
            arr[txt[curr]-97] = 1;

            // printf("%d %c %d %d\n", curr, txt[curr], start, ans);
        }
    }

    if (N-start > ans) {
        ans = N-start;
    }

    printf("%d\n", ans);
    
    
    return 0;
}