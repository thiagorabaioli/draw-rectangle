#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "retangulo.h"
#include "plano.h"

void exibir_menu() {
    printf("Comandos disponíveis:\n");
    printf("  create x,y+l,h    - Cria um retângulo em (x,y) com largura l e altura h\n");
    printf("  moveleft x,y+p    - Move o retângulo que contém o ponto (x,y) para a esquerda p posições\n");
    printf("  moveright x,y+p   - Move o retângulo que contém o ponto (x,y) para a direita p posições\n");
    printf("  exit              - Encerra o programa\n");
}

void exibir_posicao_retangulo(const Retangulo* ret) {
    printf("Posição atual do retângulo: (%d, %d)\n", ret->x, ret->y);
}

void processar_comando(Plano* plano, const char* comando) {
    if (strncmp(comando, "create", 6) == 0) {
        int x, y, largura, altura;
        if (sscanf(comando, "create %d,%d+%d,%d", &x, &y, &largura, &altura) == 4) {
            Retangulo novo = criar_retangulo(x, y, largura, altura);
            if (adicionar_retangulo(plano, novo)) {
                exibir_posicao_retangulo(&novo);
            } else {
                printf("Erro: Não foi possível criar o retângulo.\n");
            }
        } else {
            printf("Comando inválido.\n");
        }
    } else if (strncmp(comando, "moveleft", 8) == 0) {
        int x, y, p;
        if (sscanf(comando, "moveleft %d,%d+%d", &x, &y, &p) == 3) {
            int indice = encontrar_retangulo_por_ponto(plano, x, y);
            if (indice != -1) {
                mover_retangulo_no_plano(plano, indice, p, 0);
                exibir_posicao_retangulo(&plano->retangulos[indice]);
            } else {
                printf("Erro: Retângulo não encontrado.\n");
            }
        } else {
            printf("Comando inválido.\n");
        }
    } else if (strncmp(comando, "moveright", 9) == 0) {
        int x, y, p;
        if (sscanf(comando, "moveright %d,%d+%d", &x, &y, &p) == 3) {
            int indice = encontrar_retangulo_por_ponto(plano, x, y);
            if (indice != -1) {
                mover_retangulo_no_plano(plano, indice, p, 1);
                exibir_posicao_retangulo(&plano->retangulos[indice]);
            } else {
                printf("Erro: Retângulo não encontrado.\n");
            }
        } else {
            printf("Comando inválido.\n");
        }
    } else if (strncmp(comando, "exit", 4) == 0) {
        printf("Saindo...\n");
    } else {
        printf("Comando não reconhecido.\n");
    }

    desenhar_plano(plano);
    
}
