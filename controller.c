#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main(int argc, char ** argv){
	if(argc <= 1){
		printf("usage:\n-c N\n    creates a semaphore and sets its value to N\n\n-v\n    view the current value of the semaphore\n\n-r\n    removes the semaphore\n");
		return 0;
	}
}
