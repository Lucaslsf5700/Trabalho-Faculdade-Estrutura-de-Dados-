#include <stdio.h>
#include "fila.h"
#include "funcoes.h"

int main() {
    FilaDecolagem fila;
    inicializarFila(&fila); // Inicializa a fila de decolagem

    int opcao;
    do {
        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1. Listar número de aviões aguardando na fila de decolagem\n");
        printf("2. Autorizar decolagem do primeiro avião da fila\n");
        printf("3. Adicionar um avião à fila de espera\n");
        printf("4. Listar todos os aviões na fila de espera\n");
        printf("5. Listar características do primeiro avião da fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        switch (opcao) {
            case 1:
                // Lista o número de aviões na fila de decolagem
                printf("Número de aviões na fila de decolagem: %d\n", fila.tamanho);
                break;
            case 2:
                // Autoriza a decolagem do primeiro avião na fila
                autorizarDecolagem(&fila);
                break;
            case 3: {
                // Adiciona um avião à fila de espera
                Aviao aviao;
                printf("Digite o identificador do avião: ");
                scanf("%d", &aviao.identificador); // Lê o identificador do avião
                printf("Digite o nome do avião: ");
                scanf("%s", aviao.nome); // Lê o nome do avião
                adicionarAviao(&fila, aviao); // Adiciona o avião à fila
                break;
            }
            case 4:
                // Lista todos os aviões na fila de espera
                listarAvioes(&fila);
                break;
            case 5:
                // Lista as características do primeiro avião na fila
                listarPrimeiroAviao(&fila);
                break;
            case 0:
                // Sai do programa
                printf("Saindo...\n");
                break;
            default:
                // Trata uma opção inválida
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0); // Continua até o usuário escolher sair

    return 0;
}
