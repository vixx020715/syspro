#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>

void p1();
void intHandler();
jmp_buf env;

int main() 
{
    signal(SIGINT, intHandler);
    if (setjmp(env) != 0) {
         printf("return due to interrupt\n");
         exit(0);
    }
    else printf("first pass\n");
    p1(); 
} 
void p1()
{ 
    while (1) {
        printf("loof\n");
        sleep(1);
    }
}
	
void intHandler() 
{
	
    printf("interrupt\n");
    longjmp(env, 1);
}

