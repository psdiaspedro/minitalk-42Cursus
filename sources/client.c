#include "../include/minitalk.h"
# include <stdio.h>

void send_char (int pid, unsigned char byte)
{
	//verificar bit
	int i;
	int mask;


	i = 0;
	mask = 1;
	while (i < 8)
	{
		if (byte & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask << 1;
		i++;
	}
}

void send_message(pid_t pid, char *string)
{
	int i;
	char letra;

	i = 0;
	while (string[i] != '\0')
	{
		send_char (pid, string[i]);
		i++;
	}
	send_char (pid, string[i])
}

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
		send_message(pid, argv[2]);
	}
	return (0);
}
