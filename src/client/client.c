/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:41:26 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/16 20:11:09 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/* When a SIGUSR1 signal arrives, set this variable. */
int g_acknowledge_client;

// void	synch_signal(int sig)
// {
// 	g_acknowledge_client = 1;
// 	(void)sig;
// }

/* The child process executes this function. */
// void	child_function(void)
// {
// 	/* Perform initialization. */
// 	printf("I'm here!!!  My pid is %d.\n", (int)getpid());

// 	/* Let parent know you’re done. */
// 	kill(getppid(), SIGUSR1);

// 	/* Continue with execution. */
// 	puts ("Bye, now....");
// 	exit (0);
// }

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	g_acknowledge_client = 1;
	// ft_putstr("message sent:");
	// ft_putnbr(signum);
	// ft_putstr("\n");
	(void)signum;
	(void)info;
	(void)ucontext;
}



void	send_character(char character, int server_pid)
{
	int	i;
	int	signal;

	i = 7;
	while (i >= 0)
	{
		if (((character >> i) & 1) == 0)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		
		kill(server_pid, signal);
		wait_for_ack(g_acknowledge_client);
		// printf("ALI server:%d signal:%d\n", server_pid, signal);
		g_acknowledge_client = 0;
		i--;
	}
	//ft_putstr("**** char sent:");
	//ft_putchar(character);
	//ft_putnbr(character);
	//ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	struct	sigaction act;
	int		i;
	int		server_pid;

	//printf("I'm here ROMEU!!!  My pid is %d.\n", (int)getpid());
	g_acknowledge_client = 0;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	
	validate_args(argc, argv);
	server_pid = validate_server(argv[1]);
	
	g_acknowledge_client = 0;
	while (argv[2][i] != '\0')
	{
		// printf("aqui\n");
		send_character(argv[2][i], server_pid);
		i++;
	}
	send_character(EOT, server_pid);

	// /* Busy wait for the child to send a signal. */
	// while (!g_acknowledge_client)
	// 	;

	/* Now continue execution. */
	ft_putstr("Message Sent\n");

	return 0;
}