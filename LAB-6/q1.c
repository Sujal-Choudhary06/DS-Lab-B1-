#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (*head == NULL) { 
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void printForward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void printBackward(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void insertatbegning(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void insertatend(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertatpos(struct Node** head, int data, int pos){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for(int i = 0; i < pos-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void deleteatbegning(struct Node** head){
    struct Node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}
void deleteatend(struct Node** head){
    struct Node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteatpos(struct Node** head, int pos){
    struct Node* temp = *head;
    for(int i = 0; i < pos-1; i++){
        temp = temp->next;
    }
    struct Node* temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);
}

int main(){
    createNode(2);
    createNode(3); 
    createNode(4);
    createNode(5);
    createNode(6);
    createNode(7);
    createNode(8);
    struct Node* head = NULL;
    append(&head,2);   
    append(&head,3);
    append(&head,4);
    append(&head,5);    
    append(&head,6);   
    append(&head,7);
    append(&head,8);
    printForward(head);
    printBackward(head);
    insertatbegning(&head,1);
    printForward(head);
    insertatend(&head,9);
    printForward(head);
    insertatpos(&head,10,5);
    printForward(head);
    deleteatbegning(&head);
    printForward(head);
    deleteatend(&head);
    printForward(head);
    deleteatpos(&head,5);
    printForward(head);
    return 0;

}