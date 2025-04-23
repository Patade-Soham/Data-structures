
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push to stack
void push(char ch) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Peek top of stack
char peek() {
    if (top == -1)
        return -1;
    else
        return stack[top];
}

// Check precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check if operator is right-associative
int isRightAssociative(char op) {
    return op == '^';
}

// Check if character is operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            pop(); // pop '('
        } else if (isOperator(ch)) {
            while (top != -1 && isOperator(peek()) &&
                   ((precedence(ch) < precedence(peek())) ||
                    (precedence(ch) == precedence(peek()) && !isRightAssociative(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// Main function
int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
