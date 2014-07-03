#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int i;
	pid_t idProcesso;
	printf("Comecando o programa...\n");
	idProcesso = fork();
	//system("ps");
	switch(idProcesso){
		case -1:
  			printf("Houve erro na execucao");
  			exit(1);
		case 0:
			for(i = 0; i<8; i++){
	  			printf("Sou o processo filho 1 ID: %d\n", getpid());
					idProcesso = fork();	
				sleep(4);
			}
			//system("ps");
		break;
		default:
			for(i=0; i<10; i++){
				printf("Sou o processo pai de ID: %d, IDFilho: %d\n", getpid(),idProcesso);
				idProcesso = fork();
				sleep(5);
			}
			switch(idProcesso){
				case -1:
					  printf("Houve erro na execucao");
					  exit(1);
				case 0:
					for(i=0; i<6; i++){
						printf("Sou o processo filho 2 ID: %d\n", getpid());
						sleep(3);
					}
					//system("ps");
				break;
				default:
					for(i=0; i<8; i++){
						  printf("Sou o processo pai de ID: %d, IDFilho: %d\n", getpid(), idProcesso);
					sleep(4);
					}
				break;
					  }
		break;

	}
}
