#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	int idProcesso;
	int retorno;
	int retorno2;
        int i;
	int cont = 0;
	printf("\n AVO \n");
	
	idProcesso = fork();
	
	for(i = 0; i <=60; i++){
		if(i>=14){
		switch(idProcesso){
			case -1:
				printf("Erro na execucao");
			break;
			case 0:
				printf("\n-------Pai1 ID: %d", getpid());
				printf("\n Relatorio do sistema \n");
				system("ps");
				if(i >=26){
				
				idProcesso = fork();
				
				
				switch(idProcesso){
					case -1:
						printf("Erro na execucao");
					break;
					case 0:
						printf("\n------Neto1 ID: %d", getpid());
						printf("Relatorio do Sistema");
						system("ps");
						if( i >= 38 ){
						kill(getpid(),9);
						printf("\n-------Neto 1 morreu");
						printf("\n Relatorio do sistema");
						system("ps");
						}
					break;
					default:
						printf("\n-------Pai1 ID: %d", getppid());
						printf("\n Relatorio do Sistema");
						system("ps");
						
						if(i > 30){
						
						switch(idProcesso){
							case -1:
								printf("Erro na execucao");
							break;
							case 0:
								printf("\n------Neto2 ID: %d", getpid());
								printf("Relatorio do sistema");
								system("ps");
								if(i >= 48){
								kill(getpid(),9);
								printf("\n-------Neto2 morreu");
								printf("\n Relatorio do Sistema");
								system("ps");
								}
							break;
	
							default:
								printf("\n------Pai1 ID: %d", getppid());
							
							break;
						}
						}
						
					break;
					
				}
				}
			if( i > 49 ){
			kill(getpid(), 9);
			printf("\n--------Morreu Pai 1");
			printf("\n Relatorio do Sistema");
			}
			break;
				
			default:
				printf("\n------Sou o avo de ID: %d", getppid());
				printf("Relatorio do sistema\n");
				system("ps");
				if(i >= 16){
				idProcesso = fork();
				
					switch(idProcesso){
					case -1:
						printf("Erro na execucao");
					break;
					case 0:
						printf("\n-------Pai2 criado: ID: %d", getpid());
						printf("Relatorio do sistema");
						system("ps");
					
						if(i>=46){
						kill(getpid(),9);
						printf("\n------Morreu o pai 2");
						printf("\n Relatorio do Sistema");
						system("ps");
						}
					break;
					
					default:
						printf("\n-------Avo ID: %d", getppid());
					break;
				}
				}
			if( i > 60 ){
			kill(getpid(), 9);
			printf("\n-----Morreu o avo");
			printf("Relatorio do sistema");
			system("ps");
			}
			break;
		}
		}
		sleep(1);
	}
}		
