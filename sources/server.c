#include "../include/minitalk.h"


void my_handler(int signum)
{
    if (signum == SIGUSR1)
        ft_printf("Received SIGUSR1!\n");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, my_handler);
	while (1)
		pause();
	return (0);
}
