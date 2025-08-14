#include <stdio.h>
int main()
{
    // Variáveis Atributos da carta 1
    char estado1[3], codigo1[5], cidade1[50];
    int pontosTuristicos1;
    float area1, pib1;
    unsigned long int populacao1;

    // Variáveis Atributos da carta 2
    char estado2[3], codigo2[5], cidade2[50];
    int pontosTuristicos2;
    float area2, pib2;
    unsigned long int populacao2;

    // Solicitacao dos atributos carta 1
    printf("Cadastro dos atributos da carta 1: \n");
    printf("Estado (ex: SP): \n");
    scanf(" %2s", estado1);
    printf("Código da Carta (ex:SP01): \n");
    scanf("%s", codigo1);
    printf("Nome da Cidade: \n");
    scanf(" %49[^\n]", cidade1);
    printf("População: \n");
    scanf("%lu", &populacao1);
    printf("Área (em km²): \n");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): \n");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: \n");
    scanf("%d", &pontosTuristicos1);

    // Solicitação dos atributos carta 2
    printf("\nCadastro dos atributos da carta 2: \n");
    printf("Estado (ex: RJ):: \n");
    scanf(" %2s", estado2);
    printf("Código da carta (ex: RJ02): \n");
    scanf("%s", codigo2);
    printf("Nome da cidade: \n");
    scanf(" %49[^\n]", cidade2);
    printf("População: \n");
    scanf("%lu", &populacao2);
    printf("Área (em km²): \n");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): \n");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: \n");
    scanf("%d", &pontosTuristicos2);

    // Variáveis do cálculo da densidade populacional, PIB per capita e Super Poder
    float densidadePopulacional1 = populacao1 / area1, densidadePopulacional2 = populacao2 / area2;
    float pibPerCapita1 = (pib1 * 1e9) / populacao1, pibPerCapita2 = (pib2 * 1e9) / populacao2;
    float superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + densidadePopulacional1 + pibPerCapita1;
    float superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + densidadePopulacional2 + pibPerCapita2;

    //Confronto para comparação
    //Comparação das cartas Atributo População
    printf("\n%s X %s\n", cidade1, cidade2);
    printf("\nConfronto dos atributos População:\n");
    printf("Carta 1 - Cidade %s População: %lu habitantes\n", cidade1, populacao1);
    printf("Carta 1 - Cidade %s População: %lu habitantes\n", cidade2, populacao2);

    if( populacao1 > populacao2) {
        printf("Carta 1 - Cidade %s vence no atributo População.\n", cidade1);
    }  else {
        printf("Carta 2 - Cidade %s vence no atributo População.\n", cidade2);
    }

    //Comparação das cartas Atributo Área
    printf("\nConfronto dos atributos Área:\n");
    printf("Carta 1 - Cidade %s Área: %.2f km²\n", cidade1, area1);
    printf("Carta 2 - Cidade %s Área: %.2f km²\n", cidade2, area2);

    if( area1 > area2) {
        printf("Carta 1 - Cidade %s vence no atributo Área.\n", cidade1);
    }  else {
        printf("Carta 2 - Cidade %s vence no atributo Área.\n", cidade2);
    }

    //Comparação das cartas Atributo PIB
    printf("\nConfronto dos atributos PIB:\n");
    printf("Carta 1 - Cidade %s PIB: R$ %.2f bilhões de reais\n", cidade1, pib1);
    printf("Carta 2 - Cidade %s PIB: R$ %.2f bilhões de reais\n", cidade2, pib2);

    if( pib1 > pib2) {
        printf("Carta 1 - Cidade %s vence no atributo PIB.\n", cidade1);
    }  else {
        printf("Carta 2 - Cidade %s vence no atributo PIB.\n", cidade2);
    }

    //Comparação das cartas Atributo Pontos Turísticos
    printf("\nConfronto dos atributos Pontos Turísticos:\n");
    printf("Carta 1 - Cidade %s Pontos Turísticos: %d\n", cidade1, pontosTuristicos1);
    printf("Carta 2 - Cidade %s Pontos Turísticos: %d\n", cidade2, pontosTuristicos2);

    if( pontosTuristicos1 > pontosTuristicos2) {
        printf("Carta 1 - Cidade %s vence no atributo Pontos Turísticos.\n", cidade1);
    }  else {
        printf("Carta 2 - Cidade %s vence no atributo Pontos Turísticos.\n", cidade2);
    }

    //Comparação das cartas Atributo Densidade Populacional
    printf("\nConfronto dos atributos Densidade Populacional:\n");
    printf("Carta 1 - Cidade %s Densidade Populacional: %.2f habitantes/km²\n", cidade1, (float)populacao1 / area1);
    printf("Carta 2 - Cidade %s Densidade Populacional: %.2f habitantes/km²\n", cidade2, (float)populacao2 / area2);

    if( (float)populacao1 / area1 < (float)populacao2 / area2) {
        printf("Carta 1- Cidade %s vence no atributo Densidade Populacional.\n", cidade1);
    }  else {
        printf("Carta 2 - Cidade %s vence no atributo Densidade Populacional.\n", cidade2);
    }

    //Comparação das cartas Atributo PIB per capita
    printf("\nConfronto dos atributos PIB per capita:\n");
    printf("Carta 1 - Cidade %s PIB per capita: R$ %.2f/habitante.\n", cidade1, (float) (pib1 *1e9) / populacao1);
    printf("Carta 2 - Cidade %s PIB per capita: R$ %.2f/habitante\n", cidade2, (float) (pib2 *1e9) / populacao2);

    if( (float)(pib1 * 1e9) / populacao1 > (float)(pib2 * 1e9) / populacao2) {
        printf("Carta 1 - Cidade %s vence no atributo PIB per capita.\n", cidade1);
    }  else {
        printf("Carta 2 - Cidade %s vence no atributo PIB per capita.\n", cidade2);
    }

    //Comparação das cartas Atributo Super Poder
    printf("\nConfronto dos atributos Super Poder:\n");
    printf("Carta 1 - Cidade %s Super Poder: %.2f\n", cidade1, (float) populacao1 + area1 + pib1 + pontosTuristicos1 + (float) (pib1 *1e9) / populacao1);
    printf("Carta 2 - Cidade %s Super Poder: %.2f\n", cidade2, (float) populacao2 + area2 + pib2 + pontosTuristicos2 + (float)(pib2 *1e9) / populacao2);

    if( (float) populacao1 + area1 + pib1 + pontosTuristicos1 + (float) (pib1 *1e9) / populacao1 > (float)populacao2 + area2 + pib2 + pontosTuristicos2 + (float)(pib2 *1e9) / populacao2) {
        printf("Carta 1 - Cidade %s vence no atributo Super Poder.\n", cidade1);
    }  else {
        printf("Carta 2 - Cidade %s vence no atributo Super Poder.\n", cidade2);
    }

    return 0;
}