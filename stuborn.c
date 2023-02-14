/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-10 - 16:13 +0100
 * 1st author:  sokaneil.sieng - sokaneil.sieng
 * description: stuborn
 */

#include <unistd.h>
#include <signal.h>

void signal_handling(int sig_num)
{
    if (sig_num == SIGINT) {
    write(1, "Ctrl + C is rejected\n", 22);
    }
    /*
     * signal(SIGINT, signal_handling);
     * write(1, "Ctrl + C is rejected\n", 22);
     */
}

void stuborn(void)
{
    struct sigaction act;

    act.sa_handler = &signal_handling;
    act.sa_flags = SA_RESTART;
    sigaction(SIGINT, &act, NULL);
    sleep(10);
    write(1, "Program has been slept\n", 23);
}

int main(void)
{
    stuborn();
    return (0);
}
