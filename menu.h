#ifndef MENU_H
#define MENU_H

#include "plano.h"

void exibir_menu();
void processar_comando(Plano* plano, const char* comando);
void exibir_posicoes_retangulos(const Plano* plano);

#endif // MENU_H
