/* Assignment 3, Question 2 : String Permutations */

#include <stdio.h>
#include <string.h>

// Helper function for swapping two characters
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Helper function for string rearrangement
void rearrange(char str[], int start, int end) {
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

// Function to get the next permutation of a string
void next(char str[]) {
    int x = 0, y = 0;

    // Find the rightmost character which is smaller than its next character
    for (x = strlen(str)-2; x >= 0; x--) {
        if (str[x] < str[x + 1]) {
            break;
        }
    }

    // If no such character is found, then all permutations are done
    if (x < 0) {
        return;
    }
    
    // Find the smallest character on right side of x which is greater than str[x]
    for (y = strlen(str) - 1; y > x; y--) {
        if (str[y] > str[x]) break;
    }

    // Swap the above found two characters
    swap(&str[x], &str[y]);
    rearrange(str, x + 1, strlen(str) - 1);
    return;
}

int main() {
    // Taking input
    char str[9];
    scanf("%s", str);
    int n = strlen(str);

    // Sorting the string
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                swap(&str[i], &str[j]);
            }
        }
    }
    
    // Hardcoding the factorial values ( to use basic PNC formula )
    int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

    // Calculating the frequency of each character
	int freq[26] = {0};
    int index = 0;
	while (str[index] != '\0') {
		freq[str[index] - 'a'] += 1;
		index++;
	}

    // Calculating the denominator
    int den = 1;
    for (int j = 0; j < 26; j++) {
        den = den * fact[freq[j]];
    }

    // Calculating the total number of permutations
    int total = fact[n] / den;
    printf("%d\n", total);

    // Printing all the permutations
    while (total) {
        printf("%s\n", str);
        next(str);
        total--;
    }

    return 0;
}

