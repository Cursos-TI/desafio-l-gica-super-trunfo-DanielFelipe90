#include <stdio.h>

int main()
{
    // Variáveis Atributos da carta 1
    char estado1[3], codigo1[4], cidade1[50];
    int pontosTuristicos1;
    unsigned long int populacao1;
    float area1, pib1, densidadePopulacional1, pibPerCapita1, superPoder1;

    // Variáveis Atributos da carta 2
    char estado2[3], codigo2[4], cidade2[50];
    int pontosTuristicos2;
    unsigned long int populacao2;
    float area2, pib2, densidadePopulacional2, pibPerCapita2, superPoder2;

    // Variáveis dos menus
    int menuIniciar, menuConfronto1, menuConfronto2;

    // Inicio do código do jogo
    printf("*** Bem Vindo ao jogo Super Trunfo. ***\n");
    printf("Escolha uma opção: \n");
    printf("1. Jogar \n");
    printf("2. Regras\n");
    printf("3. Sair\n");
    printf("Digite sua escolha (1-3): \n");
    scanf("%d", &menuIniciar);

    switch (menuIniciar)
    {
    case 1:
        // Solicitacao dos atributos carta 1
        printf("Cadastre os atributos da carta 1: \n");
        printf("Digite o Estado (ex: SP): \n");
        scanf(" %2s", estado1);
        printf("Digite Código da Carta (ex:SP01): \n");
        scanf(" %s", codigo1);
        printf("Digite o nome da Cidade: \n");
        scanf(" %49[^\n]", cidade1);
        printf("Digite a População: \n");
        scanf("%d", &populacao1);
        printf("Digite a Área (em km²): \n");
        scanf("%f", &area1);
        printf("Digite o PIB (em bilhões de reais): \n");
        scanf("%f", &pib1);
        printf("Digite o número de Pontos Turísticos: \n");
        scanf("%d", &pontosTuristicos1);

        // Solicitacao dos atributos carta 2
        printf("\nCadastre os atributos da carta 2: \n");
        printf("Digite o Estado (ex: RJ): \n");
        scanf(" %2s", estado2);
        printf("Digite Código da Carta (ex: RJ02): \n");
        scanf("%s", codigo2);
        printf("Digite o nome da Cidade: \n");
        scanf(" %49[^\n]", cidade2);
        printf("Digite a População: \n");
        scanf("%d", &populacao2);
        printf("Digite a Área (em km²): \n");
        scanf("%f", &area2);
        printf("Digite o PIB (em bilhões de reais): \n");
        scanf("%f", &pib2);
        printf("Digite o Número de Pontos turísticos: \n");
        scanf("%d", &pontosTuristicos2);

        // Escolha do atributo para o primeiro confronto
        printf("\nEscolha o primeiro atributo para o confronto:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per Capita\n");
        printf("7. Super Poder\n");
        printf("Digite sua escolha (1-7): \n");
        scanf("%d", &menuConfronto1);

        // Escolha do atributo para o segundo confronto
        printf("\nEscolha o segundo atributo para o confronto:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per Capita\n");
        printf("7. Super Poder\n");
        printf("Digite sua escolha (1-7): \n");
        scanf("%d", &menuConfronto2);

        // Validação
        if (menuConfronto2 == menuConfronto1 || menuConfronto1 < 1 || menuConfronto1 > 7 || menuConfronto2 < 1 || menuConfronto2 > 7)
        {
            // Escolha do atributo para o segundo confronto
            printf("\nInválido ou atributo repetido!\n");
            printf("\nEscolha o segundo atributo para o confronto:\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade Populacional\n");
            printf("6. PIB per Capita\n");
            printf("7. Super Poder\n");
            printf("Digite sua escolha (1-7): \n");
            scanf("%d", &menuConfronto2);
        }

        // Variáveis para o cálculo Densidade demográfica, PIB per capita e Super Poder
        float densidadePopulacional1 = populacao1 / area1;
        float densidadePopulacional2 = populacao2 / area2;
        float pibPerCapita1 = (pib1 * 1e9) / populacao1;
        float pibPerCapita2 = (pib2 * 1e9) / populacao2;
        float superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + densidadePopulacional1 + pibPerCapita1;
        float superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + densidadePopulacional2 + pibPerCapita2;

        // Resultado do confronto
        printf("\n*** Confronto ***\n");

        // Variáveis para a captura do atributo selecionado
        float menuConfronto1_Valor1_carta1, menuConfronto2_valor2_carta1;

        // Atributo 1
        switch (menuConfronto1)
        {
        case 1:
            menuConfronto1_Valor1_carta1 = populacao1;
            menuConfronto2_valor2_carta1 = populacao2;
            break;
        case 2:
            menuConfronto1_Valor1_carta1 = area1;
            menuConfronto2_valor2_carta1 = area2;
            break;
        case 3:
            menuConfronto1_Valor1_carta1 = pib1;
            menuConfronto2_valor2_carta1 = pib2;
            break;
        case 4:
            menuConfronto1_Valor1_carta1 = pontosTuristicos1;
            menuConfronto2_valor2_carta1 = pontosTuristicos2;
            break;
        case 5:
            menuConfronto1_Valor1_carta1 = densidadePopulacional1;
            menuConfronto2_valor2_carta1 = densidadePopulacional2;
            break;
        case 6:
            menuConfronto1_Valor1_carta1 = pibPerCapita1;
            menuConfronto2_valor2_carta1 = pibPerCapita2;
            break;
        case 7:
            menuConfronto1_Valor1_carta1 = superPoder1;
            menuConfronto2_valor2_carta1 = superPoder2;
            break;
        }

        // Variáveis aplicadas para a captura do atributo selecionado
        float menuConfronto1_valor1_carta2, menuConfronto2_valor2_carta2;

        // Atributo 2
        switch (menuConfronto2)
        {
        case 1:
            menuConfronto1_valor1_carta2 = populacao1;
            menuConfronto2_valor2_carta2 = populacao2;
            break;
        case 2:
            menuConfronto1_valor1_carta2 = area1;
            menuConfronto2_valor2_carta2 = area2;
            break;
        case 3:
            menuConfronto1_valor1_carta2 = pib1;
            menuConfronto2_valor2_carta2 = pib2;
            break;
        case 4:
            menuConfronto1_valor1_carta2 = pontosTuristicos1;
            menuConfronto2_valor2_carta2 = pontosTuristicos2;
            break;
        case 5:
            menuConfronto1_valor1_carta2 = densidadePopulacional1;
            menuConfronto2_valor2_carta2 = densidadePopulacional2;
            break;
        case 6:
            menuConfronto1_valor1_carta2 = pibPerCapita1;
            menuConfronto2_valor2_carta2 = pibPerCapita2;
            break;
        case 7:
            menuConfronto1_valor1_carta2 = superPoder1;
            menuConfronto2_valor2_carta2 = superPoder2;
            break;
        }

        // Resultado do primeiro confronto
        printf("\n%s X %s\n", cidade1, cidade2);
        printf("\nConfronto do Primeiro Atributo: \n");
        switch (menuConfronto1)
        {
        case 1:
            printf("População: ");
            break;
        case 2:
            printf("Área em km²:");
            break;
        case 3:
            printf("PIB em bilhões de R$: ");
            break;
        case 4:
            printf("Pontos Turísticos: ");
            break;
        case 5:
            printf("Densidade Populacional: ");
            break;
        case 6:
            printf("PIB per capita em R$: ");
            break;
        case 7:
            printf("Super Poder: ");
            break;
        }
        printf("\n%s: %.2f\n%s: %.2f\n", cidade1, menuConfronto1_Valor1_carta1, cidade2, menuConfronto2_valor2_carta1);
        printf("Vencedor: %s\n", (menuConfronto1 == 5) ? (menuConfronto1_Valor1_carta1 < menuConfronto2_valor2_carta1 ? cidade1 : (menuConfronto2_valor2_carta1 < menuConfronto1_Valor1_carta1 ? cidade2 : "Empate")) : (menuConfronto1_Valor1_carta1 > menuConfronto2_valor2_carta1 ? cidade1 : (menuConfronto2_valor2_carta1 > menuConfronto1_Valor1_carta1 ? cidade2 : "Empate")));

        // Resultado do segundo confronto
        printf("\nConfronto do Segundo Atributo: \n");
        switch (menuConfronto2)
        {
        case 1:
            printf("População: ");
            break;
        case 2:
            printf("Área em km²: ");
            break;
        case 3:
            printf("PIB em bilhões de R$: ");
            break;
        case 4:
            printf("Pontos Turísticos: ");
            break;
        case 5:
            printf("Densidade Populacional: ");
            break;
        case 6:
            printf("PIB per capita em R$: ");
            break;
        case 7:
            printf("Super Poder: ");
            break;
        }

        // Exibe o resultado final do confronto
        printf("\n%s: %.2f\n%s: %.2f\n", cidade1, menuConfronto1_valor1_carta2, cidade2, menuConfronto2_valor2_carta2);
        printf("Vencedor: %s\n", (menuConfronto2 == 5) ? (menuConfronto1_valor1_carta2 < menuConfronto2_valor2_carta2 ? cidade1 : (menuConfronto2_valor2_carta2 < menuConfronto1_valor1_carta2 ? cidade2 : "Empate")) : (menuConfronto1_valor1_carta2 > menuConfronto2_valor2_carta2 ? cidade1 : (menuConfronto2_valor2_carta2 > menuConfronto1_valor1_carta2 ? cidade2 : "Empate")));

        // Variáveis Soma para o resultado final
        float soma1 = menuConfronto1_Valor1_carta1 + menuConfronto1_valor1_carta2;
        float soma2 = menuConfronto2_valor2_carta1 + menuConfronto2_valor2_carta2;

        printf("\nSoma dos Atributos das cidades:\n%s: %.2f\n%s: %.2f\n", cidade1, soma1, cidade2, soma2);
        printf("\nResultado Final do Confronto: \n*** %s Vence!! ***\n",
               soma1 > soma2 ? cidade1 : (soma2 > soma1 ? cidade2 : "Empate"));
        break;
        // Fim do código do jogo

    case 2:
        // Inicio do código das regra do jogo
        printf("*** Regras do jogo: ***\n");
        printf("1. Adicione os atributos das cartas 1 e 2.\n");
        printf("2. O jogador escolhe um atributo para o confronto.\n");
        printf("3. O jogador com a maior soma dos atributos vence a rodada.\n");
        break;
        // Fim do código das regra do jogo
    case 3:
        printf("\nSaindo...\n");
        break;

    default:
        printf("\nOpção inválida!\n");
        break;
    }

    return 0;
}