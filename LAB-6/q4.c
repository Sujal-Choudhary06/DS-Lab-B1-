#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (*head == NULL) { 
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) 
            temp = temp->next;
        
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = *head;
    }
}
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev = NULL;
    if (curr->data == key) {
        while (curr->next != *head) 
            curr = curr->next;
        
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL;
            return;
        }
        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }
    prev = *head;
    while (prev->next != *head && prev->next->data != key) 
        prev = prev->next;

    if (prev->next->data == key) {
        struct Node* temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
}
int search(struct Node* head, int key) {
    struct Node* temp = head;
    if (head == NULL) return 0;

    do {
        if (temp->data == key)
            return 1; 
        temp = temp->next;
    } while (temp != head);

    return 0;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    display(head);

    insertAtBeginning(&head, 5);
    display(head);

    insertAfter(head->next, 15);
    display(head);

    deleteNode(&head, 20);
    display(head);

    return 0;
}