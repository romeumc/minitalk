/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:41:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/18 15:55:17 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_signal;

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	if (g_signal == -1)
		g_signal = info->si_pid;
	else
		g_signal = signum;
	(void)ucontext;
}

char	get_signal_data(int signal, int *index)
{
	char	bit;

	if (signal == SIGUSR1)
		bit = '0';
	else
		bit = '1';
	*index += 1;
	return (bit);
}

char	get_character(t_server *data)
{
	char	character;
	int		i;

	data->index = 0;
	character = 0;
	i = 0;
	while (i < 8)
	{
		character = character << 1;
		if (data->bin[i] == '1')
			character++;
		i++;
	}
	return (character);
}

void	display_server_pid(void)
{
	ft_putstr("Server ready - pid:");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

int	main(void)
{
	t_server			data;
	char				current_char;
	struct sigaction	act;

	display_server_pid();
	g_signal = -1;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	data.index = 0;
	data.client_pid = 0;
	while (1)
	{
		//******************************** SET PID ***************
		while (data.client_pid == 0)
		{
			if (g_signal > 0)
			{
				data.client_pid = g_signal;
				if (kill(data.client_pid, SIGUSR1) == -1)
				{
					print_error_and_exit("Could not establish connection with client");
				}
			}
		}
		//********************************************************
		
		if (g_signal == SIGUSR1 || g_signal == SIGUSR2)
		{
			data.bin[data.index] = get_signal_data(g_signal, &data.index);
			if (data.index == 8)
			{
				current_char = get_character(&data);
				if (current_char != EOT)
					ft_putchar(current_char);
			}
			if (kill(data.client_pid, g_signal) == -1)
				print_error_and_exit("Connection to client Lost");
		}
		if (current_char == EOT)
		{
			data.client_pid = 0;
			g_signal = -1;
			current_char = 0;
			ft_putchar('\n');
		}
		else
			g_signal = 0;
		usleep(1000);
	}
}