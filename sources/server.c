#include "../include/minitalk.h"

void my_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
    if (signum == SIGUSR1)
	{
        ft_printf("Received SIGUSR1!\n");
		//ft_printf("Client PID: %d\n", info->si_pid);
	}
	if (signum == SIGUSR2)
	{
        ft_printf("Received SIGUSR2!\n");
		//ft_printf("Client PID: %d\n", info->si_pid);
	}

}

int	main(void)
{
	struct sigaction act;
	//sigset_t mask_set;
	pid_t	pid;

	// sigemptyset(&mask_set);
	// sigaddset(&mask_set, SIGTSTP);
	// sigaddset(&mask_set, SIGINT);
	act.sa_handler = NULL;
	act.sa_flags = SA_SIGINFO;
	//act.sa_mask = mask_set;
	act.sa_sigaction = my_handler;
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
		void *sa_handler -> ponteiro para a função de manipulação
		void *sa_sigaction -> um ponteiro para a função de manipulação (habilitada com SA_SIGINFO)
		int sa_flags -> SA_SIGINFO (habilita a configuração do sa_sigaction)
		sigset_t sa_mask;
	}
*/

/*
	struct siginfo_t {
		int si_signo -> singal number (ex: SIGUSR1)
		int si_errno -> an errno value
		int si_code -> signal code
		pid_t si_pid -> sending processes ID -> IMPORTANTE
		uid_t si_uid -> real user ID of sending process
		int si_status -> ext value or signal
	}
*/
