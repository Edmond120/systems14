#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

void flag_c(int argc,char ** argv){

}
void flag_v(int argc,char ** argv){

}
void flag_r(int argc,char ** argv){

}

int main(int argc, char ** argv){
	if(argc <= 1){
		printf("usage:\n-c N\n    creates a semaphore and sets its value to N\n\n-v\n    view the current value of the semaphore\n\n-r\n    removes the semaphore\n");
		return 0;
	}
	if(!strcmp(argv[1],"-c")){
		flag_c(argc,argv);
	}
	else if(!strcmp(argv[1],"-v")){
		flag_v(argc,argv);
	}
	else if(!strcmp(argv[1],"-r")){
		flag_r(argc,argv);
	}
	else{
		printf("unknown flag: %s\n",argc[1]);
	}
	return 0;
}
