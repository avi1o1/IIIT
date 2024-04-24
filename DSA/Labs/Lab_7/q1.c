#include <stdio.h>

typedef struct Node {
    int val;
} Node;

int main() {
    int Q;
    scanf("%d", &Q);

    long long int arr[Q+1];
    arr[0] = -1;
    long long int eleCount = 0;

    for (int i = 1; i < Q+1; i++) {
        int qry;
        scanf("%d", &qry);

        if (qry == 1) {
            scanf("%lld", &arr[++eleCount]);

            int idx = eleCount;
            while (arr[idx/2] > arr[idx]) {
                int temp = arr[idx];
                arr[idx] = arr[idx/2];
                arr[idx/2] = temp;

                idx /= 2;
                if (idx == 1) {
                    break;
                }
            }
        }

        else if (qry == 2) {
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

        else {
            printf("%lld\n", arr[1]);
        }

        // for (int x = 1; x < eleCount+1; x++) {
        //     printf("%lld ", arr[x]);
        // }
        // printf("\n");
    }

    return 0;
}