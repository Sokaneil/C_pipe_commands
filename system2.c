/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-10 - 14:33 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: system2
 */

#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>

pid_t child_pid;

struct sys {
    struct sigaction sig;
    pid_t fork_res;
    int status;
    int res;
    char *buf[4];
}

static void signal_handling()
{
    signal(SIGINT, signal_handling);
    kill(child_pid, SIGINT);
}

static void sys_execute(struct *sys)
{
    sys.buf[0] = "sh";
    sys.buf[1] = "-c";
    sys.buf[2] = command;
    sys.buf[3] = NULL;
    sys.res = execv("/bin/sh", buf);
    if (sys.res == -1) {
        return (-1);
        }
}

int stu_system2(char *command)
{
    struct sys sys;

    sys.sig.sa_handler = &signal_handling;
    sys.sig.sa_flags = 0;
    sys.fork_res = fork();
    if (fork_res == -1) {
        return (-1);
    }
    if (fork_res == 0) {
        sys_execute()
    } else {
        sigaction(SIGINT, &sys, 0);
        waitpid(fork_res, &status, 0);
    }
    return (0);
}
