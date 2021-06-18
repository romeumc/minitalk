/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:11:35 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/18 15:35:39 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	validate_args(int argc, char **argv)
{
	if (argc != 3)
		print_error_and_exit("Wrong usage: client PID \"message\"");
	else if (ft_atoi(argv[1]) == 0)
		print_error_and_exit("Not a valid PID");
}

int	validate_server(char *pid)
{
	int	server_pid;

	server_pid = ft_atoi(pid);
	if (kill(server_pid, SIGUSR1) == -1)
		print_error_and_exit("No server listening");
	wait_for_ack(server_pid, SIGUSR1);
	g_acknowledge = 0;
	return (server_pid);
}
