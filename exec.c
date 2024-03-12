#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]){
    printf("Hello World (PID:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("Child (PID:%d)\n", (int)getpid());
        char pid_str[16];
        sprintf(pid_str, "%d", getpid());
        char *myargv[4];
        myargv[0] = strdup("printf");
        myargv[1] = strdup("Child (PID:%d)\n");
        myargv[2] = strdup(pid_str);
        myargv[3] = NULL;
        execvp(myargv[0], myargv);
        printf("This should not print out\n");
        exit(1);
    } else {
        int rc_wait = wait(NULL);
        printf("Parent of %d (rc_wait:%d) (PID:%d\n)", rc, rc_wait, (int)getpid());
    }
    return 0;
}