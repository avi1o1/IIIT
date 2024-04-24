#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int index;
    struct Node* next;
} Node;
typedef Node* LL;

int hashMeDaddy(int val) {
    return val % 196613;
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

int find(LL* hT, int value, int index, int K) {
    if (value < 0) {
        return 0;
    }

    int hashVal = hashMeDaddy(value);
    LL tempNode = hT[hashVal];
    int ctr = 0;

    while (tempNode != NULL) {
        if ((tempNode->val == value) && (tempNode->index-index >= K)) {
            ctr++;
        }
        tempNode = tempNode->next;
    }
    return ctr;
}

int main() {
    int N, Q, K;
    scanf("%d %d %d", &N, &Q, &K);

    LL hT[196613];
    for (int x = 0; x < 196613; x++) {
        hT[x] = NULL;
    }

    for (int i = 0; i < N; i++) {
        int ele;
        scanf("%d", &ele);
        insert(hT, ele, i);
    }

    for (int j = 0; j < Q; j++) {
        int tgt;
        scanf("%d", &tgt);
        int ctr = 0;

        for (int k = 0; k < N; k++) {
            LL temp = hT[k];
            if (temp) {
                while (temp) {  
                    ctr += find(hT, tgt-temp->val, temp->index, K);
                    temp = temp->next;
                }
            }
        }
        printf("%d\n", ctr);
    }

    return 0;
}