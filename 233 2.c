#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
if (top == MAX - 1)
printf("Stack Overflow\n");
else
stack[++top] = c;
}


char pop() {
if (top == -1) {
printf("Stack Underflow\n");
return -1;
} else
return stack[top--];
}


int precedence(char op) {
if (op == '+' || op == '-')
return 1;
if (op == '*' || op == '/')
return 2;
return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
int i = 0, j = 0;
char c;

while ((c = infix[i++]) != '\0') {
if (isalnum(c)) {
postfix[j++] = c;
}
else if (c == '(') {
push(c);
}
else if (c == ')') {
while (top != -1 && stack[top] != '(')
postfix[j++] = pop();
pop();
}
else {
while (top != -1 && precedence(stack[top]) >= precedence(c))
postfix[j++] = pop();
push(c);
}
}

while (top != -1)
postfix[j++] = pop();

postfix[j] = '\0';

}

int main() {
char infix[MAX], postfix[MAX];

printf("Enter a valid parenthesized infix expression: ");
scanf("%s", infix);

infixToPostfix(infix, postfix);

printf("Postfix expression: %s\n", postfix);

return 0;
}



