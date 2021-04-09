#include <stdio.h>
#define MAX 10


//Optamos por imaginar que o CRUD seria utilizado pelo recepcionista do HOTEL, e não pelo cliente em si.


struct hospede {
    int dia_entrada, mes_entrada, dia_saida, mes_saida, consumo_frigobar;
    char nome_hospede[20];
};

struct quarto {
    int  ocupado, servico_de_quarto, tipo_quarto;
    struct hospede hospede;
};

struct quarto quarto[MAX]; //variável global

int calculo_dias (int mes_saida, int dia_saida, int mes_entrada, int dia_entrada){
    int numero_dias;
    numero_dias = ((mes_saida - 1)*30  +  dia_saida) - ((mes_entrada - 1)*30 + dia_entrada);

    return numero_dias;
}

int calculo_valor_total (int valor_diaria, int numero_dias, int valor_consumo){

    int valor_total;

    valor_total = (valor_diaria * numero_dias) + valor_consumo;

    return valor_total;
}

void cadastro (int apartamento){
    printf("Digite o nome do cliente:\n");
    scanf("%s", quarto[apartamento].hospede.nome_hospede);
    fflush(stdin);

    printf("Digite o dia e mes de entrada e o dia e mes de saida no formato abaixo:\n");

    printf("Dia de entrada:Ex(03)\n");
    printf("Mes de entrada:Ex(02)\n");
    printf("Dia de saida:(07)\n");
    printf("Mes de saida:(02)\n");
    scanf("%d", &quarto[apartamento].hospede.dia_entrada);
    scanf("%d", &quarto[apartamento].hospede.mes_entrada);
    scanf( "%d", &quarto[apartamento].hospede.dia_saida);
    scanf("%d", &quarto[apartamento].hospede.mes_saida);

    printf("Deseja consumir a taxa do frigobar? 1 para Nao, 2 para Sim \n");
    scanf("%d", &quarto[apartamento].hospede.consumo_frigobar);

    printf("O numero do quarto de %s e %d\n", quarto[apartamento].hospede.nome_hospede, apartamento+1);
    printf("\nCadastro completo.\n");
}

void consulta (int apartamento){
    printf("hospede: %s, / Tipo de quarto: %d\n", quarto[apartamento].hospede.nome_hospede, quarto[apartamento].tipo_quarto);
    printf("Dia de entrada e mes: %.d/%.d\n", quarto[apartamento].hospede.dia_entrada, quarto[apartamento].hospede.mes_entrada);
    printf("Dia de saida e mes: %.d/%.d\n", quarto[apartamento].hospede.dia_saida, quarto[apartamento].hospede.mes_saida);
}

int main()
{
    int menu, numero_dias;
    int valor_diaria, valor_total, valor_consumo, apartamento;
    int s;
    int achou = 0;



    for (int i = 0; i < MAX; i++){
        quarto[i].ocupado = 0;
        quarto[i].servico_de_quarto = 1;

        if (i<MAX/2){ //Dessa forma metade vai ser solteiro o restante pra casal, assim podendo alterar apenas o valor no MAX
            quarto[i].tipo_quarto = 1;

        }
        else {
            quarto[i].tipo_quarto = 2;
        }
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
                printf("Digite o tipo de quarto desejado (1 para solteiro ou 2 para casal): \n");
                scanf("%d", &s);

                for (int i=0; i<MAX; i++){ //Vai procurar um quarto disponível e informar que achou
                    if (quarto[i].tipo_quarto == s && quarto[i].ocupado == 0){
                        apartamento = i;
                        achou = 1;
                        break;
                    }
                }

                if (achou == 0){
                    printf("Todos os quartos desse tipo estao ocupados.");
                }

                if (quarto[apartamento].servico_de_quarto == 0){
                    printf("O quarto desejado nao esta limpo.\n");
                    break;
                }

                cadastro (apartamento);

                quarto[apartamento].ocupado = 1;
                quarto[apartamento].servico_de_quarto = 0;

                break;

            case 2:
                printf("Digite o numero do quarto do cliente:\n");
                scanf("%d", &apartamento);
                apartamento--;

                consulta (apartamento);

                if (quarto[apartamento].hospede.consumo_frigobar == 1) {
                    valor_consumo = 0;
                } else {
                    valor_consumo = 20;
                }

                if (quarto[apartamento].tipo_quarto == 1) {
                    valor_diaria = 50;
                } else {
                    valor_diaria = 100;
                }

                numero_dias = calculo_dias (quarto[apartamento].hospede.mes_saida, quarto[apartamento].hospede.dia_saida, quarto[apartamento].hospede.mes_entrada, quarto[apartamento].hospede.dia_entrada);
                valor_total = calculo_valor_total (valor_diaria, numero_dias, valor_consumo);
                printf("Numero do Apartamento e numero de dias: Apt. %d e %d dias de estadia\n", apartamento+1, numero_dias);
                printf("O valor total sera: %.d reais", valor_total);
                break;

            case 3:
                printf("Digite o numero do quarto do cliente\n");
                scanf("%d", &apartamento);
                apartamento--;

                if (quarto[apartamento].ocupado == 0){
                    printf("Quarto vazio, nao ha o que alterar.\t\n");
                break;
                }


               consulta (apartamento);


                printf("\tDigite as novas informacoes\n");

                cadastro (apartamento);

                break;


            case 4:
                printf("Digite o numero do quarto desejado para limpeza\n");
                scanf("%d", &apartamento);
                apartamento--;

                quarto[apartamento].servico_de_quarto = 1;
                        break;





            case 0:
                return 0;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while (menu);
}
