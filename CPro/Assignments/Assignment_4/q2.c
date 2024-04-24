// Need to run gcc with math library

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Defining the structure of the linked list
typedef struct field{
    float value;
    struct field* next;
} field;
typedef field* LinkedList;

// Function prototypes
LinkedList INPUT(int N) {
    /* Input  : Dimensionality of the complex number
       Output : Returns the address of the first vector of the complex number (in reversed order)
    */

    LinkedList prev1 = NULL;
    for (int i = 0; i < N; i++) {
        float num1;
        scanf("%f", &num1);

        LinkedList record = (LinkedList) malloc(sizeof(field));
        record->value = num1;
        record->next = prev1;

        prev1 = record;
    }
    return prev1;
}

void print(LinkedList l) {
    /* Input  : Address of the first vector of the complex number (final answer).
       Output : Prints the complete complex number (in reversed, ie, correct order).
    */

    while (l != NULL) {
        printf("%.2f ", l->value);
        l = l->next;
    }
    printf("\n\n");
}

float MODULUS(LinkedList l) {
    /* Input  : Address of the first vector of the complex number.
       Output : Returns the modulus of the complex number.
    */

    float ans = 0;

    while (l != NULL) {
        ans += l->value * l->value;
        l = l->next;
    }
    return sqrt(ans);
}

LinkedList ADD(LinkedList l1, LinkedList l2) {
    /* Input  : Address of the first vector of the two complex numbers.
       Output : Returns the sum of the two complex number.
    */

    float ans = 0;

    LinkedList prev = NULL;
    while (l1 != NULL) {
        LinkedList ans = (LinkedList) malloc(sizeof(field));
        ans->value = l1->value + l2->value;
        ans->next = prev;
        l1 = l1->next;
        l2 = l2->next;
        prev = ans;
    }
    return prev;
}

LinkedList SUB(LinkedList l1, LinkedList l2) {
    /* Input  : Address of the first vector of the two complex numbers.
       Output : Returns the difference of the two complex number.
    */

    float ans = 0;

    LinkedList prev = NULL;
    while (l1 != NULL) {
        LinkedList ans = (LinkedList) malloc(sizeof(field));
        ans->value = l1->value - l2->value;
        ans->next = prev;
        l1 = l1->next;
        l2 = l2->next;
        prev = ans;
    }
    return prev;
}

float DOT(LinkedList l1, LinkedList l2) {
    /* Input  : Address of the first vector of the two complex numbers.
       Output : Returns the dot product of the two complex number.
    */

    float ans = 0;

    while (l1 != NULL) {
        ans += l1->value * l2->value;
        l1 = l1->next;
        l2 = l2->next;
    }
    return ans;
}

float COSINE(LinkedList l1, LinkedList l2) {
    /* Input  : Address of the first vector of the two complex numbers.
       Output : Returns the cosine-similarity of the two complex number.
    */

    float ans = DOT(l1, l2) / (MODULUS(l1)*MODULUS(l2));

    return ans;
}

int main() {
    // Defining the operations
    char check[] = "-1";
    char mod[] = "MOD";
    char add[] = "ADD";
    char sub[] = "SUB";
    char dot[] = "DOT";
    char cos[] = "COSINE";

    // Indefinitely looping until the user enters -1
    while (true) {
        // Setting up variables and taking input
        char x = '\0';
        int n;
        char op[3];
        scanf("%s", op);

        // EXIT condition
        if (strcmp(op, check) == 0) {
            break;
        }

        // Taking the dimensionality of the complex number
        scanf("%d", &n);

        // MODULUS operation
        if (strcmp(op, mod) == 77) {
            LinkedList num = INPUT(n);
            printf("Result : ");
            printf("%.2f \n\n", MODULUS(num));
        }

        // ADD operation
        else if (strcmp(op, add) == 0) {
            LinkedList num1 = INPUT(n);
            LinkedList num2 = INPUT(n);
            printf("Result : ");
            print(ADD(num1, num2));
        }

        // SUB operation
        else if (strcmp(op, sub) == 0) {
            LinkedList num1 = INPUT(n);
            LinkedList num2 = INPUT(n);
            printf("Result : ");                
            print(SUB(num1, num2));
        }

        // DOT operation
        else if (strcmp(op, dot) == 0) {
            LinkedList num1 = INPUT(n);
            LinkedList num2 = INPUT(n);
            printf("Result : ");
            printf("%.2f \n\n", DOT(num1, num2));
        }

        // COSINE operation
        else if (strcmp(op, cos) == 0) {
            LinkedList num1 = INPUT(n);
            LinkedList num2 = INPUT(n);
            printf("Result : ");
            printf("%.2f \n\n", COSINE(num1, num2));
        }

        // Invalid operation
        else {
            // printf("\n * Ur mom gey! [ Invalid Input ] * \n");
            printf("\n * Task Failed Successfully! [ Invalid Input ] * \n\n");
        }
    }
    return 0;
}
