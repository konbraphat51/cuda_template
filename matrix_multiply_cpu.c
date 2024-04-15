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

int main() {
    int 

    return 0;
}