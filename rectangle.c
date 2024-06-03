#include "retangulo.h"

Retangulo criar_retangulo(int x, int y, int largura, int altura) {
    Retangulo ret;
    ret.x = x;
    ret.y = y;
    ret.largura = largura;
    ret.altura = altura;
    return ret;
}

void mover_retangulo_esquerda(Retangulo* ret, int p) {
    ret->x -= p;
    if (ret->x < 1) ret->x = 1;  // Não permitir que saia da borda esquerda
}

void mover_retangulo_direita(Retangulo* ret, int p) {
    ret->x += p;
    if (ret->x + ret->largura - 1 > 80) ret->x = 80 - ret->largura + 1;  // Não permitir que saia da borda direita
}
