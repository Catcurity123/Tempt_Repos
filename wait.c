#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main (int argc, char *argv[]){
    printf("Hello World (PID:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("Child (PID: %d)\n", (int) getpid());
    } else {
        int rc_wait = wait(NULL);
        printf("Parent of %d (rc_wait: %d) (PID: %d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}