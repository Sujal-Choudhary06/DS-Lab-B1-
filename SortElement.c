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

    // Separate even and odd arrays
    int even[n], odd[n];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        } else {
            odd[oddCount++] = arr[i];
        }
    }

    // Sorting even and odd arrays
    sortArray(even, evenCount);
    sortArray(odd, oddCount);

    // Printing sorted even and odd arrays
    printf("Sorted even elements: ");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("Sorted odd elements: ");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}
