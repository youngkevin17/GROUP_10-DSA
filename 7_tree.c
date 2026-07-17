#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value);
Node* insertNode(Node *root, int value);
void bfsTraversal(Node *root);
void preOrderTraversal(Node *root);

int main(void)
{
    Node *root = NULL;
    int values[7] = {50, 30, 70, 20, 40, 60, 80};
    int i;

    for (i = 0; i < 7; i++) {
        root = insertNode(root, values[i]);
    }

    printf("Inserted values: ");
    for (i = 0; i < 7; i++) {
        printf("%d ", values[i]);
    }
    printf("\n\n");

    printf("Breadth-First Traversal (level order): ");
    bfsTraversal(root);

    printf("\nDepth-First Traversal (pre-order): ");
    preOrderTraversal(root);
    printf("\n");

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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert: O(log n) average, O(n) worst case - walks down comparing values */
Node* insertNode(Node *root, int value)
{
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

/* BFS (level order): O(n) - visits every node once using a queue */
void bfsTraversal(Node *root)
{
    Node *queue[MAX_NODES];
    int front = 0;
    int rear = 0;
    Node *current;

    if (root == NULL) {
        printf("[empty]\n");
        return;
    }

    queue[rear] = root;
    rear++;

    while (front < rear) {
        current = queue[front];
        front++;
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear] = current->left;
            rear++;
        }
        if (current->right != NULL) {
            queue[rear] = current->right;
            rear++;
        }
    }
    printf("\n");
}

/* DFS pre-order: O(n) - visits every node once, root then left then right */
void preOrderTraversal(Node *root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
