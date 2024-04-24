#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matrix {
    int num_rows;
    int num_cols;
    long long int** data;
} Matrix;

Matrix* create_matrix(int r, int c);

Matrix* fill_val(Matrix* m);

Matrix* read_matrix_from_file();

void write_matrix_to_file(Matrix* M);

void destroy_matrix(Matrix* M);

Matrix* add_matrix(Matrix* A, Matrix* B);

Matrix* mult_matrix(Matrix* A, Matrix* B);

Matrix* scalar_mult_matrix(long long int s, Matrix* M);

Matrix* transpose_matrix(Matrix* A);

int check_det(Matrix* M);

long long int determinant(Matrix* M);

void print_matrix(Matrix* m);

void history();
