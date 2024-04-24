#include <stdio.h>
#include <stdlib.h>

// Defining the structure of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef Node* LinkedList;

// Function prototypes
LinkedList APPEND(LinkedList l, int ele) {
    /* Input  : Linkedlist containing all unique colours & the new unique colour.
       Output : Returns a modified original linked-list, with the new unique
                colour appended to it.
    */

    Node* node = (Node *) malloc(sizeof(Node));
    node->data = ele;
    node->next = NULL;

    if (l == NULL) {
        return node;
    }

    else {
        l->next = APPEND(l->next, ele);
        return l;
    }
}

LinkedList INPUT(LinkedList l, int count) {
    /* Input  : An empty Linkedlist & the number of colours to be inputted.
       Output : Returns a Linkedlist of inputted colours.
    */

    printf("Enter the colours: ");

    while (count) {
        int colour;
        scanf("%d", &colour);

        l = APPEND(l, colour);
        count--;
    }
    return l;
}

LinkedList REM_DUP(LinkedList l) {
    /* Input  : The original input LinkedList.
       Output : Returns the original inputted Linkedlist without any duplicates.
    */

    LinkedList original = l;
    LinkedList prev = NULL;
    int last_val = -1;
    
    while (l != NULL) {
        if (l->data == last_val) {
            prev->next = l->next;
        }

        else {
            prev = l;
        }
        
        last_val = l->data;
        l = l->next;
    }
    return original;
}

void PRINT(LinkedList l) {
    /* Input  : Address of the first colour of the palette (final unique-only palette).
       Output : Prints all the unique colours.
    */

    printf("%d", l->data);
    l = l->next;

    while (l != NULL) {
        printf(" -> %d", l->data);
        l = l->next;
    }
    printf("\n");
}

int main() {
    // Taking input for the number of colours
    printf("Input:\n");
    printf("Enter the number of colors in the list: ");
    int n;
    scanf("%d", &n);

    // Initialising the linked list
    LinkedList lst = NULL;
    lst = INPUT(lst, n);

    // Removing duplicates
    lst = REM_DUP(lst);

    // Printing the final linked list
    printf("\nOutput:\n");
    printf("Modified Linked List: ");
    PRINT(lst);

    return 0;
}
