#include "../include/minitalk.h"
# include <stdio.h>


int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		kill(pid, "oi");
	}
	return (0);
}
