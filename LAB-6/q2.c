#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void length_Linklist(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("The length of the list is: %d", count);
}
int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    if (head == NULL || second == NULL || third == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    length_Linklist(head);
    free(head);
    free(second);
    free(third);

    return 0;
}