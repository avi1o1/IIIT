#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef struct Node{
    int val;
    struct Node* right;
    struct Node* left;
} Node;

Node* init(int x){
    Node* head = (Node*) malloc(sizeof(Node));
    head->right = NULL;
    head->left = NULL;
    head->val = x;
    return head;
}

Node* createTree(int* arr, int n){
    Node* v[n];
    for(int i=0;i<n;i++){
        if(arr[i] != -1){
            v[i] = init(arr[i]);
        }
    }

    int idx = 0;

    while(idx<n){
        if(arr[idx] == -1){
            idx+=1;
            continue;
        }
        if(2*idx+1<n && arr[2*idx+1]!=-1){
            v[idx]->left = v[2*idx+1];
        }
        if(2*idx+2<n && arr[2*idx+2]!=-1){
            v[idx]->right = v[2*idx+2];
        }
        idx+=1;
    }
    return v[0];
}

long long int urmom(Node* tree) {
    if (tree == NULL) {
        return 0;
    }

    int grandChildren = 0;
    if (tree->left != NULL) {
        if (tree->left->left != NULL) {
            grandChildren++;
        }
        if (tree->left->right != NULL) {
            grandChildren++;
        }
    }
    if (tree->right != NULL) {
        if (tree->right->left != NULL) {
            grandChildren++;
        }
        if (tree->right->right != NULL) {
            grandChildren++;
        }
    }
    // printf("%d %d\n", tree->val, grandChildren);

    if (tree->val % 2 == 0) {
        return ((tree->val)*grandChildren) + urmom(tree->left) + urmom(tree->right);
    }
    else {
        return urmom(tree->left) + urmom(tree->right);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr1[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }

    Node* Tree = createTree(arr1, N);
    long long int ans = urmom(Tree);
    printf("%lld\n", ans);
    return 0;
}