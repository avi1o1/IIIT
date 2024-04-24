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

LinkedList insertStart(LinkedList head, int ele) {
    LinkedList newNode = (LinkedList) malloc(sizeof(Node));
    newNode->val = ele;
    newNode->next = head;

    return newNode;
}

LinkedList reverseList(LinkedList head) {
    LinkedList prev = NULL;

    if (head == NULL) {
        return head;
    }
    
    while (head->next != NULL) {
        LinkedList temp = head->next;
        head->next = prev;

        prev = head;
        head = temp;
    }

    head->next = prev;
    return head;
}

int main() {
    LinkedList front = NULL;
    LinkedList mid = NULL;
    LinkedList rear = NULL;

    int n, start, end;
    scanf("%d %d %d", &n, &start, &end);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (i < start-1) {
            front = insertStart(front, num);
        }
        else if (i >= end) {
            rear = insertStart(rear, num);
        }
        else {
            mid = insertStart(mid, num);
        }
    }

    front = reverseList(front);
    rear = reverseList(rear);

    LinkedList List = NULL;

    if (front != NULL) {
        List = front;
    }

    if (List == NULL) {
        List = mid;
    }
    else {
        LinkedList temp = List;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = mid;
    }

    if (List == NULL) {
        List = rear;
    }
    else {
        LinkedList temp = List;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = rear;
    }

    //###########################################################################################
    
    print(List);
    return 0;
}
