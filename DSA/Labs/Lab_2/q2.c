#include <stdio.h>
#include <stdlib.h>

int main() {
    long int arr[200001];
    int top = 0;

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        if (n == 1) {
            long int ele;
            scanf("%ld", &ele);

            if (top == 0) {
                arr[top++] = ele;
            }
            else {
                while (arr[top-1] <= ele) {
                    top--;

                    if (top == 0) {
                        break;
                    }
                }
                arr[top++] = ele;
            }
        }

        else {
            printf("%d\n", top);
        }
    }
    return 0;
}
