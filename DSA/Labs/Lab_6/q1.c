#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int index;
    struct Node* next;
} Node;
typedef Node* LL;

int hashMeDaddy(int val) {
    int hash = val % 196613;
    if (hash < 0) {
        hash *= -1;
    }
    return hash;
}

void insert(LL* hT, int ele, int index) {
    int hashVal = hashMeDaddy(ele);
    LL tempNode = hT[hashVal];

    LL valNode = (LL) malloc(sizeof(Node));
    valNode->val = ele;
    valNode->index = index;
    valNode->next = NULL;

    if (!tempNode) {
        hT[hashVal] = valNode;
        return;
    }

    while (tempNode->next) {
        tempNode = tempNode->next;
    }
    tempNode->next = valNode;
    return;
}

int find(LL* hT, int ele) {
    int hashVal = hashMeDaddy(ele);
    LL tempNode = hT[hashVal];

    while (tempNode) {
        if (tempNode->val == ele) {
            return tempNode->index;
        }
        tempNode = tempNode->next;
    }
    return -1;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    LL hT[196613];
    for (int x = 0; x < 196613; x++) {
        hT[x] = NULL;
    }

    for (int i = 0; i < N; i++) {
        int ele;
        scanf("%d", &ele);
        insert(hT, ele, i);
    }

    // for (int x = 0; x < 196613; x++) {
    //     if (hT[x]) {
    //         printf("%d\n", hT[x]->val);
    //     }
    // }

    for (int j = 0; j < Q; j++) {
        int f;
        scanf("%d", &f);
        printf("%d\n", find(hT, f));
    }

    return 0;
}