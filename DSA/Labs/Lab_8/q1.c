#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void* n1, const void* n2) {
    int* num1 = (int*) n1;
    int* num2 = (int*) n2;
    return *num1 - *num2;
}

int main() {
    int N;
    scanf("%d", &N);
    long long int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, N, sizeof(long long int), cmpFunc);
    long long int mid = arr[N/2];

    long long int final = 0;
    for (int i = 0; i < N; i++) {
        long long int temp = arr[i] - mid;
        if (temp < 0) {
            temp *= -1;
        }
        final += temp;
    }

    // printf("%lld", mid);
    printf("\n%lld\n", final);
    return 0;
}
