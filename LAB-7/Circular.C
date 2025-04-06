#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = *head, *prev = NULL;

    // If head node itself holds the key
    if (current->data == key) {
        if (current->next == *head) {
            free(current);
            *head = NULL;
            return;
        }

        while (current->next != *head) {
            current = current->next;
        }
        current->next = (*head)->next;
        free(*head);
        *head = current->next;
        return;
    }

    // Search for the key
    do {
        prev = current;
        current = current->next;
    } while (current != *head && current->data != key);

    if (current->data == key) {
        prev->next = current->next;
        free(current);
    } else {
        printf("Key not found in the list.\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Circular Linked List: ");
    display(head);

    printf("Deleting 20...\n");
    deleteNode(&head, 20);
    printf("Circular Linked List after deletion: ");
    display(head);

    return 0;
}