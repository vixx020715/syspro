#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void intHandler();
int main( )
{
   signal(SIGINT,intHandler);
   while (1)
      pause();
   printf("not start \n");
}
void intHandler(int signo)
{
   printf("inturrupt signal\n"); 
   printf("signal number: %d\n", signo);
   exit(0);
}

