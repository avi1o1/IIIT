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

bool isSame(Node* T1, Node* T2) {
    if (!T1 && !T2) {
        return true;
    }

    if (!T1 || !T2) {
        return false;
    }

    return T1->val == T2->val && isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr1[N];
    int arr2[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr2[i]);
    }

    Node* Tree1 = createTree(arr1, N);
    Node* Tree2 = createTree(arr2, N);

    if (isSame(Tree1, Tree2)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}