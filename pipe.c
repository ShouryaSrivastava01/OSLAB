#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h>


int main(){
    int fd[2], n;
    char buffer[100];
    pid_t pid;
    pipe(fd);
    pid = fork();

    if(pid>0){
        printf("I'm parent and I'm sending\n");
        write(fd[1], "helloworld\n", 11);
    }
    else {
        printf("I'm child and I received\n");
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
    }
}