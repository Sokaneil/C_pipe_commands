/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-09 - 11:19 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: to each their turn
 */

#include <unistd.h>
#include <sys/wait.h>

unsigned int stu_strlen(const char *str)
{
    unsigned int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int to_each_their_turn(char *str)
{
    pid_t fork_res;
    int status;

    fork_res = fork();
    if (fork_res == -1) {
        return (-1);
    }
    if (fork_res == 0) {
        write(1, "child: ", 7);
        write(1, str, stu_strlen(str));
        write(1, "\n", 1);
    } else {
        waitpid(fork_res, &status, 0);
        write(1, "parent: ", 8);
        write(1, str, stu_strlen(str));
        write(1, "\n", 1);
    }
    return (0);
}
