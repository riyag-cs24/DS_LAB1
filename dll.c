#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    Node* temp = head;

    printf("\nDoubly Linked List Structure:\n");
    printf("--\n");
    printf("| %-14s | %-14s | %-5s | %-14s |\n", "Node Addr", "Prev Addr", "Data", "Next Addr");
    printf("--\n");

    while (temp != NULL) {
        printf("| %-14p | %-14p | %-5d | %-14p |\n",
               (void*)temp,
               (void*)temp->prev,
               temp->data,
               (void*)temp->next);
        temp = temp->next;
    }

    printf("--\n");
}

int main() {
    Node* N1 = createNode(1);
    Node* N2 = createNode(2);
    Node* N3 = createNode(3);
    Node* N4 = createNode(4);
    Node* N5 = createNode(5);

    // Original links
    N1->next = N2;
    N2->prev = N1;
    N2->next = N3;
    N3->prev = N2;
    N3->next = N4;
    N4->prev = N3;
    N4->next = N5;
    N5->prev = N4;

    printf("Before dragging:\n");
    displayList(N1);

    // "Drag" node 3 to the front
    // Detach N3 from its current position
    N2->next = N4;
    N4->prev = N2;

    // Insert N3 before N1
    N3->next = N1;
    N3->prev = NULL;
    N1->prev = N3;

    // New head is now N3
    Node* head = N3;

    printf("\nAfter dragging (Node 3 moved to front):\n");
    displayList(head);

    // Free all nodes
    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}


