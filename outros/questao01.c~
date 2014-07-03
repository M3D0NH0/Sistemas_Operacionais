#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t idProcesso;	
	printf("Comecando o programa...\n");
	idProcesso = fork();
	switch(idProcesso){
		case -1:
  			printf("Houve erro na execucao");
  			exit(1);
		case 0:
  			printf("Sou o processo pai 1 ID: %d\n", getpid());
				idProcesso = fork();
				switch(idProcesso){
					case -1:
					  printf("Houve erro na execucao");
					  exit(1);
					case 0:
					  printf("Sou o processo filho 1 ID: %d\n", getpid());
					  break;
					default:
					  printf("Sou o processo pai 1 de ID: %d, IDAvo: %d e IDFilho: %d\n", getpid(), getppid(), idProcesso);
					  break;
					  }
  		break;
		default:
			printf("Sou o processo avo de ID: %d, IDAvo: %d e IDFilho 1.: %d\n", getpid(), getppid(), idProcesso);
			idProcesso = fork();
			switch(idProcesso){		
				case -1:
  					printf("Houve erro na execucao");
				 	exit(1);
				case 0:
				 	 printf("Sou o processo pai 2 ID: %d\n", getpid());
						idProcesso = fork();
						switch(idProcesso){
							case -1:
							  printf("Houve erro na execucao");
							  exit(1);
							case 0:
							  printf("Sou o processo filho 2 ID: %d\n", getpid());
							  break;
							default:
							  printf("Sou o processo pai 2 de ID: %d, IDAvo: %d e IDFilho: %d\n", getpid(), getppid(), idProcesso);
							  break;
						}
		break;
		default:
			printf("Sou o processo avo de ID: %d, IDAvo: %d e IDFilho 2: %d\n", getpid(), getppid(), idProcesso);
		break;  
		}
break;
}		
		exit(0);
}
