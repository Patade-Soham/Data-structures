#include <stdio.h>
#include <stdlib.h>

// Define the structure for stack nodes
struct Node {
    int data;
    struct Node* next;
};

// Declare a global pointer to the top of the stack
struct Node* top = NULL;

// Function to push an element to the stack
void push() {
    int value;
    printf("Enter the value to push: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value; // Set data to the new node
    newNode->next = top;    // Point new node to the current top
    top = newNode;          // Move top to the new node
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack underflow! The stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next; // Move top to the next node
    free(temp);      // Free memory of the popped node
    printf("%d popped from stack\n", poppedValue);
}

// Function to display the elements of the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with user input
int main() {
    int choice;

    while (1) {
        // Menu options for the user
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                push();
                break;

            case 2:
                // Pop operation
                pop();
                break;

            case 3:
                // Display stack
                display();
                break;

            case 4:
                // Exit the program
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
/* 
Output


Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Stack underflow! The stack is empty.

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 45
45 pushed to stack

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 18
18 pushed to stack

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 7
7 pushed to stack

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 10
10 pushed to stack

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack contents: 10 7 18 45

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
10 popped from stack

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack contents: 7 18 45

Stack Operations Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting program...

Process returned 0 (0x0)   execution time : 51.186 s
Press any key to continue.


*/
