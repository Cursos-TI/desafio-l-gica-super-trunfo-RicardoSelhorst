#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int area; 
    int populacao; 
    int pib;  
    int densidade_demografica;  
} Carta;

void exibirMenu(char *atributo1, char *atributo2) {
    printf("\nEscolha o primeiro atributo:\n");
    printf("1. Área\n");
    printf("2. População\n");
    printf("3. PIB\n");
    printf("4. Densidade Demográfica\n");
    printf("Escolha: ");
    
    int escolha1;
    scanf("%d", &escolha1);

    switch (escolha1) {
        case 1:
            strcpy(atributo1, "Área");
            break;
        case 2:
            strcpy(atributo1, "População");
            break;
        case 3:
            strcpy(atributo1, "PIB");
            break;
        case 4:
            strcpy(atributo1, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            exit(1);
    }

    printf("\nEscolha o segundo atributo (não pode ser o mesmo do primeiro):\n");
    printf("1. Área\n");
    printf("2. População\n");
    printf("3. PIB\n");
    printf("4. Densidade Demográfica\n");
    printf("Escolha: ");
    
    int escolha2;
    scanf("%d", &escolha2);

    if (escolha2 == escolha1) {
        printf("Você não pode escolher o mesmo atributo. Tente novamente.\n");
        exit(1);
    }

    switch (escolha2) {
        case 1:
            strcpy(atributo2, "Área");
            break;
        case 2:
            strcpy(atributo2, "População");
            break;
        case 3:
            strcpy(atributo2, "PIB");
            break;
        case 4:
            strcpy(atributo2, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            exit(1);
    }
}

int compararAtributos(Carta carta1, Carta carta2, char *atributo1, char *atributo2) {
    int resultado = 0;  
    int somaCarta1 = 0, somaCarta2 = 0;
    

    int valorAtributo1Carta1 = 0, valorAtributo1Carta2 = 0;
    if (strcmp(atributo1, "Área") == 0) {
        valorAtributo1Carta1 = carta1.area;
        valorAtributo1Carta2 = carta2.area;
    } else if (strcmp(atributo1, "População") == 0) {
        valorAtributo1Carta1 = carta1.populacao;
        valorAtributo1Carta2 = carta2.populacao;
    } else if (strcmp(atributo1, "PIB") == 0) {
        valorAtributo1Carta1 = carta1.pib;
        valorAtributo1Carta2 = carta2.pib;
    } else if (strcmp(atributo1, "Densidade Demográfica") == 0) {
        valorAtributo1Carta1 = carta1.densidade_demografica;
        valorAtributo1Carta2 = carta2.densidade_demografica;
    }

    int valorAtributo2Carta1 = 0, valorAtributo2Carta2 = 0;
    if (strcmp(atributo2, "Área") == 0) {
        valorAtributo2Carta1 = carta1.area;
        valorAtributo2Carta2 = carta2.area;
    } else if (strcmp(atributo2, "População") == 0) {
        valorAtributo2Carta1 = carta1.populacao;
        valorAtributo2Carta2 = carta2.populacao;
    } else if (strcmp(atributo2, "PIB") == 0) {
        valorAtributo2Carta1 = carta1.pib;
        valorAtributo2Carta2 = carta2.pib;
    } else if (strcmp(atributo2, "Densidade Demográfica") == 0) {
        valorAtributo2Carta1 = carta1.densidade_demografica;
        valorAtributo2Carta2 = carta2.densidade_demografica;
    }

    printf("\nResultado da comparação:\n");
    printf("Atributo 1: %s\n", atributo1);
    printf("%s: %d\n", carta1.nome, valorAtributo1Carta1);
    printf("%s: %d\n", carta2.nome, valorAtributo1Carta2);
    
    printf("Atributo 2: %s\n", atributo2);
    printf("%s: %d\n", carta1.nome, valorAtributo2Carta1);
    printf("%s: %d\n", carta2.nome, valorAtributo2Carta2);
    
    somaCarta1 = valorAtributo1Carta1 + valorAtributo2Carta1;
    somaCarta2 = valorAtributo1Carta2 + valorAtributo2Carta2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %d\n", carta1.nome, somaCarta1);
    printf("%s: %d\n", carta2.nome, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        resultado = 1;
    } else if (somaCarta2 > somaCarta1) {
        resultado = 2;
    } else {
        resultado = 0;
    }

    return resultado;
}

int main() {

    Carta cartaBrasil = {"Brasil", 8515767, 211049527, 2055, 25};
    Carta cartaArgentina = {"Argentina", 2780400, 44938712, 638, 16};
    
    char atributo1[50], atributo2[50];
    
    exibirMenu(atributo1, atributo2);
    
    int resultado = compararAtributos(cartaBrasil, cartaArgentina, atributo1, atributo2);
    
    if (resultado == 0) {
        printf("\nEmpate!\n");
    } else if (resultado == 1) {
        printf("\n%s venceu a rodada!\n", cartaBrasil.nome);
    } else {
        printf("\n%s venceu a rodada!\n", cartaArgentina.nome);
    }

    return 0;
}
