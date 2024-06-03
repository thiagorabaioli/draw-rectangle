#include <stdio.h>
#include "plano.h"

Plano criar_plano() {
    Plano plano;
    plano.num_retangulos = 0;
    return plano;
}

int adicionar_retangulo(Plano* plano, Retangulo ret) {
    if (plano->num_retangulos < MAX_RETANGULOS) {
        plano->retangulos[plano->num_retangulos] = ret;
        plano->num_retangulos++;
        aplicar_gravidade(plano);
        return 1;  // Sucesso
    }
    return 0;  // Falha
}

void aplicar_gravidade(Plano* plano) {
    for (int i = 0; i < plano->num_retangulos; i++) {
        while (plano->retangulos[i].y > 1) {
            int pode_descer = 1;
            for (int j = 0; j < plano->num_retangulos; j++) {
                if (i != j &&
                    plano->retangulos[i].x < plano->retangulos[j].x + plano->retangulos[j].largura &&
                    plano->retangulos[i].x + plano->retangulos[i].largura > plano->retangulos[j].x &&
                    plano->retangulos[i].y - 1 == plano->retangulos[j].y + plano->retangulos[j].altura) {
                    pode_descer = 0;
                    break;
                }
            }
            if (pode_descer) {
                plano->retangulos[i].y--;
            } else {
                break;
            }
        }
    }
}

void desenhar_plano(Plano* plano) {
    char tela[25][80] = { ' ' };
    for (int i = 0; i < plano->num_retangulos; i++) {
        Retangulo ret = plano->retangulos[i];
        for (int y = ret.y; y < ret.y + ret.altura; y++) {
            for (int x = ret.x; x < ret.x + ret.largura; x++) {
                tela[25 - y][x - 1] = 'x';
            }
        }
    }
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            printf("%c", tela[y][x]);
        }
        printf("\n");
    }
}

int encontrar_retangulo_por_ponto(Plano* plano, int x, int y) {
    for (int i = 0; i < plano->num_retangulos; i++) {
        Retangulo ret = plano->retangulos[i];
        if (x >= ret.x && x < ret.x + ret.largura && y >= ret.y && y < ret.y + ret.altura) {
            return i;
        }
    }
    return -1;  // Não encontrado
}

void mover_retangulo_no_plano(Plano* plano, int indice, int deslocamento, int direcao) {
    if (direcao == 0) {  // Esquerda
        mover_retangulo_esquerda(&plano->retangulos[indice], deslocamento);
    } else {  // Direita
        mover_retangulo_direita(&plano->retangulos[indice], deslocamento);
    }
    aplicar_gravidade(plano);
}
