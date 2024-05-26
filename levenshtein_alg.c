#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "levenshtein_alg.h"

// Function to return the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to return the minimum of three values
int min_of_three(int a, int b, int c) {
    return min(min(a, b), c);
}

// Function to calculate the Levenshtein distance between two strings
int calculate_levenshtein_distance(char source[], char target[]) {
    int source_length = strlen(source);
    int target_length = strlen(target);

    // Allocate a 2D array for dynamic programming table
    int **distance_matrix = (int **)malloc((source_length + 1) * sizeof(int *));
    for (int i = 0; i <= source_length; i++) {
        distance_matrix[i] = (int *)malloc((target_length + 1) * sizeof(int));
    }

    // Initialize the first row and first column of the distance matrix
    for (int i = 0; i <= source_length; i++) {
        distance_matrix[i][0] = i; // Cost of deleting all characters from source
    }
    for (int j = 0; j <= target_length; j++) {
        distance_matrix[0][j] = j; // Cost of inserting all characters to target
    }

    // Fill in the distance matrix
    for (int i = 1; i <= source_length; i++) {
        for (int j = 1; j <= target_length; j++) {
            if (source[i - 1] == target[j - 1]) {
                distance_matrix[i][j] = distance_matrix[i - 1][j - 1]; // No cost if characters match
            } else {
                int insertion_cost = distance_matrix[i][j - 1] + 1;
                int deletion_cost = distance_matrix[i - 1][j] + 1;
                int replacement_cost = distance_matrix[i - 1][j - 1] + 1;
                distance_matrix[i][j] = min_of_three(insertion_cost, deletion_cost, replacement_cost);
            }
        }
    }

    // The Levenshtein distance is found at the bottom-right cell of the matrix
    int result = distance_matrix[source_length][target_length];

    // Free the allocated memory for the distance matrix
    for (int i = 0; i <= source_length; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);

    return result;
}
