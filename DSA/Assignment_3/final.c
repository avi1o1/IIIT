#include <stdio.h>
#include <stdlib.h>

// Defining the data structure
typedef struct Node {
    long long int data;
    long long int index;
    int height;

    struct Node* left;
    struct Node* right;
} Node;
typedef Node* AVL;

// Helper function to get the height of the tree
int height(AVL tree) { 
    if (tree == NULL) {
        return 0;
    }
    return tree->height; 
}

// Helper function to get the difference in height of the left and right subtrees
int diff(AVL tree) { 
    if (tree == NULL) {
        return 0; 
    }
    return height(tree->left) - height(tree->right); 
}

// Helper function to get the maximum of two integers
int max(int x, int y) { 
    return (x > y) ? x : y; 
}

// Function to perform right AVL rotation
AVL rightRotate(AVL root) { 
    AVL T1 = root->left; 
    AVL T2 = T1->right; 

    T1->right = root; 
    root->left = T2; 

    root->height = max(height(root->left), height(root->right)) + 1; 
    T1->height = max(height(T1->left), height(T1->right)) + 1; 

    return T1; 
}

// Function to perform left AVL rotation
AVL leftRotate(AVL root) {
    AVL T1 = root->right;
    AVL T2 = T1->left;

    T1->left = root;
    root->right = T2;

    root->height = max(height(root->left), height(root->right)) + 1;
    T1->height = max(height(T1->left), height(T1->right)) + 1;

    return T1;
}

// Function to insert a node into the AVL tree
AVL insert(AVL tree, long long int data, long long int index) {
    // Inserting the first node
    if (tree == NULL) {
        AVL newNode = (AVL) malloc(sizeof(Node));
        if (!newNode) {
            printf("Fricking malloc!\n");
            return tree;
        }

        newNode->height = 1;
        newNode->data = data;
        newNode->index = index;

        newNode->left   = NULL;
        newNode->right  = NULL;
        return newNode;
    }
    
    // Inserting the node
    if (data < tree->data) {
        tree->left  = insert(tree->left, data, index);
    }
    
    else if (data > tree->data) {
        tree->right = insert(tree->right, data, index);
    }

    else {
        tree->index = index;
        return tree;
    }

    // Updating the height of the tree
    tree->height = 1 + max(height(tree->left), height(tree->right)); 
    int balance = diff(tree); 

    // Balancing the tree
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

    // Return the final tree
    return tree; 
} 

// Function to find a value in the AVL tree
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

int main() {
    // Input the number of elements
    int N;
    scanf("%d", &N);

    // Edge case with no elements
    if (N == 0) {
        printf("0\n");
        return 0;
    }

    // Input the elements
    long long int arr[N];
    for (int a = 0; a < N; a++) {
        scanf("%lld", &arr[a]);
    }

    // Initialise a temp array
    long long int dic[N];
    for (int b = 0; b < N; b++) {
        dic[b] = 0;
    }

    // Initialise the AVL tree
	long long int ans = 1;
    int startIndex = 0;
    AVL avilol = NULL;

    // Iterate through the array and update the AVL tree
	for (int i = N-1; i >= 0; i--) {
        // printf("%d %lld %d\n", i, arr[i], startIndex);
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
    // Printing the length of the longest subsequence
	printf("%lld\n", ans);

    // Printing the indices of the longest subsequence
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
