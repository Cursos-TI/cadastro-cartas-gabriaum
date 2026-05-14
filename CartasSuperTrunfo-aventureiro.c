#include <stdio.h>

typedef struct {
    char estado;
    char codigo[8];
    char nomeDaCidade[28];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void makeCarta(Carta *carta, int numero) {
    printf("\n===== Registro da carta %i =====\n", numero);
    printf("Estado:\n");
    scanf(" %c", &carta->estado);

    printf("Codigo:\n");
    scanf("%s", carta->codigo);

    printf("Nome:\n");
    scanf("%s", carta->nomeDaCidade);

    printf("Populacao:\n");
    scanf("%d", &carta->populacao);

    printf("Area:\n");
    scanf("%f", &carta->area);

    printf("PIB:\n");
    scanf("%f", &carta->pib);

    printf("Pontos turisticos:\n");
    scanf("%d", &carta->pontosTuristicos);
}

void mostrarCarta(Carta *c, int numero) {
    const float populationDensity = (float) c->populacao / c->area;
    const float pibPerCapital = c->pib / (float) c->populacao;

    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %c\n", c->estado);
    printf("Código: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->nomeDaCidade);
    printf("População: %d\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2f bilhões de reais\n", c->pib);
    printf("Número de Pontos Turísticos: %d\n", c->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", populationDensity);
    printf("PIB per Capita: %.2f reais\n", pibPerCapital);
}

int main() {
    Carta carta1, carta2;

    makeCarta(&carta1, 1);
    makeCarta(&carta2, 2);

    mostrarCarta(&carta1, 1);
    mostrarCarta(&carta2, 2);
}
