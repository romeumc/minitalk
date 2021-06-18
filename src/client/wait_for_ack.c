/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_ack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:19:15 by rmartins          #+#    #+#             */
/*   Updated: 2021/06/18 14:39:57 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	wait_for_ack(int server_pid, int signal)
{
	int max_wait;
	int	time;

	time = 0;
	max_wait = 10;
	while (g_acknowledge == 0)
	{
		if (max_wait > 1000)
		{
			print_error("Timeout !");
			exit(EXIT_FAILURE);
		}
		else if (time > max_wait)
		{
			max_wait += 10;
			if (kill(server_pid, signal) == -1)
			{
				print_error("Server is not respondig");
				exit(EXIT_FAILURE);
			}
		}
		else
			usleep(100);
		time++;
	}
	return ;
}