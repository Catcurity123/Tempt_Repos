#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, int *argv[]){
    printf("Hello World (PID:%d)\n", (int) getpid());
    int rc = fork();
    printf("Hello World (PID:%d)\n", (int) getpid());
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("Child (PID:%d)\n", (int) getpid());
    } else{
        printf("Parent of %d (PID:%d)\n", rc, (int) getpid());
    }
    return 0;
}