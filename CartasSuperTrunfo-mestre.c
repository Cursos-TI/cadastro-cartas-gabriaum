#include <stdio.h>

typedef struct {
    char estado;
    char codigo[8];
    char nomeDaCidade[28];
    unsigned long int populacao;
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
    scanf("%lu", &carta->populacao);

    printf("Area:\n");
    scanf("%f", &carta->area);

    printf("PIB:\n");
    scanf("%f", &carta->pib);

    printf("Pontos turisticos:\n");
    scanf("%d", &carta->pontosTuristicos);
}

float makeSuperPower(const Carta *c) {
    const float populationDensity = (float) c->populacao / c->area;
    const float pibPerCapital = c->pib / (float) c->populacao;
    const float invertDensity = 1.0f / populationDensity;

    return (float) c->populacao + c->area + c->pib + (float) c->pontosTuristicos + pibPerCapital + invertDensity;
}

void mostrarCarta(Carta *c, int numero) {
    const float populationDensity = (float) c->populacao / c->area;
    const float pibPerCapital = c->pib / (float) c->populacao;

    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %c\n", c->estado);
    printf("Código: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->nomeDaCidade);
    printf("População: %lu\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2f bilhões de reais\n", c->pib);
    printf("Número de Pontos Turísticos: %d\n", c->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", populationDensity);
    printf("PIB per Capita: %.2f reais\n", pibPerCapital);
    printf("Super Poder: %.2f\n", makeSuperPower(c));
}

void compareCartas(Carta *c1, Carta *c2) {
    const float densidade1 = (float) c1->populacao / c1->area;
    const float densidade2 = (float) c2->populacao / c2->area;

    const float pibPerCapita1 = c1->pib / (float) c1->populacao;
    const float pibPerCapita2 = c2->pib / (float) c2->populacao;

    const float super1 = makeSuperPower(c1);
    const float super2 = makeSuperPower(c2);

    printf("\n=== Comparação de Cartas ===\n");

    int res = c1->populacao > c2->populacao;
    printf("População: Carta %d venceu (%d)\n", res ? 1 : 2, res);

    res = c1->area > c2->area;
    printf("Área: Carta %d venceu (%d)\n", res ? 1 : 2, res);

    res = c1->pib > c2->pib;
    printf("PIB: Carta %d venceu (%d)\n", res ? 1 : 2, res);

    res = c1->pontosTuristicos > c2->pontosTuristicos;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", res ? 1 : 2, res);

    res = densidade1 < densidade2;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", res ? 1 : 2, res);

    res = pibPerCapita1 > pibPerCapita2;
    printf("PIB per Capita: Carta %d venceu (%d)\n", res ? 1 : 2, res);

    res = super1 > super2;
    printf("Super Poder: Carta %d venceu (%d)\n", res ? 1 : 2, res);
}

int main() {
    Carta carta1, carta2;

    makeCarta(&carta1, 1);
    makeCarta(&carta2, 2);

    mostrarCarta(&carta1, 1);
    mostrarCarta(&carta2, 2);

    compareCartas(&carta1, &carta2);
}
