#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

/* 
 * Exercise 3.1: Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside).
 * Write a version with only one test inside the loop and measure
 * the difference in run-time.
 */

int binSearchBook(int x, int elements[], int n);
int binSearchExercise(int x, int elements[], int n);

int main() {
    int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    int result;
    int iterations = 100000;
    clock_t start, end;
    double time_book, time_exercise;

    printf("========================================\n");
    printf("Binary Search Comparison\n");
    printf("========================================\n");
    printf("Array size: %d elements (0 to %d)\n", n, n-1);
    printf("Iterations per test: %d\n", iterations);
    printf("========================================\n\n");

    printf("=== Test 1: First element (0) ===\n");

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchBook(0, arr, n);
    }
    end = clock();
    time_book = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Book version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_book);

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchExercise(0, arr, n);
    }
    end = clock();
    time_exercise = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Exercise version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_exercise);
    printf("Difference: %.3f ms (%.2f%%)\n\n",
           time_book - time_exercise, ((time_book - time_exercise) / time_book) * 100);

    printf("=== Test 2: Last element (%d) ===\n", ARRAY_SIZE-1);

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchBook(ARRAY_SIZE-1, arr, n);
    }
    end = clock();
    time_book = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Book version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_book);

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchExercise(ARRAY_SIZE-1, arr, n);
    }
    end = clock();
    time_exercise = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Exercise version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_exercise);
    printf("Difference: %.3f ms (%.2f%%)\n\n",
           time_book - time_exercise, ((time_book - time_exercise) / time_book) * 100);

    printf("=== Test 3: Middle element (%d) ===\n", ARRAY_SIZE/2);

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchBook(ARRAY_SIZE/2, arr, n);
    }
    end = clock();
    time_book = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Book version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_book);

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchExercise(ARRAY_SIZE/2, arr, n);
    }
    end = clock();
    time_exercise = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Exercise version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_exercise);
    printf("Difference: %.3f ms (%.2f%%)\n\n",
           time_book - time_exercise, ((time_book - time_exercise) / time_book) * 100);

    printf("=== Test 4: Non-existing element (-1) ===\n");

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchBook(-1, arr, n);
    }
    end = clock();
    time_book = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Book version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_book);

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchExercise(-1, arr, n);
    }
    end = clock();
    time_exercise = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Exercise version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_exercise);
    printf("Difference: %.3f ms (%.2f%%)\n\n",
           time_book - time_exercise, ((time_book - time_exercise) / time_book) * 100);

    printf("=== Test 5: Non-existing element (beyond array) ===\n");

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchBook(ARRAY_SIZE+5000, arr, n);
    }
    end = clock();
    time_book = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Book version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_book);

    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = binSearchExercise(ARRAY_SIZE+5000, arr, n);
    }
    end = clock();
    time_exercise = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
    printf("Exercise version: %s (index: %d) - %.3f ms\n",
           result != -1 ? "Found" : "Not found", result, time_exercise);
    printf("Difference: %.3f ms (%.2f%%)\n",
           time_book - time_exercise, ((time_book - time_exercise) / time_book) * 100);

    return 0;
}

/* Book version: 2 tests inside the loop */
int binSearchBook(int x, int elements[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x < elements[mid])
            high = mid - 1;
        else if (x > elements[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

/* Exercise version: 1 test inside the loop */
int binSearchExercise(int x, int elements[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;

        if (x <= elements[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (elements[low] == x)
        return low;

    return -1;
}
