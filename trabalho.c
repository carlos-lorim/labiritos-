#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100 // Tamanho máximo da pilha

// Estrutura para a pilha, que armazena coordenadas (i,j)
struct pilha {
    int topo;
    int tamanho;
    int *valori;  // Armazena as coordenadas i
    int *valorj;  // Armazena as coordenadas j
};

// Função para criar a pilha dinamicamente
struct pilha *criar_pilha(int tamanho) {
    struct pilha *p = (struct pilha *)malloc(sizeof(struct pilha));
    p->tamanho = tamanho;
    p->topo = -1;
    p->valori = (int *)malloc(tamanho * sizeof(int));
    p->valorj = (int *)malloc(tamanho * sizeof(int));
    return p;
}

// Verifica se a pilha está cheia
bool ehCheia(struct pilha *p) {
    return (p->topo == p->tamanho - 1);
}

// Verifica se a pilha está vazia
bool ehVazia(struct pilha *p) {
    return (p->topo == -1);
}

// Função para inserir coordenadas na pilha
void push(struct pilha *p, int itemi, int itemj) {
    if (ehCheia(p)) {
        printf("\nPilha cheia. Impossível inserir elementos.\n");
        return;
    }
    p->topo++;
    p->valori[p->topo] = itemi;
    p->valorj[p->topo] = itemj;
}

// Função para remover o elemento do topo da pilha
void pop(struct pilha *p) {
    if (ehVazia(p)) {
        printf("\nPilha vazia. Impossível remover elementos.\n");
        return;
    }
    p->topo--;
}

// Função para imprimir o caminho percorrido
void imprimir_caminho(struct pilha *p) {
    printf("Caminho da entrada até a saída:\n");
    for (int i = 0; i <= p->topo; i++) {
        printf("(%d,%d)\n", p->valori[i], p->valorj[i]);
    }
}

// Função para ler a matriz do arquivo
void lerMatriz(char m[10][10], FILE *ARQ) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(ARQ, " %c", &m[i][j]);  // Note o espaço antes de %c para ignorar espaços em branco
        }
    }
}

// Função que verifica se a posição é válida e não é parede ('X')
bool posicao_valida(char m[10][10], int i, int j) {
    return (i >= 0 && i < 10 && j >= 0 && j < 10 && m[i][j] != 'X');
}

// Função recursiva que resolve o labirinto usando backtracking
bool resolver_labirinto(char m[10][10], int i, int j, struct pilha *p) {
    // Se encontrar a saída
    if (m[i][j] == 'S') {
        push(p, i, j);
        return true;
    }

    // Marca a posição atual como visitada
    m[i][j] = '.';

    // Tentativa de movimento para cima
    if (posicao_valida(m, i - 1, j) && m[i - 1][j] != '.') {
        push(p, i, j);
        if (resolver_labirinto(m, i - 1, j, p)) {
            return true;
        }
        pop(p);  // Backtrack
    }

    // Tentativa de movimento para baixo
    if (posicao_valida(m, i + 1, j) && m[i + 1][j] != '.') {
        push(p, i, j);
        if (resolver_labirinto(m, i + 1, j, p)) {
            return true;
        }
        pop(p);  // Backtrack
    }

    // Tentativa de movimento para a esquerda
    if (posicao_valida(m, i, j - 1) && m[i][j - 1] != '.') {
        push(p, i, j);
        if (resolver_labirinto(m, i, j - 1, p)) {
            return true;
        }
        pop(p);  // Backtrack
    }

    // Tentativa de movimento para a direita
    if (posicao_valida(m, i, j + 1) && m[i][j + 1] != '.') {
        push(p, i, j);
        if (resolver_labirinto(m, i, j + 1, p)) {
            return true;
        }
        pop(p);  // Backtrack
    }

    return false;
}

int main() {
    FILE *arq;
    char M[10][10];  // Matriz que representa o labirinto
    struct pilha *p = criar_pilha(TAM);  // Pilha para armazenar o caminho

    // Abre o arquivo contendo o labirinto
    arq = fopen("labirinto2.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 0;
    }

    // Lê a matriz do arquivo
    lerMatriz(M, arq);
    fclose(arq);

    // Encontra a posição da entrada 'E'
    int start_i = -1, start_j = -1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (M[i][j] == 'E') {
                start_i = i;
                start_j = j;
                break;
            }
        }
        if (start_i != -1) break;
    }

    // Tenta resolver o labirinto
    if (resolver_labirinto(M, start_i, start_j, p)) {
        imprimir_caminho(p);  // Imprime o caminho encontrado
    } else {
        printf("Nenhum caminho encontrado.\n");
    }

    // Libera a memória alocada para a pilha
    free(p->valori);
    free(p->valorj);
    free(p);

    return 0;
}