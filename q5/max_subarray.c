#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomArray(int arr[], int size, unsigned int seed);
int maxSubArraySumN(int arr[], int size);
int maxSubArraySumN2(int arr[], int size);
int maxSubArraySumN3(int arr[], int size);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <random_seed> <array_size>\n", argv[0]);
        return 1;
    }

    // Read command line arguments
    unsigned int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    // Allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Generate random array
    generateRandomArray(arr, size, seed);

    clock_t start, end;
    double cpu_time_used;

    // Measure and print time for O(n) algorithm
    start = clock();
    int maxSumN = maxSubArraySumN(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Max Subarray Sum (O(n)): %d, Time: %f seconds\n", maxSumN, cpu_time_used);

    // Measure and print time for O(n^2) algorithm
    start = clock();
    int maxSumN2 = maxSubArraySumN2(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Max Subarray Sum (O(n^2)): %d, Time: %f seconds\n", maxSumN2, cpu_time_used);

    // Measure and print time for O(n^3) algorithm
    start = clock();
    int maxSumN3 = maxSubArraySumN3(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Max Subarray Sum (O(n^3)): %d, Time: %f seconds\n", maxSumN3, cpu_time_used);

    // Free allocated memory
    free(arr);
    return 0;
}

// Function to generate random array with values in range [-25, 74]
void generateRandomArray(int arr[], int size, unsigned int seed) {
    srand(seed);
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 25;
    }
}

// O(n) algorithm for maximum subarray sum (Kadane's Algorithm)
int maxSubArraySumN(int arr[], int size) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (int i = 1; i < size; i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here < arr[i]) 
            max_ending_here = arr[i];
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

// O(n^2) algorithm for maximum subarray sum
int maxSubArraySumN2(int arr[], int size) {
    int max_sum = arr[0];

    for (int i = 0; i < size; i++) {
        int current_sum = 0;
        for (int j = i; j < size; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) 
                max_sum = current_sum;
        }
    }
    return max_sum;
}

// O(n^3) algorithm for maximum subarray sum
int maxSubArraySumN3(int arr[], int size) {
    int max_sum = arr[0];

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int current_sum = 0;
            for (int k = i; k <= j; k++) {
                current_sum += arr[k];
            }
            if (current_sum > max_sum) 
                max_sum = current_sum;
        }
    }
    return max_sum;
}

