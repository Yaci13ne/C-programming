#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define M 100

char infix[M], postfix[M], stack[M];
int top = -1; // Top of the stack

// Function prototypes
void push(char);
char pop();
bool isEmpty();
int precedence(char);
void toPostfix();

void push(char x) {
    if (top == M - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top] = x;
}

char pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return '\0';
    } 
    return stack[top--];
  
}

bool isEmpty() {
    return top == -1;
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
              return 3;

        case '/':  case '*': 
                return 2;

        case '+': case '-':
                 return 1;

        default: 
                 return 0;
    }
}

void toPostfix() {
    char symbol, next;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];
        

        switch (symbol) {
            case '(':
                push(symbol);
                break;

            case ')':
                while ((next = pop()) != '(') {
                    postfix[j++] = next;
                }
                break;

            case '+': case '-': case '*': case '/': case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;

            default:
               
                postfix[j++] = symbol;
        }
    }

   
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    printf("Enter the infix expression: ");
    fgets(infix, M, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    toPostfix();

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
