#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;
typedef Node* Tree;

void print(Tree root) {
    if (!root) {
        return;
    }

    print(root->left);
    printf("%d ", root->val);
    print(root->right);
}

Tree insertNode(Tree root, int ele) {
    if (!root) {
        Tree tempNode = (Tree) malloc(sizeof(Node));
        tempNode->val = ele;
        tempNode->left = NULL;
        tempNode->right = NULL;

        return tempNode;
    }

    if (root->val > ele) {
        root->left = insertNode(root->left, ele);
    }
    if (root->val < ele) {
        root->right = insertNode(root->right, ele);
    }

    return root;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Tree avilol = NULL;

    for (int i = 0; i < N; i++) {
        int ele;
        scanf("%d", &ele);

        avilol = insertNode(avilol, ele);
    }

    // print(avilol);
    // printf("\n");
    
    for (int j = 0; j < M; j++) {
        if (!avilol) {
            break;
        }

        int move;
        scanf("%d", &move);

        if (move) {
            avilol = avilol->right;
        }
        else {
            avilol = avilol->left;
        }
    }

    if (avilol) {
        printf("%d\n", avilol->val);
    }
    else {
        printf("-1\n");
    }

    return 0;
}