#include "../include/minitalk.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}
