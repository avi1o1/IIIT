#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void* n1, const void* n2) {
    int* num1 = (int*) n1;
    int* num2 = (int*) n2;
    return *num1 - *num2;
}

int main() {
    long long int N, M;
    scanf("%lld %lld", &N, &M);

    long long int arr[N];

    for (long long int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, N, sizeof(long long int), cmpFunc);

    long long int ans[N];
    ans[0] = arr[0];
    long long int sum = ans[0];

    for (long long int k = 1; k < M; k++) {
        ans[k] = sum + arr[k];
        sum = ans[k];
    }

    for (long long int k = M; k < N; k++) {
        sum += arr[k];
        ans[k] = ans[k-M] + sum;
    }

    for (long long int j = 0; j < N; j++) {
        printf("%lld ", ans[j]);
    }

    return 0;
}