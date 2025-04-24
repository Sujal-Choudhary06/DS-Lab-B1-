#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to swap data of two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform Bubble Sort on the linked list
void bubbleSort(struct Node* head) {
    if (head == NULL) return;
    
    int swapped;
    struct Node *ptr1, *lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Reduce the range of the next pass
    } while (swapped);
}

// Function to insert a node at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the Bubble Sort implementation
int main() {
    struct Node* head = NULL;
    
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 5);
    
    printf("Original List: \n");
    printList(head);
    
    bubbleSort(head);
    
    printf("Sorted List: \n");
    printList(head);
    
    return 0;
}
