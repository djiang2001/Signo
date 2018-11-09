#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(SIGINT == signo){
    printf("\n Program exited due to SIGINT \n");
    exit(0);
  }else if(SIGUSR1 == signo){
    printf("\n Parent Process: %d \n", getppid());
  }
}
int main(){

  signal(SIGINT,sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("Process: %d \n",getpid());
    sleep(1);
  }
  return 0;
}
