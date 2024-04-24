#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;
typedef Node* Tree;

typedef struct trieNode {
    int end;
    struct trieNode *left;  // 0
    struct trieNode *right; // 1
} trieNode;
typedef trieNode* Trie;

// Defining a queue structure (to assist in tree formation)
Tree nodesLeft[300000];
Tree nodesRight[300000];
int leftFront = 0;
int leftRear = 0;
int rightFront = 0;
int rightRear = 0;

// Add a new node to the tree
Tree addToTree(Tree root, int ele) {
    // When tree is NULL (same as no node in the tree)
    if (!root) {
        // New node is creared and returned
        if (ele) {
            Tree newNode = (Tree)malloc(sizeof(Node));
            newNode->val = ele;
            newNode->left = NULL;
            newNode->right = NULL;

            nodesLeft[leftRear++] = newNode;
            nodesRight[rightRear++] = newNode;
            return newNode;
        }
        // Tree still remains empty
        else {
            return NULL;
        }
    }

    // When no new node can be added (all leaf nodes are 0)
    if ((rightRear == rightFront) && (leftFront == leftRear)) {
        // printf("Error Goes Brrr : No new node can be added!\n");
        return root;
    }

    // If new node needs to be added as a left child
    if (leftFront == rightFront) {
        // New node needs to be created
        if (ele) {
            Tree newNode = (Tree)malloc(sizeof(Node));
            newNode->val = ele;
            newNode->left = NULL;
            newNode->right = NULL;

            nodesLeft[leftFront++]->left = newNode;
            nodesLeft[leftRear++] = newNode;
            nodesRight[rightRear++] = newNode;
            return root;
        }
        // No new node is created
        else {
            leftFront++;
            return root;
        }
    }

    // If new node needs to be added as a right child
    if (leftFront == rightFront + 1) {
        // New node needs to be created
        if (ele) {
            Tree newNode = (Tree)malloc(sizeof(Node));
            newNode->val = ele;
            newNode->left = NULL;
            newNode->right = NULL;

            nodesRight[rightFront++]->right = newNode;
            nodesLeft[leftRear++] = newNode;
            nodesRight[rightRear++] = newNode;
            return root;
        }
        // No new node is created
        else {
            rightFront++;
            return root;
        }
    }
    return NULL;
}

// Solution function ( 0->No access ; 1->HasAccess ; 2->HasPhone )
int minPhones(Tree root, int *total) {
    // Base Case
    if (root == NULL) {
        return 1;
    }

    // Recursive Call
    int left = minPhones(root->left, total);
    int right = minPhones(root->right, total);

    // Both children covered
    if (left == 1 && right == 1) {
        return 0;
    }

    // One of the children is not covered
    else if (!left || !right) {
        (*total)++;
        return 2;
    }

    // Node is now monitored
    return 1;
}

// Adding new prime
void addPrime(Trie root, int prime) {
    Trie current = root;
    for (int bit = 31; bit >= 0; bit--) {
        Trie child = current->left;
        if ((prime >> bit) & 1) {
            child = current->right;
        }

        if (!child) {
            child = malloc(sizeof(trieNode));
            child->end = 0;
            child->left = NULL;
            child->right = NULL;

            if (((prime >> bit) & 1) == 0) {
                current->left = child;
            } 
            else {
                current->right = child;
            }
        }
        current = child;
    }
    current->end = 1;
}

// Search for prime
int searchPrime(Trie root, int prime) {
    if (!root) {
        return 0;
    }

    Trie current = root;
    for (int bit = 31; bit >= 0; bit--) {
        Trie child = current->left;
        if ((prime >> bit) & 1) {
            child = current->right;
        }
        if (!current) {
            return 0;
        }
    }

    return current->end;
}

int main() {
    // Inputing stuff
    int N;
    scanf("%d", &N);

    Tree avilol = NULL;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        // Adding to tree
        avilol = addToTree(avilol, num);
    }

    int min, max;
    scanf("%d %d", &min, &max);

    // Finding the minimum phones required
    int ans = 0;
    int value = minPhones(avilol, &ans);
    if (!value) {
        ans++;
    }

    // Creating trie for all primes upto ans
    // Trie nonte = malloc(sizeof(trieNode));
    // nonte->end = 0;
    // nonte->left = NULL;
    // nonte->right = NULL;

    // Get the primes and add to the trie
    int numbers[1000000];
    int primes[ans];
    long long int primeCount = 0;
    long long int result = 0;

    for (int p = 2; p < 696969; p++) {
        if (!numbers[p]) {
            // addPrime(nonte, p);

            for (long long int x = 0; x < primeCount; x++) {
                if (((p^primes[x]) < min) || ((p^primes[x]) > max)) {
                    result++;
                }
            }

            for (long long int i = 2*p; i <= 696969; i += p) {
                numbers[i] = 1;
            }
            primes[primeCount++] = p;
        }

        if (primeCount == ans) {
            break;
        }
    }
    
    printf("%lld\n%lld\n", ans, result);
    return 0;
}