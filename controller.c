#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int key = 1234; // #bestkeyever
int descriptor = -1;
void flag_c(int argc,char ** argv){//creates a semaphore
	if(argc < 2){
		printf("not enough arguments\n");
	}
	int i;
	for(i = 0; argv[2][i];i++){
		if(!isdigit(argv[2][i])){
			printf("%s is not a number\n",argv[2]);
			return;
		}
	}
	if(descriptor == -1){
		descriptor = semget(key,1,IPC_CREAT);
		semctl(descriptor,0,SETVAL,atoi(argv[2]));
		printf("semaphore created: %d\n",descriptor);
	}
	else{
		printf("semaphore is already created\n");
		return;
	}
}
void flag_v(){//views a semaphore
	if(descriptor == -1){
		printf("semaphore is not created yet\n");
		return;
	}
	else{
		printf("semaphore value: %d",semctl(descriptor,0,GETVAL));
	}
}
void flag_r(){//removes a semaphore
	if(descriptor == -1){
		printf("no semaphore to remove\n");
		return;
	}
	else{
		if(semctl(descriptor,0,IPC_RMID) == 0){
			printf("semaphore removed\n");
			return;
		}
		else{
			printf("error removing semaphore\n");
		}
	}
}

int main(int argc, char ** argv){
	if(argc <= 1){
		printf("usage:\n-c <N>\n    creates a semaphore and sets its value to N\n\n-v\n    view the current value of the semaphore\n\n-r\n    removes the semaphore\n");
		return 0;
	}
	if(!strcmp(argv[1],"-c")){
		flag_c(argc,argv);
	}
	else if(!strcmp(argv[1],"-v")){
		flag_v();
	}
	else if(!strcmp(argv[1],"-r")){
		flag_r();
	}
	else{
		printf("unknown flag: %s\n",argv[1]);
	}
	return 0;
}
