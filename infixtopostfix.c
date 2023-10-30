#include <stdio.h>
#include <string.h>

#define max 100

char stack[max];
int top = -1;

void push(char ch) {
    top++;
    stack[top] = ch;
}

char pop() {
    char x;
    if (top == -1) {
        return -1; // Return an error value to indicate stack underflow
    } else {
        x = stack[top];
        top--;
        return x; // Return the popped character
    }
}

int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '/' || x == '*')
        return 2;
    if (x == '^')
        return 3;
    return -1; // Invalid operator
}

int main() {
    char exp[max];
    printf("Enter the expression : ");
    gets(exp);
    printf("The infix expression is : %s\n", exp);
    printf("The postfix expression is :" );
    int i = 0;
    while (i < strlen(exp)) {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
            printf("%c", exp[i]);
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            char ch;
            while ((ch = pop()) != '(') {
                printf("%c",ch);
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
        i++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
    return 0;
}
