/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:44:18 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/19 18:47:01 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	if (g_signal == -1)
		g_signal = info->si_pid;
	else
		g_signal = signum;
	(void)ucontext;
}

void	set_client_pid(t_server *data)
{
	while (data->client_pid == 0)
	{
		if (g_signal > 0)
		{
			data->client_pid = g_signal;
			if (kill(data->client_pid, SIGUSR1) == -1)
			{
				print_error_and_exit("Could not establish connection");
			}
		}
	}
}

void	init_data(t_server *data, struct sigaction *act)
{
	g_signal = -1;
	data->index = 0;
	data->client_pid = 0;
	act->sa_flags = SA_SIGINFO;
	act->sa_sigaction = &handler;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
}

void	display_server_pid(void)
{
	ft_putstr("Server ready - pid:");
	ft_putnbr(getpid());
	ft_putchar('\n');
}
