#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/* Helper function to check if an array is sorted */
bool is_sorted(int *array, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

/* Test function for bubble_sort */
void test_bubble_sort(int *array, size_t size) {
    printf("Original array: ");
    print_array(array, size);

    // Make a copy of the original array to compare with the sorted result
    int *expected_array = malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
        expected_array[i] = array[i];
    }

    // Sort the array using bubble_sort
    bubble_sort(array, size);

    printf("Sorted array:   ");
    print_array(array, size);

    // Check if the array is correctly sorted
    bool sorted_correctly = is_sorted(array, size);
    printf("Test result:    %s\n\n", sorted_correctly ? "PASSED" : "FAILED");

    // Free dynamically allocated memory
    free(expected_array);
}

int main() {
    // Test cases
    int test1[] = {5, 2, 9, 1, 5, 6};
    size_t size1 = sizeof(test1) / sizeof(test1[0]);

    int test2[] = {1, 2, 3, 4, 5};
    size_t size2 = sizeof(test2) / sizeof(test2[0]);

    int test3[] = {5, 4, 3, 2, 1};
    size_t size3 = sizeof(test3) / sizeof(test3[0]);

    int test4[] = {2, 2, 2, 2, 2};
    size_t size4 = sizeof(test4) / sizeof(test4[0]);

    // Randomly generated test case
    int test5[] = {10, 3, 6, 8, 1, 7, 4, 5, 9, 2};
    size_t size5 = sizeof(test5) / sizeof(test5[0]);

    test_bubble_sort(test1, size1);
    test_bubble_sort(test2, size2);
    test_bubble_sort(test3, size3);
    test_bubble_sort(test4, size4);
    test_bubble_sort(test5, size5);

    return 0;
}

