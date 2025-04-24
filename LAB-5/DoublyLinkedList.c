// 1. Create a doubly linked list and print the doubly linked list.
// 	 i. In forward direction
// 	ii. In reverse direction
// 2. Insert a node in doubly linked list
// 	  i. At beginning 
// 	 ii. At end
// 	iii. At specific position
// 3. Delete a node from doubly linked list
// 	  i. At beginning 
// 	 ii. At end
// 	iii. At specific position

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to print list in forward direction
void printForward() {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print list in reverse direction
void printReverse() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Reverse: NULL\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at specific position (1-based index)
void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from beginning
void deleteAtBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

// Delete from end
void deleteAtEnd() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

// Delete at specific position (1-based index)
void deleteAtPosition(int position) {
    if (head == NULL) return;
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    int i;
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
}

// Main driver function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    printForward();
    printReverse();

    insertAtBeginning(5);
    printForward();

    insertAtPosition(25, 4);
    printForward();

    deleteAtBeginning();
    printForward();

    deleteAtEnd();
    printForward();

    deleteAtPosition(2);
    printForward();

    return 0;
}
