#include "../include/minitalk.h"

static void	handle(int sig, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_printf("Message Recieved Successfully\n");
		exit(0);
	}
}

static void	ft_kill(int server_pid, int signal)
{
	kill(server_pid, signal);
	usleep(10000);
}

static void	send_char(int server_pid, unsigned char c)
{
	int	count;

	count = -1;
	while (++count < 8)
	{
		if (c % 2 == 0)
			ft_kill(server_pid, SIGUSR1); //0
		else
			ft_kill(server_pid, SIGUSR2); //1
		c /= 2;
	}
}

static void send_message(int server_pid, const char *message)
{
	unsigned int i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, message[i]);
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("Wrong input. Must be: ./client + Server PID + Message\n");
		return (1);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handle;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	while (1)
		pause();
}
