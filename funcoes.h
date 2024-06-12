#ifndef FUNCOES_H
#define FUNCOES_H

#include "fila.h"
#include <stdio.h>
#include <string.h>

// Inicializa a fila de decolagem
void inicializarFila(FilaDecolagem* fila) {
    fila->frente = 0;        // Define o índice da frente da fila como 0
    fila->traseira = -1;     // Define o índice da traseira da fila como -1 (fila vazia)
    fila->tamanho = 0;       // Define o tamanho da fila como 0 (fila vazia)
}

// Verifica se a fila de decolagem está vazia
int estaVazia(FilaDecolagem* fila) {
    return fila->tamanho == 0;    // Retorna verdadeiro se o tamanho da fila for 0
}

// Verifica se a fila de decolagem está cheia
int estaCheia(FilaDecolagem* fila) {
    return fila->tamanho == MAX_AVIOES;   // Retorna verdadeiro se o tamanho da fila atingir o máximo
}

// Adiciona um avião à fila de decolagem
void adicionarAviao(FilaDecolagem* fila, Aviao aviao) {
    if (estaCheia(fila)) {  // Verifica se a fila está cheia
        printf("A fila de decolagem está cheia.\n");
    } else {
        fila->traseira = (fila->traseira + 1) % MAX_AVIOES; // Calcula o próximo índice da traseira
        fila->avioes[fila->traseira] = aviao;  // Adiciona o avião à fila
        fila->tamanho++;        // Incrementa o tamanho da fila
        printf("Avião ID: %d, Nome: %s adicionado à fila de decolagem.\n", aviao.identificador, aviao.nome);
    }
}

// Autoriza a decolagem do primeiro avião na fila de decolagem
void autorizarDecolagem(FilaDecolagem* fila) {
    if (estaVazia(fila)) {  // Verifica se a fila está vazia
        printf("Não há aviões na fila de decolagem.\n");
    } else {
        Aviao aviao = fila->avioes[fila->frente];   // Obtém o avião na frente da fila
        fila->frente = (fila->frente + 1) % MAX_AVIOES; // Calcula o próximo índice da frente
        fila->tamanho--;      // Decrementa o tamanho da fila
        printf("Autorizando decolagem do avião ID: %d, Nome: %s\n", aviao.identificador, aviao.nome);
    }
}

// Lista todos os aviões na fila de decolagem
void listarAvioes(FilaDecolagem* fila) {
    if (estaVazia(fila)) {  // Verifica se a fila está vazia
        printf("Não há aviões na fila de decolagem.\n");
    } else {
        printf("Aviões na fila de decolagem:\n");
        for (int i = 0; i < fila->tamanho; i++) {
            int indice = (fila->frente + i) % MAX_AVIOES; // Calcula o índice atual na fila circular
            printf("\nID: %d, Nome: %s\n\n", fila->avioes[indice].identificador, fila->avioes[indice].nome);
        }
    }
}

// Lista as características do primeiro avião na fila de decolagem
void listarPrimeiroAviao(FilaDecolagem* fila) {
    if (estaVazia(fila)) {  // Verifica se a fila está vazia
        printf("Não há aviões na fila de decolagem.\n");
    } else {
        Aviao aviao = fila->avioes[fila->frente];   // Obtém o avião na frente da fila
        printf("Primeiro avião na fila: ID: %d, Nome: %s\n", aviao.identificador, aviao.nome);
    }
}

#endif
