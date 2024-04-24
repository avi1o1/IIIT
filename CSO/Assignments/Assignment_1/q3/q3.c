#include <stdio.h>

long long int palindrome(long long int N, char arr[]);

int main() {
    char arr[1000];                     // Assuming a max limit of 999 chars
    long long int N = -1;

    for (int i = 0; i < 1000; i++) {
        scanf("%c", &arr[i]);
        N++;

        if (arr[i] == '\n') {
            break;
        }
    }

    long long int res = palindrome(N, arr);
    printf("%lld\n", res);
    
    return 0;
}