#include "../include/minitalk.h"
# include <stdio.h>

void handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("signal recived\n");
		exit(0);
	}
}

void	decimal_conversion(unsigned char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) != 0)
		{
			ft_printf("Error signal!\n");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) != 0)
		{
			ft_printf("Error signal!\n");
			exit(0);
		}
	}
	usleep(2500);
}

int	send_message(int server_pid, char *msg)
{
	int		i;

	i = 0;
	while (msg[i] != '\0')
	{
		decimal_conversion(msg[i], 7, server_pid);
		i++;
	}
	decimal_conversion('\n', 7, server_pid);
	decimal_conversion((unsigned char)msg[i], 7, server_pid);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Por favor, escreva no formato: ./client + PID + Mensagem\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
	{
		ft_printf("Valor do PID invalido");
		return (1);
	}
	signal(SIGUSR1, handler);
	send_message(pid, argv[2]);
	while(1)
		pause();
	return (0);
}
