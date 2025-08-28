#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* expr) {
    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            // Convert character to integer and push
            push(ch - '0');
        } else if (ch == ' ') {
            continue; // Skip spaces
        } else {
            // Operator encountered
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }

            push(result);
        }
    }

    return pop(); // Final result
}

int main() {
    char expr[100];

    printf("Enter postfix expression (single-digit operands, e.g. '5 6 + 2 *'):\n");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0; // Remove newline

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}

