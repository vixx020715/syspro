#include <stdio.h>
#include <stdio.h>
static void exit_handler1(void), exit_handler2(void);
int main(void) 
	{
if (atexit(exit_handler1) != 0)
     perror("exit_handler1 x");
  if (atexit(exit_handler2) != 0)
     perror("exit_handler2 x");
  printf("main 끝 \n");
 exit(0);
 }

static void exit_handler1(void)
{
  printf("first exit handler\n");
}

static void exit_handler2(void)
{
  printf("second exit handler\n");
 }

