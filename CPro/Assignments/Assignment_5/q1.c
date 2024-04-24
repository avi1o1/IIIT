/* Assignment 5, Question 1 : H-Factor */

#include <stdio.h>
#include <string.h>

// Function to check the number of substrings of length 'h' that contain only character 'c'
int check(char* str, char c, int n, int h) {
    int total = 0;
    int i = 0;

    // Loop to check all substrings of length 'h'
    while (i < h || i+h <= n) {
        int flag = 0;

        // Loop to check if all characters in the substring are equal to 'c'
        for (int j = i; j < i+h; j++) {
            if (str[j] != c) {
                flag = 1;
                break;
            }
        }
        
        // If all characters are equal to 'c', increment the total count and move to the next substring
        if (flag == 0) {
            total++;
            i += h;
        }

        // Otherwise, move to the next substring
        else {
            i++;
        }
    }
    // Return the total count of substrings
    return total;
}

int main() {
    // Taking input
    int n, h;
    scanf("%d %d", &n, &h);
    char str[n];
    scanf("%s", str);

    // Initialising variables and reference list of all characters
    int ans = 0;
    char check_list[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                           'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Loop to check the number of substrings for each character
    for (int k = 0; k < 26; k++) {
        int val = check(str, check_list[k], n, h);
        if (val > ans) {
            ans = val;
        }
    }

    // Printing the maximum number of substrings
    printf("%d\n", ans);
    return 0;
}