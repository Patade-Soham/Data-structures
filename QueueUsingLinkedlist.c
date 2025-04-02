#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Define the queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize the queue
void initQueue() {
    front = rear = NULL;
}

// Check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Enqueue operation
void enqueue() {
    int value;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    printf("Dequeued value: %d\n", value);
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with switch case
int main() {
    int choice;

    // Initialize queue
    initQueue();

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
/*
OUTPUT

Queue Operations:
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Enter the value to enqueue: 10

Queue Operations:
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Enter the value to enqueue: 20

Queue Operations:
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 3
Queue: 10 20

Queue Operations:
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 2
Dequeued value: 10

Queue Operations:
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 3
Queue: 20

Queue Operations:
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 4
Exiting program...

*/
