#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
	if(argc <= 1 || argc > 2){
		fprintf(2, "usage: grep pattern [file ...]\n");
		exit(1);
	}
	int ticks = atoi(argv[1]);
	
	sleep(ticks);
	
	exit(0);
}
