#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef Node* LinkedList;

void print(LinkedList head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

LinkedList deleteAtIndex(LinkedList head, int index) {
    if (head == NULL) {
        return NULL;
    }

    if (index == 0) {
        LinkedList temp = head->next;
        free(head);
        return temp;
    }
    else {
        LinkedList temp = head;
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
        }

        LinkedList loser = temp->next;
        temp->next = temp->next->next;
        free(loser);

        return head;        
    }
}

LinkedList insertAtIndex(LinkedList head, int index, int ele) {
    LinkedList newNode = (LinkedList) malloc(sizeof(Node));
    newNode->val = ele;

    if (head == NULL) {
        newNode->next = NULL;
        return newNode;
    }

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }
    else {
        LinkedList temp = head;
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
}

int main() {
    LinkedList LL = NULL;

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int a;
        scanf("%d", &a);

        if (a) {
            int b;
            scanf("%d", &b);

            LL = deleteAtIndex(LL, b);
            print(LL);
        }

        else {
            int b, c;
            scanf("%d %d", &b, &c);

            LL = insertAtIndex(LL, b, c);
            print(LL);
        }
    }

    return 0;
}

// array arr [69] int* char*.
// What else will annoy us...