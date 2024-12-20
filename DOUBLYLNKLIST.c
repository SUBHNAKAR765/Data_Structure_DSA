
// WRITE A C PROGRAM TO PERFORM THE FOLLOWING IN DOUBLY LINKED LIST
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
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertBeginning(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
} 
void insertPosition(struct Node** head, int data, int position) 
{
    if (position < 1) 
    {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        if (position != 1) 
        {
            printf("List is empty. Cannot insert at specified position.\n");
            return;
        }
        *head = newNode;
    } 
    else 
    {
        struct Node* current = *head;
        int count = 1;
        while (count < position - 1 && current->next != NULL) 
        {
            current = current->next;
            count++;
        }
        if (count != position - 1) 
        {
            printf("Position out of range.\n");
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) 
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}
void insertEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}
void deleteBeginning(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty. Nothing to delete.\n");
    } 
    else 
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) 
        {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}
void deletePosition(struct Node** head, int position) 
{
    if (*head == NULL) 
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position < 1) 
    {
        printf("Invalid position.\n");
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (count < position && current != NULL) 
    {
        current = current->next;
        count++;
    }
    if (current == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }
    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    }
    if (current->next != NULL) 
    {
        current->next->prev = current->prev;
    }
    free(current);
}
void deleteEnd(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        if (current->prev != NULL) 
        {
            current->prev->next = NULL;
        } 
        else 
        {
            *head = NULL;
        }
        free(current);
    }
}
void printList(struct Node* head) 
{
    printf("Doubly linked list: ");
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;

    insertBeginning(&head, 15);
    insertBeginning(&head, 5);
    printf("List after insertion at beginning: ");
    printList(head);
    
    insertPosition(&head, 10, 2);
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
