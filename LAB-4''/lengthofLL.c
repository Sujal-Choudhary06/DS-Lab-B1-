#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to calculate the length of the linked list
int getLength(struct Node* head) {
    int count = 0; // Initialize count
    struct Node* current = head; // Start from the head
    
    while (current != NULL) {
        count++; // Increase count for each node
        current = current->next; // Move to the next node
    }
    
    return count; // Return the total count
}

// Function to add a node at the beginning
void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Driver function to test the code
int main() {
    struct Node* head = NULL;

    // Creating a linked list: 3 -> 2 -> 1
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Length of the linked list: %d\n", getLength(head));

    return 0;
}
