#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

Matrix* create_matrix(int r, int c) {
    /* Input  : Number of rows and columns of the matrix
       Output : Creates and returns an empty matrix.
    */

    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int**) calloc(r, sizeof(long long int*));

    for (int i =0; i < r; i++) {
        m->data[i] = (long long int*) calloc(c, sizeof(long long int));
    }

    return m;
}

Matrix* fill_val(Matrix* m) {
    /* Input  : A matrix structure
       Output : Fills the value in the matrix, and returns it.
    */

    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            scanf("%lld", &m->data[i][j]);
        }
    }
    return m;
}

void destroy_matrix(Matrix* m) {
    /* Input  : A matrix structure
       Output : Deletes the matrix, and frees all memory used by it
    */

   free(m);
}

Matrix* add_matrix(Matrix* A, Matrix* B) {
    /* Input  : Two matrix structures
       Output : A new matrix, which is the sum of the two matrices, while A and B
                remain unmodified. If dimensions don't match, return NULL.
    */

    if (A->num_rows != B->num_rows || A->num_cols != B->num_cols) {
        printf("ERROR: INVALID ARGUMENT\n");
        return NULL;   
    }

    Matrix* sum = create_matrix(A->num_rows, B->num_cols);

    for (int i = 0; i < sum->num_rows; i++) {
        for (int j = 0; j < sum->num_cols; j++) {
            sum->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
    return sum;
}

Matrix* mult_matrix(Matrix* A, Matrix* B) {
    /* Input  : Two matrix structures
       Output : A new matrix, which is the matrix multiplication of the two matrices,
                while A and B remain unmodified. If dimensions don't match, return NULL.
    */

    if (A->num_rows != B->num_cols) {
        printf("ERROR: INVALID ARGUMENT\n");
        return NULL;
    }

    Matrix* sum = create_matrix(A->num_rows, B->num_cols);

    for (int i = 0; i < sum->num_rows; i++) {
        for (int j = 0; j < sum->num_cols; j++) {
            sum->data[i][j] = A->data[i][j] * B->data[j][i];
        }
    }
    return sum;
}

Matrix* scalar_mult_matrix(long long int s, Matrix* M) {
    /* Input  : A scalar & a matrix structure
       Output : A new matrix, which is the scalar product of the two matrices, while A
                and B remain unmodified. If dimensions don't match, return NULL.
    */

    Matrix* scalar = create_matrix(M->num_rows, M->num_cols);

    for (int i = 0; i < scalar->num_rows; i++) {
        for (int j = 0; j < scalar->num_cols; j++) {
            scalar->data[i][j] = s*M->data[i][j];
        }
    }
    return scalar;
}

Matrix* transpose_matrix(Matrix* M) {
    /* Input  : A matrix structure
       Output : A new matrix, which is the transpose of the two matrices, while A remains
                unmodified.
    */

    Matrix* transpose = create_matrix(M->num_cols, M->num_rows);

    for (int i = 0; i < transpose->num_cols; i++) {
        for (int j = 0; j < transpose->num_rows; j++) {
            transpose->data[j][i] = M->data[i][j];
        }
    }
    return transpose;
}

int check_det(Matrix* M) {
    if (M->num_cols != M->num_rows) {
        printf("ERROR: INVALID ARGUMENT\n");
        return 0;
    }
    return 69;
}

long long int determinant(Matrix* M) {
    /* Input  : A matrix structure
       Output : Calculates and returns the determinant of the provided matrix. If not a
                square matrix, return -1.
    */

    if (M->num_cols == 2) {
        return M->data[0][0]*M->data[1][1] - M->data[0][1]*M->data[1][0];
    }

    else {
        Matrix* Minor = create_matrix(M->num_rows-1, M->num_cols-1);
        long long int value = 0;
        int c[100];
        int O = 1;

        for(int i = 0 ; i < M->num_rows; i++) {
            int c1 = 0, c2 = 0;

            for(int j = 0 ; j < M->num_rows; j++) {
                for(int k = 0 ; k < M->num_cols; k++) {
                    if(j != 0 && k != i) {
                        Minor->data[c1][c2] = M->data[j][k];
                        c2++;

                        if (c2 > M->num_rows-2) {
                            c1++;
                            c2 = 0;
                        }
                    }
                }
            }
            value += O*(M->data[0][i]*determinant(Minor));
            O *= -1;
        }
        return value;
    }
}

void print_matrix(Matrix* m) {
    /* Input  : A matrix structure
       Output : Prints the provided matrix
    */

    printf("%d %d\n", m->num_rows, m->num_cols);

    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* read_matrix_from_file() {
    /* Input  : Nothing
       Output : Inputs and returns a matrix, read from the input file.
    */
    
    char filename[64];
    char data[100];
    scanf("%s", filename);

    FILE* fPtr;
    fPtr = fopen(filename, "r");
    
    if(fPtr == NULL) {
        printf("ERROR: INVALID ARGUMENT\n");
        return NULL;
    }

    int r, c;
    fscanf(fPtr, "%d %d", &r, &c);

    Matrix* M = create_matrix(r, c);

    for (int i = 0; i < M->num_rows; i++) {
        for (int j = 0; j < M->num_cols; j++) {
            fscanf(fPtr, "%lld", &M->data[i][j]);
        }
    }
    fclose(fPtr);

    return M;
}

void write_matrix_to_file(Matrix* M) {
    /* Input  : A matrix structure
       Output : Prints the provided matrix into the provided file
    */

    char filename[64];
    scanf("%s", filename);

    FILE* fPtr;
    fPtr = fopen(filename, "w");
    
    if(fPtr == NULL) {
        printf("ERROR: INVALID ARGUMENT\n");
        return;
    }


    fprintf(fPtr, "%d %d\n", M->num_rows, M->num_cols);

    for (int i = 0; i < M->num_rows; i++) {
        for (int j = 0; j < M->num_cols; j++) {
            fprintf(fPtr, "%lld ", M->data[i][j]);
        }
        fprintf(fPtr, "\n");
    }
}

void history() {
    /* Input  : None
       Output : Retreives and prints the history of all the functions.
    */

    FILE* fPtr;
    fPtr = fopen("mx_history", "r");
    
    if(fPtr == NULL) {
        printf("ERROR: INVALID ARGUMENT\n");
        return;
    }

    char data[100];

    while (fgets(data, 100, fPtr)) {
        printf("%s", data);
    }
}
