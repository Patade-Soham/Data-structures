// Soham Patade
// 241P004
#include <stdio.h>
#define SIZE 5 // Maximum size of the stack
int stack[SIZE], top = -1; // Stack array and top pointer
// Function to push an element into the stack
void push(int value) {
if (top == SIZE - 1) {
printf("Stack is FULL, insertion not possible!\n");
} else {
top++;
stack[top] = value;
printf("Inserted %d into the stack.\n", value);
}
}
// Function to pop an element from the stack
void pop() {
if (top == -1) {
printf("Stack is EMPTY, deletion not possible!\n");
} else {
printf("Popped %d from the stack.\n", stack[top]);
top--;
}
}
// Function to display the stack elements
void display() {
if (top == -1) {
printf("Stack is EMPTY.\n");
} else {
printf("Stack elements: ");
for (int i = top; i >= 0; i--) {
printf("%d ", stack[i]);
}
printf("\n");
}
}
// Main function
int main() {
int choice, value;
while (1) {
printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to push: ");
scanf("%d", &value);
push(value);
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
printf("Exiting program.\n");
return 0;
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}
/*
 >>>>>>OUTPUT<<<<<<<
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 5
Inserted 5 into the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 5 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped 5 from the stack.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack is EMPTY.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting program.


...Program finished with exit code 0
Press ENTER to exit console
*/
