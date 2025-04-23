#include <stdio.h>
#include <ctype.h>

#define SIZE 50

// Stack initialization
int stack[SIZE];
int top = -1;

// Push function to add an element to the stack
void push(int x) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

// Pop function to remove an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Returning -1 for error
    } else {
        int y = stack[top];
        top--;
        return y;
    }
}

// Main function to evaluate postfix expression
int main() {
    char exp[SIZE];
    int i = 0, op1, op2, result;

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // Convert char to integer and push onto stack
        } else {
            op1 = pop();  // Pop two operands
            op2 = pop();

            switch (exp[i]) {
                case '+':
                    push(op2 + op1);  // Addition
                    break;
                case '-':
                    push(op2 - op1);  // Subtraction
                    break;
                case '*':
                    push(op2 * op1);  // Multiplication
                    break;
                case '/':
                    push(op2 / op1);  // Division
                    break;
                case '^':
                    push(op2 ^ op1);  // Bitwise XOR (power is not typical here)
                    break;
                default:
                    printf("Invalid operator encountered.\n");
                    return -1;
            }
        }
        i++; // Move to the next character
    }

    result = pop();

    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
