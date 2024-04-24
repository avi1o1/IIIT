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

int checkBST(Tree root) {
    if (!root) {
        return 1;
    }

    int temp = 1;
    if (root->left) {
        temp = temp && (root->left->val < root->val);
    }
    if (root->right) {
        temp = temp && (root->right->val > root->val);
    }

    return (temp && checkBST(root->left) && checkBST(root->right));
}

int main() {
    int N;
    scanf("%d", &N);
    Tree arr[N];

    for (int i = 0; i < N; i++) {
        int ele;
        scanf("%d", &ele);

        Tree tempNode;
        if (ele == -1) {
            tempNode = NULL;
        }
        else {
            tempNode = (Tree) malloc(sizeof(Node));
            tempNode->val = ele;
            tempNode->left = NULL;
            tempNode->right = NULL;
        }

        arr[i] = tempNode;
    }

    // for (int i = 0; i < N; i++) {
    //     if (arr[i]) {
    //         Tree temp = arr[i];
    //         printf("%d ", temp->val);
    //     }
    // }

    int idx = 0;
    while (idx < N) {
        if (arr[idx]) {
            if (2*idx+1 < N && arr[2*idx+1]) {
                Tree temp = arr[idx];
                temp->left = arr[2*idx+1];
            }

            if (2*idx+2 < N && arr[2*idx+2]) {
                Tree temp = arr[idx];
                temp->right = arr[2*idx+2];
            }
        }
        idx++;
    }

    Tree avilol = arr[0];
    // print(avilol);
    printf("%d\n", checkBST(avilol));

    return 0;
}