#include <stdio.h>
#include <string.h>
#include "plano.h"
#include "menu.h"

int main() {
    Plano plano = criar_plano();
    char comando[100];

    exibir_menu();

    while (1) {
        printf("Digite um comando: ");
        if (fgets(comando, sizeof(comando), stdin) == NULL) {
            break;
        }

        // Remove newline character if present
        comando[strcspn(comando, "\n")] = 0;

        if (strncmp(comando, "exit", 4) == 0) {
            break;
        }

        processar_comando(&plano, comando);
    }

    return 0;
}
