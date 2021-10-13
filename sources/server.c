#include "../include/minitalk.h"

void receive_message(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)unused;
	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	power += 1;
	kill(siginfo->si_pid, SIGUSR1);
	if (power == 8)
	{
		ft_printf("%c", ascii);
		if(ascii == '\0')
			kill(siginfo->si_pid, SIGUSR2);
		power = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction act;
	pid_t	pid;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = receive_message;
	pid = getpid();
	ft_printf("Esse é o PID: %d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
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
