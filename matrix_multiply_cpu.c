#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

#define SIZE 4096

//Randomly generate a matrix of size SIZE x SIZE
int **generate_matrix() {
    int i, j;
    int **matrix = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        matrix[i] = (int *)malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++) {
            //Random number between 0 and 999
            matrix[i][j] = rand() % 1000;   
        }
    }
    return matrix;
}

int **multiply_matrices_3for(int **matrix_input0, int **matrix_input1) {
    int i, j, k;
    int **matrix_output = (int **)malloc(SIZE * sizeof(int *));

    for (i = 0; i < SIZE; i++) {
        matrix_output[i] = (int *)malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++) {
            matrix_output[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                matrix_output[i][j] += matrix_input0[i][k] * matrix_input1[k][j];
            }
        }
    }

    return matrix_output;
}

int main() {
    int i, j, k;
    int **matrix_input0 = generate_matrix();
    int **matrix_input1 = generate_matrix();

    //Start time
    time_t time_start = time(NULL);

    //compute (CPU)
    int **matrix_output_cpu = multiply_matrices_3for(matrix_input0, matrix_input1);

    //End time
    time_t time_end = time(NULL);

    //Print the execution time
    printf("Execution(CPU) time: %ld seconds\n", time_end - time_start);

    return 0;
}