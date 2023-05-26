/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-05-24 - 18:12 +0200
 * 1st author:  Sokaneil SIeng - sokaneil
 * description: system2 test
 */

#include <stdio.h>

int stu_system2(char *command);

int main(void)
{
    char command[] = "ls -l";

    int exit_status = stu_system2(command);

    printf("Command exited with status: %d\n", exit_status);

    return (0);
}
