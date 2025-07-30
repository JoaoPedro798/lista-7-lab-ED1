#include <stdio.h>
#include <ctype.h>

#define MAX 100

char pilha[MAX];
int topo = -1;

int prioridade(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void push(char c) {
    pilha[++topo] = c;
}

char pop() {
    return pilha[topo--];
}

char peek() {
    return pilha[topo];
}

int main() {
    char infixa[MAX], c;
    printf("Digite expressão infixa: ");
    fgets(infixa, MAX, stdin);

    printf("Pós-fixa: ");
    for (int i = 0; infixa[i]; i++) {
        c = infixa[i];
        if (isdigit(c))
            printf("%c ", c);
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (topo >= 0 && peek() != '(')
                printf("%c ", pop());
            pop(); // remove '('
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (topo >= 0 && prioridade(peek()) >= prioridade(c))
                printf("%c ", pop());
            push(c);
        }
    }

    while (topo >= 0)
        printf("%c ", pop());

    printf("\n");
    return 0;
}
