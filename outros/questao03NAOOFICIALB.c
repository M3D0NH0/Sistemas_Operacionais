#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
pid_t idProcesso;
printf("Comecando o programa...\n");
idProcesso = fork();
int i;
for(i = 1; i <= 60; i++){
switch(idProcesso){
        case -1:
            printf("Houve erro na execucao");
            exit(1);
        case 0:
	        if(i == 14){
			idProcesso = fork();
			printf("O Avo teve um Pai1 com 14 Anos : %d\n",getpid());
	        	printf("E um milagre, tive um pai1 : %d\n", idProcesso);
	        }
		if(i == 44){
			printf("Chorem, Pai1 morreu : %d\n", getpid());
			kill(getpid(),9);
	        }
		switch(idProcesso){
			case -1:
				printf("Houve erro na execucao");
				exit(1);
			case 0:		
				if(i == 26){
					idProcesso = fork();
					printf("O Pai1 teve um Neto1 com 12 Anos : %d\n",getpid());
			            	printf("Pai1 deu a luz ao neto1 : %d \n", idProcesso);
			        }
				if(i == 38){
					printf("Morreu o neto1 : %d\n", getpid());
					kill(getpid(),9);
			        }
			break;
			default:
			break;
		}
	break;
	default:
		switch(idProcesso){
			case -1:
				printf("Houve erro na execucao");
				exit(1);
			case 0:
			        if(i == 16){
					idProcesso = fork();
					printf("O Avo teve um Pai2 com 16 Anos : %d\n",getpid());
				            printf("E um milagre, tive um pai2 : %d\n", idProcesso);
			        }
				if(i == 46){
					printf("Chorem, pai2 morreu : %d \n", getpid());
					kill(getpid(),9);
				}
				 switch(idProcesso){
					case -1:
						printf("Houve erro na execucao");
						exit(1);
					case 0:
						if(i == 30){
							idProcesso = fork();
							printf("O Pai2 teve um Neto2 com 14 Anos : %d\n",getpid());
	          					printf("Pai2 deu a luz ao neto2 : %d \n", idProcesso);  
					        }
						if(i == 48){
							printf("Morreu o neto2 : %d \n", getpid());
							kill(getpid(),9);
					        } 
					break;
					default:
					break;
				}
			break;
			default:
				if(i == 60){
					printf("Morre o Avo : %d\n", getpid());
					kill(getpid(),9);
				}
			break;
		}
	break;
}
}
}
