#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[50];
    char codigo[50];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Digite o estado: ");
    scanf("%s", carta->estado);
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->nome_cidade);
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Calculando a densidade populacional e o PIB per capita
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para determinar a carta vencedora
void compararCartas(Carta c1, Carta c2, char atributo[]) {
    float valor1, valor2;
    int menorVence = 0; // 1 se a menor densidade vencer
    
    if (strcmp(atributo, "Populacao") == 0) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (strcmp(atributo, "Area") == 0) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (strcmp(atributo, "PIB") == 0) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (strcmp(atributo, "Densidade Populacional") == 0) {
        valor1 = c1.densidade_populacional;
        valor2 = c2.densidade_populacional;
        menorVence = 1;
    } else if (strcmp(atributo, "PIB per capita") == 0) {
        valor1 = c1.pib_per_capita;
        valor2 = c2.pib_per_capita;
    } else {
        printf("Atributo inválido!\n");
        return;
    }
    
    printf("\nComparação de cartas (Atributo: %s):\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nome_cidade, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome_cidade, c2.estado, valor2);
    
    if ((menorVence && valor1 < valor2) || (!menorVence && valor1 > valor2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    }
}

int main() {
    Carta carta1, carta2;
    
    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);
    
    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);
    
    // Escolha fixa do atributo a ser comparado
    char atributo[] = "Populacao"; // Pode alterar para "Area", "PIB", "Densidade Populacional" ou "PIB per capita"
    
    // Comparação das cartas
    compararCartas(carta1, carta2, atributo);
    
    return 0;
}
