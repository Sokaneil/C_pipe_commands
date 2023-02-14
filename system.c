/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-10 - 14:33 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: system
 */

#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>

int stu_system(char *command)
{
    pid_t fork_res;
    int status;
    int res;
    char *buf[4];

    buf[0] = "sh";
    buf[1] = "-c";
    buf[2] = command;
    buf[3] = NULL;
    fork_res = fork();
    if (fork_res == -1) {
        return (-1);
    }
    if (fork_res == 0) {
        res = execv("/bin/sh", buf);
        if (res == -1) {
            return (-1);
        }
    } else {
        waitpid(fork_res, &status, 0);
    }
    return (0);
}
