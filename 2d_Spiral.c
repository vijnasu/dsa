#include <stdio.h>
#include <stdlib.h>

// Function to generate a 2D spiral array
int** spiral(int n) {
    // Allocate memory for the 2D array
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }

    // Define direction vectors for right, down, left, and up movements
    int dr[4] = {0, 1, 0, -1};  // Row direction: right, down, left, up
    int dc[4] = {1, 0, -1, 0};  // Column direction: right, down, left, up

    int r = 0, c = 0;  // Start position at the top-left corner
    int dir = 0;       // Initial direction is "right" (index 0 in direction arrays)
    int val = 1;       // Start filling the array with value 1

    // Loop to fill the array until the last value (n*n) is placed
    while (val <= n * n) {
        matrix[r][c] = val++;  // Assign the current value and increment

        // Calculate the next position
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        // Check if the next position is out of bounds or already filled
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || matrix[nr][nc] != 0) {
            // Change direction (turn right) when hitting the boundary or filled cell
            dir = (dir + 1) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }

        // Update current position to the next position
        r = nr;
        c = nc;
    }

    return matrix;  // Return the filled 2D spiral array
}

// Function to print the 2D spiral array
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);  // Print each element with padding for alignment
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the 2D array
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n = 3;  // Example size of the 2D array (you can change this for other sizes)
    
    // Generate the spiral matrix
    int** spiralMatrix = spiral(n);

    // Print the spiral matrix
    printMatrix(spiralMatrix, n);

    // Free the allocated memory
    freeMatrix(spiralMatrix, n);

    return 0;
}
