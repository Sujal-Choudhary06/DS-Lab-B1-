#include <stdio.h>

int main() {
    int n, i, search, found = 0;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array

    // Input the elements of the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the elements of the array
    printf("\nArray elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Search for an element in the array
    printf("Enter the element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element %d found at position %d.\n", search, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", search);
    }

    return 0;
}
