#ifndef RETANGULO_H
#define RETANGULO_H

typedef struct {
    int x, y;  // Coordenadas do canto inferior esquerdo
    int largura, altura;  // Dimensões do retângulo
} Retangulo;

Retangulo criar_retangulo(int x, int y, int largura, int altura);
void mover_retangulo_esquerda(Retangulo* ret, int p);

void mover_retangulo_direita(Retangulo* ret, int p);

#endif // RETANGULO_H
