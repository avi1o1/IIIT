/* Assignment 3, Question 1 : Beautiful String */

#include <stdio.h>

int main() {
    // Initialising input array and index pointer
    char arr[100];
    int i = 0;

    // Setting up flags
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 1;
    
    // Taking input
    while (arr[i-1] != '\n') {
        scanf("%c", &arr[i]);
        i++;
    }

    // Initialising counter array
    int ctr[i];

    // Checking for conditions
    int index = 0;
    for (int j = 0; j < i; j++) {
        int d = arr[j];

        // Checking if the character is already present in the counter array
        for (int m = 0; m < index; m++) {
            if (ctr[m] == arr[j]) {
                flag3 = 0;
            }
        }
        
        // Checking if the character is an uppercase letter
        if (65 <= d && d <= 90) {
            flag1 = 1;
            ctr[index] = arr[j];
            index++;
        }

        // Checking if the character is a lowercase letter
        if (97 <= d && d <= 122) {
            flag2 = 1;
            ctr[index] = arr[j];
            index++;
        }
    }

    // If all flags are set (conditions satisfied), print "Yes"
    if (flag1 && flag2 && flag3) {
        printf("Yes\n");
    }
    // If any of the flags are not set (condition/s not satisfied), print "No"
    else {
        printf("No\n");
    }

    return 0;
}
