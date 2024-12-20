// WRITE A C PROGRAM TO PERFORM THE FOLLOWING IN SINGLY LINKED LIST
// 1.insert at beginning
// 2.insert at a specific position
// 3.insert at the end
// 4.delete at the beginning
// 5.delete at a specific position
// 6.delete at the end


#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void insertBeginning(struct Node** head, int newData) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertPosition(struct Node** head, int newData, int position) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    
    if (position == 1) 
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) 
    {
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertEnd(struct Node** head, int newData) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    
    struct Node* last = *head;
    while (last->next != NULL) 
    {
        last = last->next;
    }
    last->next = newNode;
}

void deleteBeginning(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deletePosition(struct Node** head, int position) 
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = *head;
    
    if (position == 1) 
    {
        *head = temp->next;
        free(temp);
        return;
    }
    
    for (int i = 1; temp != NULL && i < position - 1; i++) 
    {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) 
    {
        printf("Position out of range\n");
        return;
    }
    
    struct Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

void deleteEnd(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
        return;
    }
    
    struct Node* secondLast = *head;
    while (secondLast->next->next != NULL) 
    {
        secondLast = secondLast->next;
    }
    free(secondLast->next);
    secondLast->next = NULL;
}

void printList(struct Node* node) 
{
    while (node != NULL) 
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;
    
    insertBeginning(&head, 5);
    insertBeginning(&head, 10);
    printf("List after insertion at beginning: ");
    printList(head);
    
    insertPosition(&head, 15, 2);
    printf("List after insertion at position 2: ");
    printList(head);
    
    insertEnd(&head, 20);
    printf("List after insertion at end: ");
    printList(head);
    
    deleteBeginning(&head);
    printf("List after deletion at beginning: ");
    printList(head);
    
    deletePosition(&head, 2);
    printf("List after deletion at position 2: ");
    printList(head);
    
    deleteEnd(&head);
    printf("List after deletion at end: ");
    printList(head);
    
    return 0;
}
