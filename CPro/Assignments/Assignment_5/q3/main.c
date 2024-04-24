#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main() {
    // Taking input for th number of iterations to run
    int t;
    scanf("%d", &t);
    
    // Looping for 't' cases
    while (t) {
        // Initialising operations
        char add[] = "add_matrix";
        char mult[] = "mult_matrix";
        char sult[] = "scalar_mult_matrix";
        char trans[] = "transpose_matrix";
        char dest[] = "destroy_matrix";
        char det[] = "determinant";
        char hist[] = "history";

        // Initialising variables and taking input for the operation
        int mode;
        char cmd[24];
        scanf("%s", cmd);

        // HISTORY
        if (strcmp(cmd, hist) == 0) {
            // Opening the history file
            FILE* file;
            file = fopen("mx_history", "a");

            // If the file does not exist, create a new file
            if (file == NULL) {
                file = fopen("mx_history", "w");
            }

            // Write the operation to the file
            fprintf(file, "LOG::history\n");
            fclose(file);

            // Reading and printing the contents of the history file
            history();
        }

        // For non-history operations
        else {
            // Taking input for the mode
            scanf("%d", &mode);

            // Opening the history file
            FILE* file;
            file = fopen("mx_history", "a");

            // If the file does not exist, create a new file
            if (file == NULL) {
                file = fopen("mx_history", "w");
            }
            // Write the operation to the file
            fprintf(file, "LOG::%s %d\n", cmd, mode);

            // Closing the file
            fclose(file);
        }

        // ADD_MATRIX
        if (strcmp(cmd, add) == 0) {
            Matrix* M1;
            Matrix* M2;
            
            // If the mode is 0, read the matrices from the user
            if (mode == 0) {
                int a, b, m, n;

                scanf("%d %d", &a, &b);
                M1 = create_matrix(a, b);
                fill_val(M1);

                scanf("%d %d", &m, &n);
                M2 = create_matrix(m, n);
                fill_val(M2);

                Matrix* ans = add_matrix(M1, M2);

                if (ans != NULL) {
                    print_matrix(ans);
                }
            }
            
            // If the mode is 1, read the matrices from the file
            else {
                M1 = read_matrix_from_file();
                M2 = read_matrix_from_file();

                Matrix* ans = add_matrix(M1, M2);

                write_matrix_to_file(ans);
            }
        }

        // MULT_MATRIX
        else if (strcmp(cmd, mult) == 0) {
            Matrix* M1;
            Matrix* M2;

            // If the mode is 0, read the matrices from the user
            if (mode == 0) {
                int a, b, m, n;

                scanf("%d %d", &a, &b);
                M1 = create_matrix(a, b);
                fill_val(M1);

                scanf("%d %d", &m, &n);
                M2 = create_matrix(m, n);
                fill_val(M2);

                Matrix* ans = mult_matrix(M1, M2);

                if (ans != NULL) {
                    print_matrix(ans);
                }
            }

            // If the mode is 1, read the matrices from the file
            else {
                M1 = read_matrix_from_file();
                M2 = read_matrix_from_file();

                Matrix* ans = mult_matrix(M1, M2);

                write_matrix_to_file(ans);
            }
        }

        // SCALAR_MULT_MATRIX
        else if (strcmp(cmd, sult) == 0) {
            Matrix* M;
            int s;
            scanf("%d", &s);

            // If the mode is 0, read the matrix from the user
            if (mode == 0) {
                int a, b;
                
                scanf("%d %d", &a, &b);
                M = create_matrix(a, b);
                fill_val(M);

                Matrix* ans = scalar_mult_matrix(s, M);
                print_matrix(ans);
            }

            // If the mode is 1, read the matrix from the file
            else {
                M = read_matrix_from_file();

                Matrix* ans = scalar_mult_matrix(s, M);

                write_matrix_to_file(ans);
            }
        }

        // TRANSPOSE_MATRIX
        else if (strcmp(cmd, trans) == 0) {
            Matrix* M;

            // If the mode is 0, read the matrix from the user
            if (mode == 0) {
                int a, b;
                
                scanf("%d %d", &a, &b);
                M = create_matrix(a, b);
                fill_val(M);

                Matrix* ans = transpose_matrix(M);
                print_matrix(ans);
            }

            // If the mode is 1, read the matrix from the file
            else {
                M = read_matrix_from_file();

                Matrix* ans = transpose_matrix(M);

                write_matrix_to_file(ans);
            }
        }

        // DETERMINANT
        else if (strcmp(cmd, det) == 0) {
            Matrix* M;

            // If the mode is 0, read the matrix from the user
            if (mode == 0) {
                int a, b;
                
                scanf("%d %d", &a, &b);
                M = create_matrix(a, b);
                fill_val(M);  
            }

            // If the mode is 1, read the matrix from the file
            else {
                M = read_matrix_from_file();
            }

            // Check if the matrix is a square matrix
            if (check_det(M)) {
                // Calculate and print the determinant
                long long int ans = determinant(M);
                printf("%lld\n", ans);
            }
        }

        // HISTORY (void operation)
        else if(strcmp(cmd, hist) == 0) {
            char* truth = "ur_mom_gey";
        }

        // INVALID
        else {
            printf("ERROR: INVALID ARGUMENT\n");
        }

        // Decrement the counter
        t--;        
    }
    return 0;
}