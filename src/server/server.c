/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:41:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/16 20:15:54 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_signal;

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	// printf("packet received: %d | g_signal:%d ", signum, g_signal);
	if (g_signal == -1)
		g_signal = info->si_pid;
	else
		g_signal = signum;
	// printf("after:%d ", g_signal);
	(void)ucontext;
}

char	get_signal_data(int signal, int *index)
{
	char	bit;

	// printf("signal:%d index:%i ", signal, *index);
	if (signal == SIGUSR1)
		bit = '0';
	else
		bit = '1';
	*index += 1;
	// printf("bit:%c\n", bit);
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
		// printf(ANSI_F_YELLOW"i:%i c:%c bit:%c [%s]"ANSI_RESET"\n", i, character, data->bin[i], data->bin);
		i++;
	}
	return(character);
}

int	main(void)
{
	t_server	data;
	char		current_char;
	
	ft_putstr("pid:");
	ft_putnbr(getpid());
	ft_putchar('\n');

	struct sigaction act;
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
				kill(data.client_pid, SIGUSR1);
				//printf(ANSI_B_CYAN" signal:%d client_pid:%d "ANSI_RESET"\n", g_signal, data.client_pid);
			}
			//sleep(1);
		}
		//g_signal = 0;
		//********************************************************

		
		if (g_signal == SIGUSR1 || g_signal == SIGUSR2)
		{
			data.bin[data.index] = get_signal_data(g_signal, &data.index);
			// printf(ANSI_B_BGREEN"g_signal:%d client_pid:%d [%s]"ANSI_RESET"\n", g_signal, data.client_pid, data.bin);
			if (data.index == 8)
			{
				current_char = get_character(&data);
				// printf(ANSI_F_BRED"****letra:%c %d"ANSI_RESET"\n", current_char, current_char);
				if (current_char != EOT)
					ft_putchar(current_char);
			}
		}
		kill(data.client_pid, g_signal);
		if (current_char == EOT)
		{
			//printf("***********AQUI***************\n");
			data.client_pid = 0;
			g_signal = -1;
			current_char = 0;
			// ft_memset(data.bin, 0, 8);
		}
		else
			g_signal = 0;
		
		sleep(1);
		//printf("***current:%d\n", current_signal);
		//ft_putchar('.');
		//wait_for_ack(g_signal);
		
		//sleep(2);
		//data.client_pid = 0;
	}
}