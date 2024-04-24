/* Assignment 3, Question 3 : Cipher Distance */

#include <stdio.h>
#include <string.h>

// Helper function to find the maximum of two integers
int max(int n1, int n2) {
    if (n1 > n2) {
        return n1;
    }
    return n2;
}

// Helper function to print a character array
void print(char* arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int main() {
    // Taking input
    int n, k;
    char l;
    scanf("%d %d", &n, &k);
    scanf("%c", &l);

    char arr[n+1];
    int lst[n+1];
    int high_lst[n+1];
    scanf("%s", arr);

    // Initialising sum and high
    int sum = 0;
    int high = 0;
    for (int i = 0; i < n; i++) {
        int asci = arr[i];
        sum += asci-97;
        high += max(asci-97, 122-asci);
        lst[i] = asci-97;
        high_lst[i] = max(asci-97, 122-asci);
    }

    // Initialising the alphabet array
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Checking for edge cases (k == 1)
    if (k == 1) {
        for (int r = 0; r < n; r++) {
            if (arr[r] != 'a') {
                arr[r] = arr[r] -= 1;
                break;
            }
        }
        print(arr, n);
    }

    // Checking for edge cases (k == 25*n && arr[n-1] == 'z')
    else if (k == 25*n && arr[n-1] == 'z') {
        for (int r = 0; r < n; r++) {
            arr[r] = 'a';
        }
        print(arr, n);
    }
    
    // Other cases
    else {
        // Checking if the sum is less than k
        if (sum < k) {
            // Checking if the high is less than k
            if (k > high) {
                printf("-1\n");
            }

            // If high is greater than k
            else {
                // Initialising the text array
                char txt[n+1];
                k -= sum;
                for (int j = 0; j < n; j++) {
                    txt[j] = 'a';
                }

                int index = n-1;
                while (k) {
                    // If the high value is greater than the current value, set the character to 'z'
                    if (high_lst[index] > lst[index]) {
                        if (high_lst[index] - lst[index] < k) {
                            k -= high_lst[index] - lst[index];
                            txt[index] = 'z';
                        }

                        // If the high value is less than the current value, set the character to the appropriate value
                        else {
                            int ctr = 0;
                            for (int a = 0; a < 26; a++) {
                                if (alpha[a] == arr[index]) {
                                    ctr = a;
                                    break;
                                }
                            }
                            txt[index] = alpha[2*ctr+k];
                            k = 0;
                        }
                    }
                    // Updating index
                    index--;
                }
                // Printing the text array
                print(txt, n);
            }
        }

        // If the sum is greater than k
        else {
            int index = 0;

            // While k is greater than the current value, set characters to 'a'
            while (k > lst[index]) {
                k -= lst[index];
                lst[index] = 0;
                arr[index] = 'a';
                index++;
            }

            // If k is equal to the current value, set character to 'a'
            if (lst[index] == k) {
                k = 0;
                arr[index] = 'a';
            }

            // If k is less than the current value, set the final character to the appropriate value
            else if (lst[index] > k){
                int ctr = 0;
                for (int j = 0; j < n; j++) {
                    if (alpha[j] == arr[index]) {
                        ctr = j;
                        break;
                    }
                }
                arr[index] = alpha[lst[index]-k];
            }

            // Printing the array
            print(arr, n);
        }
    }
    return 0;
}
