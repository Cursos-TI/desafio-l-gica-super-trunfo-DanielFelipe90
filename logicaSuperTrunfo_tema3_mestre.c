#include <stdio.h>
#include <string.h>

// Função para limpar o buffer de entrada
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

    // Variáveis para contagem de vitórias
    int vitoriasCarta1 = 0;
    int vitoriasCarta2 = 0;

    printf("*** Bem Vindo ao jogo Super Trunfo. ***\n");
    printf("Escolha uma opção: \n");
    printf("1. Jogar \n");
    printf("2. Regras\n");
    printf("3. Sair\n");
    printf("Digite sua escolha (1-3): \n");
    scanf(" %d", &menuIniciar);
    clear_input_buffer();
    
    switch (menuIniciar)
    {
        case 1:
        // Inicio do código do jogo
        // Solicitacao dos atributos carta 1
        printf("Cadastre os atributos da carta 1: \n");
        printf("Digite o Estado (ex: SP): \n");
        scanf(" %2s", estado1);
        clear_input_buffer();
        printf("Digite Código da Carta (ex:SP01): \n");
        scanf(" %s", codigo1);
        clear_input_buffer();
        printf("Digite o nome da Cidade: \n");
        scanf(" %49[^\n]", cidade1);
        clear_input_buffer();
        printf("Digite a População: \n");
        scanf(" %lu", &populacao1);
        clear_input_buffer();
        printf("Digite a Área (em km²): \n");
        scanf(" %f", &area1);
        clear_input_buffer();
        printf("Digite o PIB (em bilhões de reais): \n");
        scanf(" %f", &pib1);
        clear_input_buffer();
        printf("Digite o número de Pontos Turísticos: \n");
        scanf(" %d", &pontosTuristicos1);
        clear_input_buffer();

        // Solicitacao dos atributos carta 2
        printf("\nCadastre os atributos da carta 2: \n");
        printf("Digite o Estado (ex: RJ): \n");
        scanf(" %2s", estado2);
        clear_input_buffer();
        printf("Digite Código da Carta (ex: RJ02): \n");
        scanf(" %s", codigo2);
        clear_input_buffer();
        printf("Digite o nome da Cidade: \n");
        scanf(" %49[^\n]", cidade2);
        clear_input_buffer();
        printf("Digite a População: \n");
        scanf(" %lu", &populacao2);
        clear_input_buffer();
        printf("Digite a Área (em km²): \n");
        scanf(" %f", &area2);
        clear_input_buffer();
        printf("Digite o PIB (em bilhões de reais): \n");
        scanf(" %f", &pib2);
        clear_input_buffer();
        printf("Digite o Número de Pontos turísticos: \n");
        scanf(" %d", &pontosTuristicos2);
        clear_input_buffer();

        // Calcula os atributos derivados após todas as entradas
        densidadePopulacional1 = populacao1 / area1;
        densidadePopulacional2 = populacao2 / area2;
        pibPerCapita1 = (pib1 * 1e9) / populacao1;
        pibPerCapita2 = (pib2 * 1e9) / populacao2;
        // Adiciona o inverso da densidade populacional ao super poder, com verificação de divisão por zero
        superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 +
                      (densidadePopulacional1 != 0.0f ? (1.0f / densidadePopulacional1) : 0.0f);
        superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 +
                      (densidadePopulacional2 != 0.0f ? (1.0f / densidadePopulacional2) : 0.0f);

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
        scanf(" %d", &menuConfronto1);
        clear_input_buffer();

        // Loop para validar o segundo confronto
        do
        {
            printf("\nEscolha o segundo atributo para o confronto:\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade Populacional\n");
            printf("6. PIB per Capita\n");
            printf("7. Super Poder\n");
            printf("Digite sua escolha (1-7): \n");
            scanf(" %d", &menuConfronto2);
            clear_input_buffer();

            if (menuConfronto2 == menuConfronto1 || menuConfronto2 < 1 || menuConfronto2 > 7)
            {
                printf("\nInválido ou atributo repetido! Tente novamente.\n");
            }
        } while (menuConfronto2 == menuConfronto1 || menuConfronto2 < 1 || menuConfronto2 > 7);

        // Variáveis para a captura do atributo selecionado
        float menuConfronto1_Valor1_carta1, menuConfronto2_valor2_carta1;
        float menuConfronto1_valor1_carta2, menuConfronto2_valor2_carta2;

        // Resultado do confronto
        printf("\n*** Confronto ***\n");
        printf("*** %s X %s ***\n",cidade1, cidade2);
        // --- Confronto 1 ---
        printf("\nConfronto do Primeiro Atributo: \n");
        switch (menuConfronto1)
        {
        case 1:
            printf("População: ");
            menuConfronto1_Valor1_carta1 = (float)populacao1;
            menuConfronto2_valor2_carta1 = (float)populacao2;
            break;
        case 2:
            printf("Área em km²: ");
            menuConfronto1_Valor1_carta1 = area1;
            menuConfronto2_valor2_carta1 = area2;
            break;
        case 3:
            printf("PIB em bilhões de R$: ");
            menuConfronto1_Valor1_carta1 = pib1;
            menuConfronto2_valor2_carta1 = pib2;
            break;
        case 4:
            printf("Pontos Turísticos: ");
            menuConfronto1_Valor1_carta1 = (float)pontosTuristicos1;
            menuConfronto2_valor2_carta1 = (float)pontosTuristicos2;
            break;
        case 5:
            printf("Densidade Populacional: ");
            menuConfronto1_Valor1_carta1 = densidadePopulacional1;
            menuConfronto2_valor2_carta1 = densidadePopulacional2;
            break;
        case 6:
            printf("PIB per Capita: ");
            menuConfronto1_Valor1_carta1 = pibPerCapita1;
            menuConfronto2_valor2_carta1 = pibPerCapita2;
            break;
        case 7:
            printf("Super Poder: ");
            menuConfronto1_Valor1_carta1 = superPoder1;
            menuConfronto2_valor2_carta1 = superPoder2;
            break;
        }

        printf("\n%s: %.2f\n%s: %.2f\n", cidade1, menuConfronto1_Valor1_carta1, cidade2, menuConfronto2_valor2_carta1);
        printf("Vencedor: %s\n", (menuConfronto1 == 5) ? (menuConfronto1_Valor1_carta1 < menuConfronto2_valor2_carta1 ? cidade1 : (menuConfronto2_valor2_carta1 < menuConfronto1_Valor1_carta1 ? cidade2 : "Empate")) : (menuConfronto1_Valor1_carta1 > menuConfronto2_valor2_carta1 ? cidade1 : (menuConfronto2_valor2_carta1 > menuConfronto1_Valor1_carta1 ? cidade2 : "Empate")));
        
        // Lógica para incrementar o contador de vitórias do primeiro confronto
        if ((menuConfronto1 == 5 && menuConfronto1_Valor1_carta1 < menuConfronto2_valor2_carta1) || (menuConfronto1 != 5 && menuConfronto1_Valor1_carta1 > menuConfronto2_valor2_carta1)) {
            vitoriasCarta1++;
        } else if ((menuConfronto1 == 5 && menuConfronto2_valor2_carta1 < menuConfronto1_Valor1_carta1) || (menuConfronto1 != 5 && menuConfronto2_valor2_carta1 > menuConfronto1_Valor1_carta1)) {
            vitoriasCarta2++;
        }

        // --- Confronto 2 ---
        printf("\nConfronto do Segundo Atributo: \n");
        switch (menuConfronto2)
        {
        case 1:
            printf("População: ");
            menuConfronto1_valor1_carta2 = (float)populacao1;
            menuConfronto2_valor2_carta2 = (float)populacao2;
            break;
        case 2:
            printf("Área em km²: ");
            menuConfronto1_valor1_carta2 = area1;
            menuConfronto2_valor2_carta2 = area2;
            break;
        case 3:
            printf("PIB em bilhões de R$: ");
            menuConfronto1_valor1_carta2 = pib1;
            menuConfronto2_valor2_carta2 = pib2;
            break;
        case 4:
            printf("Pontos Turísticos: ");
            menuConfronto1_valor1_carta2 = (float)pontosTuristicos1;
            menuConfronto2_valor2_carta2 = (float)pontosTuristicos2;
            break;
        case 5:
            printf("Densidade Populacional: ");
            menuConfronto1_valor1_carta2 = densidadePopulacional1;
            menuConfronto2_valor2_carta2 = densidadePopulacional2;
            break;
        case 6:
            printf("PIB per Capita: ");
            menuConfronto1_valor1_carta2 = pibPerCapita1;
            menuConfronto2_valor2_carta2 = pibPerCapita2;
            break;
        case 7:
            printf("Super Poder: ");
            menuConfronto1_valor1_carta2 = superPoder1;
            menuConfronto2_valor2_carta2 = superPoder2;
            break;
        }

        printf("\n%s: %.2f\n%s: %.2f\n", cidade1, menuConfronto1_valor1_carta2, cidade2, menuConfronto2_valor2_carta2);
        printf("Vencedor: %s\n", (menuConfronto2 == 5) ? (menuConfronto1_valor1_carta2 < menuConfronto2_valor2_carta2 ? cidade1 : (menuConfronto2_valor2_carta2 < menuConfronto1_valor1_carta2 ? cidade2 : "Empate")) : (menuConfronto1_valor1_carta2 > menuConfronto2_valor2_carta2 ? cidade1 : (menuConfronto2_valor2_carta2 > menuConfronto1_valor1_carta2 ? cidade2 : "Empate")));

        // Lógica para incrementar o contador de vitórias do segundo confronto
        if ((menuConfronto2 == 5 && menuConfronto1_valor1_carta2 < menuConfronto2_valor2_carta2) || (menuConfronto2 != 5 && menuConfronto1_valor1_carta2 > menuConfronto2_valor2_carta2)) {
            vitoriasCarta1++;
        } else if ((menuConfronto2 == 5 && menuConfronto2_valor2_carta2 < menuConfronto1_valor1_carta2) || (menuConfronto2 != 5 && menuConfronto2_valor2_carta2 > menuConfronto1_valor1_carta2)) {
            vitoriasCarta2++;
        }
        
        // Lógica final para determinar o vencedor da rodada
        printf("\nVitórias de %s: %d\n", cidade1, vitoriasCarta1);
        printf("Vitórias de %s: %d\n", cidade2, vitoriasCarta2);
        
        if (vitoriasCarta1 > vitoriasCarta2) {
            printf("\nResultado Final: \n*** %s Vence!! ***\n", cidade1);
        } else if (vitoriasCarta2 > vitoriasCarta1) {
            printf("\nResultado Final: \n*** %s Vence!! ***\n", cidade2);
        } else {
            printf("\nResultado Final: **** Empate! ****\n");
        }

        break;
        // Fim do código do jogo

    case 2:
        // Inicio do código das regra do jogo
        printf("*** Regras do jogo: ***\n");
        printf("1. Adicione os atributos das cartas 1 e 2.\n");
        printf("2. O jogador escolhe dois atributos para o confronto.\n");
        printf("3. O vencedor da rodada é quem vence a maioria dos atributos (dois de dois).\n");
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
