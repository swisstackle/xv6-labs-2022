#include "kernel/types.h"
#include "user/user.h"

int receiveAndSend(int wr[2], int lastNumber);

int main() 
{
	int wr[2];
	pipe(wr);
	int values[34] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34, 35};
	int first = fork();
	if(first == 0) {
		if(write(wr[1],values, 34*4) < 136) {
			fprintf(2, "Error writing\n");
			exit(1);
		}
		close(wr[1]);
		exit(0);
	}
  int prime;
  while(read(wr[0], &prime, 4)) {
    printf("prime %d\n", prime);
    wr[0] = receiveAndSend(wr, prime);
    if(prime == 31) {
      break;
    }
  }
  exit(0);
}

int
receiveAndSend(int wr[2], int lastNumber) {
	int newPipe[2];
	pipe(newPipe);
	int sec = fork();
	if(sec == 0) {
		int j;
		int temp = -1;
		while(read(wr[0], &j, 4)) {
			if (j % lastNumber != 0) {
				if(write(newPipe[1], &j, 4) < 0) {
          fprintf(2, "Error writing\n");
				}
			}
		}
    receiveAndSend(newPipe, temp);
    exit(0);
  }

  close(wr[0]);
  close(newPipe[1]);
  return newPipe[0];
}














