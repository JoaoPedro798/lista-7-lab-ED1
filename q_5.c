#include <stdio.h>
#include <string.h>

#define MAX 100

char acoes[MAX][100], desfazer[MAX][100];
int topoA = -1, topoD = -1;

void push(char pilha[][100], int *topo, char *acao) {
    strcpy(pilha[++(*topo)], acao);
}

void pop(char pilha[][100], int *topo, char *destino) {
    if (*topo >= 0)
        strcpy(destino, pilha[(*topo)--]);
}

int main() {
    char comando[100];

    while (1) {
        printf("Comando: ");
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = '\0';

        if (strcmp(comando, "sair") == 0)
            break;

        if (strcmp(comando, "desfazer") == 0) {
            if (topoA >= 0) {
                char temp[100];
                pop(acoes, &topoA, temp);
                push(desfazer, &topoD, temp);
                printf("Ação desfeita: %s\n", temp);
            } else {
                printf("Nada para desfazer.\n");
            }
        } else if (strcmp(comando, "refazer") == 0) {
            if (topoD >= 0) {
                char temp[100];
                pop(desfazer, &topoD, temp);
                push(acoes, &topoA, temp);
                printf("Ação refeita: %s\n", temp);
            } else {
                printf("Nada para refazer.\n");
            }
        } else {
            push(acoes, &topoA, comando);
            topoD = -1;
        }
    }

    return 0;
}