# Informações do Trabalho
`CEFET–MG / CAMPUS LEOPOLDINA
CMA02 – LABORATÓRIO DE PROGRAMAÇÃO DE
COMPUTADORES I`

A equipe deverá implementar um sistema de cadastro, consulta e
alteração de elementos, de acordo com o tema e especificação já
apresentados pela equipe na Etapa 1

`O trabalho deverá implementar o conteúdo listado abaixo, no contexto do
tema previamente escolhido:`

-Constantes

-Variáveis

-Operações aritméticas

-Operações lógicas

-Comandos de atribuição

-Comandos de entrada e saída

-Estrutura condicional simples e/ou estrutura condicional composta  
e/ou estrutura condicional de múltipla escolha

-Estrutura de repetição com teste no início e/ou estrutura de repetição  
com teste no fim e/ou estrutura de repetição com variável de controle

-Estruturas de dados homogêneas: vetores numéricos, vetores de  
caracteres.

----------------------------------

Dados apresentados na primeira parte do trabalho:

![alt text](https://images-ext-1.discordapp.net/external/m75NsKRSS2D8Uwe2KK_hrrI5sQpD07Emie3J6jStTKY/https/i.imgur.com/BbODgFx.png)
 
 
 
  O código tem como função mostrar o menu de um hotel, cadastrar clientes, 
permitir alteração no cadastro, consultas e não permitir o uso de um quarto sujo.

  No caso 1, temos o cadastro, que é a parte inicial do código, onde iremos 
cadastrar o cliente. Nele será colocado qual quarto ele vai ficar, dia e mês inicial, e dia e 
mês finais, perguntaremos se será desejado um quarto de solteiro ou casal, e por fim, se 
irá consumir no frigobar. 

  No caso 2, temos a consulta, onde verificaremos todos os dados do cadastro e
nele já calcularemos a diária e o valor total do cliente. Também adicionamos ao código 
quando a funcionabilidade está vazia, não possibilitando a consulta de um quarto vago.

  No caso 3, temos a possibilidade de alteração dos dados de cadastro, 
possibilitando ao cliente trocar os dias de estadia e o consumo do frigobar.
Como última opção utilizável, temos o caso 4, que permite a limpeza do quarto, 
permitindo a limpeza do próprio quarto, ou podendo limpar qualquer outro.
Já no caso 0, o programa se encerra.

  Colocamos em funções algumas partes do código, para que elas possam ser 
chamadas em qualquer momento posteriormente no código, para assim facilitar e deixar 
a função main mais limpa. Como por exemplo o “void cadastro” e “void consulta”, que 
são utilizadas tanto no case 1 e 2, quanto no 3, e como elas não precisam retornar 
nenhum valor, colocamos em void, ao contrário das funções “int calculo_valor_total” e 
“int calculo_dias” que retornam inteiros, fazendo cálculos dos números de dia da 
estadia do cliente e do valor total. Como são funções, podem ser chamadas a qualquer 
momento no código main.

  Como não possuímos conhecimento suficiente para trabalhar com datas, 
utilizamos o seguinte cálculo:
“numero_dias = ((mes_saida - 1)*30 + dia_saida) - ((mes_entrada - 1)*30 + 
dia_entrada)”
Com isso ele consegue calcular os dias certos de estadia, supondo se e somente se todos 
os meses tiverem 30 dias e apenas for calculado 1 ano. 
