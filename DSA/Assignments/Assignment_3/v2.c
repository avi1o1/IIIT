#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    long long int data;
    long long int index;
    long long int count;
    struct Node* left;
    struct Node* right;
} Node;
typedef Node* AVL;

AVL insert(AVL root, long long int data, long long int index) {
    if (root == NULL) {
        AVL newNode = (AVL) malloc(sizeof(Node));
        newNode->data = data;
        newNode->index = index;
        newNode->count = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data, index);
    }
    
    else if (data > root->data) {
        root->right = insert(root->right, data, index);
    }

    else {
        root->count++;
    }

    return root;
}

AVL find(AVL root, long long int ele) {
    if (root == NULL) {
        return NULL;
    }

    if (ele < root->data) {
        return find(root->left, ele);
    }

    else if (ele > root->data) {
        return find(root->right, ele);
    }

    else {
        if (root->count > 0) {
            return root;
        }
    }

    return NULL;
}

void print(AVL root) {
    if (root == NULL) {
        return;
    }

    print(root->left);
    if (root->count > 0) {
        printf("%lld ", root->data);
    }
    print(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    // Storing elements
    long long int arr[N];
	memset(arr, -69, sizeof(arr));
    AVL avilol = NULL;

    for (int a = 0; a < N; a++) {
        scanf("%lld", &arr[a]);
    }

    // Bookkeeeping indices
	long long int ans = 1;
    int startIndex = 0;
    long long int dic[N];

	for (int i = N-1; i >= 0; i--) {
        avilol = insert(avilol, arr[i], i);
        dic[i] = 1;

        AVL tempNode = find(avilol, arr[i]+1);
        if (tempNode != NULL && tempNode->count > 0) {
            dic[i] = dic[tempNode->index] + 1;
        }

        if (dic[i] > ans) {
            ans = dic[i];
            startIndex = i;
        }
	}
	printf("%lld\n", ans);
    // print(avilol);
    // printf("\n");

    long long int nextElement = arr[startIndex];
    for (int k = startIndex; k < N; k++) {
        if (arr[k] == nextElement) {
            printf("%d ", k);
            nextElement++;
            ans--;

            if (!ans) {
                break;
            }
        }
    }
	return 0;
}
