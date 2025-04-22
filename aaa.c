
#include <stdio.h>
#include <string.h>


typedef struct {
    char estado[50];
    char codigo[20];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;


void calcularValores(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}


void exibirCarta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código da carta: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", carta.densidade_populacional);
    printf("PIB per capita: R$ %.2f\n\n", carta.pib_per_capita);
}


void compararPibPerCapita(Carta carta1, Carta carta2) {
    printf("Comparação de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.cidade, carta1.estado, carta1.pib_per_capita);
    printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.cidade, carta2.estado, carta2.pib_per_capita);
    
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta1.pib_per_capita < carta2.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}


void compararPontosTuristicos(Carta carta1, Carta carta2) {
    printf("Comparação de cartas (Atributo: Pontos turísticos):\n");
    printf("Carta 1 - %s (%s): %d pontos turísticos\n", carta1.cidade, carta1.estado, carta1.pontos_turisticos);
    printf("Carta 2 - %s (%s): %d pontos turísticos\n", carta2.cidade, carta2.estado, carta2.pontos_turisticos);
    
    if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}


void compararDensidadePopulacional(Carta carta1, Carta carta2) {
    printf("Comparação de cartas (Atributo: Densidade Populacional):\n");
    printf("Carta 1 - %s (%s): %.2f habitantes/km²\n", carta1.cidade, carta1.estado, carta1.densidade_populacional);
    printf("Carta 2 - %s (%s): %.2f habitantes/km²\n", carta2.cidade, carta2.estado, carta2.densidade_populacional);
    
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;
    
    
    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado: ");
    scanf("%s", carta1.estado);
    printf("Digite o Código da carta: ");
    scanf("%s", carta1.codigo);
    printf("Digite o Nome da Cidade: ");
    scanf("%s", carta1.cidade);
    printf("Digite a População: ");
    scanf("%d", &carta1.populacao);
    printf("Digite a Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado: ");
    scanf("%s", carta2.estado);
    printf("Digite o Código da carta: ");
    scanf("%s", carta2.codigo);
    printf("Digite o Nome da Cidade: ");
    scanf("%s", carta2.cidade);
    printf("Digite a População: ");
    scanf("%d", &carta2.populacao);
    printf("Digite a Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    
    calcularValores(&carta1);
    calcularValores(&carta2);

    
    printf("\nCarta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    
    compararPibPerCapita(carta1, carta2);
    compararPontosTuristicos(carta1, carta2);
    compararDensidadePopulacional(carta1, carta2);

    return 0;
}
