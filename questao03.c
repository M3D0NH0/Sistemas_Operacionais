#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
pid_t idProcesso;
printf("Comecando o programa...\n");
idProcesso = fork();
int i;
for(i = 0; i <= 60; i ++){
	switch(idProcesso){
		case -1:
			printf("Houve erro na execucao");
			exit(1);
			case 0:
				printf("Sou o processo IDPai1: %d\n", getpid());
				idProcesso = fork();
				switch(idProcesso){
					case -1:
						printf("Houve erro na execucao");
						exit(1);
					case 0:
						printf("Sou o IDNeto1: %d\n", getpid());					
					break;
					default:
						printf("Sou o processo Pai 1 de ID: %d, IDNeto1: %d\n", getpid(), idProcesso);
					break;
				}	
	
			break;
		
		default:
			printf("Sou o processo IDAvo: %d\n", getpid());
			idProcesso = fork();
			switch(idProcesso){
				case -1:
					printf("Houve erro na execucao");
					exit(1);
					printf("Nasce o Pai 2");
				case 0:
					printf("Sou o IDPai2: %d\n", getpid());	
					printf("");
					idProcesso = fork();
					switch(idProcesso){
						case -1:
							printf("Houve erro na execucao");
							exit(1);
						case 0:
							printf("Sou o IDNeto2: %d\n", getpid());					
						break;
						default:
							printf("Sou o processo Pai 2 de ID: %d, IDNeto2: %d\n", getpid(), idProcesso);
						break;
					}
						
				break;
				default:
					printf("Sou o processo IDAvo de ID: %d, IDPai2: %d\n", getpid(), idProcesso);
				break;
			}
		break;
 	 }
}
kill(getpid(), 0);
printf("Pai esta Morto: %d \n", getpid());
}
