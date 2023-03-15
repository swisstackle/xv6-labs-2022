#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#define  NULL 0
int main(int argc, char *argv[]){
	if(argc <  2 || argc > 3) {
		fprintf(2, "Wrong number of arguments\n");
		exit(1);
	}
	char *command =  argv[1];
	char buf[512];
	int rear = 0;
	int lastFront = 0;
	char *prependArg = 0;
	if(argc == 3) {
		prependArg = argv[2];
	}

	while(read(0, &buf[rear], 1)) {
		if(buf[rear] == '\n') {
			// create new fork
			if(fork() == 0){
				int stringlength = rear - lastFront;	
				char** arr = (char**)malloc(2 * sizeof(char*));
				arr[0] = (char*)malloc(strlen(prependArg) * sizeof(char));
				arr[1] = (char*)malloc(stringlength * sizeof(char));
				if(prependArg == 0) {
					arr = &arr[1];
					free(arr[0]);
				} else{
					arr[0] = prependArg;
				}
				for(int i = lastFront; i < rear; i++){
							arr[1][i - lastFront] = buf[i];
				}
				char* finalargs[] = {command, arr[0], arr[1], NULL};
				printf("Executing new command\n");
				exec(command, finalargs);	
				fprintf(2, "Exec failed\n");
			}
			lastFront = rear + 1;
			wait(0);
		}
		rear++;
	}
	exit(0);
	return 0;
}
