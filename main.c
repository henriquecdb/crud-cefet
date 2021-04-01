#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int main()
{
    int menu, numero_dias, apartamento, tipo_quarto[MAX];
    int valor_diaria, valor_total, consumo_frigobar[MAX], dia_entrada[MAX], mes_entrada[MAX], dia_saida[MAX], mes_saida[MAX], valor_consumo, ocupado[MAX];
    char nome_hospede[MAX][20];

    for (int i = 0; i < MAX; i++){
        ocupado[i] = 0;
    }


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
                printf("Digite o numero do apartamento desejado (1 a 10): \n");
                scanf("%d", &apartamento);

                if (ocupado[apartamento] == 1){
                    printf("O quarto esta ocupado, tente outro.\n");
                    break;
                }

                printf("Digite o seu nome: \n");
                scanf("%s", nome_hospede[apartamento]);
                fflush(stdin);

                printf("Digite o tipo de quarto desejado (1 para solteiro ou 2 para casal): \n");
                scanf("%d", &tipo_quarto[apartamento]);

                printf("Digite o dia e mes de entrada e o dia e mes de saida: \n");

                printf("Por exemplo 03(dia) (04) mes 15(dia de saida) 04(mes de saida) \n");
                scanf("%d", &dia_entrada[apartamento]);
                scanf("%d", &mes_entrada[apartamento]);
                scanf( "%d", &dia_saida[apartamento]);
                scanf("%d", &mes_saida[apartamento]);

                printf("Deseja consumir a taxa do frigobar? 1 para Nao, 2 para Sim \n");
                scanf("%d", &consumo_frigobar[apartamento]);

                printf("Cadastro completo.\n");

                ocupado[apartamento] = 1;
                break;

            case 2:
                printf("Ola cliente, por favor digite o numero do quarto:\n");
                scanf("%d", &apartamento);


                printf("Oi %s, seu tipo de quarto: %d\n", nome_hospede[apartamento], tipo_quarto[apartamento]);
                printf("Dia de entrada e mes: %.d/%.d\n", dia_entrada[apartamento], mes_entrada[apartamento]);
                printf("Dia de saida e mes: %.d/%.d\n", dia_saida[apartamento], mes_saida[apartamento]);

                if (consumo_frigobar[apartamento] == 1) {
                    valor_consumo = 0;
                } else {
                    valor_consumo = 20;
                }

                if (tipo_quarto[apartamento] == 1) {
                    valor_diaria = 50;
                } else {
                    valor_diaria = 100;
                }

                numero_dias = ((mes_saida[apartamento] - 1)*30  +  dia_saida[apartamento]) - ((mes_entrada[apartamento] - 1)*30 + dia_entrada[apartamento]);
                valor_total = (valor_diaria * numero_dias) + valor_consumo;
                printf("Numero do Apartamento e numero de dias: Apt. %d e %d dias de estadia\n", apartamento, numero_dias);
                printf("O valor total sera: %.d reais", valor_total);
                break;

            case 3:
                printf("Ola cliente, por favor digite o numero do quarto:\n");
                scanf("%d", &apartamento);
                if (ocupado[apartamento] == 0){
                    printf("Quarto vazio, nao ha o que alterar.\t\n");
                break;
                }


                printf("Oi %s, seu tipo de quarto: %d\n", nome_hospede[apartamento], tipo_quarto[apartamento]);
                printf("Dia de entrada e mes: %.d/%.d\n", dia_entrada[apartamento], mes_entrada[apartamento]);
                printf("Dia de saida e mes: %.d/%.d\n", dia_saida[apartamento], mes_saida[apartamento]);



                printf("\tDigite as novas informacoes\n");



                printf("Digite o tipo de quarto desejado (1 para solteiro ou 2 para casal): \n");
                printf("Caso nao seja interesse do cliente mudar, favor digitar o atual tipo de quarto: \n");
                scanf("%d", &tipo_quarto[apartamento]);

                printf("Digite o dia e mes de entrada e o dia e mes de saida: \n");

                printf("Por exemplo 03(dia) (04) mes 15(dia de saida) 04(mes de saida) \n");
                scanf("%d", &dia_entrada[apartamento]);
                scanf("%d", &mes_entrada[apartamento]);
                scanf( "%d", &dia_saida[apartamento]);
                scanf("%d", &mes_saida[apartamento]);

                printf("Deseja consumir a taxa do frigobar? 1 para Nao, 2 para Sim \n");
                scanf("%d", &consumo_frigobar[apartamento]);

                printf("Cadastro completo.\n");


                break;


            case 0:
                return 0;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while (menu);
}
