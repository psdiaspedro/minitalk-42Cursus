#include "../include/minitalk.h"
# include <stdio.h>


int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Por favor, escreva no formato: ./client + PID + Mensagem\n");
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 1)
		{
			ft_printf("Valor do PID invalido");
			return (1);
		}
		kill(pid, SIGUSR1);
	}
	return (0);
}
