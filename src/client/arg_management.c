/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:11:35 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/16 10:19:11 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	print_error(char *error_message)
{
	ft_putstr(ANSI_F_BRED);
	ft_putstr("ERROR: ");
	ft_putstr(ANSI_RESET);
	ft_putstr(error_message);
	ft_putstr("\n");
}

void	validate_args(int argc, char **argv)
{
	if (argc != 3)
	{
		print_error("Wrong usage: client PID \"message\"");
		exit(EXIT_FAILURE);
	}
	else if (ft_atoi(argv[1]) == 0)
	{
		print_error("Not a valid PID");
		exit(EXIT_FAILURE);
	}
}

int	validate_server(char *pid)
{
	int	server_pid;

	server_pid = ft_atoi(pid);
	if (kill(server_pid, SIGUSR1) == -1)
	{
		print_error("No server listening");
		exit(EXIT_FAILURE);
	}
	wait_for_ack(g_acknowledge_client);
	ft_putstr("server set\n");
	g_acknowledge_client = 0;
	return (server_pid);
}
