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
    // Variáveis Atributos carta 1
    char estado1[3], codigo1[4], cidade1[50];
    int pontosTuristicos1;
    unsigned long int populacao1;
    float area1, pib1;
    
    // Variáveis Atributos carta 2
    char estado2[3], codigo2[4], cidade2[50];
    int pontosTuristicos2;
    unsigned long int populacao2;
    float area2, pib2;
    
    // Variáveis dos menus (switch)
    int menuIniciar, menuConfronto;

    // Início do jogo
    printf("*** Bem Vindo ao jogo Super Trunfo. ***\n");
    printf("Escolha uma opção: \n");
    printf("1. Iniciar jogo.\n");
    printf("2. Regras.\n");
    printf("3. Sair.\n");
    printf("Digite sua escolha (1-3): \n");
    scanf("%d", &menuIniciar);
    clear_input_buffer();

    switch (menuIniciar)
    {
     case 1:
      //Inicio do código do jogo
        printf("\n*** Iniciando jogo... ***\n");
        // Solicitacao dos atributos carta 1
        printf("\nCadastre os atributos da carta 1: \n");
        printf("Digite o Estado (ex: SP): \n");
        scanf("%2s", estado1);
        clear_input_buffer();
        printf("Digite o Código da Carta (ex: SP01): \n");
        scanf("%3s", codigo1);
        clear_input_buffer();
        printf("Digite o nome da Cidade: \n");
        fgets(cidade1, sizeof(cidade1), stdin);
        cidade1[strcspn(cidade1, "\n")] = 0; // Remove o '\n' do final
        printf("Digite a População: \n");
        scanf("%lu", &populacao1);
        clear_input_buffer();
        printf("Digite a Área (em km²): \n");
        scanf("%f", &area1);
        clear_input_buffer();
        printf("Digite o PIB (em bilhões de reais): \n");
        scanf("%f", &pib1);
        clear_input_buffer();
        printf("Digite o número de Pontos Turísticos: \n");
        scanf("%d", &pontosTuristicos1);
        clear_input_buffer();

        // Cadastro dos atributos da carta 2
        printf("\nCadastre os atributos da carta 2: \n");
        printf("Digite o Estado (ex: RJ): \n");
        scanf("%2s", estado2);
        clear_input_buffer();
        printf("Digite o Código da Carta (ex: RJ02): \n");
        scanf("%3s", codigo2);
        clear_input_buffer();
        printf("Digite o nome da Cidade: \n");
        fgets(cidade2, sizeof(cidade2), stdin);
        cidade2[strcspn(cidade2, "\n")] = 0; // Remove o '\n' do final
        printf("Digite a População: \n");
        scanf("%lu", &populacao2);
        clear_input_buffer();
        printf("Digite a Área (em km²): \n");
        scanf("%f", &area2);
        clear_input_buffer();
        printf("Digite o PIB (em bilhões de reais): \n");
        scanf("%f", &pib2);
        clear_input_buffer();
        printf("Digite o Número de Pontos turísticos: \n");
        scanf("%d", &pontosTuristicos2);
        clear_input_buffer();

        // Menu para escolher o atributo para o confronto
        printf("\nEscolha o atributo para o confronto:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per Capita\n");
        printf("7. Super Poder\n");
        printf("Digite sua escolha (1-7): \n");
        scanf("%d", &menuConfronto);
        clear_input_buffer();

            switch (menuConfronto)
            {
             case 1:
                // Variáveis do cálculo da densidade populacional, PIB per capita e Super Poder
                float densidadePopulacional1 = populacao1 / area1,  densidadePopulacional2 = populacao2 / area2;
                float pibPerCapita1 = (pib1 * 1e9) / populacao1, pibPerCapita2 = (pib2 * 1e9) / populacao2;
                float superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + densidadePopulacional1 + pibPerCapita1;
                float superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + densidadePopulacional2 + pibPerCapita2;

                //Comparação do Atributo População
                printf("\nConfronto do atributo População:\n");
                printf("\n**** %s X %s ***\n", cidade1, cidade2);
                printf("Carta 1 - Cidade %s População: %lu habitantes.\n", cidade1, populacao1);
                printf("Carta 1 - Cidade %s População: %lu habitantes.\n", cidade2, populacao2);
                if( populacao1 > populacao2) {
                printf("Vence a Carta 1 - Cidade %s no atributo População.\n", cidade1);
                } else if (populacao1 < populacao2){
                printf("Vence a Carta 2 - Cidade %s no atributo População.\n", cidade2);
                } else {
                    printf("*** Empate ***");
                }
                break;
            
             case 2:
                //Comparação do Atributo Área
                printf("\nConfronto do atributo Área:\n");
                printf("\n*** %s X %s ***\n", cidade1, cidade2);
                printf("Carta 1 - Cidade %s Área: %.2f km².\n", cidade1, area1);
                printf("Carta 2 - Cidade %s Área: %.2f km².\n", cidade2, area2);
                if( area1 > area2) {
                printf("Vence a Carta 1 - Cidade %s no atributo Área.\n", cidade1);
                }  else if (area1 < area2){
                printf("Vence a Carta 2 - Cidade %s no atributo Área.\n", cidade2);
                } else{
                    printf("*** Empate ***");
                }
                break;
            
             case 3:
                //Comparação do Atributo PIB
                printf("\nConfronto do atributo PIB:\n");
                printf("\n*** %s X %s ***\n", cidade1, cidade2);
                printf("Carta 1 - Cidade %s PIB: R$ %.2f bilhões.\n", cidade1, pib1);
                printf("Carta 2 - Cidade %s PIB: R$ %.2f bilhões.\n", cidade2, pib2);
                if( pib1 > pib2) {
                printf("Vence a Carta 1 - Cidade %s no atributo PIB.\n", cidade1);
                }  else if (pib1 < pib2){
                printf("Vence a Carta 2 - Cidade %s no atributo PIB.\n", cidade2);
                } else {
                    printf("*** Empate ***");
                }
                break;

             case 4:
                //Comparação do Atributo Pontos Turísticos
                printf("\nConfronto do atributo Pontos Turísticos:\n");
                printf("\n*** %s X %s ***\n", cidade1, cidade2);
                printf("Carta 1 - Cidade %s Pontos Turísticos: %d\n", cidade1, pontosTuristicos1);
                printf("Carta 2 - Cidade %s Pontos Turísticos: %d\n", cidade2, pontosTuristicos2);
                if( pontosTuristicos1 > pontosTuristicos2) {
                printf("Vence a Carta 1 - Cidade %s no atributo Pontos Turísticos.\n", cidade1);
                }  else if (pontosTuristicos1 < pontosTuristicos2){
                printf("Vence a Carta 2 - Cidade %s no atributo Pontos Turísticos.\n", cidade2);
                } else {
                    printf("*** Empate ***");
                }
                break;

             case 5:
                //Comparação do Atributo Densidade Populacional
                printf("\nConfronto do atributo Densidade Populacional:\n");
                printf("\n*** %s X %s ***\n", cidade1, cidade2);
                printf("Carta 1 - Cidade %s Densidade Populacional: %.2f habitantes/km².\n", cidade1, (float)populacao1 / area1);
                printf("Carta 2 - Cidade %s Densidade Populacional: %.2f habitantes/km².\n", cidade2, (float)populacao2 / area2);
                if ((float)populacao1 / area1 < (float)populacao2 / area2){
                printf("Vence a Carta 1 - Cidade %s no atributo Densidade Populacional.\n", cidade1);
                }  else if (densidadePopulacional1 < densidadePopulacional2){
                printf("Vence a Carta 2 - Cidade %s no atributo Densidade Populacional.\n", cidade2);
                } else {
                    printf("*** Empate ***");
                }
                break;

             case 6:
                //Comparação do Atributo PIB per capita
                printf("\nConfronto do atributo PIB per capita:\n");
                printf("\n*** %s X %s ***\n", cidade1, cidade2);
                printf("Carta 1 - Cidade %s PIB per capita: R$ %.2f/habitante.\n", cidade1, (float) (pib1 *1e9) / populacao1);
                printf("Carta 2 - Cidade %s PIB per capita: R$ %.2f/habitante.\n", cidade2, (float) (pib2 *1e9) / populacao2);
                if( (float)(pib1 * 1e9) / populacao1 > (float)(pib2 * 1e9) / populacao2) {
                printf("Vence a Carta 1 - Cidade %s no atributo PIB per capita.\n", cidade1);
                }  else if (pibPerCapita1 < pibPerCapita2){
                printf("Vence a Carta 2 - Cidade %s no atributo PIB per capita.\n", cidade2);
                } else {
                    printf("*** Empate ***");
                }
                break;

             case 7:
                //Comparação do Atributo Super Poder
                printf("\nConfronto dos atributos Super Poder:\n");
                printf("\n*** %s X %s ***\n", cidade1, cidade2);
                printf("Carta 1 - Cidade %s Super Poder: %.2f.\n", cidade1, superPoder1);
                printf("Carta 2 - Cidade %s Super Poder: %.2f.\n", cidade2, superPoder2);
                if(superPoder1 > superPoder2) {
                printf("Vence a Carta 1 - Cidade %s no atributo Super Poder.\n", cidade1);
                }  else if (superPoder1 < superPoder2){
                printf("Vence a Carta 2 - Cidade %s no atributo Super Poder.\n", cidade2);
                } else {
                    printf("*** Empate ***");
                }
                break;
            }
       break;
     //Fim do código jogo

     case '2':
        // Inicio do código das regra do jogo
        printf("*** Regras do jogo: ***\n");
        printf("1. Adicione os atributos das cartas 1 e 2.\n");
        printf("2. O jogador escolhe uma característica para comparar.\n");
        printf("3. O jogador com a maior característica vence a rodada.\n");
        // Fim do código das regra do jogo
        break;

     case '3':
        printf("Saindo do jogo...\n");
        break;

     default:
        printf("Opção inválida. Por favor, escolha 1, 2 ou 3.\n");
        break;
   }

 return 0;
}