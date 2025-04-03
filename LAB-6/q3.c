#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void odd_even_Linklist(struct node* head) {
    if (head == NULL || head->next == NULL) return;

    struct node *odd = head;
    struct node *even = head->next;
    struct node *evenFirst = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenFirst;
}

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node *head = NULL, *second = NULL, *third = NULL, *fourth = NULL;
    struct node *fifth = NULL, *sixth = NULL, *seventh = NULL, *eighth = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));
    sixth = (struct node*)malloc(sizeof(struct node));
    seventh = (struct node*)malloc(sizeof(struct node));
    eighth = (struct node*)malloc(sizeof(struct node));

    if (!head || !second || !third || !fourth || !fifth || !sixth || !seventh || !eighth) {
        printf("Memory allocation failed\n");
        return 1;
    }

   
    head->data = 1; head->next = second;
    second->data = 2; second->next = third;
    third->data = 3; third->next = fourth;
    fourth->data = 4; fourth->next = fifth;
    fifth->data = 5; fifth->next = sixth;
    sixth->data = 6; sixth->next = seventh;
    seventh->data = 7; seventh->next = eighth;
    eighth->data = 8; eighth->next = NULL;  

    printf("Original List:\n");
    printList(head);

    odd_even_Linklist(head);

    printf("Modified List (Odd-Indexed Nodes First):\n");
    printList(head);
    
    freeList(head);

    return 0;
}