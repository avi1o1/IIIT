#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long int a;
    long long int b;
} Node;
typedef Node* Range;

int cmp(const void* x, const void* y) {
    const Range val1 = *(Range*) x;
    const Range val2 = *(Range*) y;

    if (val1->b > val2->b) {
        return 1;
    }
    else if (val1->b == val2->b) {
        return 0;
    }
    else {
        return -1;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Range arr[N];

    for (int i = 0; i < N; i++) {
        long long int a;
        scanf("%lld", &a);

        Range newNode = (Range) malloc(sizeof(Node));
        newNode->a = a;
        arr[i] = newNode;
    }

    for (int j = 0; j < N; j++) {
        long long int b;
        scanf("%lld", &b);
        arr[j]->b = b;
    }

    qsort(arr, N, sizeof(Range), cmp);

    long long int k = N-1;
    long long int ctr = 0;
    while (k >= 0) {
        long long int lastValidIndex = k-1;
        while ((lastValidIndex >= 0) && (arr[lastValidIndex]->b > arr[k]->a)) {
            if ((arr[lastValidIndex]->a > arr[k]->a)) {
                ctr++;
                break;
            }
            ctr++;
            lastValidIndex--;
        }
        k = lastValidIndex;
    }

    printf("%lld\n", ctr);
    return 0;
}