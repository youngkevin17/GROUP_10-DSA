#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value);
void insertAtHead(Node **head, int value);
void insertAtTail(Node **head, int value);
int deleteByValue(Node **head, int value);
void traverse(Node *head);
void freeList(Node *head);

int main(void)
{
    Node *head = NULL;

    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    printf("After inserting 10, 20, 30 at tail:\n");
    traverse(head);

    insertAtHead(&head, 5);
    printf("\nAfter inserting 5 at head:\n");
    traverse(head);

    printf("\nDeleting value 20:\n");
    deleteByValue(&head, 20);
    traverse(head);

    printf("\nDeleting value 5 (head):\n");
    deleteByValue(&head, 5);
    traverse(head);

    freeList(head);
    return 0;
}

Node* createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at head: O(1) - just repoints the head */
void insertAtHead(Node **head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

/* Insert at tail: O(n) - must walk to the last node */
void insertAtTail(Node **head, int value)
{
    Node *newNode = createNode(value);
    Node *current;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

/* Delete by value: O(n) - must search the list for the value */
int deleteByValue(Node **head, int value)
{
    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    return 1;
}

/* Traverse: O(n) - visits every node once */
void traverse(Node *head)
{
    Node *current = head;
    if (current == NULL) {
        printf("List: [empty]\n");
        return;
    }
    printf("List: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(Node *head)
{
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
