#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX], pilha[MAX];
    int topo = -1;

    printf("Digite a string: ");
    scanf("%s", str);

    for (int i = 0; str[i]; i++)
        pilha[++topo] = str[i];

    printf("Invertida: ");
    while (topo >= 0)
        printf("%c", pilha[topo--]);

    printf("\n");
    return 0;
}
