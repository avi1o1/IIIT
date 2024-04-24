#include <stdio.h>

int main() {
    long long int K, N;
    scanf("%lld", &K);

    long long int tmp[K];
    for (long long int i = 0; i < K; i++) {
        scanf("%lld", &tmp[i]);
    }

    scanf("%lld", &N);
    long long int arr[K+N+1];
    long long int eleCount = 0;
    arr[0] = -1;

    for (long long int j = 0; j < K; j++) {
        if (tmp[j] != 0) {
            arr[++eleCount] = tmp[j];

            long long int idx = eleCount;
            while (arr[idx/2] > arr[idx]) {
                long long int x = arr[idx];
                arr[idx] = arr[idx/2];
                arr[idx/2] = x;

                idx /= 2;
                if (idx == 1) {
                    break;
                }
            }
        }
    }

    long long int appleCount = 0;
    long long int day = 1;

    for (long long int k = 0; k < N; k++) {
        long long int temp;
        scanf("%lld", &temp);

        if (temp != 0) {
            arr[++eleCount] = temp+k;

            long long int idx = eleCount;
            while (arr[idx/2] > arr[idx]) {
                long long int x = arr[idx];
                arr[idx] = arr[idx/2];
                arr[idx/2] = x;

                idx /= 2;
                if (idx == 1) {
                    break;
                }
            }
        }

        long long int extract = arr[1];
        if (extract >= day) {
            arr[1] = arr[eleCount--];
            int idx = 1;
            while (idx*2 <= eleCount) {
                int smallest = idx;

                if (arr[idx*2] < arr[smallest]) {
                    smallest = idx*2;
                }

                if (idx*2+1 <= eleCount && arr[idx*2+1] < arr[smallest]) {
                    smallest = idx*2+1;
                }
                
                if (smallest == idx) {
                    break;
                }
                else {
                    int temp = arr[smallest];
                    arr[smallest] = arr[idx];
                    arr[idx] = temp;
                    idx = smallest;
                }
            }
        }

        while (extract < day && eleCount > 0) {
            arr[1] = arr[eleCount--];
            int idx = 1;
            while (idx*2 <= eleCount) {
                int smallest = idx;

                if (arr[idx*2] < arr[smallest]) {
                    smallest = idx*2;
                }

                if (idx*2+1 <= eleCount && arr[idx*2+1] < arr[smallest]) {
                    smallest = idx*2+1;
                }
                
                if (smallest == idx) {
                    break;
                }
                else {
                    int temp = arr[smallest];
                    arr[smallest] = arr[idx];
                    arr[idx] = temp;
                    idx = smallest;
                }
            }
            
            extract = arr[1];
        }

        if (extract >= day) {
            // printf("%lld %lld\n", extract, day);
            appleCount++;
        }
        day++;
    }

    if (eleCount > 0) {
        // for (int x = 1; x < eleCount+1; x++) {
        //     printf("%lld ", arr[x]);
        // }
        // printf("\n");
        long long int extract = arr[1];
        if (extract >= day) {
            arr[1] = arr[eleCount--];
            int idx = 1;
            while (idx*2 <= eleCount) {
                int smallest = idx;

                if (arr[idx*2] < arr[smallest]) {
                    smallest = idx*2;
                }

                if (idx*2+1 <= eleCount && arr[idx*2+1] < arr[smallest]) {
                    smallest = idx*2+1;
                }
                
                if (smallest == idx) {
                    break;
                }
                else {
                    int temp = arr[smallest];
                    arr[smallest] = arr[idx];
                    arr[idx] = temp;
                    idx = smallest;
                }
            }
        }

        while (extract < day && eleCount > 0) {
            arr[1] = arr[eleCount--];
            int idx = 1;
            while (idx*2 <= eleCount) {
                int smallest = idx;

                if (arr[idx*2] < arr[smallest]) {
                    smallest = idx*2;
                }

                if (idx*2+1 <= eleCount && arr[idx*2+1] < arr[smallest]) {
                    smallest = idx*2+1;
                }
                
                if (smallest == idx) {
                    break;
                }
                else {
                    int temp = arr[smallest];
                    arr[smallest] = arr[idx];
                    arr[idx] = temp;
                    idx = smallest;
                }
            }
            
            extract = arr[1];
        }

        if (extract >= day) {
            // printf("--> %lld %lld\n", extract, day);
            appleCount++;
        }
        day++;
        // printf("%lld %lld\n", day, eleCount);
        // for (int x = 1; x < eleCount+1; x++) {
        //     printf("%lld ", arr[x]);
        // }
        // printf("\n");
    }

    printf("%lld\n", appleCount);

    return 0;
}
