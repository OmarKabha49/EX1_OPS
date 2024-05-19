#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PHONEBOOK "phonebook.txt"

void executeCommand(char *cmd[], int inputFd, int outputFd) {
    if (fork() == 0) {
        if (inputFd != 0) {
            dup2(inputFd, 0);
            close(inputFd);
        }
        if (outputFd != 1) {
            dup2(outputFd, 1);
            close(outputFd);
        }
        execvp(cmd[0], cmd);
        perror("execvp");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }

    int pipe1[2], pipe2[2], pipe3[2];
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    char *catCmd[] = {"cat", PHONEBOOK, NULL};
    char *grepCmd[] = {"grep", argv[1], NULL};
    char *sedCmd1[] = {"sed", "s/ /#/g", NULL};
    char *sedCmd2[] = {"sed", "s/,/ /", NULL};
    char *awkCmd[] = {"awk", "{print $2}", NULL};

    // cat phonebook.txt
    executeCommand(catCmd, 0, pipe1[1]);
    close(pipe1[1]);

    // grep "name"
    executeCommand(grepCmd, pipe1[0], pipe2[1]);
    close(pipe1[0]);
    close(pipe2[1]);

    // sed 's/ /#/g'
    executeCommand(sedCmd1, pipe2[0], pipe3[1]);
    close(pipe2[0]);
    close(pipe3[1]);

    // sed 's/,/ /'
    executeCommand(sedCmd2, pipe3[0], pipe1[1]);
    close(pipe3[0]);
    close(pipe1[1]);

    // awk '{print $2}'
    executeCommand(awkCmd, pipe1[0], 1);
    close(pipe1[0]);

    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    return 0;
}
