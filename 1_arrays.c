#include <stdio.h>

#define SIZE 5
#define CAPACITY (SIZE + 1) /* one extra slot reserved for the insertion */

void traverse(int arr[], int n);
int readValue(int arr[], int index);
void updateValue(int arr[], int index, int value);
int findMax(int arr[], int n);
int insertAt(int arr[], int n, int index, int value);

int main(void)
{
    int marks[CAPACITY] = {70, 85, 60, 90, 75};
    int n = SIZE;
    int maxVal;

    printf("Initial marks array:\n");
    traverse(marks, n);

    printf("\nValue at index 2: %d\n", readValue(marks, 2));

    updateValue(marks, 2, 65);
    printf("\nAfter updating index 2 to 65:\n");
    traverse(marks, n);

    maxVal = findMax(marks, n);
    printf("\nMaximum value: %d\n", maxVal);

    printf("\nArray before insertion:\n");
    traverse(marks, n);
    n = insertAt(marks, n, 1, 100);
    printf("\nArray after inserting 100 at index 1:\n");
    traverse(marks, n);

    return 0;
}

/* Read: O(1) - direct index access */
int readValue(int arr[], int index)
{
    return arr[index];
}

/* Update: O(1) - direct index access */
void updateValue(int arr[], int index, int value)
{
    arr[index] = value;
}

/* Traverse: O(n) - visits every element exactly once */
void traverse(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Find max: O(n) - single pass, one comparison per element */
int findMax(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/* Insert: O(n) worst case - shifting every element from index onward */
int insertAt(int arr[], int n, int index, int value)
{
    int i;
    for (i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    return n + 1;
}
