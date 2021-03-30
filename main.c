#include <stdlib.h>
#include <stdio.h>

int main()
{
    int menu;
    char nome_hospede;
    int tipo_quarto;
    int numero_apt, numero_dias, data_entrada, data_saida;
    float valor_diaria, valor_total, consumo_frigobar;

    do
    {
        printf("\n\tHotel de Transito - CEFET/MG\n\n");
        printf("1. Cadastro\n");
        printf("2. Consulta\n");
        printf("3. Alteracao\n");
        printf("0. Sair\n");

        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Tipo de quarto:\n 1. Casal\n 2. Solteiro\n");
            printf("Digite o seu nome e o tipo de quarto desejado: \n");
            scanf("%c %d", &nome_hospede, &tipo_quarto);

            printf("Digite a data de entrada e saida: \n");
            scanf("%d %d", &data_entrada, &data_saida);

            printf("Digite o numero do apartamento escolhido e o numero de dias: \n");
            scanf("%d %d", &numero_apt, &numero_dias);
            break;

        case 2:
            printf("Oi %c, seu tipo de quarto: %d\n", nome_hospede, tipo_quarto);
            printf("Data de entrada e saida: %d e %d\n", data_entrada, data_saida);
            printf("Numero do Apartamento e numero de dias: %d e %d dias\n", numero_apt, numero_dias);
            break;

        case 3:
            break;

        case 0:
            return 0;

        default:
            printf("Digite uma opcao valida\n");
        }
    } while (menu);
}
