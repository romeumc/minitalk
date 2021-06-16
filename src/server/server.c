/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:41:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/16 11:52:22 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_signal;

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	g_signal = signum;
	//sigval_t teste;
	if (signum == SIGUSR1)
		ft_putstr("SIGUSR_1:");
	else
		ft_putstr("SIGUSR_2:");
	ft_putnbr(signum);
	ft_putstr (" Sending PID:");
	ft_putnbr(info->si_pid);
	ft_putstr("\n");
	(void)info;
	(void)ucontext;
	kill(info->si_pid, signum);
	wait_for_ack(g_signal);
}

int	get_signal_data(int *signal, int *index)
{
	int	bit;

	if (*signal == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	(*index)++;
	*signal = 0;
	g_signal = 0;
	printf("bit:%i index:%i\n", bit, *index);
	sleep(1);
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
		if (data->bin[i] == 1)
			character++;
		i++;
	}
	return(character);
}

int	main(void)
{
	t_server	data;
	int			current_signal;
	char		current_char;
	
	ft_putstr("pid:");
	ft_putnbr(getpid());
	ft_putchar('\n');

	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	//g_signal = 0;
	data.client_pid = 0;
	data.index = 0;
	while (1)
	{
		if (data.client_pid == 0)
		{
			wait_for_ack(g_signal);
			data.client_pid = 1;
			ft_putstr(ANSI_F_BCYAN);
			ft_putstr("setup_pid done\n");
			ft_putstr(ANSI_RESET);
		}
		current_signal = g_signal;
		//printf("current:%d\n", current_signal);
		if (current_signal == SIGUSR1 || current_signal == SIGUSR2)
		{
			data.bin[data.index] = get_signal_data(&current_signal, &data.index);
			if (data.index == 8)
			{
				current_char = get_character(&data);
				printf(ANSI_F_RED"****letra:%c"ANSI_RESET"\n", current_char);
				if (current_char == EOT)
				{
					printf("***********AQUI***************\n");
					data.client_pid = 0;
				}
			}
		}
		//printf("***current:%d\n", current_signal);
		//ft_putchar('.');
		//wait_for_ack(g_signal);
		
		//sleep(2);
		//data.client_pid = 0;
	}
}