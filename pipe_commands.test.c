/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-05-26 - 11:21 +0200
 * 1st author:  Sokaneil SIeng - sokaneil
 * description: pipe commands test
 */

#include <stdio.h>

int pipe_commands(const char **commands);

int main(void)
{
    const char *commands[2];
    commands[0] = "echo hello world";
    commands[1] = "wc -c";

    int status = pipe_commands(commands);
    //printf("Exit status of the second command: %d\n", status);
    return 0;
}
