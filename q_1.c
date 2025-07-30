#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int estaVazia(Pilha* p) {
    return p->topo == -1;
}

int estaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha* p, char c) {
    if (!estaCheia(p)) {
        p->itens[++(p->topo)] = c;
    }
}

char desempilhar(Pilha* p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0';
}

int ehPar(char a, char b) {
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

int verificarBalanceamento(const char* expr) {
    Pilha p;
    inicializar(&p);
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            empilhar(&p, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (estaVazia(&p) || !ehPar(desempilhar(&p), expr[i]))
                return 0;
        }
    }
    return estaVazia(&p);
}

int main() {
    char entrada[100];
    printf("Digite a expressao: ");
    scanf("%s", entrada);
    if (verificarBalanceamento(entrada))
        printf("Entrada Balanceada\n");
    else
        printf("Entrada nao Balanceada\n");
    return 0;
}
