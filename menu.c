#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "retangulo.h"
#include "plano.h"

void exibir_menu() {
    printf("Comandos disponiveis:\n");
    printf("  create x,y+l,h    - Cria um retangulo em (x,y) com largura l e altura h\n");
    printf("  moveleft x,y+p    - Move o retangulo que contem o ponto (x,y) para a esquerda p posicoes\n");
    printf("  moveright x,y+p   - Move o retangulo que contem o ponto (x,y) para a direita p posicoes\n");
    printf("  exit              - Encerra o programa\n");
}

void processar_comando(Plano* plano, const char* comando) {
    if (strncmp(comando, "create", 6) == 0) {
        int x, y, largura, altura;
        if (sscanf(comando, "create %d,%d+%d,%d", &x, &y, &largura, &altura) == 4) {
            Retangulo novo = criar_retangulo(x, y, largura, altura);
            if (!adicionar_retangulo(plano, novo)) {
                printf("Erro: Não foi possivel criar o retangulo.\n");
            }
        } else {
            printf("Comando invalido.\n");
        }
    } else if (strncmp(comando, "moveleft", 8) == 0) {
        int x, y, p;
        if (sscanf(comando, "moveleft %d,%d+%d", &x, &y, &p) == 3) {
            int indice = encontrar_retangulo_por_ponto(plano, x, y);
            if (indice != -1) {
                mover_retangulo_no_plano(plano, indice, p, 0);
            } else {
                printf("Erro: Retangulo nao encontrado.\n");
            }
        } else {
            printf("Comando invalido.\n");
        }
    } else if (strncmp(comando, "moveright", 9) == 0) {
        int x, y, p;
        if (sscanf(comando, "moveright %d,%d+%d", &x, &y, &p) == 3) {
            int indice = encontrar_retangulo_por_ponto(plano, x, y);
            if (indice != -1) {
                mover_retangulo_no_plano(plano, indice, p, 1);
            } else {
                printf("Erro: Retangulo nao encontrado.\n");
            }
        } else {
            printf("Comando invalido.\n");
        }
    } else if (strncmp(comando, "exit", 4) == 0) {
        printf("Saindo...\n");
    } else {
        printf("Comando não reconhecido.\n");
    }

    desenhar_plano(plano);
}
