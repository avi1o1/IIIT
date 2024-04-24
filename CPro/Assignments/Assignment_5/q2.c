#include <stdio.h>  
#include <string.h>   
      
int main() {
    // Taking input
    char str[1000000];
    scanf("%s", str);

    // Initialising the flag variable and a temporary string
    int flag = 1;
    char temp[1000000];

    // Inputting th number of cases
    int t;
    scanf("%d", &t);

    // Looping for 't' cases
    while (t) {
        // Taking input
        int val;
        scanf("%d ", &val);

        // Flag for reversing the string
        if (val == 1) {
            flag *= -1;
        }

        // Otherwise, input a string
        else {
            // Taking input
            int a;
            char b;
            scanf("%d %c", &a, &b);

            // If a new string needs to be added
            if (a == 1) {
                // If the flag is 1, input the character in the temporary string
                if (flag == 1) {
                    temp[strlen(temp)] = b;
                }
                // Otherwise, input the character in the main string
                else {
                    str[strlen(str)] = b;
                }
            }

            // In case of reversing, update flag and add the temporary string to the main string
            else {

                if (flag == 1) {
                    str[strlen(str)] = b;
                }
                else {
                    temp[strlen(temp)] = b;
                }
            }
        }
        // Decrement the counter
        t--;
    }

    // Print the final string
    if (flag == 1) {
        for (int i = strlen(temp)-1; i >= 0; i--) {
            printf("%c", temp[i]);
        }
        printf("%s\n", str);
    }
    else {
        for (int i = strlen(str)-1; i >= 0; i--) {
            printf("%c", str[i]);
        }
        printf("%s\n", temp);
    }
    return 0;
}  