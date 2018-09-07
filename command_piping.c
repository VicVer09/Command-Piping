#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
int main () {

    int fd[2]; // fd[0] = reading (stdin), fd[1] = writing (stdout)
    pipe(fd);
    char *command[2];
    command [0] = "ls";
    command [1] = NULL;

    //fflush(stdout);
    if (fork() == 0) {
        
        close(1);
        int f1 = dup(fd[1]);
        
        // execute ls using execvp
        execvp(command[0], command); 

    } else {
        
        close(0);
        int f0 = dup(fd[0]);
        char *buffer = (char *) malloc(512);
        read(0, buffer, 512);
        printf("%s",buffer);

    }
    return 0;

}