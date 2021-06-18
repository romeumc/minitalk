/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:41:26 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/18 14:36:16 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int g_acknowledge;

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	g_acknowledge = 1;
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
		
		if (kill(server_pid, signal) == -1)
		{
			print_error("Lost connection with server");
			exit(EXIT_FAILURE);
		}
		wait_for_ack(server_pid, signal);
		g_acknowledge = 0;
		i--;
	}
}

int	main(int argc, char **argv)
{
	struct	sigaction act;
	int		i;
	int		server_pid;

	g_acknowledge = 0;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);	
	validate_args(argc, argv);
	server_pid = validate_server(argv[1]);
	g_acknowledge = 0;
	while (argv[2][i] != '\0')
	{
		send_character(argv[2][i], server_pid);
		i++;
	}
	send_character(EOT, server_pid);
	ft_putstr("Message Sent\n");
	return (EXIT_SUCCESS);
}