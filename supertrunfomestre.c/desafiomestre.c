#include <stdio.h>
#include <string.h>

// Definindo a estrutura para a carta
typedef struct {
    char estado;
    char codigo[5];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para mapear o número do atributo para o nome
const char* obterNomeAtributo(int num) {
    switch (num) {
        case 1:
            return "Populacao";
        case 2:
            return "Area";
        case 3:
            return "PIB";
        case 4:
            return "Pontos Turisticos";
        case 5:
            return "Densidade Populacional";
        case 6:
            return "PIB per Capita";
        default:
            return "N/A";
    }
}

// Função para obter o valor de um atributo de uma carta
float obterValorAtributo(Carta carta, int num) {
    switch (num) {
        case 1:
            return (float)carta.populacao;
        case 2:
            return carta.area;
        case 3:
            return carta.pib;
        case 4:
            return (float)carta.pontosTuristicos;
        case 5:
            return carta.densidadePopulacional;
        case 6:
            return carta.pibPerCapita;
        default:
            return 0.0;
    }
}

int main() {
    Carta carta1, carta2;
    int escolha1, escolha2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma_carta1, soma_carta2;

    // --- CADASTRO DA CARTA 1 ---
    printf("\n*INFORME OS DADOS PARA CADASTRAR A CARTA 1*\n");
    printf("Informe uma letra de 'A a H' representando o estado: \n");
    scanf(" %c", &carta1.estado);
    printf("Informe o codigo da carta. EX: A01: \n");
    scanf(" %s", carta1.codigo);
    printf("Informe o nome da cidade: \n");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("Informe a populacao da carta 1: \n");
    scanf("%lu", &carta1.populacao);
    printf("Informe a area da cidade da carta 1 (em km2): \n");
    scanf("%f", &carta1.area);
    printf("Informe o PIB (em bilhoes de reais): \n");
    scanf("%f", &carta1.pib);
    printf("Informe o numero de pontos turisticos: \n");
    scanf("%d", &carta1.pontosTuristicos);

    // --- CALCULOS PARA A CARTA 1 ---
    carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;

    // Consumir o caractere de nova linha pendente
    while (getchar() != '\n');
    
    // --- CADASTRO DA CARTA 2 ---
    printf("\n*INFORME OS DADOS PARA CADASTRAR A CARTA 2*\n");
    printf("Informe uma letra de 'A a H' representando o estado: \n");
    scanf(" %c", &carta2.estado);
    printf("Informe o codigo da carta. EX: A01: \n");
    scanf(" %s", carta2.codigo);
    printf("Informe o nome da cidade: \n");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Informe a populacao da carta 2: \n");
    scanf("%lu", &carta2.populacao);
    printf("Informe a area da cidade da carta 2 (em km2): \n");
    scanf("%f", &carta2.area);
    printf("Informe o PIB (em bilhoes de reais): \n");
    scanf("%f", &carta2.pib);
    printf("Informe o numero de pontos turisticos: \n");
    scanf("%d", &carta2.pontosTuristicos);
    
    // --- CALCULOS PARA A CARTA 2 ---
    carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;
    
    printf("\n--- DESAFIO: SUPER TRUNFO AVANCADO ---\n");
    printf("O duelo sera entre %s e %s.\n", carta1.nomeCidade, carta2.nomeCidade);

    // --- Menu para a primeira escolha ---
    printf("\nEscolha o PRIMEIRO atributo para a comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    
    do {
        printf("Sua escolha: ");
        scanf("%d", &escolha1);
        if (escolha1 < 1 || escolha1 > 6) {
            printf("Escolha invalida. Tente novamente.\n");
        }
    } while (escolha1 < 1 || escolha1 > 6);
    
    // Consumir o caractere de nova linha pendente
    while (getchar() != '\n');

    // --- Menu para a segunda escolha ---
    printf("\nEscolha o SEGUNDO atributo para a comparacao:\n");
    if (escolha1 != 1) printf("1 - Populacao\n");
    if (escolha1 != 2) printf("2 - Area\n");
    if (escolha1 != 3) printf("3 - PIB\n");
    if (escolha1 != 4) printf("4 - Pontos Turisticos\n");
    if (escolha1 != 5) printf("5 - Densidade Populacional\n");
    if (escolha1 != 6) printf("6 - PIB per Capita\n");

    do {
        printf("Sua escolha: ");
        scanf("%d", &escolha2);
        if (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1) {
            printf("Escolha invalida ou ja selecionada. Tente novamente.\n");
        }
    } while (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1);

    // --- Implementando a logica de comparacao e soma ---
    valor1_carta1 = obterValorAtributo(carta1, escolha1);
    valor1_carta2 = obterValorAtributo(carta2, escolha1);
    valor2_carta1 = obterValorAtributo(carta1, escolha2);
    valor2_carta2 = obterValorAtributo(carta2, escolha2);
    
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor2_carta1 + valor2_carta2;
    
    // --- Exibicao do resultado ---
    printf("\n--- RESULTADO DA RODADA ---\n");
    printf("Atributos escolhidos: %s e %s\n\n", obterNomeAtributo(escolha1), obterNomeAtributo(escolha2));

    printf("%s:\n", carta1.nomeCidade);
    printf("  > %s: %.2f\n", obterNomeAtributo(escolha1), valor1_carta1);
    printf("  > %s: %.2f\n", obterNomeAtributo(escolha2), valor2_carta1);
    printf("  > **Soma dos atributos:** %.2f\n\n", soma_carta1);
    
    printf("%s:\n", carta2.nomeCidade);
    printf("  > %s: %.2f\n", obterNomeAtributo(escolha1), valor1_carta2);
    printf("  > %s: %.2f\n", obterNomeAtributo(escolha2), valor2_carta2);
    printf("  > **Soma dos atributos:** %.2f\n\n", soma_carta2);

    // Determinando o vencedor com base na soma e tratando empates
    if (soma_carta1 > soma_carta2) {
        printf("A soma dos atributos de %s e maior. %s VENCEU!\n", carta1.nomeCidade, carta1.nomeCidade);
    } else if (soma_carta2 > soma_carta1) {
        printf("A soma dos atributos de %s e maior. %s VENCEU!\n", carta2.nomeCidade, carta2.nomeCidade);
    } else {
        printf("A soma dos atributos de ambas as cartas e a mesma. EMPATE!\n");
    }

    printf("\n----------------------------------\n");
    printf("Obrigado por jogar! Desafio mestre concluido.\n");

    return 0;
}