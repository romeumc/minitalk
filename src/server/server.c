/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:41:16 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/19 18:47:54 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_signal;

char	get_signal_data(int signal, t_server *data)
{
	char	bit;

	if (signal == SIGUSR1)
		bit = '0';
	else
		bit = '1';
	data->index++;
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

void	process_signal(t_server *data, char *current_char)
{
	data->i = data->index;
	data->bin[data->i] = get_signal_data(g_signal, data);
	if (data->index == 8)
	{
		*current_char = get_character(data);
		if (*current_char != EOT)
			ft_putchar(*current_char);
	}
	if (kill(data->client_pid, g_signal) == -1)
		print_error_and_exit("Connection to client Lost");
}

int	main(void)
{
	t_server			data;
	char				current_char;
	struct sigaction	act;

	display_server_pid();
	init_data(&data, &act);
	while (1)
	{
		set_client_pid(&data);
		if (g_signal == SIGUSR1 || g_signal == SIGUSR2)
		{
			process_signal(&data, &current_char);
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
