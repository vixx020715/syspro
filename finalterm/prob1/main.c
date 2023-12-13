#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    
    pid_t childPid;
    int status,i;
    
    childPid = fork();
    
    if(childPid > 0) { 
        pid_t waitPid;
        
        while((((waitPid = wait(&status)) == -1) && errno == EINTR));
        
        if(waitPid == -1) {
            perror("error");
        }
        else {
                printf("child killed\n");
        }
        
        printf("parent killed\n");
    }
    else if(childPid == 0){ 

        printf("child killed\n");
        exit(0);
    }
    else { 
        perror("fork Fail! \n");
        return -1;
    }
    
    return 0;
}

