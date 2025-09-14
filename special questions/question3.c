//Detect Cycle in a Linked List
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect cycle using Floyd’s algorithm
int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast) {
            return 1; // cycle detected
        }
    }

    return 0; // no cycle
}

// Driver program
int main() {
    // Create nodes
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Uncomment the below line to create a cycle
    head->next->next->next->next = head->next; // cycle: 4 -> 2

    if (detectCycle(head))
        printf("Cycle detected!\n");
    else
        printf("No cycle detected.\n");

    return 0;
}
