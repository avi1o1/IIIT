#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    long long int data;
    long long int index;
    int height;

    struct Node* left;
    struct Node* right;
} Node;
typedef Node* AVL;

int height(AVL tree) { 
    if (tree == NULL) {
        return 0;
    }
    
    return tree->height; 
}

int diff(AVL tree) { 
    if (tree == NULL) {
        return 0; 
    }

    return height(tree->left) - height(tree->right); 
} 

int max(int x, int y) { 
    return (x > y)? x : y; 
}

AVL rightRotate(AVL root) { 
    AVL T1 = root->left; 
    AVL T2 = T1->right; 

    T1->right = root; 
    root->left = T2; 

    root->height = max(height(root->left), height(root->right)) + 1; 
    T1->height = max(height(T1->left), height(T1->right)) + 1; 

    return T1; 
}

AVL leftRotate(AVL root) {
    AVL T1 = root->right;
    AVL T2 = T1->left;

    T1->left = root;
    root->right = T2;

    root->height = max(height(root->left), height(root->right)) + 1;
    T1->height = max(height(T1->left), height(T1->right)) + 1;

    return T1;
}
 
AVL insert(AVL tree, long long int data, long long int index) {
    if (tree == NULL) {
        AVL newNode = (AVL) malloc(sizeof(Node));
        newNode->height = 1;
        newNode->data = data;
        newNode->index = index;

        newNode->left   = NULL;
        newNode->right  = NULL;
        return newNode;
    }
  
    if (data < tree->data) {
        tree->left  = insert(tree->left, data, index);
    }
    
    else if (data > tree->data) {
        tree->right = insert(tree->right, data, index);
    }

    else {
        return tree;
    }

    tree->height = 1 + max(height(tree->left), height(tree->right)); 
    int balance = diff(tree); 

    if (balance > 1 && data < tree->left->data) {
        return rightRotate(tree);
    }

    if (balance < -1 && data > tree->right->data) {
        return leftRotate(tree);
    }

    if (balance > 1 && data > tree->left->data) { 
        tree->left =  leftRotate(tree->left); 
        return rightRotate(tree); 
    } 

    if (balance < -1 && data < tree->right->data) { 
        tree->right = rightRotate(tree->right); 
        return leftRotate(tree); 
    }

    return tree; 
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
        return root;
    }
}

void clearTree(AVL root) {
    if (!root) {
        return;
    }

    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("0\n");
        return 0;
    }

    long long int arr[N];
    for (int a = 0; a < N; a++) {
        scanf("%lld", &arr[a]);
    }

    long long int dic[N];
    for (int b = 0; b < N; b++) {
        dic[b] = 0;
    }

	long long int ans = 1;
    int startIndex = 0;
    AVL avilol = NULL;

	for (int i = N-1; i >= 0; i--) {
        dic[i] = 1;
        AVL tempNode = find(avilol, arr[i]+1);
        if (tempNode) {
            dic[i] = dic[tempNode->index] + 1;
        }

        if (dic[i] > ans) {
            ans = dic[i];
            startIndex = i;
        }

        avilol = insert(avilol, arr[i], i);
	}

    clearTree(avilol);
	printf("%lld\n", ans);

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
    
    printf("\n");
	return 0;
}
