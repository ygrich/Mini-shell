#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 100

int main() {
    while (1) {
        printf("mini-shell> ");
        fflush(stdout);

        char *line = NULL;
        size_t len = 0;
        ssize_t read = getline(&line, &len, stdin);

        if (read == -1) {
            free(line);
            break;
        }

        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0) {
            free(line);
            break;
        }

        char *argv[MAX_ARGS];
        int argc = 0;
        char *token = strtok(line, " ");
        while (token != NULL && argc < MAX_ARGS - 1) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;

        if (argc == 0) {
            free(line);
            continue;
        }

        pid_t pid = fork();
        if (pid == 0) {
            execvp(argv[0], argv);
            perror("Erreur d'exécution");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            perror("Erreur fork");
        }

        free(line);
    }

    printf("Bye!\n");
    return 0;
}
