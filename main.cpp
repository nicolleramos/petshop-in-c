#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

/* by Nicolle Ramos - Pet's & Pet's
Sistema de cadastro para Banho & Tosa de pet + loja
*/

typedef struct {
	char nome[50];
	char tel[20];
	char end[100];
} Cliente;

typedef struct {
	char nome[50];
} Pet;

typedef struct {
	int id;
	char nome[50];
	float preco;
} Produto;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen() {
	printf("\033[2J\033[1;1H");
}

int menuExibido = 0;

void entrarMenu() {

	int coluna, linha;
	int larguraJanela = 80;
	int comprimentoImagem = 25;
	coluna = (larguraJanela - comprimentoImagem) / 2;
	linha = 8;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD coresPadrao = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

	gotoxy(coluna, linha);
	printf("   |\\_/|\n");
	gotoxy(coluna, linha+1);
	printf("   | @ @   Woof!\n");
	gotoxy(coluna, linha+2);
	printf("   |   <>              _\n");
	gotoxy(coluna, linha+3);
	printf("   |  _/\\------____ ((| |))\n");
	gotoxy(coluna, linha+4);
	printf("   |               `--' |\n");
	gotoxy(coluna, linha+5);
	printf("___|_       ___|   |___.'\n");
	gotoxy(coluna, linha+6);
	printf("/_/_____/____/_______|\n\n");

	gotoxy(coluna, linha+8);
	printf("BEM-VINDO(A) A CLAW & PAW PETSHOP\n");
	gotoxy(coluna, linha+9);
	system("pause");
	clearScreen();

	SetConsoleTextAttribute(hConsole, coresPadrao);

	menuExibido = 1;
}


