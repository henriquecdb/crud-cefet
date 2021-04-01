#include <stdlib.h>
#include <stdio.h>
#define MAX 10


//Optamos por imaginar que o CRUD seria utilizado pelo recepcionista do HOTEL, e não pelo cliente em si.

int main()
{
    int menu, numero_dias, apartamento, tipo_quarto[MAX];
    int valor_diaria, valor_total, consumo_frigobar[MAX], dia_entrada[MAX], mes_entrada[MAX], dia_saida[MAX], mes_saida[MAX], valor_consumo, ocupado[MAX], servico_de_quarto[MAX];
    char nome_hospede[MAX][20];

    for (int i = 0; i < MAX; i++){
        ocupado[i] = 0;
    }

    for (int i = 0; i < MAX; i++) {
        servico_de_quarto[i] = 1;
    }

    do
    {
        printf("\n\tHotel de Transito - CEFET/MG\n\n");
        printf("1. Cadastro\n");
        printf("2. Consulta\n");
        printf("3. Alteracao\n");
        printf("4. Limpeza do Quarto\n");
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
                if (servico_de_quarto[apartamento] == 0){
                    printf("O quarto desejado nao esta limpo.\n");
                    break;
                }

                printf("Digite o nome do cliente:\n");
                scanf("%s", nome_hospede[apartamento]);
                fflush(stdin);

                printf("Digite o tipo de quarto desejado (1 para solteiro ou 2 para casal): \n");
                scanf("%d", &tipo_quarto[apartamento]);

                printf("Digite o dia e mes de entrada e o dia e mes de saida no formato abaixo:\n");

                printf("Dia de entrada:Ex(03)\n");
                printf("Mes de entrada:Ex(02)\n");
                printf("Dia de saida:(07)\n");
                printf("Mes de saida:(02)\n");
                scanf("%d", &dia_entrada[apartamento]);
                scanf("%d", &mes_entrada[apartamento]);
                scanf( "%d", &dia_saida[apartamento]);
                scanf("%d", &mes_saida[apartamento]);

                printf("Deseja consumir a taxa do frigobar? 1 para Nao, 2 para Sim \n");
                scanf("%d", &consumo_frigobar[apartamento]);


                printf("Cadastro completo.\n");

                ocupado[apartamento] = 1;
                servico_de_quarto[apartamento] = 0;
                break;

            case 2:
                printf("Digite o numero do quarto do cliente:\n");
                scanf("%d", &apartamento);


                printf("hospede: %s, / Tipo de quarto: %d\n", nome_hospede[apartamento], tipo_quarto[apartamento]);
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
                printf("Digite o numero do quarto do cliente\n");
                scanf("%d", &apartamento);

                if (ocupado[apartamento] == 0){
                    printf("Quarto vazio, nao ha o que alterar.\t\n");
                break;
                }


                printf("Hospede: %s, / Tipo de quarto: %d\n", nome_hospede[apartamento], tipo_quarto[apartamento]);
                printf("Dia de entrada e mes: %.d/%.d\n", dia_entrada[apartamento], mes_entrada[apartamento]);
                printf("Dia de saida e mes: %.d/%.d\n", dia_saida[apartamento], mes_saida[apartamento]);



                printf("\tDigite as novas informacoes\n");



                printf("Digite o tipo de quarto desejado (1 para solteiro ou 2 para casal): \n");
                printf("Caso nao seja interesse do cliente mudar, favor digitar o atual tipo de quarto: \n");
                scanf("%d", &tipo_quarto[apartamento]);

                printf("Digite o dia e mes de entrada e o dia e mes de saida no formato abaixo:\n");

                printf("Dia de entrada:Ex(03)\n");
                printf("Mes de entrada:Ex(02)\n");
                printf("Dia de saida:(07)\n");
                printf("Mes de saida:(02)\n");
                scanf("%d", &dia_entrada[apartamento]);
                scanf("%d", &mes_entrada[apartamento]);
                scanf( "%d", &dia_saida[apartamento]);
                scanf("%d", &mes_saida[apartamento]);

                printf("Deseja consumir a taxa do frigobar? 1 para Nao, 2 para Sim \n");
                scanf("%d", &consumo_frigobar[apartamento]);

                printf("Cadastro completo.\n");


                break;


            case 4:
                printf("Digite o numero do quarto desejado para limpeza\n");
                scanf("%d", &apartamento);

                servico_de_quarto[apartamento]= 1;
                        break;





            case 0:
                return 0;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while (menu);
}
