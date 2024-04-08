#include <stdio.h>
#include <stdlib.h>

// Defining tree nodes and structure
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;
typedef Node* Tree;

// Defining a queue structure (to assist in tree formation)
Tree nodesLeft[300000];
Tree nodesRight[300000];
int leftFront = 0;
int leftRear = 0;
int rightFront = 0;
int rightRear = 0;

// Print the tree (in-order traversal)
void print(Tree root) {
    if (!root) {
        return;
    }

    print(root->left);
    printf("%d ", root->val);
    print(root->right);
    return;
}

// Add a new node to the tree
Tree addToTree(Tree root, int ele) {
    // When tree is NULL (same as no node in the tree)
    if (!root) {
        // New node is creared and returned
        if (ele) {
            Tree newNode = (Tree) malloc(sizeof(Node));
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
            Tree newNode = (Tree) malloc(sizeof(Node));
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
            Tree newNode = (Tree) malloc(sizeof(Node));
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
int minPhones(Tree root, int* total) {
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

int main() {
    int N;
    scanf("%d", &N);

    Tree avilol = NULL;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        avilol = addToTree(avilol, num);
    }

    // print(avilol);
    // printf("\n");

    int ans = 0;
    int value = minPhones(avilol, &ans);

    if (value) {
        printf("%d\n", ans);
    }
    else {
        printf("%d\n", ans+1);
    }
    return 0;
}
