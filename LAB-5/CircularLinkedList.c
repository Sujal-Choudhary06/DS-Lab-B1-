#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(1);
    newNode->data = data;
    newNode->next = newNode; // Point to self initially
    return newNode;
}

// Function to traverse a circular linked list
void traverse(Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Insert a node at a specific position
Node* insertAtPosition(Node* head, int data, int pos) {
    Node* newNode = createNode(data);
    if (!head) return newNode;

    if (pos == 1) {
        Node* last = head;
        while (last->next != head)
            last = last->next;
        newNode->next = head;
        last->next = newNode;
        return newNode; // New head
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete a node with given value
Node* deleteNode(Node* head, int key) {
    if (!head) return NULL;

    Node *curr = head, *prev = NULL;
    while (curr->data != key) {
        if (curr->next == head) {
            printf("Node not found\n");
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        Node* last = head;
        while (last->next != head)
            last = last->next;
        if (head->next == head) {
            free(head);
            return NULL;
        }
        last->next = head->next;
        head = head->next;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

// Join two circular linked lists
Node* joinCircularLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* temp1 = head1;
    while (temp1->next != head1)
        temp1 = temp1->next;

    Node* temp2 = head2;
    while (temp2->next != head2)
        temp2 = temp2->next;

    temp1->next = head2;
    temp2->next = head1;

    return head1;
}

// Merge two sorted circular linked lists
Node* mergeSortedCircularLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node *temp1 = head1, *temp2 = head2;
    Node* merged = NULL;

    do {
        merged = insertAtPosition(merged, temp1->data, 1);
        temp1 = temp1->next;
    } while (temp1 != head1);

    do {
        merged = insertAtPosition(merged, temp2->data, 1);
        temp2 = temp2->next;
    } while (temp2 != head2);

    // Simple bubble sort for demonstration (inefficient for large lists)
    Node* i = merged;
    do {
        Node* j = i->next;
        while (j != merged) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
            j = j->next;
        }
        i = i->next;
    } while (i->next != merged);

    return merged;
}

// MAIN FUNCTION TO DEMONSTRATE ALL
int main() {
    Node* list1 = NULL;
    list1 = insertAtPosition(list1, 10, 1);
    list1 = insertAtPosition(list1, 20, 2);
    list1 = insertAtPosition(list1, 30, 3);
    printf("List 1: ");
    traverse(list1);

    Node* list2 = NULL;
    list2 = insertAtPosition(list2, 5, 1);
    list2 = insertAtPosition(list2, 25, 2);
    printf("List 2: ");
    traverse(list2);

    printf("After inserting 15 at position 2 in list 1:\n");
    list1 = insertAtPosition(list1, 15, 2);
    traverse(list1);

    printf("After deleting 20 from list 1:\n");
    list1 = deleteNode(list1, 20);
    traverse(list1);

    printf("After joining List 1 and List 2:\n");
    Node* joinedList = joinCircularLists(list1, list2);
    traverse(joinedList);

    printf("Merging two sorted circular lists into a sorted list:\n");
    Node* sorted1 = NULL;
    sorted1 = insertAtPosition(sorted1, 1, 1);
    sorted1 = insertAtPosition(sorted1, 3, 2);
    sorted1 = insertAtPosition(sorted1, 5, 3);

    Node* sorted2 = NULL;
    sorted2 = insertAtPosition(sorted2, 2, 1);
    sorted2 = insertAtPosition(sorted2, 4, 2);
    sorted2 = insertAtPosition(sorted2, 6, 3);

    Node* merged = mergeSortedCircularLists(sorted1, sorted2);
    traverse(merged);

    return 0;
}
