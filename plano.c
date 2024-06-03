#include <stdio.h>
#include "plano.h"

Plano criar_plano() {
    Plano plano;
    plano.num_retangulos = 0;
    return plano;
}

int adicionar_retangulo(Plano *plano, Retangulo ret) {
    if (plano->num_retangulos >= MAX_RETANGULOS) {
        return 0;
    }

    // Aplicar gravidade ao retângulo recém-criado
    while (ret.y > 1) {
        int pode_cair = 1;
        for (int i = 0; i < plano->num_retangulos; i++) {
            Retangulo outro = plano->retangulos[i];
            if (ret.x < outro.x + outro.largura && ret.x + ret.largura > outro.x &&
                ret.y == outro.y + outro.altura) {
                pode_cair = 0;
                break;
            }
        }
        if (pode_cair) {
            ret.y--;
        } else {
            break;
        }
    }

    plano->retangulos[plano->num_retangulos++] = ret;
    return 1;
}

void mover_retangulo_no_plano(Plano *plano, int indice, int deslocamento, int direcao) {
    if (indice < 0 || indice >= plano->num_retangulos) {
        return;
    }

    Retangulo *ret = &plano->retangulos[indice];

    if (direcao == 0) { // move left
        ret->x -= deslocamento;
        if (ret->x < 1) {
            ret->x = 1;
        }
    } else { // move right
        ret->x += deslocamento;
        if (ret->x + ret->largura > 80) {
            ret->x = 80 - ret->largura;
        }
    }

    // Aplicar gravidade após mover
    aplicar_gravidade(plano);
}

void aplicar_gravidade(Plano *plano) {
    for (int i = 0; i < plano->num_retangulos; i++) {
        Retangulo *ret = &plano->retangulos[i];
        while (ret->y > 1) {
            int pode_cair = 1;
            for (int j = 0; j < plano->num_retangulos; j++) {
                if (i == j) continue;
                Retangulo outro = plano->retangulos[j];
                if (ret->x < outro.x + outro.largura && ret->x + ret->largura > outro.x &&
                    ret->y == outro.y + outro.altura) {
                    pode_cair = 0;
                    break;
                }
            }
            if (pode_cair) {
                ret->y--;
            } else {
                break;
            }
        }
    }
}

int encontrar_retangulo_por_ponto(const Plano *plano, int x, int y) {
    for (int i = 0; i < plano->num_retangulos; i++) {
        Retangulo ret = plano->retangulos[i];
        if (x >= ret.x && x < ret.x + ret.largura && y >= ret.y && y < ret.y + ret.altura) {
            return i;
        }
    }
    return -1;
}

void desenhar_plano(const Plano *plano) {
    char canvas[25][81] = {0};

    // Preencher com espaços vazios
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Desenhar retângulos
    for (int k = 0; k < plano->num_retangulos; k++) {
        Retangulo ret = plano->retangulos[k];
        for (int i = 0; i < ret.altura; i++) {
            for (int j = 0; j < ret.largura; j++) {
                if (ret.y + i < 25 && ret.x + j < 80) {
                    canvas[ret.y + i - 1][ret.x + j - 1] = 'x';
                }
            }
        }
    }

    // Imprimir canvas
    for (int i = 24; i >= 0; i--) {
        for (int j = 0; j < 80; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}
