#ifndef FILA_H
#define FILA_H

#define MAX_AVIOES 100  // Define o tamanho máximo da fila de decolagem
#define TAM_NOME 50     // Define o tamanho máximo do nome de um avião

// Definição da estrutura Aviao, representando um avião na fila de decolagem
typedef struct {
    int identificador;      // Identificador do avião
    char nome[TAM_NOME];    // Nome do avião
} Aviao;

// Definição da estrutura FilaDecolagem, representando a fila de decolagem de aviões
typedef struct {
    Aviao avioes[MAX_AVIOES];   // Array de aviões na fila
    int frente;                 // Índice da frente da fila
    int traseira;               // Índice da traseira da fila
    int tamanho;                // Número de aviões na fila
} FilaDecolagem;

// Função para inicializar a fila de decolagem
void inicializarFila(FilaDecolagem* fila);

// Funções para verificar se a fila está vazia ou cheia
int estaVazia(FilaDecolagem* fila);
int estaCheia(FilaDecolagem* fila);

// Funções para adicionar um avião à fila de decolagem
void adicionarAviao(FilaDecolagem* fila, Aviao aviao);

// Função para autorizar a decolagem do primeiro avião na fila
void autorizarDecolagem(FilaDecolagem* fila);

// Função para listar todos os aviões na fila de decolagem
void listarAvioes(FilaDecolagem* fila);

// Função para listar as características do primeiro avião na fila de decolagem
void listarPrimeiroAviao(FilaDecolagem* fila);

#endif
