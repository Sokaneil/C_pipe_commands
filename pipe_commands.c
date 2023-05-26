/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-05-26 - 10:32 +0200
 * 1st author:  Sokaneil Sieng - sokaneil
 * description: pipe commands
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static int execute_command(const char* command, int fd_in, int fd_out)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        return (-1);
    } else if (pid == 0) {
        if (fd_in != STDIN_FILENO) {
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }
        if (fd_out != STDOUT_FILENO) {
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }
        execl("/bin/sh", "/bin/sh", "-c", command, NULL);
        return (-1);
    }
    return (pid);
}

int pipe_commands(const char **commands)
{
    int pipefd[2];
    int status;
    int pid1;
    int pid2;

    if (pipe(pipefd) == -1) {
        return (-1);
    }
    pid1 = execute_command(commands[0], STDIN_FILENO, pipefd[1]);
    if (pid1 == -1) {
        return (-1);
    }
    close(pipefd[1]);
    pid2 = execute_command(commands[1], pipefd[0], STDOUT_FILENO);
    if (pid2 == -1) {
        return (-1);
    }
    close(pipefd[0]);
    waitpid(pid1, &status, 0);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        return (-1);
    }
    waitpid(pid2, &status, 0);
    return WEXITSTATUS(status);
}
