/* Assignment 3, Question 5 : Maximum Irritation */

#include <stdio.h>

int main() {
    // Taking input
    int t;
    scanf("%d", &t);

    // Looping for 't' cases
    while (t) {
        // Taking input
        int n;
        scanf("%d", &n);
        
        // Initialising array
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int ctr[n]; 

        // Traversing to find the maximum irritation
        int max = 0;
        for (int i = n-1; i >= 0; i--) {
            // Initialising a temp irritation level
            int ans = 0;
            
            // Checking if the irritation level is within bounds
            if (i + arr[i] < n) {
                ans = arr[i] + ctr[i + arr[i]];
                ctr[i] = ans;
            }

            // If not, set the irritation level to the current level
            else {
                ans = arr[i];
                ctr[i] = ans;
            }

            // Update max, if required
            if (ans > max) {
                max = ans;
            }
            
        }

        // Printing the maximum irritation level
        printf("%d\n", max);
        t--;
    }
    return 0;
}
