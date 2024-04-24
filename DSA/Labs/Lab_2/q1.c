#include <stdio.h>

int main() {
    int arr[1000069] = { 0 };
    int front = -1;
    int rear = -1;
    int size = 0;

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        if (n == 1) {
            int ele;
            scanf("%d", &ele);

            arr[++rear] = ele;
            size++;
        }

        else if (n == 2) {
            if (size != 0) {
                front++;
                size--;
            }

            if (size == 0) {
                front = -1;
                rear = -1;
            }
        }

        else if (n == 3) {
            if (size == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", arr[front+1]);
            }
        }

        // for (int x = front+1; x < rear+1; x++) {
        //     printf("%d ", arr[x]);
        // }
        // printf("\n");
    }
    return 0;
}