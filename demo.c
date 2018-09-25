#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ufrn_al5d.h"

//Posicao inicial para todos os servos
#define HOME_POS "#0P1500T1000#1P1200T1000#2P1500T1000#3P2500T1000#4P1500T1000"
#define PI 3.14159265358979

void calcular(int posicao_base,int posicao_ombro,int posicao_cotovelo,int posicao_punho,int posicao_garra);

int main()
{
	ufrn_header();

	int serial_fd;
	char *comando;

	// INICIO DO PROGRAMA DEMO //

	printf("PROGRAMA DEMONSTRACAO INICIADO\n\n");

	serial_fd = abrir_porta();

	if(serial_fd == -1)
	{
		printf("Erro abrindo a porta serial /dev/ttyS0\nAbortando o programa...");
		return -1;
	}
	else
	{
		printf("Porta serial /dev/ttyS0 aberta com sucesso\n");

		if(configurar_porta(serial_fd) == -1)
		{
		    printf("Erro inicializando a porta\n");
		    close(serial_fd);
		    return -1;
		}

		comando = (char*) malloc(sizeof(char)*BUFSIZE);

		//////////////////////
		// PRIMEIRO COMANDO //
		//////////////////////

//
		printf("\nPRIMEIRO COMANDO - POSICAL INICIAL\n");

		sprintf(comando,"%s",HOME_POS);

		//Escrevendo com teste de escrita
		if(enviar_comando(comando,serial_fd)!=-1)
		{
			printf("Enviando de comando com teste de envio: %s\n",HOME_POS);
		}
		else
		{
			printf("Problema no envio do comando\nAbortando o programa...");
			return -1;
		}

		char entrada;
		int posicao_base = 1500;
		int posicao_ombro = 1200;
		int posicao_cotovelo = 1500;
		int posicao_punho = 2500;
		int posicao_garra = 1500;
		scanf("%c", &entrada);

		// servo base > 1500 direita(tecla d)       < 1500 esquerda(tecla a)

		/////////////////////
		// SEGUNDO COMANDO //
		/////////////////////

        printf("options:\n --aperte 'm' para mostrar este menu novamente\n");
        printf("options:\n --aperte 'r' para mover para a posicao inicial\n");
        printf("options:\n --aperte 'd' ou 'a' para mover a base\n");
        printf("options:\n --aperte 'w' ou 's' para mover o ombro\n");
        printf("options:\n --aperte 'i' ou 'k' para mover o cotovelo\n");
        printf("options:\n --aperte 'j' ou 'l' para mover o punho\n");
        printf("options:\n --aperte 'q' para fechar a garra\n");
        printf("options:\n --aperte 'e' para abrir a garra\n");
        printf("options:\n --aperte 'c' para calcular a posicao e os angulos\n");
		while(1){
			printf("digite a tecla: ");
			scanf("%c", &entrada);
			switch(entrada){
				case 'm':
					printf("options:\n --aperte 'm' para mostrar este menu\n");
					printf("options:\n --aperte 'r' para mover para a posicao inicial\n");
					printf("options:\n --aperte 'd' ou 'a' para mover a base\n");
					printf("options:\n --aperte 'w' ou 's' para mover o ombro\n");
					printf("options:\n --aperte 'i' ou 'k' para mover o cotovelo\n");
					printf("options:\n --aperte 'j' ou 'l' para mover o punho\n");
					printf("options:\n --aperte 'q' para fechar a garra\n");
					printf("options:\n --aperte 'e' para abrir a garra\n");
					printf("options:\n --aperte 'c' para calcular a posicao e os angulos\n");
					break;
				case 'r':
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"%s",HOME_POS);
					enviar_comando(comando,serial_fd);
                    posicao_base = 1500;
                    posicao_ombro = 1200;
                    posicao_cotovelo = 1500;
                    posicao_punho = 2500;
                    posicao_garra = 1500;
					break;
				case 'd':
					if(posicao_base+100 <= 2380)
						posicao_base += 100;
					else printf("alcancou o maximo\n");
					printf("\nSEGUNDO COMANDO - MOVER A BASE\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",0, posicao_base);
					enviar_comando(comando,serial_fd);
					break;
				case 'a':
					if(posicao_base-100 >= 500)
						posicao_base -= 100;
					else printf("alcancou o maximo\n");
					printf("\nSEGUNDO COMANDO - MOVER A BASE\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",0, posicao_base);
					enviar_comando(comando,serial_fd);
					break;
				case 'w':
					if(posicao_ombro+50 <= 2000)
						posicao_ombro += 50;
					else printf("alcancou o maximo\n");
					printf("\nSEGUNDO COMANDO - MOVER O OMBRO\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",1, posicao_ombro);
					enviar_comando(comando,serial_fd);
					break;
				case 's':
					if(posicao_ombro-50 >= 1200)
						posicao_ombro -= 50;
					else printf("alcancou o maximo\n");
					printf("\nSEGUNDO COMANDO - MOVER O OMBRO\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",1, posicao_ombro);
					enviar_comando(comando,serial_fd);
					break;
				case 'i':
					if(posicao_cotovelo+100 <= 2100)
						posicao_cotovelo += 100;
					else printf("alcancou o maximo\n");
					printf("\nSEGUNDO COMANDO - MOVER O COTOVELO\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",2, posicao_cotovelo);
					enviar_comando(comando,serial_fd);
					break;
				case 'k':
					if(posicao_cotovelo-100 >= 1100)
						posicao_cotovelo -= 100;
					else printf("alcancou o maximo\n");
					printf("\nTERCEIRO COMANDO - MOVER O COTOVELO\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",2,posicao_cotovelo);
					enviar_comando(comando,serial_fd);
					break;
				case 'j':
					if(posicao_punho+200 <= 2500)
						posicao_punho += 200;
					else printf("alcancou o maximo\n");
					printf("\nSEGUNDO COMANDO - MOVER O PUNHO\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",3, posicao_punho);
					enviar_comando(comando,serial_fd);
					break;
				case 'l':
					if(posicao_punho-200 >= 500)
						posicao_punho -= 200;
					else printf("alcancou o maximo\n");
					printf("\nTERCEIRO COMANDO - MOVER O PUNHO\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",3,posicao_punho);
					enviar_comando(comando,serial_fd);
					break;
				case 'q':
					if(posicao_garra+150 <= 2400)
						posicao_garra += 100;
					else printf("alcancou o maximo\n");
					printf("\nTERCEIRO COMANDO - ABRIR GARRA\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",4,posicao_garra);
					enviar_comando(comando,serial_fd);
					break;
				case 'e':
					if(posicao_garra-150 >= 1500)
						posicao_garra -= 100;
					else printf("alcancou o maximo\n");
					printf("\nTERCEIRO COMANDO - FECHAR A GARRA\n");
					memset(comando, 0, BUFSIZE);
					sprintf(comando,"#%dP%dT1000",4,posicao_garra);
					enviar_comando(comando,serial_fd);
					break;
				case 'c':
					calcular(posicao_base,posicao_ombro,posicao_cotovelo,posicao_punho,posicao_garra);
					break;
				default:
					printf("opcao invalida\n");
					break;
			}
		}
		printf("%s\n",comando);

		// FIM DO PROGRAMA DEMO //
	    fechar_porta(serial_fd);
		printf("\nAcesso a porta serial /dev/ttyS0 finalizado\n");

    }
	printf("\nPROGRAMA DEMONSTRACAO FINALIZADO\n\n");
	return 0;
}

