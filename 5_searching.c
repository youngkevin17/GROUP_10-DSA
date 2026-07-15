#include <stdio.h>

#define SIZE 20

int linearSearch(int arr[], int n, int target, int *comparisons);
int binarySearch(int arr[], int n, int target, int *comparisons);

int main(void)
{
    int arr[SIZE] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29,
                      32, 35, 38, 41, 44, 47, 50, 53, 56, 59};
    int target = 44;
    int comparisonsLinear;
    int comparisonsBinary;
    int indexLinear;
    int indexBinary;
    int i;

    printf("Sorted array of %d items:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Searching for target value: %d\n\n", target);

    indexLinear = linearSearch(arr, SIZE, target, &comparisonsLinear);
    printf("Linear Search: found at index %d, comparisons = %d\n", indexLinear, comparisonsLinear);

    indexBinary = binarySearch(arr, SIZE, target, &comparisonsBinary);
    printf("Binary Search: found at index %d, comparisons = %d\n", indexBinary, comparisonsBinary);

    return 0;
}

/* Linear search: O(n) - checks each element in order until a match is found */
int linearSearch(int arr[], int n, int target, int *comparisons)
{
    int i;
    *comparisons = 0;
    for (i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

/* Binary search: O(log n) - halves the search range on every comparison */
int binarySearch(int arr[], int n, int target, int *comparisons)
{
    int low = 0;
    int high = n - 1;
    int mid;

    *comparisons = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        (*comparisons)++;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
