#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main(){

	setlocale(LC_ALL,"portuguese");
	system("color f5");

	int rodada=0;

	do{

		int vetor, chances=6 , venceu=0, L=0, cont ;
		char palavraSorteada [10], lacuna[10]=" ", letrasUsadas[10], letra, dica [11];

		char banco[10][10]={"cadeira",
							"mesa",
							"mouse",
							"monitor",
							"teclado",
							"cachorro",
							"gato",
							"cavalo",
							"vaca",
							"porco"
		};
		char categoria[20][20]={"escritório",
								"escritório",
								"escritório",
								"escritório",
								"escritório",
								"animal",
								"animal",
								"animal",
								"animal",
								"animal"
		};


		srand(time(NULL));
		vetor = rand() % 10;								//vetor recebe número aleatório, o mode resultante da divisão das horas do relógio

		for(int m=0; m<10; m++){
			palavraSorteada[m] = banco [vetor][m];			//palavraSorteada recebe o número aleatório como uma localização de colunas na matriz banco.
		}

		for(int i=0; i<11; i++){
			dica[i] = categoria [vetor][i];					//dica recebe o número aleatório como uma localização de colunas na matriz categoria.
		}

		for(cont=0; cont<strlen(palavraSorteada);cont++){				//troca por traços as letras da palavra sorteada na etapa anterior. Adiona o resultado na varável lacuna
			if(palavraSorteada[cont] != ' '){lacuna[cont]='__';}
			else{lacuna[cont]=' ';}
		}


		while(chances>0 && venceu ==0){						//repete o processo enquanto houver chances ou  não houver vitória
			system("cls");
			printf("\n\n\t\t\t\t\t=================================\n\t\t\t\t\t||--------Jogo da Forca--------||\n\t\t\t\t\t=================================\n\n\n");
			printf("\t\t\t\t\tQuantidade de letras: %d\n", strlen(palavraSorteada));
			printf("\t\t\t\t\tDica: %s\n\n", dica);
			printf("\t\t\t\t\tChances restantes: %d\n\n", chances);


			switch (chances)
			{
				case 0:
					printf("\t\t\t\t\t__________\n");
					printf("\t\t\t\t\t|        |\n");
					printf("\t\t\t\t\t|        0\n");
					printf("\t\t\t\t\t|       /|\\\n");
					printf("\t\t\t\t\t|        | \n");
					printf("\t\t\t\t\t|       / \\\n\n");
					break;
				case 1:
					printf("\t\t\t\t\t__________\n");
					printf("\t\t\t\t\t|         |\n");
					printf("\t\t\t\t\t|         0\n");
					printf("\t\t\t\t\t|        /|\\\n");
					printf("\t\t\t\t\t|         | \n");
					printf("\t\t\t\t\t|          \\\n\n");
					break;
				case 2:
						printf("\t\t\t\t\t__________\n");
					printf("\t\t\t\t\t|         |\n");
					printf("\t\t\t\t\t|         0\n");
					printf("\t\t\t\t\t|        /|\\\n");
					printf("\t\t\t\t\t|         | \n");
					printf("\t\t\t\t\t|            \n\n");

					break;
				case 3:
					printf("\t\t\t\t\t__________\n");
					printf("\t\t\t\t\t|         |\n");
					printf("\t\t\t\t\t|         0\n");
					printf("\t\t\t\t\t|         |\\\n");
					printf("\t\t\t\t\t|         | \n");
					printf("\t\t\t\t\t|           \n\n");

					break;
				case 4:
					printf("\t\t\t\t\t__________\n");
					printf("\t\t\t\t\t|         |\n");
					printf("\t\t\t\t\t|         0\n");
					printf("\t\t\t\t\t|         | \n");
					printf("\t\t\t\t\t|         | \n");
					printf("\t\t\t\t\t|           \n\n");

					break;
				case 5:
					printf("\t\t\t\t\t__________\n");
					printf("\t\t\t\t\t|         |\n");
					printf("\t\t\t\t\t|         0\n");
					printf("\t\t\t\t\t|            \n");
					printf("\t\t\t\t\t|           \n");
					printf("\t\t\t\t\t|            \n\n");

					break;
				case 6:
					printf("\t\t\t\t\t__________\n");
					printf("\t\t\t\t\t|         |\n");
					printf("\t\t\t\t\t|          \n");
					printf("\t\t\t\t\t|            \n");
					printf("\t\t\t\t\t|           \n");
					printf("\t\t\t\t\t|            \n\n");

					break;
			}

			printf("\t\t\t\t\tLetras já usadas:");
			for(int j=0; j<L; j++){
				printf(" %c,", letrasUsadas[j]);
			}

			printf("\n\n \t\t\t\t\t\t%s\n\n", lacuna);
			printf("\t\t\t\t\tDigite um letra: ");
			letra = getch();

			for(int a=0; a<strlen(palavraSorteada); a++){	//compara a letra digitada com as letras da palavra secreta
				if(palavraSorteada[a]==letra){
					lacuna[a]=letra;
					cont++;								//se cont for diferente de 0, marca-se um acerto
				}
			}

			if(cont==0){
				printf("\n\n\t\t\t\t\tVocê errou uma letra!\n");    //em caso de erro diminui o número de chances
				chances--;
				Sleep(1000);
			}

			if(cont>0){
				printf("\n\n\t\t\t\t\tVocê acertou uma letra!\n");
				Sleep(1000);
			}

			if(chances==0)venceu=-1;							 	//no caso de terem acabado as chances, adiciona o valor de -1 a variável para servir de referência para mensagem ao vencedor

			if (strcmp(palavraSorteada, lacuna)==0) venceu=1;		//strcmp compara duas string. Se iguais =0, 1ª<2ª=<0; 1ª>2ª=>0.
			cont=0;													//caso as strings não sejam iguais, cont=0 vai imprimir mensagem erro de letra.

			letrasUsadas[L]=letra;
			L++;
		}

		system("cls");



		if (venceu==1) printf("\n\n\n\n\n\n\t\t\t\t\tParabéns! Você venceu! \n\n");
		if (venceu==1){
		 printf("\t\t\t\t\t      _____________\n");
		 printf("\t\t\t\t\t      |           |\n");
		 printf("\t\t\t\t\t      |           |\n");
         printf("\t\t\t\t\t      |           |\n");
         printf("\t\t\t\t\t       \\         /\n");
         printf("\t\t\t\t\t        \\       /\n");
         printf("\t\t\t\t\t         \\     /\n");
         printf("\t\t\t\t\t          |   |\n");
         printf("\t\t\t\t\t          |   |\n");
         printf("\t\t\t\t\t      ____|___|____\n");
        }

		if (venceu==-1){
		 printf("\n\n\n\n\n\n\t\t\t\t\t\tVocê perdeu!\n\t\t\t\t\tA palavra era: %s\n\n\n", palavraSorteada);
		 printf("\t\t\t\t\t      _..-------.\n");
         printf("\t\t\t\t\t     /           \\\n");
         printf("\t\t\t\t\t     |     __    _\\\n");
         printf("\t\t\t\t\t     |'._ /  \ _/ \\\n");
         printf("\t\t\t\t\t     |  _ \__/.v._/\n");
         printf("\t\t\t\t\t      \( ,~._,,,,-)\n");
         printf("\t\t\t\t\t       `-\\' \`,,j|\n");
         printf("\t\t\t\t\t          \\_,____J\n");
        }

             Sleep(5000);
		system("cls");

		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tDigite!\n\t\t\t\t\t 2 continuar    3 sair\nt\t\t\t\t\t -----------------------\n\t\t\t\t\t\t");
		scanf("%i",&rodada);

	}
	while(rodada==2);

	return 0;
}

void imprimirForca(void)
{
    printf("");
}

