#include <stdio.h>
#include <string.h>

// Helper function to rotate a string
char* rotate(char* str) {
    char first = str[0];
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i+1];
    }
    str[strlen(str)] = first;
    return str;
}

// Function to get the minimum permutation of a string
char* min_perm(char* word) {
    char min[1000];
    strcpy(min, word);

    for (int i = 0; i < strlen(word); i++) {        
        if (strcmp(word, min) > 0) {
            strcpy(word, min);
        }
        char* result = rotate(min);
        strcpy(min, result);
    }
    return word;
}

// Function to get the maximum permutation of a string
char* max_perm(char* word) {
    char max[1000];
    strcpy(max, word);

    for (int i = 0; i < strlen(word); i++) {        
        if (strcmp(word, max) < 0) {
            strcpy(word, max);
        }
        char* result = rotate(max);
        strcpy(max, result);
    }
    return word;
}

int main() {
    char words[1000];
    scanf("%s", words);

    printf("%s\n", min_perm(words));
    printf("%s\n", max_perm(words));

    return 0;
}
