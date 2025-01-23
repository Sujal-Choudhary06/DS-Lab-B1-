#include <stdio.h>

int main() {
    int n, i, pos;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array

    // Input the elements of the array
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the elements of the array
    printf("The elements of the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the position of the element to delete
    printf("Enter the position of the element to delete (1 to %d): ", n);
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position! Please run the program again.\n");
        return 1;
    }

    // Delete the element
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Reduce the size of the array

    // Print the array after deletion
    printf("The array after deletion is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
