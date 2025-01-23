#include <stdio.h>

int main() {
    int n, pos, element;

    // Ask the user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n + 1]; // Declare an array with size n + 1 to accommodate the new element

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Input the position and the new element
    printf("Enter the position to insert the new element (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 1; // Exit the program for invalid position
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    // Shift elements to the right from the position
    for (int i = n; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[pos - 1] = element;

    // Update size of the array
    n++;

    // Print the updated array
    printf("The array after insertion is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
