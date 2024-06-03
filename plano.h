#ifndef PLANO_H
#define PLANO_H

#include "retangulo.h"

#define MAX_RETANGULOS 100

typedef struct {
    Retangulo retangulos[MAX_RETANGULOS];
    int num_retangulos;
} Plano;

Plano criar_plano();
int adicionar_retangulo(Plano *plano, Retangulo ret);
void mover_retangulo_no_plano(Plano *plano, int indice, int deslocamento, int direcao);
int encontrar_retangulo_por_ponto(const Plano *plano, int x, int y);
void desenhar_plano(const Plano *plano);

#endif // PLANO_H
