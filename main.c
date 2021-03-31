#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int main()
{
    int menu, numero_dias, apartamento;
    float valor_diaria, valor_total, consumo_frigobar, data_entrada, data_saida;
    char tipo_quarto[10], nome_hospede[10][20];

    // consumo_frigobar

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
                printf("Digite o seu nome: \n");
                scanf("%s", nome_hospede);

                printf("Digite o tipo de quarto desejado (solteiro ou casal): \n");
                scanf("%s", tipo_quarto);

                printf("Digite a data de entrada e saida: \n");
                scanf("%f %f", &data_entrada, &data_saida);

                printf("Digite o numero do apartamento escolhido (1 a 10) e o numero de dias: \n");
                scanf("%d %d", &apartamento, &numero_dias);
                break;

            case 2:
                printf("Oi %s, seu tipo de quarto: %s\n", nome_hospede, tipo_quarto);
                printf("Data de entrada e saida: %.f e %.f\n", data_entrada, data_saida);
                printf("Numero do Apartamento e numero de dias: Apt. %d e %d dias de estadia\n", apartamento, numero_dias);

                if(tipo_quarto == "Solteiro")
                {
                    valor_diaria = 50;
                }
                else
                {
                    valor_diaria = 100;
                }

                valor_total = valor_diaria * numero_dias;
                printf("O valor total sera: %.f reais", valor_total);
                break;

            case 3:
                printf("Digite o seu nome: \n");
                scanf("%s", nome_hospede);

                printf("Digite o tipo de quarto desejado (solteiro ou casal): \n");
                scanf("%s", tipo_quarto);

                printf("Digite a data de entrada e saida: \n");
                scanf("%f %f", &data_entrada, &data_saida);

                printf("Digite o numero do apartamento escolhido (1 a 10) e o numero de dias: \n");
                scanf("%d %d", &apartamento, &numero_dias);
                break;

            case 0:
                return 0;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while (menu);
}