void calcular(int posicao_base,int posicao_ombro,int posicao_cotovelo,int posicao_punho,int posicao_garra){
	float resol_base,resol_ombro,resol_cotovelo,resol_punho;
	float ang_base,ang_ombro,ang_cotovelo,ang_punho;
	float ponto_x, ponto_y, ponto_z;

	//resolução
	resol_base=180.0/(2380-500);
	resol_ombro=90.0/(2000-1200);
	resol_cotovelo=180.0/(2100-1100);
	resol_punho=180.0/(2000);

	//angulo
	ang_base=((posicao_base-500)*resol_base)*PI/180.0;
	ang_ombro=((posicao_ombro-500)*resol_ombro - 78.75)*PI/180.0;
	ang_cotovelo=((posicao_cotovelo-500)*resol_cotovelo - 108)*PI/180.0;
	ang_punho=((posicao_punho-500)*resol_punho)*PI/180.0;

	printf("posicao_cotovelo: %d\n", posicao_cotovelo);

	//pontos
	ponto_x=cos(ang_base)*(7*cos(ang_ombro + ang_cotovelo + ang_punho)+15*cos(ang_ombro)+18*cos(ang_ombro + ang_cotovelo));
	ponto_y=sin(ang_base)*(7*cos(ang_ombro + ang_cotovelo + ang_punho)+15*cos(ang_ombro)+18*cos(ang_ombro + ang_cotovelo));
	ponto_z=7*sin(ang_ombro + ang_cotovelo + ang_punho)+15*sin(ang_ombro)+18*sin(ang_ombro + ang_cotovelo)+3;
	printf("ang_base = %f\nang_ombro = %f\nang_cotovelo = %f\nang_punho = %f\n", ang_base, ang_ombro, ang_cotovelo, ang_punho);
	printf("ponto_x: %f\n ponto_y: %f\n ponto_z: %f\n", ponto_x, ponto_y, ponto_z);
}

