#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int pilha[MAX];
int topo = -1;

void push(int n) {
    pilha[++topo] = n;
}

int pop() {
    return pilha[topo--];
}

int main() {
    char expr[MAX];
    printf("Digite expressão pós-fixa (ex: 34+2*): ");
    scanf("%s", expr);

    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (isdigit(c))
            push(c - '0');
        else {
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Resultado: %d\n", pop());
    return 0;
}