/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-10 - 14:33 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: system2
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

pid_t child_pid;

static void signal_handling(int signum)
{
    kill(child_pid, signum);
}

int stu_system2(char *command)
{
    struct sigaction sa;
    pid_t pid;
    int status;

    sa.sa_handler = signal_handling;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    pid = fork();
    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, NULL);
    } else {
        child_pid = pid;
        waitpid(pid, &status, 0);
        child_pid = 0;
        sigaction(SIGINT, &(struct sigaction){0}, NULL);
        while (!WIFEXITED(status)) {
            waitpid(pid, &status, 0);
        }
        child_pid = 0;
        sigaction(SIGINT, &(struct sigaction){0}, NULL);
        return WEXITSTATUS(status);
    }
}
