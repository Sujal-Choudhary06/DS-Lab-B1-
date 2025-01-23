#include <stdio.h>

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    // Taking size of array as input
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking elements of the array as input
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Printing original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Separate even-indexed and odd-indexed elements
    int evenIndex[n], oddIndex[n];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenIndex[evenCount++] = arr[i];
        } else {
            oddIndex[oddCount++] = arr[i];
        }
    }

    // Sorting even-indexed and odd-indexed arrays
    sortArray(evenIndex, evenCount);
    sortArray(oddIndex, oddCount);

    // Printing sorted even-indexed and odd-indexed elements
    printf("Sorted elements at even indices: ");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", evenIndex[i]);
    }
    printf("\n");

    printf("Sorted elements at odd indices: ");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", oddIndex[i]);
    }
    printf("\n");

    return 0;
}
