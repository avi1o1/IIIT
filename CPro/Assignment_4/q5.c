#include <stdio.h>

int main() {
    // Inputting the number of characters to be read
    int N;
    scanf("%d", &N);

    // Setting up flag to check if the character is within quotes
    int flag = 1;

    // Reading the characters and printing them
    while (N+1) {
        // Inputting the character
        char ele;
        scanf("%c", &ele);

        // Checking if the character is a quote
        if (ele == '"') {
            flag = flag * (-1);
        }

        // Checking if the character is a comma, and also if it falls inside quotes (updating, if required)
        else if (ele == ',' && flag == 1) {
            ele = '*';
        }

        // Printing the character element
        printf("%c", ele);
        N--;
    }

    return 0;
}
