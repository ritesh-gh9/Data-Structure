#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    printf("\nDoubly Linked List Structure:\n");
    printf("--------------------------------------------------\n");
    printf("| %-12s | %-12s | %-5s | %-12s |\n",
           "Node Addr", "Prev Addr", "Data", "Next Addr");
    printf("--------------------------------------------------\n");

    while (temp != NULL) {
        printf("| %-12p | %-12p | %-5d | %-12p |\n",
               (void*)temp,
               (void*)temp->prev,
               temp->data,
               (void*)temp->next);
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
}

Node* searchElement(Node* head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return temp;  // found
        }
        temp = temp->next;
    }

    return NULL;  // not found
}

int main() {
    Node* N1 = createNode(1);
    Node* N2 = createNode(2);
    Node* N3 = createNode(3);
    Node* N4 = createNode(4);
    Node* N5 = createNode(5);

    // Linking nodes
    N1->next = N2;

    N2->prev = N1;
    N2->next = N3;

    N3->prev = N2;
    N3->next = N4;

    N4->prev = N3;
    N4->next = N5;

    N5->prev = N4;

    displayList(N1);


    int key;
    printf("\nEnter element to search in the doubly linked list: ");
    scanf("%d", &key);


    Node* result = searchElement(N1, key);

    if (result != NULL) {
        printf("\nElement %d found at node address: %p\n", key, (void*)result);
    } else {
        printf("\nElement %d NOT found in the list.\n", key);
    }

    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}
