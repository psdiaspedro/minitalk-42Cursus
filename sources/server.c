#include "../include/minitalk.h"

static void	ft_finish(int pid)
{
	ft_printf("\n");
	if (kill(pid, SIGUSR1))
		ft_printf("Error to notify client\n");
}

static void	recive_message(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned int	count;
	static unsigned int	letter;

	(void)context;
	if (count > 7)
	{
		count = 0;
		letter = 0;
	}
	if (sig == SIGUSR2)
		letter += 1 << count;
	count++;
	if (count == 8)
	{
		if (letter == 0)
		{
			ft_finish(siginfo->si_pid);
			return ;
		}
		else
			ft_printf("%c", letter);
	}
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;
	
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = recive_message;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("[SERVER] > listening on pid %d\n", getpid());
	while (1)
		pause();
}

/*
	struct sigaction {
		void *sa_sigaction -> um ponteiro para a função de manipulação (habilitada com SA_SIGINFO)
		int sa_flags -> SA_SIGINFO (habilita a configuração do sa_sigaction)
		sigset_t sa_mask;
	}
*/

/*
	struct siginfo_t {
		pid_t si_pid -> sending processes ID -> IMPORTANTE
	}
*/
