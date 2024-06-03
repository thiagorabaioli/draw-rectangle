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
void aplicar_gravidade(Plano *plano);
int encontrar_retangulo_por_ponto(const Plano *plano, int x, int y);
void desenhar_plano(const Plano *plano);
void mover_retangulo(Plano* plano, int x, int y, int deslocamento); // Nova declaração
void merge_retangulos(Plano *plano, int x1, int y1, int x2, int y2); // Declaração da função merge_retangulos
void remover_retangulo(Plano *plano, int indice);



#endif // PLANO_H
