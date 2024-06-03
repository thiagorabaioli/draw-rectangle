#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "retangulo.h"
#include "plano.h"
#include <locale.h> //necessário para usar setlocale



void exibir_menu() {
    printf("Comandos disponíveis:\n");
    printf("  create x,y+l,h    - Cria um Retângulo em (x,y) com largura l e altura h\n");
    printf("  moveleft x,y+p    - Move o Retangulo que contém o ponto (x,y) para a esquerda p posicoes\n");
    printf("  moveright x,y+p   - Move o Retangulo que contém o ponto (x,y) para a direita p posições\n");
    printf("  merge x1,y1+ x2,y2   - Merge Retangulos que contém oos ponto (x1,y1) (x2,y2)\n");
    printf("  exit              - Encerra o programa\n");
}

void exibir_posicoes_retangulos(const Plano* plano) {
    printf("Posições atuais dos Retangulo:\n");
    for (int i = 0; i < plano->num_retangulos; i++) {
        printf("  Retangulo %d: (%d, %d)\n", i + 1, plano->retangulos[i].x, plano->retangulos[i].y);
    }
}

void processar_comando(Plano* plano, const char* comando) {
    if (strncmp(comando, "create", 6) == 0) {
        int x, y, largura, altura;
        if (sscanf(comando, "create %d,%d+%d,%d", &x, &y, &largura, &altura) == 4) {
            Retangulo novo = criar_retangulo(x, y, largura, altura);
            if (adicionar_retangulo(plano, novo)) {
                printf("Retângulo criado com sucesso.\n");
            } else {
                printf("Erro: Não foi possível criar o retângulo.\n");
            }
        } else {
            printf("Comando invalido.\n");
        }
    }else if (strncmp(comando, "moveleft", 8) == 0) {
        int x, y, p;
        if (sscanf(comando, "moveleft %d,%d+%d", &x, &y, &p) == 3) {

            int indice = encontrar_retangulo_por_ponto(plano, x, y);
            if (indice != -1) {
                mover_retangulo_no_plano(plano, indice, p, 0);
                printf("Retângulo movido para a esquerda.\n");
            } else {
                printf("Erro: Retângulo não encontrado.\n");
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
                printf("Retângulo movido para a direita.\n");
            } else {
                printf("Erro: Retângulo não encontrado.\n");
            }
        }

        else {
            printf("Comando invalido.\n");
        }
    }
    else if (strncmp(comando, "merge", 5) == 0) {
        printf("Comando reconhecido ");
        int x1, y1, x2, y2;
        if (sscanf(comando, "merge %d,%d+%d,%d", &x1, &y1, &x2, &y2) == 4) {
            merge_retangulos(plano, x1, y1, x2, y2);
        } else {
            printf("Comando invalido.\n");
        }
    }

    else if (strncmp(comando, "exit", 4) == 0) {
        printf("Saindo...\n");
    } else {
        printf("Comando não reconhecido.\n");
    }

    desenhar_plano(plano);
    exibir_posicoes_retangulos(plano);
}
