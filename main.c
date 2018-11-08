#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(SIGINT == signo){
    printf("\n Program exited due to SIGINT \n");
    exit(0);
  }

}
int main(){

  signal(SIGINT,sighandler);

  while(1){
    printf("Process: %d \n",getpid());
    sleep(1);
  }
  return 0;
}
