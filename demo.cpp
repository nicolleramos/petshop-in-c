#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

 

int abril[] = {0, 0, 0, 0, 0, 0, 1, 

               2, 3, 4, 5, 6, 7, 8, 

               9, 10, 11, 12, 13, 14, 15, 

               16, 17, 18, 19, 20, 21, 22, 

               23, 24, 25, 26, 27, 28, 29, 

               30, 31, 0, 0, 0, 0, 0, 0}; 


struct login_acesso{ 

char nome[50]; 

int codigo; 

char senha[10]; 

} funcionario; 

 

struct cliente_pet{ 

char nome_cliente[50];     

char nome_pet[50]; 

char raca[50]; 

long int telefone; 

} cliente; 

 

struct agendar_servicos{ 

float data; 

float hora; 

} servicos; 

 

int main(void){ 

int i; 

int item; 

float preco; 

float total=0; 

 

int escolha=0; 
 
/*
printf("\n----------Login de funcionario----------\n\n\n"); 

printf("Nome......: "); 

fgets(funcionario.nome, 50, stdin); 

fflush(stdin); 

 

printf("Código......: "); 

scanf("%d", &funcionario.codigo); 

fflush(stdin); 

getchar(); 

 

printf("Senha......: "); 

fgets(funcionario.senha, 10, stdin); 

fflush(stdin); 

getchar();  



system("cls"); 

*/

printf("\n-----------Menu Pet's&Pet's-----------\n\n\n"); 

printf("Escolha uma opcao:\n"); 

printf("1 -> Banho Normal\n"); 

printf("2 -> Banho & Tosa\n"); 

printf("3 -> Estoque da Loja\n"); 

printf("4 - Sair do Menu de Servicos\n"); 

 

do { scanf("%d", &escolha); 

fflush(stdin); 

    system("cls"); 

   

switch (escolha) { 

case 1: 

printf("Opcao 1 selecionada.\n"); 

printf("\n-----------BanhoNormal Pet's&Pet's-----------\n\n\n"); 

 

printf("Nome do Cliente......: "); 

scanf("%49s", cliente.nome_cliente); 

fflush(stdout); 

 

printf("Nome do Pet......: "); 

scanf("%49s", cliente.nome_pet); 

fflush(stdin); 

 

printf("Raça......: "); 

scanf("%49s", cliente.raca); 

fflush(stdin); 

 

char porte; 

float valor_banho; 

 

printf("Porte do cachorro (P, M ou G)......: "); 

scanf(" %c", &porte); 

 

if (porte == 'P') { 

    valor_banho = 80.0; 

} else if (porte == 'M') { 

    valor_banho = 100.0; 

} else if (porte == 'G') { 

    valor_banho = 150.0; 

} else { 

    printf("Porte inválido.\n"); 

    return 0; 

} 

 

        printf("Tel......: (55) "); 

        scanf("%ld", &cliente.telefone); 

 

        system("cls"); 

 

        printf("\n-----------BanhoNormal Pet's&Pet's-----------\n\n\n"); 

        printf("Agendar Banho......\n"); 

 

        printf("Calendário de 2023:\n\n"); 

        printf("Dom  Seg  Ter  Qua  Qui  Sex  Sáb\n"); 

        for (int i = 0; i < 6; i++) { 

            for (int j = 0; j < 7; j++) { 

                if (abril[i*7+j] == 0) { 

                    printf("     "); 

                } else { 

                    printf("%-5d", abril[i*7+j]); 

                } 

            } 

            printf("\n"); 

        } 

        printf("\n"); 

 

        printf("Digite a Data disponível para agendar: "); 

        scanf("%f", &servicos.data); 

 

        printf("Digite a Hora disponível para agendar: "); 

        scanf("%f", &servicos.hora); 

 

        system("cls"); 

 

        printf("\n-----------Confirmação de Dados-----------\n\n\n"); 

        printf("Nome do Cliente......: %s\n",cliente.nome_cliente); 

        printf("\nNome do Pet......: %s\n",cliente.nome_pet); 

        printf("Raça......: %s\n",cliente.raca); 

        printf("Tel......: (55) %ld\n",cliente.telefone); 

        printf("Data......: %g\n",servicos.data); 

        printf("Hora......: %0.2f\n",servicos.hora); 

        printf("Tipo de serviço......: Banho Normal\n"); 

        printf("Valor Total á pagar......:R$ %.2f\n", valor_banho); 

 

        char opcao2; 

        do { 

            printf("Deseja continuar? (s/n): "); 

            scanf(" %c", &opcao2); 

        } while (opcao2 != 's' && opcao2 != 'n'); 

 

        if (opcao2 == 's') { 

            printf("Opção selecionada: sim\n"); 

            printf(" volte sempre! :)"); 

            system("cls"); 

        } else { 

            printf("Opção selecionada: não\n"); 

            system("cls"); 

        } 

        break; 

   

case 2: 

printf("Opcao 2 selecionada.\n"); 

printf("\n-----------Banho&Tosa Pet's&Pet's-----------\n\n\n"); 

 

  printf("Nome do Cliente......: "); 

scanf("%49s", cliente.nome_cliente); 

fflush(stdout); 

 

printf("Nome do Pet......: "); 

scanf("%49s", cliente.nome_pet); 

fflush(stdin); 

 

printf("Raça......: "); 

scanf("%49s", cliente.raca); 

fflush(stdin); 

 

char porte2; 

float valor_banho2; 

 

printf("Porte do cachorro (P, M ou G)......: "); 

scanf(" %c", &porte2); 

 

if (porte2 == 'P') { 

    valor_banho2 = 100.0; 

} else if (porte2 == 'M') { 

    valor_banho2 = 150.0; 

} else if (porte2 == 'G') { 

    valor_banho2 = 200.0; 

} else { 

    printf("Porte inválido.\n"); 

    return 0; 

} 

 

        printf("Tel......: (55) "); 

        scanf("%ld", &cliente.telefone); 

 

        system("cls"); 

 

printf("\n-----------Banho&Tosa Pet's&Pet's-----------\n\n\n"); 

 printf("Agendar Banho......\n"); 

 

        printf("Calendário de 2023:\n\n"); 

        printf("Dom  Seg  Ter  Qua  Qui  Sex  Sáb\n"); 

        for (int i = 0; i < 6; i++) { 

            for (int j = 0; j < 7; j++) { 

                if (abril[i*7+j] == 0) { 

                    printf("     "); 

                } else { 

                    printf("%-5d", abril[i*7+j]); 

                } 

            } 

            printf("\n"); 

        } 

        printf("\n"); 

 

        printf("Digite a Data disponível para agendar: "); 

        scanf("%f", &servicos.data); 

 

        printf("Digite a Hora disponível para agendar: "); 

        scanf("%f", &servicos.hora); 

 

        system("cls"); 

 

        printf("\n-----------Confirmação de Dados-----------\n\n\n"); 

        printf("Nome do Cliente......: %s\n",cliente.nome_cliente); 

        printf("\nNome do Pet......: %s\n",cliente.nome_pet); 

        printf("Raça......: %s\n",cliente.raca); 

        printf("Tel......: (55) %ld\n",cliente.telefone); 

        printf("Data......: %g\n",servicos.data); 

        printf("Hora......: %0.2f\n",servicos.hora); 

        printf("Tipo de serviço......: Banho&Tosa\n"); 

        printf("Valor Total á pagar......:R$ %.2f\n", valor_banho2); 

 

        char opcao; 

        do { 

            printf("Deseja continuar? (s/n): "); 

            scanf(" %c", &opcao); 

        } while (opcao != 's' && opcao != 'n'); 

 

        if (opcao == 's') { 

            printf("Opção selecionada: sim\n"); 

            printf(" volte sempre! :)"); 

            system("cls"); 

        } else { 

            printf("Opção selecionada: não\n"); 

            system("cls"); 

        } 

        break; 

   

   

case 3: 

   

printf("\n-----------Loja Pet's&Pet's-----------\n\n\n"); 

printf("Digite o número do item que você deseja comprar......:\n"); 

printf("1 - Roupas\n"); 

printf("2 - Brinquedos\n"); 

printf("3 - Utensílios básicos para seu pet\n"); 

printf("4 - Tapetes higiênicos para animais\n"); 

scanf("%d", &item); 

 

   switch(item) { 

      case 1: 

         preco = 50.0; 

         break; 

      case 2: 

         preco = 20.0; 

         break; 

      case 3: 

         preco = 30.0; 

         break; 

      case 4: 

         preco = 10.0; 

         break; 

      default: 

         printf("Item inválido.\n"); 

         return 0; 

   } 

 

printf("O preço do item %d é R$%.2f.\n", item, preco); 

printf("Valor total da compra: R$%.2f\n", preco); 

               

break; 

case 4: 

               

    for(i=0; i<5; i++) { 

        printf("Saindo0…."); 

        Sleep(1000);  

        printf("Saindo.0…"); 

        Sleep(100);   

        printf("Saindo..0…"); 

        Sleep(1000); 

        printf("Saindo…0..\r"); 

       Sleep(100);    

       printf("Saindo….0.\r"); 

       Sleep(100); 

       printf("Saindo....0\r"); 

        fflush(stdout);   

    } 

printf("Tchau!\n"); 

break; 

    } 

   

        } while (escolha != 4); 

 

    return 0; 

} 

 
