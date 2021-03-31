#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int main()
{
    int menu, numero_dias, apartamento, tipo_quarto;
    float valor_diaria, valor_total, consumo_frigobar = 0, data_entrada, data_saida;
    char nome_hospede[10][20];

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

                printf("Digite o tipo de quarto desejado (1 para solteiro ou 2 para casal): \n");
                scanf("%d", &tipo_quarto);

                printf("Digite a data de entrada e saida: \n");
                scanf("%f %f", &data_entrada, &data_saida);

                printf("Digite o numero do apartamento escolhido (1 a 10) e o numero de dias: \n");
                scanf("%d %d", &apartamento, &numero_dias);

                printf("Deseja consumir a taxa do frigobar (1 e 0): \n");
                scanf("%f", &consumo_frigobar);
                break;

            case 2:
                printf("Oi %s, seu tipo de quarto: %d\n", nome_hospede, tipo_quarto);
                printf("Data de entrada e saida: %.f e %.f\n", data_entrada, data_saida);
                printf("Numero do Apartamento e numero de dias: Apt. %d e %d dias de estadia\n", apartamento, numero_dias);

                if(tipo_quarto == 1 && consumo_frigobar == 1)
                {
                    valor_diaria = 50;
                    consumo_frigobar = 20;
                }
                else if(tipo_quarto == 1 && consumo_frigobar == 0)
                {
                    valor_diaria = 50;
                    consumo_frigobar = 0;
                }
                else if(tipo_quarto == 2 && consumo_frigobar == 1)
                {
                    valor_diaria = 100;
                    consumo_frigobar = 20;
                }
                else
                {
                    valor_diaria = 100;
                    consumo_frigobar = 0;
                }

                valor_total = (valor_diaria * numero_dias) + consumo_frigobar;
                printf("O valor total sera: %.f reais", valor_total);
                break;

            case 3:
                printf("Digite o seu nome: \n");
                scanf("%s", nome_hospede);

                printf("Digite o tipo de quarto desejado (1 para solteiro ou 2 para casal): \n");
                scanf("%d", &tipo_quarto);

                printf("Digite a data de entrada e saida: \n");
                scanf("%f %f", &data_entrada, &data_saida);

                printf("Digite o numero do apartamento escolhido (1 a 10) e o numero de dias: \n");
                scanf("%d %d", &apartamento, &numero_dias);

                printf("Deseja consumir a taxa do frigobar (1 e 0): \n");
                scanf("%f", &consumo_frigobar);
                break;

            case 0:
                return 0;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while (menu);
}