void agendarBanho(Cliente* clientes, Pet* cachorro) {

	int escolha=1;
	int porte;
	float ValorTotal;
	int dia, mes, ano;
	char barra1, barra2;
	int dataValida = 0;
	int horario;
	int formaPagamento;
	char confirmacao;

	time_t tempoAtual = time(NULL);
	struct tm *dataAtual = localtime(&tempoAtual);
	int diaAtual = dataAtual->tm_mday;
	int mesAtual = dataAtual->tm_mon + 1;
	int anoAtual = dataAtual->tm_year + 1900;

	do {

		clearScreen();
		printf("1. AGENDAR BANHO\n");
		printf("==========================\n");
		printf("Escolha o tipo de banho:\n");
		printf("[1] Banho Regular \n");
		printf("[2] Banho Hidratante\n");
		printf("[3] Banho Antiparasitas\n");
		printf("[0] Voltar \n");
		printf("==========================\n");
		printf("digite a opção:");
		scanf("%d", &escolha);

		switch(escolha) {

			case 1:

				clearScreen();
				printf("2. FICHA DO PET(Banho Regular)\n");
				printf("Digite o seu nome(dono do PET!): ");
				scanf(" %[^\n]", clientes->nome);
				printf("Digite o seu endereço: ");
				scanf(" %[^\n]", clientes->end);
				getchar();
				printf("Digite o seu telefone de contato: ");
				scanf(" %[^\n]", clientes->tel);
				getchar();

				printf("Digite o nome do seu PET!: ");
				scanf(" %[^\n]", cachorro->nome);
				getchar();

				do {

					printf("Porte do seu PET: [1] Pequeno [2] Médio [3] Grande \nopçao:");
					scanf("%d", &porte);

					if(porte==1) {
						ValorTotal=80.00;
					}

					else if(porte==2) {
						ValorTotal=150.00;
					}

					else if(porte==3) {
						ValorTotal=250.00;
					}

					else {
						printf("\033[31mDigite uma opção válida!\033[0m\n");
						Sleep(1000);
					}

				} while (porte != 1 && porte != 2 && porte != 3);

				printf("\033[32mSalvo com sucesso!\033[0m\n");
				Sleep(2000);

				clearScreen();
				printf("3. FORMA DE PAGAMENTO\n");
				do {
					printf("Data(formato dd/mm/aaaa):");
					scanf("%d%c%d%c%d", &dia, &barra1, &mes, &barra2, &ano);
					if (barra1 == '/' && barra2 == '/') {
						if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0 && ano <= 9999) {
							if (ano > anoAtual || (ano == anoAtual && mes > mesAtual) || (ano == anoAtual && mes == mesAtual && dia >= diaAtual)) {
								if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
									printf("\033[31mDia inválido para o mês informado. Tente novamente!\033[0m\n");
									Sleep(1000);
								} else if (mes == 2) {
									int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
									if ((bissexto && dia > 29) || (!bissexto && dia > 28)) {
										printf("\033[31mDia inválido para o mês e ano informados. Tente novamente!\033[0m\n");
										Sleep(1000);
									} else {
										dataValida = 1;
									}
								} else {
									dataValida = 1;
								}
							} else {
								printf("\033[31mDigite uma data válida!\033[0m\n");
								Sleep(1000);
							}
						} else {
							printf("\033[31mDigite uma data válida!\033[0m\n");
							Sleep(1000);
						}
					} else {
						printf("\033[31mFormato de data inválido! Tente novamente\033[0m\n");
						Sleep(1000);
					}
				} while (!dataValida);

				do {
					printf("Horários disponíveis: [1] às 1h [2] às 2h [3] às 3h [4] às 4h  \nopção:");
					scanf("%d", &horario);

					if(horario==1) {
						continue;
					}
					if(horario==2) {
						continue;
					}
					if(horario==3) {
						continue;
					}
					if(horario==4) {
						continue;
					} else if(horario != 1 && horario != 2 && horario != 3 && horario != 4) {
						continue;
					}
				} while(horario != 1 && horario != 2 && horario != 3 && horario != 4);

				do {
					printf("Forma de pagamento: [1] dinheiro [2] crédito [3] débito [4] pix  \nopção:");
					scanf("%d", &formaPagamento);

					if (formaPagamento >= 1 && formaPagamento <= 4) {
						printf("\033[32mSalvo com sucesso!\033[0m\n");
						Sleep(2000);
						break;
					} else {
						printf("\033[31mDigite uma opção válida!\033[0m\n");
					}
				} while (1);

				clearScreen();
				printf("4. INFORMAÇÕES DO BANHO!\n");
				printf("Nome do Cliente : %s\n", clientes->nome);
				printf("Nome do Pet : %s\n", cachorro->nome);
				printf("Endereço : %s\n", clientes->end);
				printf("Telefone de Contato: %s\n", clientes->tel);
				printf("Tipo de Banho: Banho Regular | Valor: R$ %.2f\n", ValorTotal);
				printf("Marcado para o dia: %02d/%02d/%04d às %02dh.\n\n", dia, mes, ano, horario);
				printf("-> Confirma as seguintes informaçõe? [s/n]:");
				scanf(" %c",&confirmacao);

				if(confirmacao=='s' || confirmacao=='S') {
					printf("\033[38;5;208mObrigado por agendar!! Temos opções de entrega a domicílio \nou retirada na loja, entraremos em contato.\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				} else if(confirmacao=='n' || confirmacao=='N') {
					printf("\033[31mInformações excluídas com sucesso!\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				}

				break;

			case 2:
				clearScreen();
				printf("2. FICHA DO PET(Banho Hidratante)\n");
				printf("Digite o seu nome(dono do PET!): ");
				scanf(" %[^\n]", clientes->nome);
				printf("Digite o seu endereço: ");
				scanf(" %[^\n]", clientes->end);
				getchar();
				printf("Digite o seu telefone de contato: ");
				scanf(" %[^\n]", clientes->tel);
				getchar();
				printf("Digite o nome do seu PET!: ");
				scanf(" %[^\n]", cachorro->nome);
				getchar();

				do {

					printf("Porte do seu PET: [1] Pequeno [2] Médio [3] Grande \nopçao:");
					scanf("%d", &porte);

					if(porte==1) {
						ValorTotal=80.00;
					}

					else if(porte==2) {
						ValorTotal=150.00;
					}

					else if(porte==3) {
						ValorTotal=250.00;
					}

					else {
						printf("\033[31mDigite uma opção válida!\033[0m\n");
						Sleep(1000);
					}

				} while (porte != 1 && porte != 2 && porte != 3);

				printf("\033[32mSalvo com sucesso!\033[0m\n");
				Sleep(2000);

				clearScreen();
				printf("3. FORMA DE PAGAMENTO\n");
				do {
					printf("Data(formato dd/mm/aaaa):");
					scanf("%d%c%d%c%d", &dia, &barra1, &mes, &barra2, &ano);
					if (barra1 == '/' && barra2 == '/') {
						if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0 && ano <= 9999) {
							if (ano > anoAtual || (ano == anoAtual && mes > mesAtual) || (ano == anoAtual && mes == mesAtual && dia >= diaAtual)) {
								if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
									printf("\033[31mDia inválido para o mês informado. Tente novamente!\033[0m\n");
									Sleep(1000);
								} else if (mes == 2) {
									int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
									if ((bissexto && dia > 29) || (!bissexto && dia > 28)) {
										printf("\033[31mDia inválido para o mês e ano informados. Tente novamente!\033[0m\n");
										Sleep(1000);
									} else {
										dataValida = 1;
									}
								} else {
									dataValida = 1;
								}
							} else {
								printf("\033[31mDigite uma data válida!\033[0m\n");
								Sleep(1000);
							}
						} else {
							printf("\033[31mDigite uma data válida!\033[0m\n");
							Sleep(1000);
						}
					} else {
						printf("\033[31mFormato de data inválido! Tente novamente\033[0m\n");
						Sleep(1000);
					}
				} while (!dataValida);

				do {
					printf("Horários disponíveis: [1] às 1h [2] às 2h [3] às 3h [4] às 4h  \nopção:");
					scanf("%d", &horario);

					if(horario==1) {
						continue;
					}
					if(horario==2) {
						continue;
					}
					if(horario==3) {
						continue;
					}
					if(horario==4) {
						continue;
					} else if(horario != 1 && horario != 2 && horario != 3 && horario != 4) {
						continue;
					}
				} while(horario != 1 && horario != 2 && horario != 3 && horario != 4);

				do {
					printf("Forma de pagamento: [1] dinheiro [2] crédito [3] débito [4] pix  \nopção:");
					scanf("%d", &formaPagamento);

					if (formaPagamento >= 1 && formaPagamento <= 4) {
						printf("\033[32mSalvo com sucesso!\033[0m\n");
						Sleep(2000);
						break;
					} else {
						printf("\033[31mDigite uma opção válida!\033[0m\n");
					}
				} while (1);

				clearScreen();
				printf("4. INFORMAÇÕES DO BANHO!\n");
				printf("Nome do Cliente : %s\n", clientes->nome);
				printf("Nome do Pet : %s\n", cachorro->nome);
				printf("Endereço : %s\n", clientes->end);
				printf("Telefone de Contato: %s\n", clientes->tel);
				printf("Tipo de Banho: Banho Hidratante | Valor: R$ %.2f\n", ValorTotal);
				printf("Marcado para o dia: %02d/%02d/%04d às %02dh.\n\n", dia, mes, ano, horario);
				printf("-> Confirma as seguintes informaçõe? [s/n]:");
				scanf(" %c",&confirmacao);

				if(confirmacao=='s' || confirmacao=='S') {
					printf("\033[38;5;208mObrigado por agendar!! Temos opções de entrega a domicílio \nou retirada na loja, entraremos em contato.\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				} else if(confirmacao=='n' || confirmacao=='N') {
					printf("\033[31mInformações excluídas com sucesso!\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				}



				break;

			case 3:

				clearScreen();
				printf("2. FICHA DO PET(Banho Antiparasitas)\n");
				printf("Digite o seu nome(dono do PET!): ");
				scanf(" %[^\n]", clientes->nome);
				printf("Digite o seu endereço: ");
				scanf(" %[^\n]", clientes->end);
				getchar();
				printf("Digite o seu telefone de contato: ");
				scanf(" %[^\n]", clientes->tel);
				getchar();

				printf("Digite o nome do seu PET!: ");
				scanf(" %[^\n]", cachorro->nome);
				getchar();

				do {

					printf("Porte do seu PET: [1] Pequeno [2] Médio [3] Grande \nopçao:");
					scanf("%d", &porte);

					if(porte==1) {
						ValorTotal=80.00;
					}

					else if(porte==2) {
						ValorTotal=150.00;
					}

					else if(porte==3) {
						ValorTotal=250.00;
					}

					else {
						printf("\033[31mDigite uma opção válida!\033[0m\n");
						Sleep(1000);
					}

				} while (porte != 1 && porte != 2 && porte != 3);

				printf("\033[32mSalvo com sucesso!\033[0m\n");
				Sleep(2000);

				clearScreen();
				printf("3. FORMA DE PAGAMENTO\n");
				do {
					printf("Data(formato dd/mm/aaaa):");
					scanf("%d%c%d%c%d", &dia, &barra1, &mes, &barra2, &ano);
					if (barra1 == '/' && barra2 == '/') {
						if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0 && ano <= 9999) {
							if (ano > anoAtual || (ano == anoAtual && mes > mesAtual) || (ano == anoAtual && mes == mesAtual && dia >= diaAtual)) {
								if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
									printf("\033[31mDia inválido para o mês informado. Tente novamente!\033[0m\n");
									Sleep(1000);
								} else if (mes == 2) {
									int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
									if ((bissexto && dia > 29) || (!bissexto && dia > 28)) {
										printf("\033[31mDia inválido para o mês e ano informados. Tente novamente!\033[0m\n");
										Sleep(1000);
									} else {
										dataValida = 1;
									}
								} else {
									dataValida = 1;
								}
							} else {
								printf("\033[31mDigite uma data válida!\033[0m\n");
								Sleep(1000);
							}
						} else {
							printf("\033[31mDigite uma data válida!\033[0m\n");
							Sleep(1000);
						}
					} else {
						printf("\033[31mFormato de data inválido! Tente novamente\033[0m\n");
						Sleep(1000);
					}
				} while (!dataValida);

				do {
					printf("Horários disponíveis: [1] às 1h [2] às 2h [3] às 3h [4] às 4h  \nopção:");
					scanf("%d", &horario);

					if(horario==1) {
						continue;
					}
					if(horario==2) {
						continue;
					}
					if(horario==3) {
						continue;
					}
					if(horario==4) {
						continue;
					} else if(horario != 1 && horario != 2 && horario != 3 && horario != 4) {
						continue;
					}
				} while(horario != 1 && horario != 2 && horario != 3 && horario != 4);

				do {
					printf("Forma de pagamento: [1] dinheiro [2] crédito [3] débito [4] pix  \nopção:");
					scanf("%d", &formaPagamento);

					if (formaPagamento >= 1 && formaPagamento <= 4) {
						printf("\033[32mSalvo com sucesso!\033[0m\n");
						Sleep(2000);
						break;
					} else {
						printf("\033[31mDigite uma opção válida!\033[0m\n");
					}
				} while (1);

				clearScreen();
				printf("4. INFORMAÇÕES DO BANHO!\n");
				printf("Nome do Cliente : %s\n", clientes->nome);
				printf("Nome do Pet : %s\n", cachorro->nome);
				printf("Endereço : %s\n", clientes->end);
				printf("Telefone de Contato: %s\n", clientes->tel);
				printf("Tipo de Banho: Banho Antiparasitas | Valor: R$ %.2f\n", ValorTotal);
				printf("Marcado para o dia: %02d/%02d/%04d às %02dh.\n\n", dia, mes, ano, horario);
				printf("-> Confirma as seguintes informaçõe? [s/n]:");
				scanf(" %c",&confirmacao);

				if(confirmacao=='s' || confirmacao=='S') {
					printf("\033[38;5;208mObrigado por agendar!! Temos opções de entrega a domicílio \nou retirada na loja, entraremos em contato.\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				} else if(confirmacao=='n' || confirmacao=='N') {
					printf("\033[31mInformações excluídas com sucesso!\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				}


			case 0:
				clearScreen();
				return;
				break;

			default:
				printf("\n\033[31mDigite uma opção válida!\033[0m\n\n");

		}

	} while(escolha);

}

void agendarCheckup(Cliente* clientes, Pet* cachorro) {

	int escolha=1;
	int porte;
	float ValorTotal;
	int dia, mes, ano;
	char barra1, barra2;
	int dataValida = 0;
	int horario;
	int formaPagamento;
	char confirmacao;

	time_t tempoAtual = time(NULL);
	struct tm *dataAtual = localtime(&tempoAtual);
	int diaAtual = dataAtual->tm_mday;
	int mesAtual = dataAtual->tm_mon + 1;
	int anoAtual = dataAtual->tm_year + 1900;

	do {
		clearScreen();
		printf("1. CHECK-UP VETERINÁRIO\n");
		printf("==========================\n");
		printf("[1] Agendar consulta\n");
		printf("[2] Sobre\n");
		printf("[0] Voltar \n");
		printf("==========================\n");
		printf("digite a opção:");
		scanf("%d", &escolha);

		switch(escolha) {

			case 1:

				clearScreen();
				printf("2. FICHA DO PET!\n");
				printf("Digite o seu nome(dono do PET!): ");
				scanf(" %[^\n]", clientes->nome);
				printf("Digite o seu endereço: ");
				scanf(" %[^\n]", clientes->end);
				getchar();
				printf("Digite o seu telefone de contato: ");
				scanf(" %[^\n]", clientes->tel);
				getchar();
				printf("Digite o nome do seu PET!: ");
				scanf(" %[^\n]", cachorro->nome);
				getchar();

				do {
					printf("Data(no formato dd/mm/aaaa):");
					scanf("%d%c%d%c%d", &dia, &barra1, &mes, &barra2, &ano);
					if (barra1 == '/' && barra2 == '/') {
						if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0 && ano <= 9999) {
							if (ano > anoAtual || (ano == anoAtual && mes > mesAtual) || (ano == anoAtual && mes == mesAtual && dia >= diaAtual)) {
								if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
									printf("\033[31mDia inválido para o mês informado. Tente novamente!\033[0m\n");
									Sleep(1000);
								} else if (mes == 2) {
									int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
									if ((bissexto && dia > 29) || (!bissexto && dia > 28)) {
										printf("\033[31mDia inválido para o mês e ano informados. Tente novamente!\033[0m\n");
										Sleep(1000);
									} else {
										dataValida = 1;
									}
								} else {
									dataValida = 1;
								}
							} else {
								printf("\033[31mDigite uma data válida!\033[0m\n");
								Sleep(1000);
							}
						} else {
							printf("\033[31mDigite uma data válida!\033[0m\n");
							Sleep(1000);
						}
					} else {
						printf("\033[31mFormato de data inválido! Tente novamente\033[0m\n");
						Sleep(1000);
					}
				} while (!dataValida);

				do {
					printf("Horários disponíveis [1] às 13h [2] às 14h [3] às 15h [4] às 16h\nopção:");
					scanf("%d", &horario);

					if(horario==1) {
						continue;
					}
					if(horario==2) {
						continue;
					}
					if(horario==3) {
						continue;
					}
					if(horario==4) {
						continue;
					}

				} while(horario != 1 && horario != 2 && horario != 3 && horario != 4);

				printf("Forma de pagamento: [1] dinheiro [2] crédito [3] débito [4] pix \nopção:");
				scanf("%d",&formaPagamento);

				printf("\033[32mSalvo com sucesso!\033[0m\n");
				Sleep(2000);

				clearScreen();
				printf("3. INFORMAÇÕES GERAIS:\n");
				printf("Nome do Cliente : %s\n", clientes->nome);
				printf("Nome do Pet : %s\n", cachorro->nome);
				printf("Endereço : %s\n", clientes->end);
				printf("Telefone de Contato: %s\n", clientes->tel);
				printf("Tipo de Consulta: Check-up | Valor: R$ 50,00\n");
				printf("Marcado para o dia: %02d/%02d/%04d às %02dh.\n\n", dia, mes, ano, horario);


				printf("Confirma as seguintes informaçõe? [s/n] ");
				scanf(" %c",&confirmacao);

				if(confirmacao=='s' || confirmacao=='S') {
					printf("\033[38;5;208mObrigado por agendar! Qualquer custo adicional será informado após a consulta, \npedimos gentilmente que não esqueça de levar a carteirinha do seu animalzinho.\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				} else if(confirmacao=='n' || confirmacao=='N') {
					printf("\033[31mInformações apagadas por segurança!\033[0m\n");
					Sleep(8000);
					clearScreen();
					return;
				}

			case 2:

				clearScreen();
				printf("\033[1;34mCHECK-UP VETERINÁRIO:\033[0m\n");
				printf("Por que recomendamos fazer um check-up veterinário? \nÉ importante ressaltar que o check-up do seu bichinho de estimação não é obrigatório. \nNo entanto, conhecer o seu pet nos ajuda a criar e fornecer um banho de qualidade, sem \ncausar danos a ele ou inconveniências para você. O check-up rápido consiste em atender\nas preferências e prioridades do seu bichinho!\n");
				printf("\033[1;34mAperte ENTER para continuar!\033[0m\n");
				getch();
				break;

			case 0:
				clearScreen();
				return;
				break;

			default:
				printf("\n\033[31mDigite uma opção válida!\033[0m\n\n");
		}
	} while(escolha);
}

void lojaPet() {
	Produto produtosSelecionados[10];
	int quantidadeProdutosSelecionados = 0;
	clearScreen();

	Produto produtos[10];

	produtos[0].id = 1;
	strcpy(produtos[0].nome, "Shampoo e Condicionador");
	produtos[0].preco = 25.99;

	produtos[1].id = 2;
	strcpy(produtos[1].nome, "Escova e pente de Banho");
	produtos[1].preco = 12.50;

	produtos[2].id = 3;
	strcpy(produtos[2].nome, "Toalha Absorvente");
	produtos[2].preco = 18.75;

	produtos[3].id = 4;
	strcpy(produtos[3].nome, "Higiene bucal");
	produtos[3].preco = 10.35;

	produtos[4].id = 5;
	strcpy(produtos[4].nome, "Acessórios para secagem");
	produtos[4].preco = 40.89;

	produtos[5].id = 6;
	strcpy(produtos[5].nome, "Lenços umedecidos");
	produtos[5].preco = 6.00;

	produtos[6].id = 7;
	strcpy(produtos[6].nome, "Perfumes e desodorantes");
	produtos[6].preco = 20.99;

	produtos[7].id = 8;
	strcpy(produtos[7].nome, "Brinquedos");
	produtos[7].preco = 7.35;

	produtos[8].id = 9;
	strcpy(produtos[8].nome, "Coleiras, guias e peitorais");
	produtos[8].preco = 20.75;

	produtos[9].id = 10;
	strcpy(produtos[9].nome, "Tábuas de corte de unhas");
	produtos[9].preco = 9.56;

	printf("PRODUTOS PARA O SEU PET!\n");
	for (int i = 0; i < 10; i++) {
		printf("id: %d * %s * preço: R$ %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
	}

	char resposta;
	printf("\nDeseja comprar produtos na nossa loja? [s/n]: ");
	scanf(" %c", &resposta);

	if (resposta == 's' || resposta == 'S') {
		int idProduto;
		char adicionarMais;
		float valorTotal = 0.0;

		do {
			printf("Digite o ID do produto que deseja comprar: ");
			scanf("%d", &idProduto);

			int indexProduto = -1;
			for (int i = 0; i < 10; i++) {
				if (produtos[i].id == idProduto) {
					indexProduto = i;
					break;
				}
			}

			if (indexProduto != -1) {
				valorTotal += produtos[indexProduto].preco;
				produtosSelecionados[quantidadeProdutosSelecionados] = produtos[indexProduto];
				quantidadeProdutosSelecionados++;

				printf("-> Deseja adicionar mais um?? [s/n]: ");
				scanf(" %c", &adicionarMais);
			} else {
				printf("\033[31mID de produto inválido!\033[0m\n");
				adicionarMais = 's';
			}
		} while (adicionarMais == 's' || adicionarMais == 'S');

		printf("\033[38;5;208mSeus produtos foram reservados em nossa loja!\033[0m\n");
		printf("\nSEUS PRODUTOS:\n");
		for (int i = 0; i < quantidadeProdutosSelecionados; i++) {
			printf("id: %d * nome: %s * preço: R$ %.2f\n", produtosSelecionados[i].id, produtosSelecionados[i].nome, produtosSelecionados[i].preco);
		}

		printf("Valor total a pagar: R$ %.2f\n\n", valorTotal);

		int opcao;
		while (1) {
			printf("Deseja pagar em [1] dinheiro [2] crédito [3] débito [4] pix \nopção: ");
			scanf("%d", &opcao);

			if (opcao >= 1 && opcao <= 4) {
				printf("\033[38;5;208mObrigado por comprar, Volte sempre!\033[0m\n");
				Sleep(2000);
				clearScreen();
				break;

			} else {
				printf("\033[31mDigite uma opção de pagamento válida!\033[0m\n");
				Sleep(1000);
			}
		}
	}

	if (resposta == 'n' || resposta == 'N') {
		clearScreen();
	}
}


void sair() {

	printf("\033[38;5;208mObrigado, Volte sempre!\033[0m\n");
	Sleep(2000);
	clearScreen();

}

int main() {

	setlocale(LC_ALL, "portuguese");

	Cliente clientes[5];
	Pet cachorro[5];

	int continuar=1;

	entrarMenu();

	do {

		printf("       PETSHOP MENU \n");
		printf("==========================\n");
		printf("[1] Check-up Veterinário \n");
		printf("[2] Agendar Banho \n");
		printf("[3] Loja: Claw & Paw \n");
		printf("[0] Sair \n");
		printf("========================== \n");
		printf("digite a opção:");
		scanf("%d", &continuar);

		switch(continuar) {

			case 1:
				agendarCheckup(clientes, cachorro);
				break;

			case 2:
				agendarBanho(clientes, cachorro);
				break;

			case 3:
				lojaPet();
				break;

			case 0:
				sair();
				break;

			default:
				printf("\n\033[31mDigite uma opção válida!\033[0m\n\n");
				Sleep(1000);
		}

	} while(continuar);

	return 0;
}
